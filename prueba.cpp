#include <iostream>

using namespace std;

struct nodo{
    int num;
    nodo *sig;
};

void aggPila(nodo*&,int);

int main(){
    int num,cont=0;
    nodo *pila = NULL;
    char band = 'y';

    while (band == 'y')
    {
        cout<<"digite un numero: ";
        cin>>num;
        aggPila(pila, num);

        cont++;
        cout<<"desea ingresar otro numero?(pene/n)\n";
        cin>>band;
    }

    cout<<"se ingresaron "<<cont<<" datos.";
    
    return 0;
}

void aggPila(nodo *&pila, int n){
    nodo *new_nodo = new nodo();
    new_nodo->num = n;
    new_nodo->sig = pila;
    pila = new_nodo;
}