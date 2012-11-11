/* Rocrail - Model Railroad Software Copyright (C) 2002-2012 Rob Versluis, Rocrail.net Without an official permission commercial use is not permitted. Forking this project is not permitted. This program is free software; you can redistribute it and/or as published by the Free Software Foundation; either version 2 modify it under the terms of the GNU General Public License of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.*/#include "locowidget.h"#include <wx/dataobj.h>#include <wx/dnd.h>#include "rocrail/wrapper/public/Loc.h"#include "rocrail/wrapper/public/DataReq.h"#include "rocview/public/guiapp.h"#include "rocview/wrapper/public/Gui.h"#include "rocview/dialogs/loccontroldlg.h"#include "rocs/public/file.h"#include "rocs/public/system.h"#include "rocview/public/base.h"#include "rocview/xpm/nopict12030.xpm"LocoWidget::LocoWidget( wxWindow* parent, iONode props ):LocoWidgetGen( parent ){  m_Props = props;  m_hasImageRequested = false;  UpdateLocoImg();  InitLoco();}void LocoWidget::InitLoco() {  char id[32];  StrOp.fmtb(id, "%.20s", wLoc.getid( m_Props ));  m_ID->SetLabel(wxString(wLoc.getid( m_Props ),wxConvUTF8));  // Set the window name to get it findable by parent->FindWindowByName(name)  SetName(m_ID->GetLabel());  m_Block->SetLabel(_T(""));  m_Destination->SetLabel(_T(""));  UpdateLoco(m_Props);}void LocoWidget::UpdateLoco(iONode node) {  Boolean dir = wLoc.isdir(node);  Boolean placing = wLoc.isplacing(node);  char* val = StrOp.fmt( "%s%s%d%s", dir?"":"<", placing?"":"-", wLoc.getV( node )==-1?0:wLoc.getV( node ), dir?">":"" );  m_Speed->SetLabel( wxString(val,wxConvUTF8) );  StrOp.free( val );  m_Speed->SetBackgroundColour( wLoc.isplacing(node)?GetBackgroundColour():wxColour(240,200,200));  m_Stop->Enable( wLoc.getV( node ) > 0 );  if( wLoc.getblockid( node ) != NULL ) {    m_Block->SetLabel( (wLoc.isblockenterside(node)?_T(""):_T("-")) + wxString(wLoc.getblockid( node ),wxConvUTF8) );  }  if(!wLoc.isactive(node))    m_Mode->SetLabel( _T("hold") );  else if( wLoc.ismanual(node))    m_Mode->SetLabel( _T(">") + wxString(wLoc.getmode( node ),wxConvUTF8) );  else    m_Mode->SetLabel( wxString(wLoc.isresumeauto( node ) ? "*":"",wxConvUTF8) + wxString(wLoc.getmode( node ),wxConvUTF8) );  m_Mode->SetBackgroundColour( GetBackgroundColour());  if( StrOp.equals( wLoc.mode_auto, wLoc.getmode( node ) ) ) {    m_Mode->SetBackgroundColour( Base::getRes2Color() );  }  else if( StrOp.equals( wLoc.mode_wait, wLoc.getmode( node ) ) ) {    m_Mode->SetBackgroundColour( Base::getBlue());  }  else if(!wLoc.isactive(node))    m_Mode->SetBackgroundColour( Base::getNoneActiveColor());  if( wLoc.getdestblockid( node ) != NULL ) {    if( wLoc.getscidx(node) == -1 )    m_Destination->SetLabel( wxString(wLoc.getdestblockid( node ),wxConvUTF8) );    else {      val = StrOp.fmt( "[%s:%d] %s", wLoc.getscheduleid(node), wLoc.getscidx( node ), wLoc.getdestblockid( node ) );      m_Destination->SetLabel( wxString(val,wxConvUTF8) );      StrOp.free( val );    }  }}void LocoWidget::UpdateLocoImg(){  // Get copied node:  if( wLoc.getimage( m_Props ) != NULL && StrOp.len(wLoc.getimage( m_Props )) > 0 ) {    wxBitmapType bmptype = wxBITMAP_TYPE_XPM;    if( StrOp.endsWithi( wLoc.getimage( m_Props ), ".gif" ) )      bmptype = wxBITMAP_TYPE_GIF;    else if( StrOp.endsWithi( wLoc.getimage( m_Props ), ".png" ) )      bmptype = wxBITMAP_TYPE_PNG;    TraceOp.trc( "frame", TRCLEVEL_INFO, __LINE__, 9999, "***** UpdateLocImage %s", wLoc.getimage( m_Props ) );    const char* imagepath = wGui.getimagepath(wxGetApp().getIni() );    static char pixpath[256];    StrOp.fmtb( pixpath, "%s%c%s", imagepath, SystemOp.getFileSeparator(), FileOp.ripPath( wLoc.getimage( m_Props ) ) );    if( FileOp.exist(pixpath)) {      wxBitmap bmp = scale(wxBitmap(wxString(pixpath,wxConvUTF8), bmptype), 120, 30);      m_LocoImage->SetBitmap( bmp );    }    else if(!m_hasImageRequested) {      m_hasImageRequested = true;      m_LocoImage->SetBitmap( wxBitmap(nopict12030_xpm) );      // request the image from server:      iONode node = NodeOp.inst( wDataReq.name(), NULL, ELEMENT_NODE );      wDataReq.setid( node, wLoc.getid(m_Props) );      wDataReq.setcmd( node, wDataReq.get );      wDataReq.settype( node, wDataReq.image );      wDataReq.setfilename( node, wLoc.getimage(m_Props) );      wxGetApp().sendToRocrail( node );    }  }  else    m_LocoImage->SetBitmap( wxBitmap(nopict12030_xpm) );  m_LocoImage->Refresh();  m_LocoImage->SetToolTip(wxString(wLoc.getid( m_Props ),wxConvUTF8) + _T(" ") + wxString(wLoc.getdesc( m_Props ),wxConvUTF8));}wxBitmap LocoWidget::scale(wxBitmap bmp,  int max_width, int max_height) {    int original_width, original_height;    original_width = bmp.GetWidth();    original_height = bmp.GetHeight();    if( original_width <= max_width && original_height <= max_height ) {      return bmp;    }    wxBitmap result;    // Regard aspect ratio.    float ws = (float)original_width / (float)max_width;    float hs = (float)original_height / (float)max_height;    wxImage img = bmp.ConvertToImage(); // create an image of the bitmap    if( ws > hs ) {      result = wxBitmap(img.Rescale((int)((float)original_width/ws), (int)((float)original_height/ws)));    }    else {      result = wxBitmap(img.Rescale((int)((float)original_width/hs), (int)((float)original_height/hs)));    }    return result;}void LocoWidget::onThrottle( wxMouseEvent& event ) {  LocControlDialog* dlg = new LocControlDialog(this, wxGetApp().getFrame()->m_LocCtrlList, wxGetApp().getFrame()->m_LocDlgMap, wLoc.getid(m_Props));  dlg->Show(TRUE);}void LocoWidget::onPopUp( wxMouseEvent& event ) {  wxMenu menu( m_ID->GetLabel() );  menu.Append( ME_GridLocGo, wxGetApp().getMenu("start"), wxGetApp().getTip("start"));  menu.Connect( ME_GridLocGo, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LocoWidget::onMenuStart ), NULL, this );  PopupMenu(&menu );}void LocoWidget::onMenuStart( wxCommandEvent& event ) {  iONode cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );  wLoc.setid( cmd, wLoc.getid(m_Props) );  wLoc.setcmd( cmd, wLoc.go );  wxGetApp().sendToRocrail( cmd );  cmd->base.del(cmd);}void LocoWidget::onStop( wxCommandEvent& event ) {  iONode cmd = NodeOp.inst( wLoc.name(), NULL, ELEMENT_NODE );  wLoc.setid( cmd, wLoc.getid(m_Props) );  wLoc.setV( cmd, 0 );  wxGetApp().sendToRocrail( cmd );  cmd->base.del(cmd);}void LocoWidget::onImageLeftDown( wxMouseEvent& event ) {  wxTextDataObject my_data(_T("moveto:") + wxString(wLoc.getid( m_Props ),wxConvUTF8)+_T("::"));  wxDropSource dragSource( this );  dragSource.SetData( my_data );  wxDragResult result = dragSource.DoDragDrop(wxDrag_CopyOnly);}