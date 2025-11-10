#include <iostream>
#include <string>
#include <set>

// Estructura para almacenar indiceormación de lenguajes de programación
struct Tiobe
{
    // La "clave" del nodo (raíz del árbol)
    float puntaje;
    std::string lenguaje_programacion;
};

struct CompTiobe {
    bool operator()(const Tiobe& a, const Tiobe& b) const {
        return a.puntaje < b.puntaje;
    }
};

struct Tiobe SolicitarDatos();
void BuscarLenguaje (const std::set<Tiobe, CompTiobe> abb, std::string lenguaje_buscado);
void Imprimir(const std::set<Tiobe, CompTiobe> abb);

int main()
{
    struct Tiobe indiceormacion;
    std::set <Tiobe, CompTiobe> abb;
    int opc;
    float puntaje_busqueda;
    do
    {
        std::cout << "Ingrese la acción que desea realizar \n"
        << "[1] - Ingresar indice \n"
        << "[2] - Borrar nodo \n"
        << "[3] - Recorrer árbol \n"
        << "[4] - Salir \n";
        std:: cin >> opc;
        switch (opc)
        {
        case 1:
            indiceormacion = SolicitarDatos();
            abb.insert(indiceormacion);
            break;
        case 2:
            //Borrar nodo
            std::cout << "Ingrese el puntaje que desea eliminar \n";
            std::cin >> puntaje_busqueda;
            break;
        case 3:
            // Recorrer arbol
            Imprimir(abb);
            break;
        case 4:
            std::cout << "Adios \n";
            break;
        default:
            std::cout << "No valido \n";
            break;
        }

    } while (opc != 4);

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

void BuscarLenguaje (const std::set<Tiobe, CompTiobe> abb, std::string lenguaje_buscado){
    /* 
    Función de BuscarLenguaje
    Si el set está vacío, devolver mensaje
    Si el elemento buscado no está en el set, devolver mensaje
    Si se encuentra, devolver la incformación
    */
   if (abb.empty()){
    std::cout << "El set esta vacio \n";
   }
   auto it = abb.find({0,lenguaje_buscado});
   if(it != abb.end())
   {
    std::cout << "Lenguaje de programacion " ;
   }
}

void Imprimir(const std::set<Tiobe, CompTiobe> abb){
   for (auto t: abb){
    std::cout << /*"Lenguaje de programacion: "<<*/ t.lenguaje_programacion 
              /*<< " - Puntaje: " */ << t.puntaje <<" ";
   } 
   std::cout << "\n";
}

