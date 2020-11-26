//+++LIBRERIAS+++//
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

//+++ESTRUCTURAS+++//
struct producto{
    int codigo;
    string nombre;
    string modelo;
    float precio;
    int cantidad;
};

struct nodo{
    struct producto producto;
    nodo *sig;
};

struct cliente{
    string nombre;
    string direccion;
    nodo *carrito = NULL;
};

struct listcliente{
    cliente cliente;
    listcliente *sig;
};
//+++VARIABLES GLOBALES+++//
nodo *listaproductos = NULL;
listcliente *listaClientes = NULL;
int opcion;

//+++PROTOTIPOS+++//

//menus//
void menuPrincipal();
void menuCliente();
void menuAdmin();

//sub menus//
void mostrarProductos();
void modificarCarrito();
void modificarClientes();
void modificarProductos();

//listas//
void mostrarProducto(nodo *&);
void agglista(nodo *&,producto);
nodo* buscarint(nodo *,int);

//+++AGG AUTOMATICO+++//
void agregarProductos(nodo *&lista){
    struct producto productotemp;
    //producto 1
    productotemp.codigo = 1001;
    productotemp.nombre = "viewsonic HD 19'";
    productotemp.modelo = "VA1903h";
    productotemp.precio = 104.21;
    productotemp.cantidad = 5;
    agglista(lista,productotemp);
    //producto 2
    productotemp.codigo = 1002;
    productotemp.nombre = "viewsonic FULL HD 24'";
    productotemp.modelo = "VA2405-H";
    productotemp.precio = 184.21;
    productotemp.cantidad = 3;
    agglista(lista,productotemp);
    //producto 3
    productotemp.codigo = 1003;
    productotemp.nombre = "HP FULL HD IPS 23.8'";
    productotemp.modelo = "N246v";
    productotemp.precio = 198.95;
    productotemp.cantidad = 9;
    agglista(lista,productotemp);
    //producto 4
    productotemp.codigo = 1004;
    productotemp.nombre = "VIOTEK FULL HD 144hz 22'";
    productotemp.modelo = "GFV22CB";
    productotemp.precio = 220.00;
    productotemp.cantidad = 10;
    agglista(lista,productotemp);
    //producto 5
    productotemp.codigo = 2001;
    productotemp.nombre = "ASUS TUF GTX1650";
    productotemp.modelo = "4GB GDDR5";
    productotemp.precio = 251.58;
    productotemp.cantidad = 30;
    agglista(lista,productotemp);
    //producto 6
    productotemp.codigo = 2002;
    productotemp.nombre = "PULSE RX 5600 XT";
    productotemp.modelo = "6GB GDDR6";
    productotemp.precio = 472.63;
    productotemp.cantidad = 20;
    agglista(lista,productotemp);
    //producto 7
    productotemp.codigo = 3001;
    productotemp.nombre = "CORE I3 10TH GEN";
    productotemp.modelo = "10100/4 nucleos/8 hilos";
    productotemp.precio = 209.47;
    productotemp.cantidad = 15;
    agglista(lista,productotemp);
    //producto 8
    productotemp.codigo = 3002;
    productotemp.nombre = "CORE I5 10TH GEN";
    productotemp.modelo = "10400/6 nucleos/12 hilos";
    productotemp.precio = 293.68;
    productotemp.cantidad = 0;
    agglista(lista,productotemp);
    //producto 9
    productotemp.codigo = 3003;
    productotemp.nombre = "RYZEN 5 3RD GEN";
    productotemp.modelo = "3600XT/6 nucleos/12 hilos";
    productotemp.precio = 363.16;
    productotemp.cantidad = 14;
    agglista(lista,productotemp);
    //producto 10
    productotemp.codigo = 3004;
    productotemp.nombre = "CORE I7 10TH GEN";
    productotemp.modelo = "10700/8 nucleos/16 hilos";
    productotemp.precio = 556.84;
    productotemp.cantidad = 17;
    agglista(lista,productotemp);
    //producto 11
    productotemp.codigo = 4001;
    productotemp.nombre = "ZALMAN S3 TG";
    productotemp.modelo = "ATX";
    productotemp.precio = 68.42;
    productotemp.cantidad = 5;
    agglista(lista,productotemp);
    //producto 12
    productotemp.codigo = 4002;
    productotemp.nombre = "SUGO SG13B-Q";
    productotemp.modelo = "MINI ITX";
    productotemp.precio = 68.42;
    productotemp.cantidad = 8;
    agglista(lista,productotemp);
    //producto 13
    productotemp.codigo = 4003;
    productotemp.nombre = "PRECISION PS15-RGB";
    productotemp.modelo = "MACRO ATX";
    productotemp.precio = 104.21;
    productotemp.cantidad = 9;
    agglista(lista,productotemp);
    //producto 14
    productotemp.codigo = 5001;
    productotemp.nombre = "GIGABYTE GA-A320M-H";
    productotemp.modelo = "socket: AM4";
    productotemp.precio = 76.32;
    productotemp.cantidad = 3;
    agglista(lista,productotemp);
    //producto 15
    productotemp.codigo = 5002;
    productotemp.nombre = "GIGABYTE B450M-H";
    productotemp.modelo = "socket: AM4";
    productotemp.precio = 102.63;
    productotemp.cantidad = 6;
    agglista(lista,productotemp);
    //producto 16
    productotemp.codigo = 5003;
    productotemp.nombre = "ASUS ROG MAXIMUS XI HERO ROG Z390";
    productotemp.modelo = "socket: 1151";
    productotemp.precio = 430.53;
    productotemp.cantidad = 7;
    agglista(lista,productotemp);
    //producto 17
    productotemp.codigo = 6001;
    productotemp.nombre = "EVGA 500 W1";
    productotemp.modelo = "certificacion 80 PLUS WHITE";
    productotemp.precio = 62.11;
    productotemp.cantidad = 9;
    agglista(lista,productotemp);
    //producto 18
    productotemp.codigo = 6002;
    productotemp.nombre = "EVGA 600 W1";
    productotemp.modelo = "certificacion 80PLUS WHITE";
    productotemp.precio = 75.45;
    productotemp.cantidad = 8;
    agglista(lista,productotemp);
    //producto 19
    productotemp.codigo = 6003;
    productotemp.nombre = "AZZA PSAZ 650W";
    productotemp.modelo = "certificacion 80 PLUS BRONZE";
    productotemp.precio = 65.45;
    productotemp.cantidad = 6;
    agglista(lista,productotemp);
    //producto 20
    productotemp.codigo = 6004;
    productotemp.nombre = "CROSSAIR 600W";
    productotemp.modelo = "certificacion 80 PLUS GOLD";
    productotemp.precio = 86.37;
    productotemp.cantidad = 14;
    agglista(lista,productotemp);
};

//+++FUNCION PRINCIPAL+++//
int main(){
    agregarProductos(listaproductos);

    menuPrincipal();

    return 0;
}

//+++FUNCIONES+++//

//menu//
void menuPrincipal(){
    bool continuar = true;
    do{
        system("cls");
        cout<<"\n\tBIENVENIDO A {INSERTE NOMBRE AQUI}\n";
        cout<<"\nSeleccione una opcion:";
        cout<<"\n1.Cliente\t\t2.Administrador\t\t3.Salir";
        cout<<"\n\nopcion: ";
        cin>>opcion;

        switch(opcion){
            case 1:
                menuCliente();
                break;
            case 2:
                menuAdmin();
                break;
            case 3:
                system("cls");
                cout<<"\n\tFUE UN GUSTO SERVIRTE\n\n";
                system("pause");
                continuar =false;
                break;
            default:
                system("cls");
                cout<<"\n\tOpcion no valida\n\n";
                system("pause");
                break;
        }
    }while(continuar);
}

void menuCliente(){
    cliente cliente1;
    bool continuar = true;

    system("cls");
    fflush(stdin);
    
    cout<<"\n\tHOLA, POR FAVOR COLOCA TUS DATOS\n";
    cout<<"\nnombre de usuario: ";
    getline(cin,cliente1.nombre);
    cout<<"\ndireccion: ";
    getline(cin,cliente1.direccion);

    system("pause");

    do{
        system("cls");

        cout<<"\n\tQUE OPERACION DESEA REALIZAR\n";
        cout<<"\n1.Agregar al carrito";
        cout<<"\n2.Modificar carrito";
        cout<<"\n3.Finalizar";
        cout<<"\n\tOpcion: ";
        cin>>opcion;

        switch(opcion){
            case 1:
                mostrarProductos();
                break;
            case 2:
                modificarCarrito();
                break;
            case 3:

                continuar = false;
                break;
            default:
                system("cls");
                cout<<"\n\tOpcion no valida\n\n";
                system("pause");
                break;
        }
    }while(continuar);
}

void menuAdmin(){
    string user1 = "admin",user2;
    string pass1 = "hiworld1234",pass2;

    system("cls");
    fflush(stdin);
    cout<<"\n\tPOR FAVOR INGRESE SUS DATOS DE ADMINISTRADOR\n";
    cout<<"\nUSUARIO: ";
    getline(cin,user2);
    cout<<"\nCONTRASEÑA: ";
    getline(cin,pass2);

    system("cls");
    if((user1==user2) && (pass1==pass2)){
        bool continuar =true;
        do{
            cout<<"\n\tQUE OPERACION DESEA REALIZAR\n";
            cout<<"\n1.Modificar compras de clientes";
            cout<<"\n2.Modificar lista de productos";
            cout<<"\n3.Regresar";
            cout<<"\n\tOpcion: ";
            cin>>opcion;

            switch(opcion){
                case 1:
                    modificarClientes();
                    break;
                case 2:
                    modificarProductos();
                    break;
                case 3:
                    system("cls");
                    cout<<"\n\tUN GUSTO AYUDARTE\n\n";
                    system("pause");
                    continuar = false;
                    break;
                default:
                    system("cls");
                    cout<<"\n\tOpcion no valida\n\n";
                    system("pause");
                    break;
            }
        }while(continuar);
    }else{
        cout<<"\n\tLas credenciales no coinciden...\n\n";
        system("pause");
    }
}

//sub menus//
void mostrarProductos(){
    bool continuar = true;
    do{
        system("cls");

        cout<<"\n\tEN QUE PRODUCTOS ESTA INTERESADO\n";
        cout<<"\n1.Monitores\t2.Tarjetas Graficas\t3.Procesadores";
        cout<<"\n4.Cases\t\t5.Placas Base \t\t6.Fuentes de poder";
        cout<<"\n7.Regresar";
        cout<<"\n\n\tOpcion: ";
        cin>>opcion;

        switch(opcion){
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
                mostrarProducto(listaproductos);
                break;
            case 7:
                continuar = false;
                break;
            default:
                 system("cls");
                cout<<"\n\tOpcion no valida\n\n";
                system("pause");
                break;
        }
        
    }while(continuar);
}

void modificarCarrito(){
    system("cls");

    cout<<"\n\tQUE operacion desea Realizar?\n";
    cout<<"\n1.Eliminar un item del carrito";
    cout<<"\n2.Eliminar un producto del carrito";
    cout<<"\n3.Vaciar el carrito";
    cout<<"\n4.Regresar";
    cout<<"\n\tOpcion: ";
    cin>>opcion;

    switch(opcion){
        case 1:

            break;
        case 2:
            
            break;
        case 3:

            break;
        case 4:

            break;
        default:
            system("cls");
            cout<<"\n\tOpcion no valida\n\n";
            system("pause");
            break;
    }
}

void modificarClientes(){
    system("cls");

    cout<<"\n\tQUE OPERACION DESEA RELIZAR\n";
    cout<<"\n1.Buscar a un cliente";
    cout<<"\n2.Reembolsar una comprar";
    cout<<"\n3.Regresar";
    cout<<"\n\tOpcion: ";
    cin>>opcion;

    switch(opcion){
        case 1:

            break;
        case 2:

            break;
        case 3:

            break;
        default:
            system("cls");
            cout<<"\n\tOpcion no valida\n\n";
            system("pause");
            break;
    }
}

void modificarProductos(){
    system("cls");

    cout<<"\n\tQUE OPERACION DESEA REALIZAR\n";
    cout<<"\n1.Agregar un producto";
    cout<<"\n2.Eliminar un producto";
    cout<<"\n3.Agregar items a un producto";
    cout<<"\n4.Regresar";
    cout<<"\n\tOpcion: ";
    cin>>opcion;

    switch(opcion){
        case 1:

            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        default:
            system("cls");
            cout<<"\n\tOpcion no valida\n\n";
            system("pause");
            break;
    }
}

//listas//
void mostrarProducto(nodo *&lista){
    int cont = 1;
    nodo *actual = new nodo();
    actual = lista;

    system("cls");
    cout<<"\n\tLos productos de la lista son:\n";

    switch(opcion){
        case 1:
            while((actual!=NULL) && (actual->producto.codigo>=1001) && (actual->producto.codigo<=1999)){
                cout<<"\n\tOpcion "<<cont;
                cout<<"\n\tNombre: "<<actual->producto.nombre;
                cout<<"\n\tModelo: "<<actual->producto.modelo;
                cout<<"\n\tPrecio: "<<actual->producto.precio;
                if(actual->producto.cantidad==0){
                    cout<<"\n\tEn stock: AGOTADO";
                }else{
                    cout<<"\n\tEn stock: "<<actual->producto.cantidad;
                }
                cout<<"\n\n";
                cont++;
                actual = actual->sig;
            }
            break;
        case 2:
            actual = buscarint(listaproductos,2001);
            while((actual!=NULL) && (actual->producto.codigo>=2001) && (actual->producto.codigo<=2999)){
                cout<<"\n\tOpcion "<<cont;
                cout<<"\n\tnombre: "<<actual->producto.nombre;
                cout<<"\n\tmodelo: "<<actual->producto.modelo;
                cout<<"\n\tprecio: "<<actual->producto.precio;
                if(actual->producto.cantidad==0){
                    cout<<"\n\tEn stock: AGOTADO";
                }else{
                    cout<<"\n\tEn stock: "<<actual->producto.cantidad;
                }
                cout<<"\n\n";
                cont++;
                actual = actual->sig;
            }
            break;
        case 3:
            actual = buscarint(listaproductos,3001);
            while((actual!=NULL) && (actual->producto.codigo>=3001) && (actual->producto.codigo<=3999)){
                cout<<"\n\tOpcion "<<cont;
                cout<<"\n\tnombre: "<<actual->producto.nombre;
                cout<<"\n\tmodelo: "<<actual->producto.modelo;
                cout<<"\n\tprecio: "<<actual->producto.precio;
                if(actual->producto.cantidad==0){
                    cout<<"\n\tEn stock: AGOTADO";
                }else{
                    cout<<"\n\tEn stock: "<<actual->producto.cantidad;
                }
                cout<<"\n\n";
                cont++;
                actual = actual->sig;
            }
            break;
        case 4:
            actual = buscarint(listaproductos,4001);
            while((actual!=NULL) && (actual->producto.codigo>=4001) && (actual->producto.codigo<=4999)){
                cout<<"\n\tOpcion "<<cont;
                cout<<"\n\tnombre: "<<actual->producto.nombre;
                cout<<"\n\tmodelo: "<<actual->producto.modelo;
                cout<<"\n\tprecio: "<<actual->producto.precio;
                if(actual->producto.cantidad==0){
                    cout<<"\n\tEn stock: AGOTADO";
                }else{
                    cout<<"\n\tEn stock: "<<actual->producto.cantidad;
                }
                cout<<"\n\n";
                cont++;
                actual = actual->sig;
            }
            break;
        case 5:
            actual = buscarint(listaproductos,5001);
            while((actual!=NULL) && (actual->producto.codigo>=5001) && (actual->producto.codigo<=5999)){
                cout<<"\n\tOpcion "<<cont;
                cout<<"\n\tnombre: "<<actual->producto.nombre;
                cout<<"\n\tmodelo: "<<actual->producto.modelo;
                cout<<"\n\tprecio: "<<actual->producto.precio;
                if(actual->producto.cantidad==0){
                    cout<<"\n\tEn stock: AGOTADO";
                }else{
                    cout<<"\n\tEn stock: "<<actual->producto.cantidad;
                }
                cout<<"\n\n";
                cont++;
                actual = actual->sig;
            }
            break;
        case 6:
            actual = buscarint(listaproductos,6001);
            while((actual!=NULL) && (actual->producto.codigo>=6001) && (actual->producto.codigo<=6999)){
                cout<<"\n\tOpcion "<<cont;
                cout<<"\n\tnombre: "<<actual->producto.nombre;
                cout<<"\n\tmodelo: "<<actual->producto.modelo;
                cout<<"\n\tprecio: "<<actual->producto.precio;
                if(actual->producto.cantidad==0){
                    cout<<"\n\tEn stock: AGOTADO";
                }else{
                    cout<<"\n\tEn stock: "<<actual->producto.cantidad;
                }
                cout<<"\n\n";
                cont++;
                actual = actual->sig;
            }
            break;
    }
    system("pause");
}

void agglista(nodo *&lista,producto n){
    nodo *new_nodo = new nodo();
    new_nodo->producto = n;

    nodo *aux1 = lista;
    nodo *aux2;

    while((aux1!= NULL) && (aux1->producto.codigo < n.codigo)){
        aux2 = aux1;
        aux1 = aux1->sig;
    }

    if(lista==aux1){
        lista = new_nodo;
    }
    else{
        aux2->sig = new_nodo;
    }
    new_nodo->sig = aux1;
}

nodo* buscarint(nodo *lista,int n){
    bool cont = false;
    nodo *actual = new nodo();
    nodo *aux1 = new nodo();
    actual = lista;

    while((actual != NULL) && (actual->producto.codigo <= n)){
        if(actual->producto.codigo == n){
            cont = true;
        }
        aux1 = actual;
        actual = actual->sig;
    }
    if (cont == true)
    {
        return aux1;
    }
}