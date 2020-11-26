#include <iostream>

using namespace std;

enum colores{Verde,Amarillo,Naranja,Rojo};
enum casos{menorque,mayorque,igualque};

struct pimientos{
    string nombre;
    int SHU;
    colores color;
    void mostrar(){
        cout << "\nnombre: " << this->nombre;
        cout << "\nSHU: " << this->SHU;
        cout << "\ncolor: "<< this->color;
        cout << "\n\n";
    }
};

typedef struct pimientos T;

struct nodo{
    T dato;
    nodo *izq;
    nodo *der;
    nodo(): izq(nullptr),der(nullptr){}
    nodo(T Datoagregado): dato(Datoagregado),izq(nullptr),der(nullptr){}
};

typedef struct nodo* ABB;

ABB Arbol = nullptr;

casos comparar(T a,T b){
    casos verificar; 
    
    if(a.SHU < b.SHU){
        verificar = menorque;
    }else if(a.SHU > b.SHU){
        verificar = mayorque;
    }else{
        verificar = igualque;
    }
    return verificar;
};

void menuPrincipal();
void InsertarNodo(ABB, T);

void agregarDatos(){
    T pimiento;
    int color;
    cout << "\n\tIngrese el nombre del pimiento: ";
    cin >> pimiento.nombre;cin.ignore();
    cout << "\n\tIngrese el SHU del pimiento: ";
    cin >> pimiento.SHU;cin.ignore();
    cout << "\n\tCual es el color del Pimiento";
    cout << "\n\n\t1.Verde\t2.Amarillo\t3.Naranja\t4.Rojo\n";
    cin >> color;

    switch(color){
        case 1:
            pimiento.color = Verde;
            break;
        case 2:
            pimiento.color = Amarillo;
            break;
        case 3:
            pimiento.color = Naranja;
            break;
        case 4:
            pimiento.color = Rojo;
            break;
    }
    if(pimiento.color < 0){
        cout << "\nNo puede ser negativo\n";
    }else{
        InsertarNodo(Arbol,pimiento);
    }
};

int main(){
    menuPrincipal();

    return 0;
}

void menuPrincipal(){
    bool continuar = true;
    unsigned short opcion;

    do{
        cout << "\nOperacion a realizar\n";
        cout << "\n1.Agregar un pimiento";
        cout << "\n2.Mostrar todos los pimientos";
        cout << "\n3.Salir\n";
        cin << opcion;

        switch(opcion){
            case 1:
                agregarDatos();
                break;
            case 2:
                break;
            case 3:
                continuar = false;   
                break;
        }
    }while(continuar);
}

void InsertarNodo(ABB arbol,T dato){
    if(!arbol){
        ABB Datoagregar = new nodo(dato);
        arbol = Datoagregar;
    }else{

        switch(comparar(arbol->dato,dato)){
            case menorque:
                InsertarNodo(arbol->izq,dato);
                break;
            case mayorque:
                InsertarNodo(arbol->der,dato);
                break;
            case igualque:
                cout << "\n\ndato ya existe en el arbol\n";
                break;
        }
    }
}

void pre_orden(){

}