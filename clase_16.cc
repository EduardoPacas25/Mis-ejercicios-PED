#include <iostream>

int sumatoria(int x);
int factorial(int x);
// int potencia(int x, int y);
bool esPar(int x);
bool esImpar(int x);

int main()
{
  int num;

  std::cout << "Ingrese el número con el que desea operar \n";
  std::cin >> num;

  std::cout << "Sumatoria: " << sumatoria(num) << "\n";
  std::cout << "Factorial: " << factorial(num) << "\n";

  if (esPar(num)){
    std::cout << "Es par \n";
  }
  else 
  {
    std::cout << "Es impar \n";
  }

  return 0;
}

int sumatoria(int x)
{
  if (x == 0)
  {
    return 0;
  }
  else
  {
    return x + sumatoria(x - 1);
  }
}

int factorial(int x)
{
  if (x == 1 || x == 0)
  {
    return 1;
  }
  else
  {
    return x * factorial(x - 1);
  }
}

/*int potencia(int x, int y)
{
  if (y == 0)
  {
    return 1;
  }
  else
  {
    return x * potencia(x, y);
  }
} */

bool esPar(int x)
{
  if (x % 2 == 0)
  {
    return true;
  }
  else
  {
    return esImpar(x);
  }
}

bool esImpar(int x)
{
  if (x % 2 != 0)
  {
    return true;
  }
  else
  {
    return esPar(x);
  }
}