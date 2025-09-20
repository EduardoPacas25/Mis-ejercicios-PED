#include <iostream> //<<>>
#include <vector>
#include <string>

struct Materia {
    std::string nombre_materia;
    float nota;
};

struct DatosEstudiante {
    std::string nombre_estudiante;
    int edad;    
    Materia materias [3];
    float promedio;
};

struct DatosEstudiante SolicitarDatos();
float CalcularPromedio(struct DatosEstudiante notas);
void Imprimir(std::vector<struct DatosEstudiante> vector_estudiantes);

std::vector<struct DatosEstudiante> vector_estudiantes;

int main(){
    int opc = 0;
    std::cout<<"Bienvenido \n";
    do{
        DatosEstudiante estudiante;
        std::cout<<"Que accion desea realizar? \n"
            <<"[1] - Agregar nuevo estudiante \n"
            <<"[2] - Mostrar estudiantes \n"
            <<"[3] - Salir \n";
        std::cin>>opc;
        std::cin.ignore();
    switch (opc){
            case 1:
                estudiante = SolicitarDatos();
                estudiante.promedio=CalcularPromedio(estudiante);
                vector_estudiantes.push_back(estudiante);
                break;
            case 2:
                Imprimir(vector_estudiantes);
                break;
            case 3:
                std::cout<<"Adios \n";
                break;
            default:
                std::cout<<"Opcion no valida \n";
                break;
        }
    } while(opc!=3);
    return 0;
}

struct DatosEstudiante SolicitarDatos(){
    DatosEstudiante estudiante;
    std::cout<<"Ingrese el nombre del estudiante \n";
    std::getline(std::cin, estudiante.nombre_estudiante);
    std::cout<<"Ingrese la edad del estudiante \n";
    std::cin>>estudiante.edad;
    std::cin.ignore();
    for (int i = 0; i < 3; i++){
        std::cout<<"Ingrese el nombre de la materia #" <<i+1 <<"\n";
        std::getline(std::cin, estudiante.materias[i].nombre_materia);
        std::cout<<"Ingrese la nota obtenida en la materia #" <<i+1 <<"\n";
        std::cin>>estudiante.materias[i].nota;
        std::cin.ignore();
    }
    return estudiante;
}

float CalcularPromedio (struct DatosEstudiante notas){
    float suma = 0;
    for (int i = 0; i < 3; i++){
        suma = suma + notas.materias[i].nota;
    }
    return suma/3;
}

void Imprimir (std::vector<struct DatosEstudiante> vector_estudiantes){
    std::cout<<"\n////////////////////////////////// \n";
    for (auto e: vector_estudiantes){
        std::cout<<"Nombre del estudiante: "<<e.nombre_estudiante <<"\n"
            <<"Edad del estudiante: " <<e.edad <<"\n";
        for (int i = 0; i < 3; i++){
        std::cout<<"Nombre de materia #" <<i+1 <<": "
            <<e.materias[i].nombre_materia <<"\n"
            <<"Nota obtenida en la materia #" <<i+1 <<": "
            <<e.materias[i].nota <<"\n";
        }
        std::cout<<"Promedio del estudiante: " <<e.promedio <<"\n";
        std::cout<<"////////////////////////////////// \n";
    }
}