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

  template <typename T>
  friend FileIterative<T> operator+=(const FileIterative<T> &, const ListeIterative<T> &);
};

#include "filei.tpp"

#endif
