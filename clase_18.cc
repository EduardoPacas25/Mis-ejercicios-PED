#include <iostream>
#include <unordered_map>

struct Animal
{
    std::string nombre_cientifico;
    std::string nombre_comun;
    std::string genero;
};

struct Animal SolicitarDatos();
void Buscar (const std::unordered_map<std::string, Animal> &umap, std::string criterio_busqueda);
void Eliminar (std::unordered_map<std::string, Animal> &umap, std::string criterio_eliminar);
void Imprimir(const std::unordered_map<std::string, Animal> &umap);

int main()
{
    Animal animal;
    int opc;
    std::string busqueda;
    std::unordered_map<std::string, Animal> umap;
    do
    {
        animal = SolicitarDatos();
        // umap.insert({animal.nombre_cientifico, animal}); -> Las llaves son para crear un objeto que la función va a guardar
        umap.emplace(animal.nombre_cientifico, animal);

        std::cout << "Desea ingresar otro animal? \n"
                  << "[1] - Si \n"
                  << "[0] - No \n";
        std::cin >> opc;
    } while (opc != 0);

    Imprimir(umap);

    std::cout << "Ingrese el nombre cientifico del animal a buscar \n";
    std::cin >> busqueda;
    Buscar(umap, busqueda);

    return 0;
}

struct Animal SolicitarDatos()
{
    Animal datos_animal;
    std::cout << "Ingrese el nombre científico del animal \n";
    std::cin >> datos_animal.nombre_cientifico;
    std::cout << "Ingrese el nombre comun del animal \n";
    std::cin >> datos_animal.nombre_comun;
    std::cout << "Ingrese el genero del animal \n";
    std::cin >> datos_animal.genero;
    return datos_animal;
}

void Imprimir(const std::unordered_map<std::string, Animal> &umap)
{
    auto hash = umap.hash_function();
    for (auto i : umap)
    {
        std::cout << "Clave: " << hash(i.first) << "\n"
                  << "Nombre cientifico: "<< i.second.nombre_cientifico << " - "
                  << "Nombre comun: "<< i.second.nombre_comun << " - "
                  << "Genero: "<< i.second.genero << "\n";
    }
}

void Buscar (const std::unordered_map<std::string, Animal> &umap, std::string criterio_busqueda)
{
    if (umap.empty())
    {
        std::cout << "El registro esta vacio \n";
    }
    auto it = umap.find(criterio_busqueda);
    if(it != umap.end()){
        std::cout << "Animal encontrado. \n"
                  << "Nombre cientifico: " << it->second.nombre_cientifico << " - "
                  << "Nombre comun: " << it->second.nombre_comun << " - "
                  << "Genero: " << it->second.genero <<"\n";
    }else{
        std::cout << "Animal no encontrado \n";
    }

}

void Eliminar (std::unordered_map<std::string, Animal> &umap, std::string criterio_eliminar){
    if (umap.empty())
    {
        std::cout << "El registro esta vacio \n";
    }
    auto it = umap.find(criterio_eliminar);
    if(it != umap.end()){
        umap.erase(it);
        std::cout <<"Animal eliminado \n";
    }else{
        std::cout << "Animal no encontrado \n";
    }

}