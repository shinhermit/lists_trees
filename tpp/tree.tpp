template <typename Element>
Tree<Element>::Tree(){}

template <typename Element>
Tree<Element>::Tree(const Tree<Element> & source):_rootnode(source._rootnode), _sub_trees(source._sub_trees){}

template <typename Element>
Tree<Element> & Tree<Element>::operator=(const Tree<Element> & source){
  this->~Tree();
  try{
    _rootnode = source._rootnode;
  _sub_trees = source._sub_trees;
  }
  catch(Node<double>::NodeLogicFault & e){
    std::cout<<e.what()<<std::endl;
    throw;
  }
  catch(ListeIterative<double>::ListLogicFault & e){
    std::cout<<e.what()<<std::endl;
    throw;
  }
  return *this;
}

template <typename Element>
Tree<Element>::~Tree(){}

template <typename Element>
Tree<Element> & Tree<Element>::build(Node<Element> n, Tree<Element>::Forest f){
  try{
  _rootnode = n;
  _sub_trees = f;
  }
  catch(Node<double>::NodeLogicFault & e){
    std::cout<<e.what()<<std::endl;
    throw;
  }
  catch(ListeIterative<double>::ListLogicFault & e){
    std::cout<<e.what()<<std::endl;
    throw;
  }
}

template <typename Element>
Node<Element> & Tree<Element>::rootnode(){
  if( isEmpty() )
    throw Tree<Element>::TreeLogicFault("method rootnode: attempt to access empty Tree");
  else return _rootnode;
}

template <typename Element>
typename Tree<Element>::Forest & Tree<Element>::subTrees(){
  if( isEmpty() )
    throw Tree<Element>::TreeLogicFault("method subTrees: attempt to access empty Tree");
  else return _sub_trees;
}

template <typename Element>
bool Tree<Element>::isEmpty()const{
  if( _sub_trees.isEmpty() )
    return _rootnode.isEmpty();
  else
    return false;
}

