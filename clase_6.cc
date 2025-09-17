#include <iostream>

struct Persona{
    std::string nombre;
    float altura;
    float peso;
    // Indice de masa corporal
    float IMC;
};//*ptr_persona;

struct Persona SolicitarDatos ();
void CalcularIMC (struct Persona *ptr);

int main(){
    struct Persona persona;
    struct Persona *ptr = &persona;

    persona=SolicitarDatos();
    CalcularIMC(&persona);



  return 0;
}

struct Persona SolicitarDatos(){
    Persona persona;
    std::cout<<"Ingrese el nombre de la persona \n";
    std::cin>> persona.nombre;
    std::cout<<"Ingrese la altura de la persona \n";
    std::cin>> persona.altura;    
    std::cout<<"Ingrese el peso de la persona \n";
    std::cin>> persona.peso;
    return persona;
}

void CalcularIMC (struct Persona *ptr){
    ptr->IMC = (ptr->peso)/((ptr->altura)*(ptr->altura));
}