#include <iostream>
#include <queue>
#include <stdlib.h>

using namespace std;

int opcion1,opcion2;
string cola;


struct canciones{
    string titulo;
    string cantante;
    string genero;
    int duracion;
}cancion;

struct colas{
    queue<canciones>colaFeliz;
    queue<canciones>colaTriste;
    queue<canciones>colaEstudio;
}reproductor;

void menuPrincipal(){
    system("cls");
    cout<<"\t---MENU PRINCIPAL---\n";
    cout<<"\n1.Cola de canciones felices.";
    cout<<"\n2.Cola de canciones tristes.";
    cout<<"\n3.Cola de canciones para estudio.";
    cout<<"\n4.Salir.";
    cout<<"\n\topcion: ";cin>>opcion1;

    switch (opcion1)
    {
    case 1:
        cola = "FELIZ";
        break;
    case 2:
        cola = "TRISTE";
        break;
    case 3:
        cola = "ESTUDIO";
        break;
    }
};

void agregar_cancion(){
    system("cls");
    fflush(stdin);
    cout<<"\t---DATOS DE LA CANCION---\n";
    cout<<"\nTitulo: ";getline(cin,cancion.titulo);
    cout<<"\nArtista: ";getline(cin,cancion.cantante);
    cout<<"\nGenero: ";getline(cin,cancion.genero);
    cout<<"\nDuracion: ";cin>>cancion.duracion;
    if ((cancion.titulo != " ") && (cancion.cantante != " ") && (cancion.genero != " ") && (cancion.duracion>0))
    {
        switch (opcion1)
        {
        case 1:
            reproductor.colaFeliz.push(cancion);
            break;
        case 2:
            reproductor.colaTriste.push(cancion);
            break;
        case 3:
            reproductor.colaEstudio.push(cancion);
            break;
        }    
    }
    
    
};

void eliminar_cancion(){
    switch (opcion1)
    {
    case 1:
        reproductor.colaFeliz.pop();
        break;
    case 2:
        reproductor.colaTriste.pop();
        break;
    case 3:
        reproductor.colaEstudio.pop();
        break;
    }
    cout<<"\nse elimino la cancion de la cola...\n";
};

void vaciar_cola(){
    switch (opcion1)
    {
    case 1:
        while (!reproductor.colaFeliz.empty())
        {
            reproductor.colaFeliz.pop();
        }
        break;
    case 2:
        while (!reproductor.colaTriste.empty())
        {
            reproductor.colaTriste.pop();
        }
        break;
    case 3:
        while (!reproductor.colaEstudio.empty())
        {
            reproductor.colaEstudio.pop();
        }
        break;
    }
    cout<<"se vacio la cola...\n";
};

void mostrar_canciones(){
    colas colatemp = reproductor;
    canciones canciontemp;
    switch (opcion1)
    {
    case 1:
        while (!colatemp.colaFeliz.empty())
        {
            system("cls");
            canciontemp = colatemp.colaFeliz.front();
            cout<<"\nTitulo: "<<canciontemp.titulo;
            cout<<"\nArtista: "<<canciontemp.cantante;
            cout<<"\nGenero: "<<canciontemp.genero;
            cout<<"\nDuracion: "<<canciontemp.duracion<<" seg\n\n";
            colatemp.colaFeliz.pop();
            system("pause");
        }
        break;
    case 2:
        while (!colatemp.colaTriste.empty())
        {
            system("cls");
            canciontemp = colatemp.colaTriste.front();
            cout<<"\nTitulo: "<<canciontemp.titulo;
            cout<<"\nArtista: "<<canciontemp.cantante;
            cout<<"\nGenero: "<<canciontemp.genero;
            cout<<"\nDuracion: "<<canciontemp.duracion<<" seg\n\n";
            colatemp.colaTriste.pop();
            system("pause");
        }
        break;
    case 3:
        while (!colatemp.colaEstudio.empty())
        {
            system("cls");
            canciontemp = colatemp.colaEstudio.front();
            cout<<"\nTitulo: "<<canciontemp.titulo;
            cout<<"\nArtista: "<<canciontemp.cantante;
            cout<<"\nGenero: "<<canciontemp.genero;
            cout<<"\nDuracion: "<<canciontemp.duracion<<" seg\n\n";
            colatemp.colaEstudio.pop();
            system("pause");
        }
        break;
    
    default:
        break;
    }
};

void menuCola(){
    system("cls");
    cout<<"\t---COLA "<<cola<<"---\n";
    cout<<"\n1.Agregar cancion.";
    cout<<"\n2.eliminar cancion.";
    cout<<"\n3.Vaciar cola.";
    cout<<"\n4.Mostrar contenido.";
    cout<<"\n\topcion: ";cin>>opcion2;

            switch (opcion2)
        {
        case 1:
            agregar_cancion();
            break;
        case 2:
            eliminar_cancion();
            system("pause");
            break;
        case 3:
            vaciar_cola();
            system("pause");
            break;
        case 4:
            mostrar_canciones();
            break;
        }
};

int main(){
    bool continuar = true;

    do
    {
        menuPrincipal();
        
        switch (opcion1)
        {
        case ((1) || (2) || (3)):
            menuCola();
            break;

        case 4:
            continuar = false;
            break;
        
        default:
            cout<<"\nopcion no valida...\n";
            break;
        }
    } while (continuar);

    return 0;
}