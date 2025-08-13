#include <iostream>
#include <cmath>

const double kPi = 3.1416;
//Declaración de la función
float CalcularAreaCirculo (float radio);

int main(){

  float radio, areac;
  std::cout<< "Ingrese el radio del area que desea calcular"<<std::endl;
  std::cin >> radio;

  //Invocación de la función
  areac = CalcularAreaCirculo(radio);

  std::cout<< "El area del circulo de radio " <<radio <<" es: " <<areac;

  return 0;
}

//Definición de la función
float CalcularAreaCirculo (float radio){
  return roundf((radio * radio) * kPi);
}