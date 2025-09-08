#include <iostream>

void PasoPorValor (int n);
void PasoPorPuntero (int *ptr);
void PasoPorReferencia (int &n);

int main()
{
  int num = 100;

  //int *ptr = &num;

  std::cout<< "Valor de num: " << num <<"\n";
  PasoPorValor(num); //110
  std::cout<< "Valor de num: " << num <<"\n"; //100
  PasoPorPuntero(&num);
  PasoPorReferencia(num); //110
  std::cout<< "Valor de num: " << num <<"\n"; //110

  return 0;
}

void PasoPorValor (int n){
  std::cout<< "Valor de n: "<< n + 10 <<"\n";
}

void PasoPorPuntero (int *ptr){
  *ptr = *ptr + 10;
  std::cout << "Valor de n: "<< *ptr <<"\n";
}

void PasoPorReferencia (int &n){
  n = n + 10;
  std::cout<< "Valor de n: " << n <<"\n";
}