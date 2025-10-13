#include <iostream>
#include <queue>

struct Persona
{
    std::string nombre;
    int fecha_nacimiento;
};

struct Persona SolicitarDatos();
void Imprimir(std::queue<struct Persona> cola);

int main(){
    std::queue<struct Persona> cola;
    struct Persona datos;
    
    datos = SolicitarDatos();
    cola.push(datos);
    Imprimir(cola);

  return 0;
}

struct Persona SolicitarDatos(){
    struct Persona persona;
    std::cout << "Ingrese el nombre de la persona \n";
    std::cin >> persona.nombre;
    std::cout << "Ingrese la fecha de nacimiento (año) de la persona \n";
    std::cin >> persona.fecha_nacimiento;
    return persona;
}

void Imprimir (std::queue<struct Persona> cola){
    while (!cola.empty())
    {
        std::cout <<"Nombre: " << cola.front().nombre << " - Año de nacimiento: " << cola.front().fecha_nacimiento <<"\n";
        cola.pop();
    }
    
}