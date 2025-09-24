#include <iostream> //listas simplemente enlazadas

struct Datos
{
  int numero;
};

struct Nodo 
{
  struct Datos datos;
  struct Nodo *siguiente;
};

// Puntero global
struct Nodo *inicio_lista = nullptr;

void InsertarInicio(int n);
void InsertarFinal(int n);
void EliminarInicio();
void EliminarFinal();
void Imprimir ();


int main()
{
  InsertarInicio(40);
  InsertarInicio(80);
  InsertarInicio(100);
  InsertarFinal(89);
  Imprimir();
  EliminarInicio();
  Imprimir();
  //std::cout << "Dir memoria: " <<inicio_lista <<" Numero " <<inicio_lista->datos.numero <<"\n";
  //std::cout << "Dir memoria: " <<inicio_lista->siguiente->siguiente <<" Numero " <<inicio_lista->siguiente->siguiente->datos.numero <<"\n";
  return 0;
}

void InsertarInicio(int n)
{
  //reserva de memoria
  struct Nodo *nuevo_nodo = new Nodo;
  // Variable auxiliar almacena el nodo actual
  nuevo_nodo ->datos.numero = n;
  nuevo_nodo->siguiente = nullptr;

  // Si la lista está vacía se agrega el valor al inicio de la lista
  if(inicio_lista == nullptr)
  {
    inicio_lista = nuevo_nodo;
  }
  else
  {
    // Agregar un nodo al inicio
    nuevo_nodo->siguiente = inicio_lista;
    //El nuevo nodo pasa a ser el inicio de la lista
    inicio_lista = nuevo_nodo;
  }

}

void InsertarFinal(int n)
{
  struct Nodo *nuevo_nodo = new Nodo;
  //Variable auxiliar almacena el dato actual 
  struct Nodo *temporal = inicio_lista;
  nuevo_nodo->datos.numero = n;
  nuevo_nodo->siguiente = nullptr;
  if(inicio_lista == nullptr)
  {
    inicio_lista = nuevo_nodo;
  }
  else
  {
    //Agregar un nodo al final
    while (temporal->siguiente != nullptr)
    {
      temporal = temporal->siguiente;
    }
    temporal->siguiente = nuevo_nodo;
  }
}

void EliminarInicio()
{
  struct Nodo *temporal = inicio_lista;
  // Si el inicio de la lista contiene elementos
  if(inicio_lista != nullptr)
  {
    //Borra el elemento
    inicio_lista = temporal->siguiente;
    //Libera memoria
    delete temporal;
    temporal = nullptr;
  }
}

void EliminarFinal()
{
  struct Nodo *temporal = inicio_lista;
  struct Nodo *temporal_2 = inicio_lista;
  if(inicio_lista != nullptr)
  {
    if(temporal->siguiente != nullptr)
    {
      while (temporal->siguiente !=nullptr)
      {
        temporal_2 = temporal;
        temporal = temporal ->siguiente;
      }
      //Almacena el penultimo nodo sera quien apunte a null
      temporal_2->siguiente = nullptr;
      //Se libera la memoria del ultimo nodo
      delete temporal;
      temporal = nullptr;
    }
    else
    {
      delete inicio_lista;
      inicio_lista = nullptr;
    }
  }
}

void Imprimir()
{
  struct Nodo *temporal = inicio_lista;

  if (inicio_lista != nullptr)
  {
    while(temporal != nullptr)
    {
      std::cout <<"///////////////////////// \n"
                <<"Valores de lista " <<temporal->datos.numero <<"\n"
                <<"Direccion: " <<temporal <<"\n"
                <<"Dir. nodo siguiente: " <<temporal->siguiente <<"\n";
      temporal = temporal->siguiente;
    }
    std::cout <<"///////////////////////// \n";
  }
}