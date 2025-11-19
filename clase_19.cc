#include <iostream>
#include <unordered_map>
#include <vector>

//typedef std::vector<int> vector; //Alias, que permite definir autmoaticamente una variable de ese tipo

using Grafo = std::unordered_map<char, std::vector <char>>; //Tambien permite guardar un Alias

void AgregarAristas(Grafo &lista_ady, char origen, char destino);
void Imprimir(const Grafo &lista_ady);

int main()
{
    Grafo lista_ady;
    AgregarAristas(lista_ady, 'a', 'c');
    AgregarAristas(lista_ady, 'a', 'd');
    AgregarAristas(lista_ady, 'c', 'd');
    AgregarAristas(lista_ady, 'd', 'b');
    Imprimir(lista_ady);

    return 0;
}

void AgregarAristas(Grafo &lista_ady, char origen, char destino)
{
    //Grafo dirigido
    lista_ady[origen].push_back(destino);

    //Grafo no dirigido
    /*lista_ady[origen].push_back(destino);
    lista_ady[destino].push_back(origen);*/
}

void Imprimir(const Grafo &lista_ady)
{
    for (auto umap: lista_ady)
    {
        std::cout << "\n" << "Nodo origen: " << umap.first << " ";
        for (auto vector: umap.second)
        {
            std::cout << " - Nodo destino: " << vector;
        }
    }
}