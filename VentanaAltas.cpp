#include "VentanaAltas.h"
#include "Producto.h"
#include <fstream>

//(*InternalHeaders(VentanaAltas)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(VentanaAltas)
const long VentanaAltas::ID_STATICTEXT1 = wxNewId();
const long VentanaAltas::ID_STATICTEXT2 = wxNewId();
const long VentanaAltas::ID_TEXTCTRL1 = wxNewId();
const long VentanaAltas::ID_BUTTON1 = wxNewId();
const long VentanaAltas::ID_BUTTON2 = wxNewId();
const long VentanaAltas::ID_TEXTCTRL2 = wxNewId();
const long VentanaAltas::ID_STATICTEXT3 = wxNewId();
const long VentanaAltas::ID_STATICTEXT4 = wxNewId();
const long VentanaAltas::ID_BUTTON3 = wxNewId();
const long VentanaAltas::ID_STATICTEXT5 = wxNewId();
const long VentanaAltas::ID_TEXTCTRL3 = wxNewId();
const long VentanaAltas::ID_STATICTEXT6 = wxNewId();
const long VentanaAltas::ID_TEXTCTRL4 = wxNewId();
//*)

BEGIN_EVENT_TABLE(VentanaAltas,wxFrame)
	//(*EventTable(VentanaAltas)
	//*)
END_EVENT_TABLE()

VentanaAltas::VentanaAltas(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(VentanaAltas)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	st1 = new wxStaticText(this, ID_STATICTEXT1, _("Alta de Producto"), wxPoint(56,40), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	wxFont st1Font(16,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	st1->SetFont(st1Font);
	st2 = new wxStaticText(this, ID_STATICTEXT2, _("Ingrese codigo del producto"), wxPoint(48,80), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	tc1 = new wxTextCtrl(this, ID_TEXTCTRL1, _("codigo"), wxPoint(208,80), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	Button1 = new wxButton(this, ID_BUTTON1, _("Aceptar"), wxPoint(136,120), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	Button2 = new wxButton(this, ID_BUTTON2, _("Cancelar"), wxPoint(192,336), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	tc2 = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxPoint(208,184), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	tc2->Disable();
	st4 = new wxStaticText(this, ID_STATICTEXT3, _("Descripcion"), wxPoint(64,192), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	st3 = new wxStaticText(this, ID_STATICTEXT4, _("Procesando..."), wxPoint(64,160), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	st3->SetForegroundColour(wxColour(255,0,0));
	wxFont st3Font(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_ITALIC,wxFONTWEIGHT_BOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	st3->SetFont(st3Font);
	Button3 = new wxButton(this, ID_BUTTON3, _("Nuevo"), wxPoint(88,336), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	st5 = new wxStaticText(this, ID_STATICTEXT5, _("Existencias"), wxPoint(64,232), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxPoint(208,232), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	TextCtrl1->Disable();
	st6 = new wxStaticText(this, ID_STATICTEXT6, _("Stock mínimo"), wxPoint(64,272), wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL4, wxEmptyString, wxPoint(208,272), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
	TextCtrl2->Disable();

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&VentanaAltas::OnButton1Click);
	Connect(ID_TEXTCTRL3,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&VentanaAltas::OnTextCtrl1Text);
	//*)
}

VentanaAltas::~VentanaAltas()
{
	//(*Destroy(VentanaAltas)
	//*)
}


void VentanaAltas::OnButton1Click(wxCommandEvent& event)
{

    tc2->Enable(false);
    wxString text_codigo;
    int codigo;
    st3 ->SetLabel("Ingrese el codigo");
    text_codigo=tc1->GetValue();
    codigo=wxAtoi(text_codigo);
    if(text_codigo!=""){
        tc2->Enable(true);
    }else{
    }
}
void VentanaAltas::OnButton3Click(wxCommandEvent& event)
{
        tc1->Clear();
}

void VentanaAltas::OnTextCtrl1Text(wxCommandEvent& event)
{
}

void VentanaAltas::OnButton4Click(wxCommandEvent& event)
{
}
