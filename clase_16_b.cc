#include <iostream>
#include <string>

// Estructura para almacenar indiceormación académica del estudiante
struct Tiobe
{
    // La "clave" del nodo (raíz del árbol)
    float puntaje;
    std::string lenguaje_programacion;
};

struct Nodo
{
    struct Tiobe indice_tiobe;
    struct Nodo *izquierdo;
    struct Nodo *derecho;
};

struct Tiobe SolicitarDatos();
// Funcion que devuelve un puntero
Nodo *crear_nodo(const Tiobe &indice);

void insertar_nodo(Nodo *&abb, const Tiobe &indice);

void recorrido_inorden(Nodo *abb);

int main()
{
    struct Nodo *abb = nullptr;
    int opc;
    do
    {
        struct Tiobe indiceormacion = SolicitarDatos();
        crear_nodo(indiceormacion);
        insertar_nodo(abb, indiceormacion);
        std::cout << "Dese agregar otro dato? \n"
                  << "[1] - Si \n"
                  << "[0] - No \n";
        std::cin >> opc;
    } while (opc != 0);

    recorrido_inorden(abb);
    return 0;
}

struct Tiobe SolicitarDatos()
{
    struct Tiobe indiceormacion_indice;
    std::cout << "Ingrese el nombre del lenguaje de programacion a agregar \n";
    std::cin >> indiceormacion_indice.lenguaje_programacion;
    std::cout << "Ingrese el puntaje que tiene el lenguaje de programacion \n";
    std::cin >> indiceormacion_indice.puntaje;
    return indiceormacion_indice;
}

// Crear un nodo a partir de la indiceormación académica
Nodo *crear_nodo(const Tiobe &indice)
{
    Nodo *nuevo_nodo = new Nodo;
    nuevo_nodo->indice_tiobe = indice;
    nuevo_nodo->izquierdo = nullptr;
    nuevo_nodo->derecho = nullptr;
    return nuevo_nodo;
}

// Insertar un nodo en el árbol
void insertar_nodo(Nodo *&abb, const Tiobe &indice)
{
    if (abb == nullptr)
    {
        abb = crear_nodo(indice);
        return;
    }

    // Comparativa con la taíz del árbol
    if (indice.puntaje < abb->indice_tiobe.puntaje)
        insertar_nodo(abb->izquierdo, indice);
    else
        insertar_nodo(abb->derecho, indice);
}

// Recorridos
void recorrido_inorden(Nodo *abb)
{
    // Si el arbol es nulo
    if (!abb)
        return;
    // Si no es nulo
    recorrido_inorden(abb->izquierdo);
    std::cout << "[Puntaje: " << abb->indice_tiobe.puntaje << " - Nombre: " << abb->indice_tiobe.lenguaje_programacion << "] ";
    recorrido_inorden(abb->derecho);
}
