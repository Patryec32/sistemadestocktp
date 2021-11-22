#ifndef VENTANAALTAS_H
#define VENTANAALTAS_H

//(*Headers(VentanaAltas)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class VentanaAltas: public wxFrame
{
	public:

		VentanaAltas(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~VentanaAltas();

		//(*Declarations(VentanaAltas)
		wxButton* Button1;
		wxButton* Button2;
		wxButton* Button3;
		wxStaticText* st1;
		wxStaticText* st2;
		wxStaticText* st3;
		wxStaticText* st4;
		wxStaticText* st5;
		wxStaticText* st6;
		wxTextCtrl* TextCtrl1;
		wxTextCtrl* TextCtrl2;
		wxTextCtrl* tc1;
		wxTextCtrl* tc2;
		//*)

	protected:

		//(*Identifiers(VentanaAltas)
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_TEXTCTRL1;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_TEXTCTRL2;
		static const long ID_STATICTEXT3;
		static const long ID_STATICTEXT4;
		static const long ID_BUTTON3;
		static const long ID_STATICTEXT5;
		static const long ID_TEXTCTRL3;
		static const long ID_STATICTEXT6;
		static const long ID_TEXTCTRL4;
		//*)

	private:

		//(*Handlers(VentanaAltas)
		void OnButton1Click(wxCommandEvent& event);
		void OnButton3Click(wxCommandEvent& event);
		void OnTextCtrl1Text(wxCommandEvent& event);
		void OnButton4Click(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
