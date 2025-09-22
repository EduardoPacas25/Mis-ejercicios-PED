#include <iostream>

int main()
{  
  /* int *ptr = new int;
  *ptr = 10;

  delete ptr;
  ptr = nullptr; */
  int cantidad = 0;
  float suma = 0;
  std::cout<<"Ingrese la cantidad de ventas \n";
  std::cin>>cantidad;
  float *ptr_ventas = new float[cantidad];
  for(int i = 0; i <cantidad; i++)
  {
    std::cout <<"Ingrese la venta #" <<i+1 <<"\n";
    std::cin >> *(ptr_ventas + i);
    suma = suma + *(ptr_ventas + i);
  }

  for (int i = 0; i < cantidad; i++){
    std::cout <<"Dir. memoria de venta " <<i+1 <<": " << ptr_ventas + i <<"\n";
  }

  std::cout<< "Promedio: " <<suma/cantidad;
  delete[] ptr_ventas;
  ptr_ventas=nullptr;

  return 0;
}

