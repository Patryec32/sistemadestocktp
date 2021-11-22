/***************************************************************
 * Name:      abmMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Patricia Estigarribia ()
 * Created:   2021-11-15
 * Copyright: Patricia Estigarribia ()
 * License:
 **************************************************************/

#include "abmMain.h"
#include <wx/msgdlg.h>
#include <fstream>
#include "Producto.h"
#include <iomanip>
#include "VentanaAltas.h"

//(*InternalHeaders(abmFrame)
#include <wx/bitmap.h>
#include <wx/font.h>
#include <wx/image.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(abmFrame)
const long abmFrame::ID_STATICTEXT1 = wxNewId();
const long abmFrame::ID_BITMAPBUTTON1 = wxNewId();
const long abmFrame::ID_MENUITEM1 = wxNewId();
const long abmFrame::ID_MENUITEM2 = wxNewId();
const long abmFrame::ID_MENUITEM3 = wxNewId();
const long abmFrame::ID_MENUITEM4 = wxNewId();
const long abmFrame::idMenuAbout = wxNewId();
const long abmFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(abmFrame,wxFrame)
    //(*EventTable(abmFrame)
    //*)
END_EVENT_TABLE()

abmFrame::abmFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(abmFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Sistema de Stock"), wxPoint(104,16), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    wxFont StaticText1Font(16,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    StaticText1->SetFont(StaticText1Font);
    BitmapButton1 = new wxBitmapButton(this, ID_BITMAPBUTTON1, wxBitmap(wxImage(_T("C:\\Users\\PCBOX\\Downloads\\1_FACU\\EMAE\\EMAE_2_cuatrimestre_2021\\1_Programacion-visual\\TP\\tp3\\abm\\img.png"))), wxPoint(24,48), wxSize(352,266), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON1"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, ID_MENUITEM1, _("Salir\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu4 = new wxMenu();
    MenuItem3 = new wxMenuItem(Menu4, ID_MENUITEM2, _("Altas"), wxEmptyString, wxITEM_NORMAL);
    Menu4->Append(MenuItem3);
    MenuItem4 = new wxMenuItem(Menu4, ID_MENUITEM3, _("Bajas"), wxEmptyString, wxITEM_NORMAL);
    Menu4->Append(MenuItem4);
    MenuItem5 = new wxMenuItem(Menu4, ID_MENUITEM4, _("Modificacion"), wxEmptyString, wxITEM_NORMAL);
    Menu4->Append(MenuItem5);
    MenuBar1->Append(Menu4, _("Operaciones"));
    Menu3 = new wxMenu();
    MenuBar1->Append(Menu3, _("Listado"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(ID_BITMAPBUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&abmFrame::OnBitmapButton1Click1);
    Connect(ID_MENUITEM1,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&abmFrame::OnQuit);
    Connect(ID_MENUITEM2,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&abmFrame::OnMenuAltasSelected);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&abmFrame::OnAbout);
    //*)
}

abmFrame::~abmFrame()
{
    //(*Destroy(abmFrame)
    //*)
}

void abmFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void abmFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void abmFrame::OnMenuAltasSelected(wxCommandEvent& event)
{
    VentanaAltas *frm=new VentanaAltas(this);
    frm->Show();

    wxString msg="Listado de RPocuctos";
    wxMessageBox(msg, _("Procesando.."));
    fstream arch;
    arch.open("Producto.dat",ios::app|ios::binary);
    if(!arch){
        msg="Error de apertura de archivo";
        wxMessageBox(msg, _("ERROR!!!"));
        Close();
    }
    arch.close();
    arch.open("Producto.dat",ios::in|ios::out|ios::binary);
    if(!arch){
        msg="Error de apertura de archivo";
        wxMessageBox(msg, _("ERROR!!!"));
        Close();
    }
    ofstream archt;
    Producto reg;
    archt.open("Producto.txt",ios::out);
    if(!archt){
        msg="Error de apertura de archivo";
        wxMessageBox(msg, _("ERROR!!!"));
    }
    archt<<left<<setw(5)<<"Codigo del artículo"<<setw(10)<<"Descripción"<<setw(5)<<"Stock mínimo"<<setw(5)<<"Stock máximo"<<setw(5)<<"Precio de reposición"<<endl;
    arch.seekg(0);
    arch.read(reinterpret_cast<char*>(&reg),sizeof(Producto));
    while(!arch.eof()){
        archt<<left<<setw(5)<<reg.getCodigo()<<setw(10)<<reg.getDescripcion()<<setw(5)<<reg.getStock_min()<<setw(5)<<reg.getStock_max()<<setw(5)<<reg.getPrecio_de_reposicion()<<endl;
        arch.read(reinterpret_cast< char *>(&reg),sizeof(Producto));
    }
    archt.close();
    arch.close();
}

void abmFrame::OnBitmapButton1Click(wxCommandEvent& event)
{
}

void abmFrame::OnBitmapButton1Click1(wxCommandEvent& event)
{
}
