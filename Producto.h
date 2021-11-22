#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED
#include <fstream>
#include <string>
using namespace std;
class Producto{
    public:
        Producto(int=0,string="", int=0, int=0, int=0);
        void setCodigo(int);
        int getCodigo();
        void setDescripcion(string);
        string getDescripcion();
        void setStock_min(int);
        int getStock_min();
        void setStock_max(int);
        int getStock_max();
        void setPrecio_de_reposicion(int);
        int getPrecio_de_reposicion();
        //void buscar(fstream &);
    private:
        int codigo;
        string descripcion;
        int stock_min;
        int stock_max;
        int precio_de_reposicion;
};


#endif // PRODUCTO_H_INCLUDED
