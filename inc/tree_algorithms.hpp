#ifndef TREE_ALGORITHMS_HPP
#define TREE_ALGORITHMS_HPP

#include "tree.hpp"
#include "filei.hpp"
#include <iostream>

namespace tree_algorithms
{
  //DECLARATIONS (pour ne pas me soucier de l'ordre d'implémentation)
  template <typename Element>
  void print_tree(Tree<Element> & theTree);

  template <typename Element>
  void width_travers_tree( Tree<Element> & theTree, void (* process)(Tree<Element> & subTree) );

  //IMPLEMENTATIONS
  template <typename Element>
  void width_travers_tree( Tree<Element> & theTree, void (* process)(Tree<Element> & subTree) ){
    int i , n;
    typename Tree<Element>::Forest subtrees;
    Tree<Element> A;
    Tree<Element> Ai;
    FileIterative< Tree<Element> > level; //représente le niveau qu'on visite
 
    try{
      level.push(theTree);
      while( !level.isEmpty() ){ //cette boucle s'arrête-t-elle toujours?
	A = level.front();
	process(A);
	subtrees = A.subTrees();
	level += subtrees;  //concaténation: opérateur à vérifier
	level.pop();
      }
    }
    catch(typename Tree<Element>::TreeLogicFault & te){
      throw;
    }
    catch(typename Node<Element>::NodeLogicFault & ne){
      throw;
    }
    catch(typename ListeIterative<Element>::ListLogicFault & le){
      throw;
    }

    /*try{
      //process : effectue un traitement sur la racine de l'arbre courant (racine et sous arbres)
      //on traite la racine
      process(theTree) ;

      file.push(theTree);
      while( !file.isEmpty() ){
	A = file.front() ;
	file.pop() ;
	//traiter les racines des sous_arbres de A
	foret = A.subTrees() ;
	n = foret.size() ;
	for(i=0; i < n; i++){
	  Ai = foret[i];
	  process(Ai);
	  file.push(Ai);
	}
      } 
    }
    catch(typename Node<Element>::NodeLogicFault & e){
      std::cout<<e.what()<<std::endl;
      throw;
    }
    catch(typename Tree<Element>::TreeLogicFault & e){
      std::cout<<e.what()<<std::endl;
      throw;
    }
    catch(...){
      std::cout<<"unknow exception"<<std::endl;
      throw;
    }
    */
  }

  template <typename Element>
  void print_tree(Tree<Element> & theTree){
    int i, len;
    typename Tree<Element>::Forest f;

    try{
      std::cout<<theTree.rootnode().getContent()<<": ";
      f = theTree.subTrees();
      len = f.size();
      for(i=0; i < len; i++){
	std::cout<<f[i].rootnode().getContent()<<" ";
      }
      std::cout<<std::endl;
    }
    catch(typename Node<Element>::NodeLogicFault & e){
      std::cout<<e.what()<<std::endl;
      throw;
    }
    catch(typename Tree<Element>::TreeLogicFault & e){
      std::cout<<e.what()<<std::endl;
      throw;
    }
  }
}

#endif
