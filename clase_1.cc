#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <cctype>

std::string SolicitarDatos();
std::string GenerarCupon (std::string letras);
void VerificarPremio (std::string cupon);

int main(){
  int cantidad_cupones = 0;

  std::cout<<"Ingrese la cantidad de cupones que desea generar \n";
  std::cin>>cantidad_cupones;
  std::string cupones[cantidad_cupones];

  for (int i = 0; i < cantidad_cupones; i++){
    std::string letras;
    std::string cupon_generado;

    letras = SolicitarDatos();

    cupon_generado = GenerarCupon(letras);
    std::cout<<"El cupon generado es: "<< cupon_generado <<std::endl;

    VerificarPremio(cupon_generado);
    cupones[i]=cupon_generado;
  }
  std::cout<<"Cupones generados: \n";
    for (int i = 0; i < cantidad_cupones; i++){
    std::cout<<cupones[i] <<std::endl;
  }
  

  return 0;
}

std::string SolicitarDatos(){
  //Solicitar el prefijo
  std::string prefijo;
  std::cout<<"Ingrese las letras para el prefijo de su cupon \n";
  std::cout<<"(Debe tener un maximo de 3 letras) \n";
  std::cin>>prefijo;
   while(prefijo.size() != 3){
    //Validar que la longitud length() sea 3
    std::cout<<"Recuerde que deben ser 3 letras \n";
    std::cin>>prefijo;
  }
  // que sea letra isalpha()
  //return el prefijo validado
  return prefijo;
}

std::string GenerarCupon (std::string letras) {
  srand(time(0));
  int numero_aleatorio = rand() % 100 + 999;
  std::string conversion = std::to_string(numero_aleatorio);  
  return letras + conversion;
}

void VerificarPremio (std::string cupon) {
  std::string numeros = cupon.substr(3,4);
  int valor_cupon = std::stoi(numeros);
  if (valor_cupon%2 == 0) {
      std::cout<<"Tiene premio \n";
  }
  else{
      std::cout<<"No tiene premio \n";
  }
}