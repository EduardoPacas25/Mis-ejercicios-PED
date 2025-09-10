#include <iostream>

std::string SaludoPorPuntero(std::string *saludo);
std::string SaludoPorValor(std::string saludo);
std::string SaludoPorReferencia(std::string &saludo);

int main(){
  std::string saludo = "Hola";
  
  std::cout<<"Saludo original: " <<saludo <<"\n"; //Hola
  std::cout<<"Nuevo saludo - " <<SaludoPorPuntero(&saludo) <<"\n"; //Buendia
  std::cout<<"Saludo original: " <<saludo <<"\n"; //Buendia
  std::cout<<"Nuevo saludo - " <<SaludoPorValor(saludo) <<"\n"; //Buenastardes
  std::cout<<"Saludo original: " <<saludo <<"\n"; //Buendia
  std::cout<<"Nuevo saludo - " <<SaludoPorReferencia(saludo) <<"\n"; //Buenasnoches
  std::cout<<"Saludo original: " <<saludo <<"\n"; //Buenasnoches

  return 0;
}

std::string SaludoPorPuntero(std::string *saludo){
  *saludo = "Buendia";
  return *saludo;
}

std::string SaludoPorValor(std::string saludo){
  saludo = "Buenastardes";
  return saludo;
}

std::string SaludoPorReferencia(std::string &saludo){
  saludo = "Buenasnoches";
  return saludo;
}