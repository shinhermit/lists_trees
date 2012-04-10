#include "tree.hpp"
#include "tree_algorithms.hpp"
#include <iostream>

using namespace tree_algorithms;

int main()
{
  Tree<double> a, b, c;
  typename Tree<double>::Forest f;

  try{ 
    //arbre (3.3 (2.2) (1.1))
    a.build(Node<double>(1.1), f);
    print_tree<double>(a);

    a = Tree<double>();

    b.build(Node<double>(2.2), f);
    c.build(Node<double>(3.3), f);

    f.insert(0, b).insert(1, c);

    a.build(Node<double>(4.4), f);

    print_tree<double>(a);
    print_tree<double>(b);
    print_tree<double>(c);
    std::cout<<std::endl;
    width_travers_tree<double>(a, print_tree<double>);
  }
  catch(Tree<double>::TreeLogicFault & e){
    std::cout<<e.what()<<std::endl;
  }
  catch(Node<double>::NodeLogicFault & e){
    std::cout<<e.what()<<std::endl;
  }
  catch(ListeIterative<double>::ListLogicFault & e){
    std::cout<<e.what()<<std::endl;
  }
  catch(...){
    std::cout<<"unknow exception"<<std::endl;
  }
}
