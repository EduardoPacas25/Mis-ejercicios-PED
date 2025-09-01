#include <iostream>
#include <vector>
#include <utility>

struct InformacionAlbum {
  std::string nombre_album;
  int fecha_lanzamiento;
  std::vector<std::pair<std::string, int>> canciones;
};

struct InformacionCantante {
  std::string nombre_cantante;
  std::string nacionalidad_cantante;
  struct InformacionAlbum album_cantante; 
};

struct InformacionCantante SolicitarDatos();

int main(){
  struct InformacionCantante cantante;
  cantante = SolicitarDatos();
  

  return 0;
}

struct InformacionCantante SolicitarDatos(){
  struct InformacionCantante cantante;
  std::cout<<"Ingrese el nombre del cantante \n";
  std::cin>> cantante.nombre_cantante;
  std::cout<<"Ingrese la nacionalidad del cantante \n";
  std::cin>> cantante.nacionalidad_cantante;
  std::cout<<"Ingrese el nombre del album \n";
  std::cin>> cantante.album_cantante.nombre_album;
  std::cout<<"Ingrese el año de lanzamiento del album \n";
  std::cin>> cantante.album_cantante.fecha_lanzamiento;
  for(int i = 0; i<2; i++){
    std::string nombre_c;
    std::cout<<"Ingrese el nombre de la cancion \n";
    std::cin>>nombre_c;
    cantante.album_cantante.canciones.push_back({nombre_c, i+1});
  }
  return cantante;
}