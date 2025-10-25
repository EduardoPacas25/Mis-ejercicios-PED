#include <iostream> // < <>>
#include <list>
#include <algorithm>

struct Luchador
{
    std::string nombre;
    float peso;
};

std::list<struct Luchador> luchadores;
struct Luchador SolicitarDatos();

bool CompararPorPeso(const Luchador &l1, const Luchador &l2)
{
    return l1.peso > l2.peso;
}

void BuscarPorNombre(std::list<Luchador> luchadores, std::string nombre_buscado);

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

    luchadores.sort(CompararPorPeso);

    for (auto l : luchadores)
    {
        std::cout << "Luchador: " << l.nombre << " --- peso lbs: " << l.peso << "\n";
    }

    std::cout << "Ingrese el peso en libras a buscar \n";
    std::cin >> peso_buscado;
    bool busqueda = std::binary_search(luchadores.begin(), luchadores.end(),
     Luchador{"", peso_buscado}, CompararPorPeso); 
     /*Se crea un struct tipo Luchador temporal, las llaves contienen 
     los campos del struct y al no importar el nombre se deja vacío y se busca el peso
     por medio de la función de comparar
     (Éste es un parámetro extra para cambiar el comportamiento de binary_search())*/

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

void BuscarPorNombre(std::list<Luchador> luchadores, std::string nombre_buscado)
{
    auto it = std::find_if(luchadores.begin(), luchadores.end(), [nombre_buscado](const Luchador &luchador)
                           { return luchador.nombre == nombre_buscado; });
     //Lambda, devuelve true si un nombre del "arreglo" es igual al buscado
     //[captura] significa el uso de una variable dentro de la lambda
    if (it != luchadores.end()) // find_if recorre un "arreglo" y busca al primero que cumpla una condición definida
    {
        std::cout << "Luchador encontrado: " << it->nombre << " con peso " << it->peso << "\n";
    }
    else
    {
        std::cout << "No se han encontrado coincidencias \n";
    }
}

/* Ordenar con vector ->  sort(vector.begin, vector.end);
      Ordenar con lista -> lista.sort();
      Para ordenar pilas o colas se puede vaciar los elementos de las dichas y meterlas en arreglos como listas
      o vectores, ordenarlos y volverlos a meter en filas o colas
*/

/*
Comandos de <list>
lista.push_back(elemento)
lista.push_front(elemento)
lista.pop_back(elemento)
lista.pop_front(elemento) 
lista.sort(lista.begin, lista.end) 

Comandos de <stack>
pila.push(elemento);
pila.pop();
pila.peek(); v pila.top();
pila.empty();
pila.size();

Comandos de <queue>
cola.push(elemento);
cola.pop();
cola.front();
cola.back();
cola.empty();
cola.size();

Comandos de <algorithm>
sort(inicio, fin); (Se puede modificar su comportamiento con lambdas para que pueda ordenar estructuras)
find_if(inicio, fin, lambda); 
binary_search(inicio, fin, valor_a_buscar); (Devuelve si se encuentra el valor o no)
*/