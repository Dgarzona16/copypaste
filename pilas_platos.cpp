#include <iostream>
#include <stack>

using namespace std;

int opcion;

struct platos{
    string material;
    string color;
    bool estado;
}mover;

struct pilas{
    stack<platos>PilaLimpia;
    stack<platos>PilaSucia;
}pPlatos;

void rellenoInicio(){
    int n_platos;
    platos plato;
    cout<<"¿cuantos platos hay disponibles?: ";
    cin>>n_platos;
    for (size_t i = 0; i < n_platos; i++)
    {
        fflush(stdin);
        cout<<"material del plato: ";
        getline(cin,plato.material);
        cout<<"color del plato: ";
        getline(cin,plato.color);
        plato.estado = true;

        pPlatos.PilaLimpia.push(plato);
    }  
};

void menu(){
    system("cls");
    cout<<"\t----OPCIONES----";
    cout<<"\n1.Ensuciar un plato.";
    cout<<"\n2.Ensuciar varios platos.";
    cout<<"\n3.Limpiar un plato.";
    cout<<"\n4.Limpiar varios platos.";
    cout<<"\n5.Mostrar platos limpios.";
    cout<<"\n6.Mostrar platos sucios.";
    cout<<"\n7.Salir\n";

    cin>>opcion;
};

void opcion1(){
    if(!pPlatos.PilaLimpia.empty()){
        mover = pPlatos.PilaLimpia.top();
        mover.estado = false;
        pPlatos.PilaSucia.push(mover);
        pPlatos.PilaLimpia.pop();
        cout<<"se ensucio un plato\n\n";
    }else{
        cout<<"todos los platos estan sucios...\n\n";
    }
};

void opcion2(){
    int cantP;
    if(!pPlatos.PilaLimpia.empty()){
    cout<<"¿cuantos platos va a ensuciar?: ";
    cin>>cantP;
    if(cantP<pPlatos.PilaLimpia.size()){
        for (size_t i = 0; i < cantP; i++)
        {
            mover = pPlatos.PilaLimpia.top();
            mover.estado = false;
            pPlatos.PilaSucia.push(mover);
            pPlatos.PilaLimpia.pop();
        }
    }else{
        cout<<"no tiene esa cantidad de platos limpios...\n\n";
    }
    }else{
        cout<<"todos los platos estan sucios...\n\n";
    }
};

void opcion3(){
    if(!pPlatos.PilaSucia.empty()){
        mover = pPlatos.PilaSucia.top();
        mover.estado = true;
        pPlatos.PilaLimpia.push(mover);
        pPlatos.PilaSucia.pop();
        cout<<"se limpio un plato...\n\n";
    }else{
        cout<<"todos los platos estan limpios...\n\n";
    }
};

void opcion4(){
    int cantP;
    if(!pPlatos.PilaSucia.empty()){
    cout<<"¿cuantos platos va a limpiar?: ";
    cin>>cantP;
    if(cantP<pPlatos.PilaSucia.size()){
        for (size_t i = 0; i < cantP; i++)
        {
            mover = pPlatos.PilaSucia.top();
            mover.estado = true;
            pPlatos.PilaLimpia.push(mover);
            pPlatos.PilaSucia.pop();
        }
    }else{
        cout<<"no tiene esa cantidad de platos sucios...\n\n";
    }
    }else{
        cout<<"todos los platos estan limpios...\n\n";
    }
};

void opcion5(){
    pilas muestra;
    muestra.PilaLimpia = pPlatos.PilaLimpia;

    cout<<"la cantidad de platos limpios son "<<muestra.PilaLimpia.size()<<endl;

    while (!muestra.PilaLimpia.empty())
    {
        mover = muestra.PilaLimpia.top();
        cout<<"plato de material: "<<mover.material<<endl<<endl;
        cout<<"de color: "<<mover.color<<endl<<endl;

        muestra.PilaLimpia.pop();
    }
    
};

void opcion6(){
    pilas muestra;
    muestra.PilaSucia = pPlatos.PilaSucia;

    cout<<"la cantidad de platos sucios son "<<muestra.PilaSucia.size()<<endl;

    while (!muestra.PilaSucia.empty())
    {
        mover = muestra.PilaSucia.top();
        cout<<"\nplato de material: "<<mover.material<<endl;
        cout<<"de color: "<<mover.color<<endl<<endl;

        muestra.PilaSucia.pop();
    }
    
};

int main(){
    bool band = true;
    rellenoInicio();
    do
    {
        menu();

        switch (opcion)
        {
        case 1:
            system("cls");
            opcion1();
            system("pause");
            break;
        
        case 2:
            system("cls");
            opcion2();
            system("pause");
            break;

        case 3:
            system("cls");
            opcion3();
            system("pause");
            break;

        case 4:
            system("cls");
            opcion4();
            system("pause");
            break;

        case 5:
            system("cls");
            opcion5();
            system("pause");
            break;

        case 6:
            system("cls");
            opcion6();
            system("pause");
            break;

        case 7:
            band = false;
            break; 

        default:
            cout<<"valor no valido.\n";
            break;
        }
    } while (band);

    return 0;
}