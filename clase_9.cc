#include <iostream> //listas doblemente enlazadas

struct Datos
{
  int numero;
};

struct Nodo 
{
  struct Datos datos;
  struct Nodo *siguiente;
  struct Nodo *anterior;
};

// Puntero global
struct Nodo *lista = nullptr;

void InsertarInicio(struct Nodo **lista, int n);
void InsertarFinal(struct Nodo **lista, int n);
//void InsertarIntermedio()

int main(/*int argc, char *argv[]*/)
{
  // Reserva memoria en stack
  struct Nodo *lista = nullptr;
  InsertarInicio(&lista, 100);
  InsertarInicio(&lista, 7);
  InsertarInicio(&lista, 17);
  std::cout << "Dir memoria: " <<lista <<"\n"
            << "Dir.memoria sig: " <<lista->siguiente <<"\n" 
            << "Dir memoria ant: " <<lista->anterior <<"\n"
            << "Numero "<<lista->datos.numero <<"\n"; // 17

  std::cout << "Dir memoria: " <<lista <<"\n"
            << "Dir.memoria sig: " <<lista->siguiente->siguiente <<"\n" 
            << "Dir memoria ant: " <<lista->siguiente->anterior <<"\n"
            << "Numero "<<lista->siguiente->datos.numero <<"\n"; // 7

  std::cout << "Dir memoria: " <<lista <<"\n"
            << "Dir.memoria sig: " <<lista->siguiente->siguiente->siguiente <<"\n" 
            << "Dir memoria ant: " <<lista->siguiente->siguiente->anterior <<"\n"
            << "Numero "<<lista->siguiente->siguiente->datos.numero <<"\n"; // 100
  return 0;
}

void InsertarInicio(struct Nodo **lista, int n)
{

  struct Nodo *nuevo_nodo = new Nodo;
  nuevo_nodo->datos.numero = n;
  nuevo_nodo->siguiente = nullptr;
  nuevo_nodo->anterior = nullptr;
  // Si la lista está vacía
  if(*lista == nullptr)
  {
    *lista = nuevo_nodo;
  }
  else
  {
    // Conexión del nuevo nodo con la lista
    nuevo_nodo->siguiente = *lista;
    (*lista)->anterior = nuevo_nodo;
    // Asignar el nuevo nodo a la cabeza de la lista
    *lista = nuevo_nodo;
  }
}

void InsertarFinal(struct Nodo **lista, int n)
{
  struct Nodo *nuevo_nodo = new Nodo;
  nuevo_nodo->datos.numero = n;
  nuevo_nodo->siguiente = nullptr;
  nuevo_nodo->anterior = nullptr;
  // Si la lista está vacía
  if(*lista == nullptr)
  {
    *lista = nuevo_nodo;
  }
  else
  {
    struct Nodo *temporal = *lista;
    while(temporal->siguiente !=nullptr)
    {
      temporal = temporal->siguiente;
    }
    temporal->siguiente = nuevo_nodo;
    temporal->anterior = temporal;
  }
}