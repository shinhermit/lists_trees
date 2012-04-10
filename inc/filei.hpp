#ifndef FILEI_HPP
#define FILEI_HPP

#include "listei.hpp"

template <typename Element>
class FileIterative: protected ListeIterative<Element>
{
public:
  FileIterative<Element> & push(Element);
  FileIterative<Element> & pop();
  Element front();
  bool isEmpty(){return ListeIterative<Element>::isEmpty();}
};

#include "filei.tpp"

#endif
