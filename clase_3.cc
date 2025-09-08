#include <iostream>

void PasoPorValor (int n);
void PasoPorPuntero (int *ptr);
void PasoPorReferencia (int &n);
// Ejercicio:
void IntercambiarValores(int a, int b);
void IntercambiarValoresPuntero(int *ptr_a, int *ptr_b);

int main()
{
  /*int num = 100;

  //int *ptr = &num;

  std::cout<< "Valor de num: " << num <<"\n";
  PasoPorValor(num); //110
  std::cout<< "Valor de num: " << num <<"\n"; //100
  PasoPorPuntero(&num);
  PasoPorReferencia(num); //110
  std::cout<< "Valor de num: " << num <<"\n"; //110
  */

  int a = 10;
  int b = 5;

  std::cout<< "Valor de a: " << a << " - Valor de b: "<< b << "\n";
  IntercambiarValores(a, b);
  std::cout<< "Valor de a: " << a << " - Valor de b: "<< b << "\n";
  IntercambiarValoresPuntero(&a, &b);
  std::cout <<"Valor de a: "<< a <<" - Valor de b: "<< b <<"\n";

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

void IntercambiarValores(int a, int b){
  int temp;
  temp = b;
  b = a;
  a = temp;
  std::cout <<"Valor de a: "<< a <<" - Valor de b: "<< b <<"\n";
}

void IntercambiarValoresPuntero(int *ptr_a, int *ptr_b){ 
  int temp;
  temp = *ptr_b;
  *ptr_b = *ptr_a;
  *ptr_a = temp;
  std::cout <<"Valor de a: "<< *ptr_a <<" - Valor de b: "<< *ptr_b <<"\n";
}