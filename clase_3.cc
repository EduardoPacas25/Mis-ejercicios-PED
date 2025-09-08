#include <iostream>

void PasoPorValor (int n);
void PasoPorReferencia (int &n);

int main()
{
  int num = 100;

  //int *ptr = &num;

  std::cout<< "Valor de num: " << num <<"\n";
  PasoPorValor(num); //110
  std::cout<< "Valor de num: " << num <<"\n"; //100

  PasoPorReferencia(num); //110
  std::cout<< "Valor de num: " << num <<"\n"; //110

  return 0;
}

void PasoPorValor (int n){
  std::cout<< "Valor de n: "<< n + 10 <<"\n";
}
void PasoPorReferencia (int &n){
  std::cout<< "Valor de n: " << n + 10 <<"\n";
}