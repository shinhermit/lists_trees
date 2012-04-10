
template <typename Element>
FileIterative<Element> & FileIterative<Element>::push(Element e){
  this->insert(this->size(), e);
  return *this;
}

template <typename Element>
FileIterative<Element> & FileIterative<Element>::pop(){
  this->remove(0);
  return *this;
}

template <typename Element>
Element FileIterative<Element>::front(){
  return (*this)[0];
}
