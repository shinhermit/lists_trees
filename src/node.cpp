#include <iostream>
#include "node.hpp"

using namespace std;

int main()
{
  Node<double> n, l;
  Node<double> m(2.3);
  Node<double> k(m);

  if(n.isEmpty())
    cout<<"n: noeud vide"<<endl;

  if(!m.isEmpty())
    cout<<"m contient: "<<m.getContent()<<endl;

  if(!k.isEmpty())
    cout<<"k contient: "<<k.getContent()<<endl;

  n = Node<double>(5.1);
  cout<<"n contient: "<<n.getContent()<<endl;

  l = n;

  if(!l.isEmpty())
    cout<<"l contient: "<<l.getContent()<<endl;

  return 0;
}
