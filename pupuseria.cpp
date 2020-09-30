#include <iostream>
#include <stdlib.h>
#include <queue>

using namespace std;

int opcion;

struct pedidos
{
    string apellido;
    int n_Mesa;
    int p_R;
    int p_FQ;
    int p_Q;
    int tiempo;
};

typedef pedidos T;
const T noValido = {{" "},-1,-1,-1,-1,-1};

struct pupuseria
{
    queue <pedidos> colapupusas;
    int cont_pupas;
};

pupuseria ricanonga;

//FUNCION DE MENU----------------------------------------------------

void Menu(){
    cout<<"\t//Menu//\n";
    cout<<"1.Agregar pedido\n";
    cout<<"2.Consultar el estado de la cola\n";
    cout<<"3.Servir pedido\n";
    cout<<"4.ver pedidos pendientes\n";
    cout<<"5.Salir\n";
    cout<<"\topcion: ";cin>>opcion;
};

//FUNCION PARA AGREGAR DATOS A LA COLA------------------------------

void agregar(){
    system("cls");
    fflush(stdin);
    pedidos unpedido;
    cout<<"apellido del cliente: ";getline(cin,unpedido.apellido);
    cout<<"numero de mesa: ";cin>>unpedido.n_Mesa;
    cout<<"cantidad de pupusas revueltas: ";cin>>unpedido.p_R;
    cout<<"cantidad de pupusas fijol/queso: ";cin>>unpedido.p_FQ;
    cout<<"cantidad de pupusas queso: ";cin>>unpedido.p_Q;
    unpedido.tiempo = (unpedido.p_FQ + unpedido.p_Q + unpedido.p_R)*90;

    ricanonga.colapupusas.push(unpedido); 
    system("pause");
};

//FUNCION PARA VER EL TAMAÑO DE LA COLA-----------------------------

void consulta(){
    system("cls");
    cout<<"la cantidad de pedidos en cola son: "<<ricanonga.colapupusas.size();
    cout<<"\n\ncantidad de pupusas entregadas: "<<ricanonga.cont_pupas<<endl;
    system("pause");
};

//FUNCION PARA SACAR UN NODO---------------------------------------

void servir(){
    pedidos actual = ricanonga.colapupusas.front();
    cout<<"familia "<<actual.apellido<<" su pedido esta listo\n";
    cout<<"\na la de mesa numero "<<actual.n_Mesa<<endl;
    ricanonga.cont_pupas += (actual.p_FQ + actual.p_Q + actual.p_R);
    ricanonga.colapupusas.pop();
};

//FUNCION PARA MOSTRAR LA COLA------------------------------------

void verTodo(){
    system("cls");
    pupuseria colatemp;
    colatemp.colapupusas = ricanonga.colapupusas; 
    
    while(!colatemp.colapupusas.empty()){
        pedidos temp = colatemp.colapupusas.front();
        cout<<"familia: "<<temp.apellido<<endl;
        cout<<"mesa: "<<temp.n_Mesa<<endl;
        cout<<"cantidad total de pupusas: "<<(temp.p_FQ + temp.p_Q + temp.p_R)<<endl<<endl;

        colatemp.colapupusas.pop();
    }
    system("pause");
}

// FUNCION PRINCIPAL---------------------------------------------

int main(){
    bool band = true;
    cout<<"\t\aBIENVENIDO A PUPUSERIA RICAÑONGA\n\n";

    do
    {
        system("cls");

        Menu();

        switch (opcion)
        {
        case 1:
            agregar();
            break;
        case 2:
            consulta();
            break;
        case 3:
            servir();
            break;
        case 4:
            verTodo();
            break;
        case 5:
            band = false;
            break;
        default:
            cout<<"dato invalido\n";
            break;
        }
    } while (band);

    system("pause");
    return 0;
}