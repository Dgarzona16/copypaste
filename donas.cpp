#include <iostream>
#include <stdlib.h>
#include <vector>
#include <queue>

using namespace std;

struct comida
{
    string nombre;
    float precio;
};

struct pedido_cliente
{
    string apellido;
    vector<comida>listadePedido;
};

int opcion = 0;
float gananciasP = 0,gananciasD = 0;

void menuP()
{
    system("cls");
    cout<<"\t---MENU---\n";
    cout<<"\n1.Atender clientes.";
    cout<<"\n2.Ganancias por donas.";
    cout<<"\n3.Ganancias por platos.";
    cout<<"\n4.Salir.";
    cout<<"\n\topcion: ";

cin>>opcion;
};

float calcmontocliente(pedido_cliente cliente){
    float sum = 0;
    comida temp;
    for(int i = 0; i<cliente.listadePedido.size();i++){
       temp = cliente.listadePedido[i];
       sum += temp.precio; 
    }
    return sum;
};

float sum_donas(float sum){
    return gananciasD += sum;

};

float sum_platos(float sum){
    return gananciasP += sum;
};

void menu_donas(pedido_cliente cliente){
    bool cont = true;
    char var;
    int op;
    float sum;
    comida pcliente;

    do
    {
        cout<<"\n1.Agregar un producto";
        cout<<"\n2.Monto a pagar del cliente";
        cout<<"\n3.Pagar";
        cout<<"\nopcion: ";
        cin>>op;

        switch(op){
            case 1:
            cout<<"que tipo de dona desea?\nS-sencilla\tR-rellena\tE-especial\n";
            cin>>var;

            switch(var){
                case 's':
                case 'S':pcliente.nombre = "sencilla";pcliente.precio = 1;break;
                case 'r':
                case 'R':pcliente.nombre = "rellena";pcliente.precio = 1.25;break;
                case 'e':
                case 'E':pcliente.nombre = "especial";pcliente.precio = 1.50;break;
            }
            cliente.listadePedido.insert(cliente.listadePedido.end(),pcliente);
            cout<<"\nse agrego un producto al carrito\n";break;
            case 2:
                cout<<"\nel monto a pagar es de: $\n"<<calcmontocliente(cliente);break;
            case 3:
                sum = calcmontocliente(cliente);
                cont = false;sum_donas(sum);break;
            default:
            cout<<"opcion no valida";break;
        }

    } while (cont); 
    
};

void menu_platos(pedido_cliente cliente){
    bool cont = true;
    char var;
    int op;
    float sum;
    comida pcliente;

    do
    {
        cout<<"\n1.Agregar un producto";
        cout<<"\n2.Monto a pagar del cliente";
        cout<<"\n3.Pagar";
        cout<<"\nopcion: ";
        cin>>op;

        switch(op){
            case 1:
            cout<<"que plato desea?\nD-desayuno\tA-almuerzo\tC-cena\n";
            cin>>var;

            switch(var){
                case 'd':
                case 'D':pcliente.nombre = "desayuno";pcliente.precio = 2.50;break;
                case 'a':
                case 'A':pcliente.nombre = "almuerzo";pcliente.precio = 5;break;
                case 'c':
                case 'C':pcliente.nombre = "cena";pcliente.precio = 3.50;break;
            }
            cliente.listadePedido.insert(cliente.listadePedido.end(),pcliente);
            cout<<"\nse agrego un producto al carrito.";break;
            case 2:
                cout<<"\nel monto a cancelar es de: $"<<calcmontocliente(cliente);break;
            case 3:
                sum = calcmontocliente(cliente);
                cont = false;sum_platos(sum);break;
            default:
            cout<<"opcion no valida";break;
        }

    } while (cont);
};

void atender_cliente()
{
    pedido_cliente cliente;
    char comida;
    fflush(stdin);
    cout<<"Apellido del cliente: ";
    getline(cin,cliente.apellido);
        cout<<"que desea ordenar?\nD-donas\tP-platos fuertes\n";
        cin>>comida;
        switch(comida){
            case 'd':
            case 'D': menu_donas(cliente);break;
            case 'p':
            case 'P': menu_platos(cliente);break;
        }
};

int main(){
    bool continuar = true;
    float temp = 0;

    do
    {
    menuP();
    switch (opcion)
    {
    case 1:
        atender_cliente();break;
    case 2:
        cout<<"las ganancias totales de las donas son: $"<<sum_donas(temp)<<" dolares\n";system("pause");break;
    case 3:
        cout<<"las ganancias totales de los platos son: $"<<sum_platos(temp)<<" dolares\n";system("pause");break;
    case 4:
        continuar = false;break;
    default:
        break;
    }    
    } while (continuar);
    
    return 0;
}