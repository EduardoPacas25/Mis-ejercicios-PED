#include <iostream>

int main(){
  int arreglo [3] = {1, 3, 100};
  // Apuntando a la dirección de memoria de la posición o
  int *ptr = arreglo;
  
  //calcluar el peso en bytes de un int
  std::cout<<"Peso en bytes de int: "<<sizeof(int) <<"\n";

  //Acceder a los elementos de un arreglo
  std::cout<< "Dir. memoria pos [0]: " << &arreglo
    << " Valor pos[0]: " << arreglo[0] <<"\n";
  
  // Acceder en notación puntero sin puntero
  std::cout<< "Dir. memoria pos [1]: " <<(arreglo + 1)
    << " Valor pos[1]: " << *(arreglo + 1)<<"\n";
  
  //acceder a los elementos con puntero
  std::cout<<"Dir. memoria pos [2]: " <<ptr+2 
    <<" Valor pos[2]: " << *(ptr + 2);
  return 0;
}