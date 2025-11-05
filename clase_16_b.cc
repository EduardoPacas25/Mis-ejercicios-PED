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
void recorrido_preorden(Nodo *abb);
void BuscarNodo(Nodo *&abb, float puntaje_a_buscar, Nodo *&padre);
Nodo *BuscarMayor(Nodo *abb);
void BorrarNodo(Nodo *&abb, float puntaje_a_borrar);

int main()
{
    struct Tiobe indiceormacion;
    struct Nodo *abb = nullptr;
    int opc;
    float puntaje_busqueda;
    do
    {
        std::cout << "Ingrese la acción que desea realizar \n"
        << "[1] - Ingresar indice \n"
        << "[2] - Borrar nodo \n"
        << "[3] - Recorrido inorden \n"
        << "[4] - Salir \n";
        std:: cin >> opc;
        switch (opc)
        {
        case 1:
            indiceormacion = SolicitarDatos();
            crear_nodo(indiceormacion);
            insertar_nodo(abb, indiceormacion);
            break;
        case 2:
            std::cout << "Ingrese el puntaje del nodo a borrar \n";
            std::cin >> puntaje_busqueda;
            BorrarNodo(abb, puntaje_busqueda);    
            break;
        case 3:
            recorrido_inorden(abb);
            break;
        case 4:
            std::cout << "Adios \n";
            break;
        default:
            std::cout << "No valido \n";
            break;
        }

    } while (opc != 4);

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

void recorrido_preorden(Nodo *abb)
{
    // Si el arbol es nulo
    if (!abb)
        return;
    // Si no es nulo
    std::cout << "[Puntaje: " << abb->indice_tiobe.puntaje << " - Nombre: " << abb->indice_tiobe.lenguaje_programacion << "] ";
    recorrido_preorden(abb->izquierdo);
    recorrido_preorden(abb->derecho);
}

// Buscar un nodo
void BuscarNodo(Nodo *&abb, float puntaje_a_buscar, Nodo *&padre)
{
    while (abb != nullptr && abb->indice_tiobe.puntaje != puntaje_a_buscar)
    {
        padre = abb;
        if (puntaje_a_buscar < abb->indice_tiobe.puntaje)
            abb = abb->izquierdo;
        else
            abb = abb->derecho;
    }
}

// Buscar el nodo menor (sucesor)
Nodo *BuscarMenor(Nodo *abb)
{
    while (abb && abb->izquierdo != nullptr)
        abb = abb->izquierdo;
    return abb;
}

// Buscar el nodo mayor (predecesor)
Nodo *BuscarMayor(Nodo *abb)
{
    while (abb && abb->derecho != nullptr)
        abb = abb->derecho;
    return abb;
}

// Borrar un nodo
void BorrarNodo(Nodo *&abb, float puntaje_a_borrar)
{
    Nodo *padre = nullptr;
    Nodo *aux = abb;
    BuscarNodo(aux, puntaje_a_borrar, padre);
    // Si es nulo
    if (!aux)
        return;

    // Si es un nodo hoja
    if (!aux->izquierdo && !aux->derecho)
    {
        if (aux == abb)
            abb = nullptr;
        else if (padre->izquierdo == aux)
            padre->izquierdo = nullptr;
        else
            padre->derecho = nullptr;
        delete aux;
    }
    // Si es un nodo con dos hijos
    else if (aux->izquierdo && aux->derecho)
    {
        /*Nodo *sucesor = BuscarMenor(aux->derecho);
        aux->indice_tiobe = sucesor->indice_tiobe;
        BorrarNodo(aux->derecho, sucesor->indice_tiobe.puntaje);*/
        Nodo *predecesor = BuscarMayor(aux->izquierdo);
        aux->indice_tiobe = predecesor->indice_tiobe;
        BorrarNodo(aux->izquierdo, predecesor->indice_tiobe.puntaje);
    }
    // Si es un nodo con un solo hijo
    else
    {
        Nodo *hijo = ((aux->izquierdo) ? aux->izquierdo : aux->derecho);
        if (aux != abb)
        {
            if (aux == padre->izquierdo)
                padre->izquierdo = hijo;
            else
                padre->derecho = hijo;
        }
        else
            abb = hijo;
        delete aux;
    }
}