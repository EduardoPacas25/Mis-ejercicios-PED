#include <iostream>
#include <stack>

int main()
{
    int cantidad = 0;
    char letras;
    std::stack <char> pila;
    std::cout <<"Ingrese la cantidad de letras que tiene su nombre \n";
    std::cin >> cantidad;

    for (int i = 0; i<cantidad; i++){
        std::cout <<"Ingrese la letra #" <<i+1 <<" de su nombre \n";
        std::cin >> letras;
        pila.push(letras);
    }

    for(int i = 0; i < cantidad; i++){
        std::cout << pila.top();
        pila.pop();
    }

    return 0;
}