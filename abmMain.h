/***************************************************************
 * Name:      abmMain.h
 * Purpose:   Defines Application Frame
 * Author:    Patricia Estigarribia ()
 * Created:   2021-11-15
 * Copyright: Patricia Estigarribia ()
 * License:
 **************************************************************/

#ifndef ABMMAIN_H
#define ABMMAIN_H

//(*Headers(abmFrame)
#include <wx/bmpbuttn.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/stattext.h>
#include <wx/statusbr.h>
//*)

class abmFrame: public wxFrame
{
    public:

        abmFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~abmFrame();

    private:

        //(*Handlers(abmFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnMenuAltasSelected(wxCommandEvent& event);
        void OnBitmapButton1Click(wxCommandEvent& event);
        void OnBitmapButton1Click1(wxCommandEvent& event);
        //*)

        //(*Identifiers(abmFrame)
        static const long ID_STATICTEXT1;
        static const long ID_BITMAPBUTTON1;
        static const long ID_MENUITEM1;
        static const long ID_MENUITEM2;
        static const long ID_MENUITEM3;
        static const long ID_MENUITEM4;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(abmFrame)
        wxBitmapButton* BitmapButton1;
        wxMenu* Menu3;
        wxMenu* Menu4;
        wxMenuItem* MenuItem3;
        wxMenuItem* MenuItem4;
        wxMenuItem* MenuItem5;
        wxStaticText* StaticText1;
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // ABMMAIN_H
