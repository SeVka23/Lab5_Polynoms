#include <iostream>
#include "TPolynom.h"
int main()
{
  int x, y, z;
  TPolynom* p;
  TPolynom* p2;
  p = new TPolynom();
  p2 = new TPolynom();
  //input
  std::cout << "Enter polynom 1: " << std::endl;
  std::cin >> *p;
  std::cout << "Enter polynom 2: " << std::endl;
  std::cin >> *p2;
  //output
  std::cout << "polynom 1: " << std::endl << *p << std::endl;
  std::cout << "polynom 2: " << std::endl << *p2 << std::endl;
  //sum
  std::cout << "Sum of polynoms = " << *p + *p2 << std::endl;
  //calculating
  std::cout << "Calculating of polynoms: " << std::endl;
  std::cout << "Enter x" << std::endl;
  std::cin >> x;
  std::cout << "Enter y" << std::endl;
  std::cin >> y;
  std::cout << "Enter z" << std::endl;
  std::cin >> z;
  std::cout << "Polynom 1 = " << p->CalculatePolynom(x, y, z) << std::endl;
  std::cout << "Polynom 2 = " << p2->CalculatePolynom(x, y, z) << std::endl;
  return 0;
}