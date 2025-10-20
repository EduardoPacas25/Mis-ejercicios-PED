#include <iostream>
#include <vector>
#include <algorithm>

struct Luchador
{
    std::string nombre;
    float peso;
};

std::vector<struct Luchador> luchadores;
struct Luchador SolicitarDatos();

int main()
{
    float opcpeso;
    Luchador luchador;
    for (int i = 0; i < 5; i++)
    {
        std::cout << "#" << i + 1 << "\n";
        luchador = SolicitarDatos();
        luchadores.push_back(luchador);
    }

    std::sort(luchadores.begin(), luchadores.end(),[](const Luchador& l1, const Luchador& l2){
        return l1.peso < l2.peso;
    });

    for (auto l : luchadores){
        std::cout << "Luchador: " << l.nombre << "--- peso lbs: " << l.peso <<"\n";
    }


    std::cout <<"Que peso pesado desea buscar? \n";
    std::cin >> opcpeso;
    std::binary_search(luchadores.begin(), luchadores.end(), opcpeso);

    return 0;
}

struct Luchador SolicitarDatos()
{
    struct Luchador luchador;
    std::cout << "Ingrese el nombre del luchador \n";
    std::cin >> luchador.nombre;
    std::cout << "Ingrese el peso en libras del luchador \n";
    std::cin >> luchador.peso;
    return luchador;
}
