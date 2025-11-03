#include <iostream>

int factorial (int x);

int main(){
  std::cout << factorial(5);
  
  return 0;
}

int factorial (int x)
{
  if( x == 1 || x == 0){
    return 1;
  }
  else 
  {
    return x * factorial(x - 1);
  }
}