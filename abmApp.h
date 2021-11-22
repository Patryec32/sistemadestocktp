/***************************************************************
 * Name:      abmApp.h
 * Purpose:   Defines Application Class
 * Author:    Patricia Estigarribia ()
 * Created:   2021-11-15
 * Copyright: Patricia Estigarribia ()
 * License:
 **************************************************************/

#ifndef ABMAPP_H
#define ABMAPP_H

#include <wx/app.h>

class abmApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // ABMAPP_H
