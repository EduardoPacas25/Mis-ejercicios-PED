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
void Imprimir(std::vector<struct Luchador> luchadores);
std::vector<struct Luchador> Comparar(std::vector<struct Luchador> luchadores);
void ImprimirMayorPeso(std::vector<struct Luchador> luchadores);
int main()
{
    Luchador luchador;
    for (int i = 0; i < 5; i++)
    {
        std::cout << "#" << i + 1 << "\n";
        luchador = SolicitarDatos();
        luchadores.push_back(luchador);
    }
    luchadores = Comparar(luchadores);
    Imprimir(luchadores);
    std::cout << "/////////////////// \n";
    ImprimirMayorPeso(luchadores);

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

std::vector<struct Luchador> Comparar(std::vector<struct Luchador> luchadores)
{

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4 - i; j++)
        {
            // Incrementamos el contador de pasos en cada comparación
            // Si el elemento actual es mayor que el siguiente, los intercambiamos
            if (luchadores[j].peso < luchadores[j + 1].peso)
            {
                // Intercambio de elementos
                float temp = luchadores[j].peso;
                std::string tempn = luchadores[j].nombre;
                luchadores[j].peso = luchadores[j + 1].peso;
                luchadores[j].nombre = luchadores[j + 1].nombre;
                luchadores[j + 1].peso = temp;
                luchadores[j + 1].nombre = tempn;
            }
        }
    }
    return luchadores;
}

void Imprimir(std::vector<struct Luchador> luchadores)
{
    std::cout << "//////////////////// \n";
    for (auto l : luchadores)
    {
        std::cout << "Nombre: " << l.nombre << "\n"
                  << "Peso: " << l.peso << "\n";
    }
}

void ImprimirMayorPeso(std::vector<struct Luchador> luchadores)
{
    std::cout << "El luchador con mayor peso es: " << luchadores[0].nombre
              << " con " << luchadores[0].peso << " libras \n";
}