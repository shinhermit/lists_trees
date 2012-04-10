#ifndef BOX_HPP
#define BOX_HPP

#include <iostream> //pour NULL

template <typename Element>
class Box
{
private:
  Element _contenu;
  Box<Element> * _precedent;
  Box<Element> * _suivant;
public:
  Box(Element, Box<Element>* = NULL, Box<Element>* = NULL);
  Box(const Box<Element> &);
  Box & operator=(const Box<Element> &);
  ~Box();

  inline Element & getContent();
  inline Element getContent()const;
  inline Box<Element> * getPrevious()const;
  inline Box<Element> * getNext()const;

  Box<Element> & setContent(Element);
  Box<Element> & setPrevious(Box<Element>*);
  Box<Element> & setNext(Box<Element>*);
};

#include "box.tpp"

#endif
