template <typename Element>
Node<Element>::Node():_vide(true){}

template <typename Element>
Node<Element>::Node(Element e):_e(e){_vide=false;}

template <typename Element>
Node<Element>::Node(const Node<Element> & source):_e(source._e), _vide(source._vide){}

template <typename Element>
Node<Element> & Node<Element>::operator=(const Node<Element> & source){
  this->~Node();
  _e = source._e;
  _vide = source._vide;
  return *this;
}
template <typename Element>
Node<Element>::~Node(){}

template <typename Element>
Element Node<Element>::getContent()const{
  if(_vide)
    throw NodeLogicFault("node logic fault: Attempt to access empty Node");
  else
    return _e;
}

template <typename Element>
Node<Element> & Node<Element>::setContent(Element e){
  _e = e;
  _vide = false;
  return *this;
}

template <typename Element>
bool Node<Element>::isEmpty()const{return _vide;}

