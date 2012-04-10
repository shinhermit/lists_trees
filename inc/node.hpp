#ifndef NODE_HPP
#define NODE_HPP

#include <string>

template <typename Element>
class Node
{
private:
  Element _e;
  bool _vide;
public:
  Node();
  Node(Element);
  Node(const Node<Element> &);
  Node<Element> & operator=(const Node<Element> &);
  ~Node();

  inline Element getContent()const;

  inline Node<Element> & setContent(Element e);

  inline bool isEmpty()const;

  class NodeLogicFault
  {
  private:
    std::string _mess;
  public:
    NodeLogicFault(std::string mess=""):_mess(mess){}
    std::string what()const{return _mess;}
  };
};

#include "node.tpp"

#endif
