#include <iostream>
#include <stdlib.h>

using namespace std;

int opcion;

struct perfil_capa{
    string suelo;
    float grosor;
    int dureza;
};

struct columna{
    perfil_capa elemento;
    columna *sig;
};

bool empty(columna *);
void push(columna *&, perfil_capa);
void pop(columna *&);
void promedio(columna *&);

void menu(){
    system("cls");
    cout<<"\t----OPCIONES----";
    cout<<"\n1.Subir un dato.";
    cout<<"\n2.Eliminar un dato.";
    cout<<"\n3.Eliminar todos los datos.";
    cout<<"\n4.Calcular el promedio de dureza.";
    cout<<"\n5.Salir\n";
    cin>>opcion;
};

int main(){
    columna *pila = NULL;
    bool band = true;
    perfil_capa temp;

    do
    {
        menu();
        switch (opcion)
        {
        case 1:
            system("cls");
            fflush(stdin);
            cout<<"\ntipo de suelo: ";
            getline(cin,temp.suelo);
            cout<<"grosor del suelo: ";
            cin>>temp.grosor;
            cout<<"dureza del suelo: ";
            cin>>temp.dureza;
            if((temp.dureza>0) && (temp.grosor>0)){
                push(pila,temp);
            }else{
                cout<<"no se pueden meter datos negativos...\n\n";
            }
            system("pause");
            break;
        
        case 2:
            if(!empty(pila)){
                pop(pila);
                cout<<"se elimino el ultimo dato..\n\n";
            }else{
                cout<<"la columna no tiene datos...\n\n";
            }
            system("pause");
            break;

        case 3:
            if(!empty(pila)){
                while(!empty(pila)){
                    pop(pila);
                }
                cout<<"toda la columna fue eliminada...\n\n";
            }else{
                cout<<"la columna no tiene datos...\n\n";
            }
            system("pause");
            break;


        case 4:
            if(!empty(pila)){
                promedio(pila);
            }else{
                cout<<"no hay datos para calcular...\n\n";
            }
            system("pause");
            break;

        case 5:
            band = false;
            break;
        default:
            cout<<"dato no valido...\n\n";
            system("pause");
            break;
        }
    } while (band);
    
}

bool empty(columna *pila){
    return (pila == NULL)? true : false;
}

void push(columna *&pila, perfil_capa elemento){
    struct columna *nuevo = new columna(); 
    nuevo->elemento = elemento;
    nuevo->sig = pila;
    pila = nuevo;
    cout<<"se agrego un dato a la columna...\n\n";
}

void pop(columna *&pila){
    columna *aux = pila;
    pila = aux->sig;
    delete aux;
}

void promedio(columna *&pila){
    columna *clone = pila;
    int prom=0, i=0;    
    while (clone != NULL)
    {
        prom+= clone->elemento.dureza;
        clone = clone->sig;
        i++;
    }
prom/=i;

cout<<"el promedio de dureza es: "<<prom<<endl<<endl;
}