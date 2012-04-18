template<typename Element>
Box<Element>::Box(Element e, Box<Element>* precedent, Box<Element>* suivant):_contenu(e), _precedent(precedent), _suivant(suivant){}

template<typename Element>
Box<Element>::Box(const Box<Element> & source):_contenu(source._contenu), _precedent(source._precedent), _suivant(source._suivant){}

template<typename Element>
Box<Element> & Box<Element>::operator=(const Box<Element> & source){
  this->~Box();
  _contenu = source._contenu;
  _precedent = source._precedent;
  _suivant = source._suivant;
  return *this;
}

template<typename Element>
Box<Element>::~Box(){}

template<typename Element>
Element & Box<Element>::getContent(){return _contenu;}

template<typename Element>
Element Box<Element>::getContent()const{return _contenu;}

template<typename Element>
Box<Element> * Box<Element>::getPrevious()const{return _precedent;}

template<typename Element>
Box<Element> * Box<Element>::getNext()const{return _suivant;}

template<typename Element>
Box<Element> & Box<Element>::setContent(Element e){_contenu = e; return *this;}

template<typename Element>
Box<Element> & Box<Element>::setPrevious(Box<Element> * prev){_precedent = prev; return *this;}

template<typename Element>
Box<Element> & Box<Element>::setNext(Box<Element> * next){_suivant = next; return *this;}
