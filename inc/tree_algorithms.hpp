#ifndef TREE_ALGORITHMS_HPP
#define TREE_ALGORITHMS_HPP

#include "tree.hpp"
#include "filei.hpp"
#include <iostream>

namespace tree_algorithms
{
  template <typename Element>
  void width_travers_tree( Tree<Element> & theTree, void (* process)(Tree<Element> & subTree) ){
    int i , n;
    typename Tree<Element>::Forest foret;
    Tree<Element> A, Ai;
    /* file : file pour ranger les sous-arbres dont les racines ont été visitées*/
    FileIterative< Tree<Element> > file;

    /* process : effectue un traitement sur la racine de l'arbre courant (racine et sous arbres) */
    //on traite la racine
    process(theTree) ;

    file.push(theTree);
    while( !file.isEmpty() ){
      A = file.front() ;
      file.pop() ;
      /* traiter les racines des sous_arbres de A */
      foret = A.subTrees() ;
      n = foret.size() ;
      for(i=0 ; i < n ; i++){
	Ai = foret[i] ;
	process(Ai);
	file.push(Ai) ; 
      }
    } 
  }

  template <typename Element>
  void print_tree(Tree<Element> & theTree){
    int i, len;
    typename Tree<Element>::Forest f;

    std::cout<<theTree.rootnode().getContent()<<": ";
    f = theTree.subTrees();
    len = f.size();
    for(i=0; i < len; i++){
      std::cout<<f[i].rootnode().getContent()<<" ";
    }
    std::cout<<std::endl;
  }
}

#endif
