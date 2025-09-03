#include <iostream>
#include <vector>
#include <utility>
#include <string>

struct InformacionAlbum {
  std::string nombre_album;
  int fecha_lanzamiento;
  std::vector<std::pair<std::string, int>> canciones;
  int antiguedad_album;
};

struct InformacionCantante {
  std::string nombre_cantante;
  std::string nacionalidad_cantante;
  struct InformacionAlbum album_cantante; 
};

struct InformacionCantante SolicitarDatos();
//struct InformacionCantante cantante;
void Imprimir(InformacionCantante cantante);
int CalcularAntiguedad(int lanzamiento);
std::vector<struct InformacionCantante> vector_cantantes;

int main(){
  char opc;

  do{
  struct InformacionCantante cantante;
  cantante = SolicitarDatos();
  vector_cantantes.push_back(cantante);
  cantante.album_cantante.antiguedad_album = CalcularAntiguedad(cantante.album_cantante.fecha_lanzamiento);
  Imprimir(cantante);
  std::cout<<"Desea registrar otro cantante? \n";
  std::cin>>opc;
  } while(opc== 's' || opc== 'S');

  return 0;
}

struct InformacionCantante SolicitarDatos(){
  struct InformacionCantante cantante;
  int cantidad_canciones;
  std::cout<<"Ingrese el nombre del cantante \n";
  std::cin>> cantante.nombre_cantante;
  std::cout<<"Ingrese la nacionalidad del cantante \n";
  std::cin>> cantante.nacionalidad_cantante;
  std::cout<<"Ingrese el nombre del album \n";
  std::cin>> cantante.album_cantante.nombre_album;
  std::cout<<"Ingrese el año de lanzamiento del album \n";
  std::cin>> cantante.album_cantante.fecha_lanzamiento;
  std::cout<<"Cuantas canciones tiene el album? \n";
  std::cin>> cantidad_canciones;
  for(int i = 0; i<cantidad_canciones; i++){
    std::string nombre_c;
    std::cout<<"Ingrese el nombre de la cancion #" <<i+1  <<"\n";
    std::cin>>nombre_c;
    cantante.album_cantante.canciones.push_back({nombre_c, i+1});
  }
  return cantante;
}

void Imprimir(InformacionCantante cantante){
  std::cout<< "///////////////////////// \n";
  std::cout<< "--Cantante: "<<cantante.nombre_cantante <<"\n";
  std::cout<< "--Nacionalidad: "<<cantante.nacionalidad_cantante<<"\n";
  std::cout<< "--Album: "<<cantante.album_cantante.nombre_album<<"\n";
  std::cout<< "--Año de lanzamiento: "<<cantante.album_cantante.fecha_lanzamiento<<"\n";

  for (auto c: cantante.album_cantante.canciones){
    std::cout<< c.second <<". " << c.first <<"\n";
  }
  std::cout<< "-- El album fue lanzado hace " <<cantante.album_cantante.antiguedad_album <<" años" <<"\n";
  std::cout<< "///////////////////////// \n";
}

int CalcularAntiguedad(int lanzamiento){
  struct InformacionCantante cantante;
  cantante.album_cantante.antiguedad_album = 2025 -  lanzamiento;
  return cantante.album_cantante.antiguedad_album;
}