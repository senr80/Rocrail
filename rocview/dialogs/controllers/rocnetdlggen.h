///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Dec 21 2009)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __rocnetdlggen__
#define __rocnetdlggen__

#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/spinctrl.h>
#include <wx/sizer.h>
#include <wx/radiobox.h>
#include <wx/checkbox.h>
#include <wx/statbox.h>
#include <wx/statline.h>
#include <wx/button.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class rocnetdlggen
///////////////////////////////////////////////////////////////////////////////
class rocnetdlggen : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_labIID;
		wxTextCtrl* m_IID;
		wxStaticText* m_labRocNetID;
		wxSpinCtrl* m_RNID;
		wxRadioBox* m_Sublib;
		wxCheckBox* m_CRC;
		wxStaticLine* m_staticline1;
		wxStaticText* m_labDevice;
		wxTextCtrl* m_Device;
		wxRadioBox* m_BPS;
		wxStaticLine* m_staticline2;
		wxStaticText* m_labAddress;
		wxTextCtrl* m_Address;
		wxStaticText* m_labPort;
		wxSpinCtrl* m_Port;
		wxStdDialogButtonSizer* m_StdButton;
		wxButton* m_StdButtonOK;
		wxButton* m_StdButtonCancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnSublib( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOK( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		rocnetdlggen( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("RocNet"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );
		~rocnetdlggen();
	
};

#endif //__rocnetdlggen__
