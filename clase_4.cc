#include <iostream>

int Acumulador(int n);
int AcumuladorRef(int &n);
int AcumuladorPtr(int *n);

int main(){
  int x = 10;
  
  std::cout<<"Nuevo valor - " <<Acumulador(x) <<"\n"; //11
  std::cout<<"Valor de x: " <<x <<"\n"; //10
  std::cout<<"Nuevo valor - " <<AcumuladorRef(x) <<"\n"; //11
  std::cout<<"Valor de x: " <<x <<"\n"; //11
  std::cout<<"Nuevo valor - " <<AcumuladorPtr(&x) <<"\n"; //12
  std::cout<<"Valor de x: " <<x <<"\n"; //12

  return 0;
}

int Acumulador(int n){
  n = n+1;
  return n;
}

int AcumuladorRef(int &n){
  n = n+1;
  return n;
}

int AcumuladorPtr(int *n){
  *n = *n+1;
  return *n;
}