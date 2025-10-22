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

bool CompararPorPeso(const Luchador &l1, const Luchador &l2)
{
    return l1.peso > l2.peso;
}

void BuscarPorNombre(std::vector<Luchador> luchadores, std::string nombre_buscado);

int main()
{
    float peso_buscado;
    std::string nombre_buscado;
    Luchador luchador;
    for (int i = 0; i < 5; i++)
    {
        std::cout << "#" << i + 1 << "\n";
        luchador = SolicitarDatos();
        luchadores.push_back(luchador);
    }

    std::sort(luchadores.begin(), luchadores.end(), CompararPorPeso);

    for (auto l : luchadores)
    {
        std::cout << "Luchador: " << l.nombre << " --- peso lbs: " << l.peso << "\n";
    }

    std::cout << "Ingrese el peso en libras a buscar \n";
    std::cin >> peso_buscado;
    bool busqueda = std::binary_search(luchadores.begin(), luchadores.end(), Luchador{"", peso_buscado}, CompararPorPeso);

    if (busqueda)
    {
        std::cout << "Peso encontrado \n";
    }
    else
    {
        std::cout << "Peso no encontrado \n";
    }

    std::cout <<"Ingrese el nombre a buscar \n";
    std::cin >> nombre_buscado;
    BuscarPorNombre(luchadores, nombre_buscado);

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

void BuscarPorNombre(std::vector<Luchador> luchadores, std::string nombre_buscado)
{
    auto it = std::find_if(luchadores.begin(), luchadores.end(), [nombre_buscado](const Luchador &luchador)
                           { return luchador.nombre == nombre_buscado; });
    if (it != luchadores.end())
    {
        std::cout << "Luchador encontrado: " << it->nombre << " con peso " << it->peso << "\n";
    }
    else
    {
        std::cout << "No se han encontrado coincidencias \n";
    }
}

//RETO: Cambiar el vector de luchadores por lista, pila o cola