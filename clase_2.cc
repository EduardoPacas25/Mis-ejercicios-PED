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
struct InformacionCantante cantante;
void Imprimir(InformacionCantante cantante);
void CalcularAntiguedad(int lanzamiento);

int main(){

  cantante = SolicitarDatos();
  CalcularAntiguedad(cantante.album_cantante.fecha_lanzamiento);
  Imprimir(cantante);

  return 0;
}

struct InformacionCantante SolicitarDatos(){
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
    std::cout<<"Ingrese el nombre de la cancion \n";
    std::cin>>nombre_c;
    cantante.album_cantante.canciones.push_back({nombre_c, i+1});
  }
  return cantante;
}

void Imprimir(InformacionCantante cantante){
  std::cout<< "--Cantante: "<<cantante.nombre_cantante <<"\n";
  std::cout<< "--Nacionalidad: "<<cantante.nacionalidad_cantante<<"\n";
  std::cout<< "--Album: "<<cantante.album_cantante.nombre_album<<"\n";
  std::cout<< "--Año de lanzamiento: "<<cantante.album_cantante.fecha_lanzamiento<<"\n";
  for (auto c: cantante.album_cantante.canciones){
    std::cout<< c.second <<". " << c.first <<"\n";
  }
  std::cout<< "-- El album fue lanzado hace " <<cantante.album_cantante.antiguedad_album <<" años" <<"\n";
}

void CalcularAntiguedad(int lanzamiento){
  cantante.album_cantante.antiguedad_album = 2025 -  cantante.album_cantante.fecha_lanzamiento;
}