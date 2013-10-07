/*
 Rocrail - Model Railroad Software

 Copyright (C) 2002-2013 Rob Versluis, Rocrail.net

 Without an official permission commercial use is not permitted.
 Forking this project is not permitted.

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 2
 of the License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/

#ifndef __rocnetnodedlg__
#define __rocnetnodedlg__

/**
@file
Subclass of rocnetnodegen, which is generated by wxFormBuilder.
*/

#include "rocnetnodegen.h"

//// end generated include
#include "rocs/public/node.h"
#include "rocs/public/map.h"

/** Implementing rocnetnodegen */
class RocnetNodeDlg : public rocnetnodegen
{
  iONode m_Ini;
  iONode m_Digint;
  iONode m_Props;
  iONode m_SelectedNode;
  iOMap m_NodeMap;
  iOMap m_TreeItemMap;
  iOMap m_TreeLocationMap;
  iONode m_SelectedZLevel;
  void initLabels();
  void initListLabels();
  void initValues();
  void initNodeList();
  void initPorts();
  void initMacro(iONode node);
  iONode getZLevel(int level, char* sLevel);
  void selChanged( iONode rnnode );
  void shutdownLocation();
  int m_PortGroup;
  int m_SortCol;

	protected:
		// Handlers for rocnetnodegen events.
    void onIndexSelected( wxListEvent& event );
		void onRocnetWrite( wxCommandEvent& event );
		void onPortPrev( wxCommandEvent& event );
		void onPortNext( wxCommandEvent& event );
		void onPortRead( wxCommandEvent& event );
		void onPortWrite( wxCommandEvent& event );
		void onOK( wxCommandEvent& event );
		void onClose( wxCloseEvent& event );
		void onNodeOptionsRead( wxCommandEvent& event );
		void onNodeOptionsWrite( wxCommandEvent& event );
		void onShutdown( wxCommandEvent& event );
    void onShutdownAll( wxCommandEvent& event );
    void onShow( wxCommandEvent& event );
    void onGCALogo( wxMouseEvent& event );
    void onQuery( wxCommandEvent& event );
    void onRocNetLogo( wxMouseEvent& event );
    void onMacroNumber( wxSpinEvent& event );
    void onMacroGet( wxCommandEvent& event );
    void onMacroSet( wxCommandEvent& event );
    void onIOType( wxCommandEvent& event );
    void onMacroLineChange( wxGridEvent& event );
    void onUpdate( wxCommandEvent& event );
    void onPortTest( wxCommandEvent& event );
    void onListColClick( wxListEvent& event );
    void onItemActivated( wxTreeEvent& event );
    void onTreeItemRightClick( wxTreeEvent& event );
    void onTreeSelChanged( wxTreeEvent& event );
    void onMenu( wxCommandEvent& event );
	public:
    void onUpdateVersion( wxCommandEvent& event );
		/** Constructor */
		RocnetNodeDlg( wxWindow* parent, iONode ini );
		~RocnetNodeDlg();
	//// end generated class members
		void event(iONode node);
	  int m_AvailableVersion;
	  char* m_VersionInfo;
	
};

#endif // __rocnetnodedlg__
