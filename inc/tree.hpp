#ifndef TREE_HPP
#define TREE_HPP

#include "node.hpp"
#include "listei.hpp"
#include <iostream>
#include <string>

template <typename Element>
class Tree
{
public:

  typedef ListeIterative< Tree<Element> >  Forest;

  Tree();
  Tree(const Tree<Element> &);
  Tree<Element> & operator=(const Tree<Element> &);
  ~Tree();

  Tree<Element> & build(Node<Element>, Forest);

  Forest & subTrees();
  Node<Element> & rootnode();
  bool isEmpty()const;

  class TreeLogicFault
  {
  private:
    std::string _mess;
  public:
    TreeLogicFault(std::string mess):_mess(mess){}
    std::string what()const{return _mess;}
  };

private:
  Node<Element> _rootnode;
  Forest _sub_trees;
};

#include "tree.tpp"

#endif
