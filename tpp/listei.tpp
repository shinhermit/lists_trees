
template <typename Element>
ListeIterative<Element>::ListeIterative():_first(NULL), _last(NULL), _size(0){}

template <typename Element>
ListeIterative<Element>::ListeIterative(const ListeIterative<Element> & source):_first(NULL), _last(NULL), _size(0){
  _clone(source);
}

template <typename Element>
ListeIterative<Element> & ListeIterative<Element>::operator=(const ListeIterative<Element> & source){
  this->~ListeIterative();
  _clone(source);
}
template <typename Element>
ListeIterative<Element>::~ListeIterative(){
  if(_first) delete _first;
  _first = NULL;
  _last = NULL;/*
  Box<Element> * current;
  Box<Element> * previous;
  int i;
    
  current = _last;
  while(current){
    previous = current->getPrevious();
    current->setPrevious(NULL);
    delete current;

    current = previous;
    _size--;
  }
  _first = NULL;
  _last = NULL;*/
}


template <typename Element>
Box<Element> * ListeIterative<Element>::_getBox(int pos){
  int i;
  Box<Element> * current;

  if(_size == 0)
    throw ListeIterative<Element>::ListLogicFault("Logic error: attempt to read empty list");
  else{
    if(0 <= pos && pos < _size){
      i=0;
      current = _first;
      while(i < pos){
	current = current->getNext();
	i++;
      }
      return current;
    }
    else{
      throw ListeIterative<Element>::ListLogicFault("Logic error: out of range error for access index");
    }
  }
}

template <typename Element>
ListeIterative<Element> &  ListeIterative<Element>::insert(int i, Element elt){
  Box<Element> * current;
  Box<Element> * previous;
  Box<Element> * newBox;


    if(_size == 0){//la liste est vide
      _first = new Box<Element>(elt, NULL, NULL);
      _last = _first;
      ++_size;
    }
    else if(0 <= i && i <= _size){
      if(i==0){//insertion en début de liste
	newBox = new Box<Element>(elt, NULL, _first);
	_first->setPrevious(newBox);
	_first = newBox;
      }
      else if(i < _size){ // insertion en milieu de liste
	current = _getBox(i);
	previous = current->getPrevious();
	newBox = new Box<Element>(elt, previous, current);

	previous->setNext(newBox);
	current->setPrevious(newBox);
      }
      else{ //insertion en fin de liste
	newBox = new Box<Element>(elt, _last, NULL);
	_last->setNext(newBox);
	_last = newBox;
      }
      ++_size;
      return *this;
  }
 else return *this;
}

template <typename Element>
ListeIterative<Element> & ListeIterative<Element>::remove(int i){
  Box<Element> * toBeRemoved;

  if(0 <= i && i < _size){
    if(i==0){
      toBeRemoved = _first;
      _first = _first->getNext();
      toBeRemoved->setNext(NULL);
      delete toBeRemoved;
    }
    else if(i==_size-1){
      toBeRemoved = _last;
      _last = _last->getPrevious();
      toBeRemoved->setPrevious(NULL);
      delete toBeRemoved;
    }
    else{
      toBeRemoved = _getBox(i);
      toBeRemoved->getPrevious()->setNext( toBeRemoved->getNext() );
      toBeRemoved->getNext()->setPrevious( toBeRemoved->getPrevious() );
      toBeRemoved->setNext(NULL).setPrevious(NULL);
      delete toBeRemoved;
    }
    _size --;
    return *this;
  }
  else return *this;
}

template <typename Element>
int ListeIterative<Element>::size() const{return _size;}

template <typename Element>
bool ListeIterative<Element>::isEmpty() const{return (_size == 0);}

template <typename Element>
Element & ListeIterative<Element>::operator[](int i){
  if(_size == 0)
    throw ListeIterative<Element>::ListLogicFault("Logic error: attempt to read empty list");
  else{
    if(0 <= i && i < _size){
      return _getBox(i)->getContent();
    }
    else{
      if(i < 0)
	return _first->getContent();
      else
	return _last->getContent();
    }
  }
}

template <typename T>
ListeIterative<T> operator+(const ListeIterative<T> & left, const ListeIterative<T> & right){
  ListeIterative<T> res(left);
  int i, len1, len2;

  len1 = left.size();
  len2 = right.size();
  for(i=0; i < len2; i++){
    res.insert(i+len1, right[i]);
  }
  return res;
}

/*template <typename Element>
ListeIterative<Element> & ListeIterative<Element>::operator+=(const ListeIterative<Element> & right){
  *this = *this + right;
  return *this;
}
*/


template <typename Element>
void ListeIterative<Element>::_clone(const ListeIterative<Element> & source){
  if(source._first){
    Box<Element> * newBox;
    Box<Element> * current;

    Box<Element> * srcCurrent = source._first->getNext();

    int i;

    _first = new Box<Element>(source._first->getContent(), NULL, NULL);
    current = _first;
    while(srcCurrent){
      newBox = new Box<Element>( srcCurrent->getContent(), current, NULL );
      current->setNext(newBox);
      current = newBox;
      srcCurrent = srcCurrent->getNext();
    }
    _size = source._size;
  }
}
