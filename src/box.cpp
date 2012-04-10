#include "box.hpp"
#include <iostream>

using namespace std;

int main()
{
  Box<double> c(1.1);
  Box<double> c1(c);

  cout<< c1.getContent()<<endl;
  
  c1 = Box<double>(2.2, NULL, &c);

  cout<<c1.getContent()<<c1.getNext()->getContent()<<endl;

  return 0;
}
