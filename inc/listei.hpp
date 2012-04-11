#ifndef LISTEI_HPP
#define LISTEI_HPP

#include "box.hpp"
#include <iostream> // pour NULL
#include <string>
#include <stdexcept>

template <typename Element>
class ListeIterative
{
 protected:
  Box<Element> * _first;
  Box<Element> * _last; //pas nécessaire, mais facilite la destruction et la recopie de liste
  int _size; // liste vide: size = 0;

  Box<Element> * _getBox(int=0);
  void _clone(const ListeIterative &);

 public:
  ListeIterative();
  ListeIterative(const ListeIterative<Element> &);
  ListeIterative<Element> & operator=(const ListeIterative<Element> &);
  ~ListeIterative();

  ListeIterative<Element> & insert(int, Element);
  ListeIterative<Element> & remove(int);

  inline int size() const;
  inline bool isEmpty() const;

  Element & operator[](int);//ieme

  template <typename T>
  friend ListeIterative<T> operator+(const ListeIterative<T> &, const ListeIterative<T> &);

  //ListeIterative<Element> & operator+=(const ListeIterative<Element> &);

  class ListLogicFault// : public exception
  {
  private:
    std::string _mess;
  public:
    ListLogicFault(std::string mess=""):_mess(mess){}
    std::string what()const{return _mess;}
  };
};

#include "listei.tpp"

#endif
