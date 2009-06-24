///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Apr 17 2008)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __powermandlggen__
#define __powermandlggen__

class basenotebook;

#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/listbox.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/textctrl.h>
#include <wx/combobox.h>
#include <wx/checkbox.h>
#include <wx/statbox.h>
#include <wx/notebook.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class powermandlggen
///////////////////////////////////////////////////////////////////////////////
class powermandlggen : public wxDialog 
{
	private:
	
	protected:
		basenotebook* m_BoosterBook;
		wxPanel* m_Index;
		wxStaticText* m_labBoosters;
		wxListBox* m_Boosters;
		wxButton* m_AddBooster;
		wxButton* m_DelBooster;
		wxPanel* m_Generel;
		wxStaticText* m_labID;
		wxTextCtrl* m_ID;
		wxStaticText* m_labDistrict;
		wxTextCtrl* m_District;
		wxPanel* m_ModulePanel;
		wxStaticText* m_labModules;
		wxListBox* m_Modules;
		wxComboBox* m_ModulesCombo;
		wxButton* m_AddModule;
		wxButton* m_DelModule;
		wxPanel* m_BlocksPanel;
		wxStaticText* m_labBlocks;
		wxListBox* m_Blocks;
		wxComboBox* m_BlocksCombo;
		wxButton* m_AddBlock;
		wxButton* m_DelBlock;
		wxPanel* m_DetailsPanel;
		wxCheckBox* m_StopDistrictLocos;
		wxCheckBox* m_PowerOffAll;
		wxCheckBox* m_RetryPowerOn;
		wxStdDialogButtonSizer* m_sdbSizer1;
		wxButton* m_sdbSizer1OK;
		wxButton* m_sdbSizer1Apply;
		wxButton* m_sdbSizer1Cancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnAddBooster( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnDelBooster( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnAddModule( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnDelModule( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnAddBlock( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnDelBlock( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnApply( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnOK( wxCommandEvent& event ){ event.Skip(); }
		
	
	public:
		powermandlggen( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Power districts setup"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 350,-1 ), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER );
		~powermandlggen();
	
};

#endif //__powermandlggen__
