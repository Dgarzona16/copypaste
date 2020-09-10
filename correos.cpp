#include <iostream>
#include <stdlib.h>

using namespace std;

struct pedidos
{
    char remitente[40];
    char destinatario[40];
    char tipo;
    int peso;
    char modalidad;
    int monto;
} pedido[5];

void montoFinal(int);

int main()
{
    int num;

    cout << "\tmaximo 5 pedidos por cliente"
         << "\ncuantos pedidos desea realizar: ";
    cin >> num;

    for (size_t i = 0; i < num; i++)
    {
        system("cls");
        fflush(stdin);
        cout << "ingrese nombre del remitente: ";
        cin.getline(pedido[i].remitente, 40);
        cout << "ingrese el nombre del destinatario: ";
        cin.getline(pedido[i].destinatario, 40);
        cout << "que tipo de pedido es:\nC-carta\nP-paquete\n";
        cin >> pedido[i].tipo;
        if ((pedido[i].tipo == 'P') || (pedido[i].tipo == 'p'))
        {
            cout << "ingrese el peso del paquete: ";
            cin >> pedido[i].peso;
        }
        cout << "en que modalidad va el paquete: \nU-urgente\nN-nacional\nI-internacional\n";
        cin >> pedido[i].modalidad;

        if ((pedido[i].tipo == 'C') || (pedido[i].tipo == 'c'))
        {
            switch (pedido[i].modalidad)
            {
            case 'u':
            case 'U':
                pedido[i].monto = 3;
                break;
            case 'n':
            case 'N':
                pedido[i].monto = 1;
                break;
            case 'i':
            case 'I':
                pedido[i].monto = 2;
                break;
            }
        }
        if ((pedido[i].tipo == 'P') || (pedido[i].tipo == 'p'))
        {
            switch (pedido[i].modalidad)
            {
            case 'u':
            case 'U':
                if ((pedido[i].peso > 0) && (pedido[i].peso <= 500))
                {
                    pedido[i].monto = 10;
                }
                else
                {
                    pedido[i].monto = 15;
                }
                break;
            case 'n':
            case 'N':
                pedido[i].monto = 5;
                break;
            case 'i':
            case 'I':
                if ((pedido[i].peso > 0) && (pedido[i].peso < 100))
                {
                    pedido[i].monto = 5;
                }
                else
                {
                    pedido[i].monto = 10;
                }
                break;
            }
        }
    }

    montoFinal(num);
}

void montoFinal(int n)
{
    int mFinal = 0;
    for (size_t i = 0; i < n; i++)
    {
        mFinal += pedido[i].monto;
    }
    cout << "el monto final a pagar es de $" << mFinal << "\nA sido un gusto atenderlo, pase feliz dia";
}