#include "Producto.h"
#include <string.h>
#include <fstream>
using namespace std;
Producto::Producto(int c, string d, int smi, int sma, int pr){
    setCodigo(c);
    setDescripcion(d);
    setStock_min(smi);
    setStock_max(sma);
    setPrecio_de_reposicion(pr);
}

void Producto::setCodigo(int c){
    codigo=c;
}
void Producto::setDescripcion(string d){
    descripcion=d;
}
void Producto::setStock_min(int smi){
    stock_min=smi;
}
void Producto::setStock_max(int sma){
    stock_max=sma;
}
void Producto::setPrecio_de_reposicion(int rp){
    precio_de_reposicion=rp;
};

int Producto::getCodigo(){
    return codigo;
}
string Producto::getDescripcion(){
    return descripcion;
}
int Producto::getStock_min(){
    return stock_min;
}
int Producto::getStock_max(){
    return stock_max;
}
int Producto::getPrecio_de_reposicion(){
    return precio_de_reposicion;
}
/*void Producto::buscar(fstream &a){
    Producto reg;
    a.clear();
    a.seekg(0,ois::beg);
    a.read(reinterpret_cast<char*>(&reg),sizeof(Producto));
    while(!a.eof()&&reg.getCodigo()!=codigo){
        a.read(reinterpret_cast<char *>(&reg),sizeof(Producto));
    }
}*/
