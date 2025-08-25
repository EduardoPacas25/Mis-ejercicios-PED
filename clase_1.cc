#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <cctype>
#include <vector>
#include <utility>

std::string SolicitarDatos();
std::string GenerarCupon (std::string letras);
std::string VerificarPremio (std::string cupon);

struct InformacionCupon {
  int cantidad_cupones;
  std::string nombre_usuario,
  std::vector<std::pair<std::string, std::string>> cupones_generados;
}cupon;

std::vector<struct InformacionCupon> inf_cupones;

int main(){
  std::cout<<"Ingrese su nombre \n";
  std::cin>>cupon.nombre_usuario;
  std::cout<<"Ingrese la cantidad de cupones que desea generar \n";
  std::cin>>cupon.cantidad_cupones;
  //std::vector<std::string> cupones; //[cantidad_cupones]

  for (int i = 0; i < cupon.cantidad_cupones; i++){
    std::string letras;
    std::string cupon_generado;

    letras = SolicitarDatos();

    cupon_generado = GenerarCupon(letras);
    std::cout<<"El cupon generado es: "<< cupon_generado <<std::endl;


    VerificarPremio(cupon_generado);
    //cupones[i]=cupon_generado;
    //cupones.push_back(cupon_generado);
    cupon.cupones_generados.push_back({cupon_generado, "premio"});
  }
  std::cout<<"///////////////////////" <<std::endl;
  std::cout<<"Cupones generados: \n";

    /*for (auto cupon: cupones){
    std::cout<<cupon <<std::endl;
    VerificarPremio(cupon);
  }*/
  inf_cupones.pushback(cupon);
  std::cout<<"Iprimiendo informacion... \n";
  std::cout<< cupon.cantidad_cupones <<std::endl;
  
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

std::string VerificarPremio (std::string cupon) {
  std::string numeros = cupon.substr(3,4);
  std::string premio;
  int valor_cupon = std::stoi(numeros);
  if (valor_cupon%2 == 0) {
      premio = "Tiene premio";
  }
  else{
    premio = "No tiene premio";
  }
  return premio;
}