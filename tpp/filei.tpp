
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

template <typename Element>
FileIterative<Element> & FileIterative<Element>::operator+=(const ListeIterative<Element> & right){
  int i, len;

  try{
    len = right.size();
    for(i=0; i<len; i++){
      push(right[i]);
    }
    return *this;
  }
  catch(...){
    throw;
  }
}


