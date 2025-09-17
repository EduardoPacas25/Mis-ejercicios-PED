#include <iostream>

int main(){
  int arreglo [5] = {1, 2, 3, 4, 5};
  // Apuntando a la dirección de memoria de la posición o
  int *ptr = arreglo;

  int suma = 0;

  std::cout<<"Valor: " <<arreglo[0] <<" Dir. memoria: "<<&arreglo <<"\n"
    <<"Valor: " <<arreglo[1] <<" Dir. memoria: "<<arreglo+1 <<"\n"
    <<"Valor: " <<arreglo[2] <<" Dir. memoria: "<<&arreglo+2 <<"\n"
    <<"Valor: " <<arreglo[3] <<" Dir. memoria: "<<&arreglo+3 <<"\n" 
    <<"Valor: " <<arreglo[4] <<" Dir. memoria: "<<&arreglo+4 <<"\n";
  
  for (int i = 0; i<5; i++){
    suma = suma+ arreglo[i];
  }
  std::cout<<"Suma total: " <<suma <<"\n";
  std::cout<<"///////////////////////////////////// \n";

  for (int i = 0; i<5; i++){
    std::cout<<"Dir. memoria: " <<(arreglo+i)
      <<" Valor: " << *(arreglo+i) <<"\n";
  }
  return 0;
}