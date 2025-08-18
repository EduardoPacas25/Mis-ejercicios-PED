#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

std::string GenerarCupon (std::string letras);
void VerificarPremio (std::string cupon);

int main(){
  std::string letras;
  std::string cupon_generado;

  std::cout<<"? \n";
  std::cin>>letras;

  cupon_generado = GenerarCupon(letras);
  std::cout<< cupon_generado <<std::endl;

  VerificarPremio(cupon_generado);

  return 0;
}

std::string GenerarCupon (std::string letras) {
  srand(time(0));
  int numero_aleatorio = rand() % 999;
  std::string conversion = std::to_string(numero_aleatorio);  
  return letras + conversion;
}

void VerificarPremio (std::string cupon) {
  std::string numeros = cupon.substr(3,4);
  int valor_cupon;
  valor_cupon = std::stoi(numeros);
  if (valor_cupon%2 == 0) {
      std::cout<<"Tiene premio" <<std::endl;
  }
  else{
      std::cout<<"No tiene premio" <<std::endl;
  }
}