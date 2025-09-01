#include <iostream>
#include <vector>

struct InformacionAlbum {
  std::string nombre_album;
  int fecha_lanzamiento;
  std::vector<std::string> canciones;
};

struct InformacionCantante {
  std::string nombre_cantante;
  std::string nacionalidad_cantante;
  struct InformacionAlbum album_cantante; 
};


int main(){
  
  
  return 0;
}