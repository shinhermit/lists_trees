
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

template <typename T>
FileIterative<T> operator+=(const FileIterative<T> &left, const ListeIterative<T> & right){
  int i, len;
  FileIterative<T>res(left);
  ListeIterative<T> r(right);

  try{
    len = r.size();
    for(i=0; i<len; i++){
      res.push(r[i]);
    }
  }
  catch(...){
    throw;
  }
  return res;
}


