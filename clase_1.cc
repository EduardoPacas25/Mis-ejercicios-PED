#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <cctype>
#include <vector>
#include <utility>

struct InformacionPersona{
  std::string nombre_usuario;
};

std::string SolicitarDatos();
std::string GenerarCupon (std::string letras);
std::string VerificarPremio (std::string cupon);
void Imprimir (std::vector<struct InformacionCupon> vector_cupon);

struct InformacionCupon SolicitarDatosGenerales();

struct InformacionCupon {
  int cantidad_cupones;
  struct InformacionPersona inf_persona;
  std::vector<std::pair<std::string, std::string>> cupones_generados;
};

std::vector<struct InformacionCupon> vector_cupones;

int main(){
  char opc;
  do{
  struct InformacionCupon cupon;
  cupon = SolicitarDatosGenerales();

  vector_cupones.push_back(cupon);

  Imprimir(vector_cupones);
  std::cout<<"//////////////////// \n";
  std::cout<<"Desea anadir otro registro? \n";
  std::cin>>opc;
  }while (opc == 's' || opc == 'S');
  
  return 0;
}

struct InformacionCupon SolicitarDatosGenerales() {
  struct InformacionCupon cupon;
  std::string premio;
  std::cout<<"Ingrese su nombre \n";
  std::cin>>cupon.inf_persona.nombre_usuario;
  std::cout<<"Ingrese la cantidad de cupones que desea generar \n";
  std::cin>>cupon.cantidad_cupones;

  for (int i = 0; i < cupon.cantidad_cupones; i++){
    std::string letras;
    std::string cupon_generado;

    letras = SolicitarDatos();

    cupon_generado = GenerarCupon(letras);
    premio = VerificarPremio(cupon_generado);
    cupon.cupones_generados.push_back({cupon_generado, premio});
  }
  return cupon;
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

void Imprimir(std::vector<struct InformacionCupon> vector_cupon) {
  std::cout<<"//////////////////// \n";
  std::cout<<"Imprimiendo informacion... \n";
  for (auto c: vector_cupones){
    std::cout<<"Nombre de la persona: " << c.inf_persona.nombre_usuario <<"\n";
    std::cout<<"Cantidad de cupones: " << c.cantidad_cupones <<"\n";
    for (auto c_g: c.cupones_generados){
      std::cout<<"Cupon: " <<c_g.first << " -Premio: " <<c_g.second << "\n";
    }
  }
}