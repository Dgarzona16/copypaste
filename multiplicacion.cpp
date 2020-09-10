#include <iostream>

using namespace std;

int multiplicacion(int, int);

int main()
{
    int a, b;
    cout << "ingrese los numeros a multiplicar:\n(tienen que ser numeros naturales)\n";
    cin >> a;
    cin >> b;

    cout << "el resultado de la multiplicacion es: " << multiplicacion(a, b);
}

int multiplicacion(int a, int b)
{
    int mult;
    if (b == 1)
    {
        mult = a;
    }
    else
    {
        mult = a + multiplicacion(a, b - 1);
    }
    return mult;
}