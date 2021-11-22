/***************************************************************
 * Name:      abmApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Patricia Estigarribia ()
 * Created:   2021-11-15
 * Copyright: Patricia Estigarribia ()
 * License:
 **************************************************************/

#include "abmApp.h"

//(*AppHeaders
#include "abmMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(abmApp);

bool abmApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	abmFrame* Frame = new abmFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
