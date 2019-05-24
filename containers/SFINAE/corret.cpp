#include <iostream>
#include "NoHostallocator.hpp"
#include "Mallocator.hpp"
#include "Vector.h"

using namespace qmcplusplus;

int main()
{
  Vector<int> a(3);
  Vector<int, Mallocator<int, 64>> b(3);
  Vector<int, NoHostallocator<int, 64>> c(3);
  std::cout << "a[2] = " << a[2] << std::endl;
  std::cout << "b[2] = " << b[2] << std::endl;
  //std::cout << "c[2] = " << c[2] << std::endl;
  return 0;
}
