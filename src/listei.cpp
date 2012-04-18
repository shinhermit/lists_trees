#include "listei.hpp"
#include <iostream>

using namespace std;

void lister(ListeIterative<double> & l){
  int i, len;

  cout<<"( ";
  len = l.size();
  for(i=0; i < len; i++){
    cout<<l[i];
    cout<<" ";
  }
  cout<<")"<<endl;
}

void supr_list_tout(ListeIterative<double> & l){
  int i, len;

  try{
    len = l.size();
    lister(l);
    for(i=0; i<len; i++){
      l.remove(0);
      lister(l);
    }
  }
  catch(ListeIterative<double>::ListLogicFault & e){
    cout<<e.what()<<endl;
  }
}

int main()
{
  ListeIterative<double> l1, l2;
  double i;


  //Axiome:
  //l=liste_vide !( ) <=> size((l) =0
  if(l1.isEmpty())
    cout<<"Liste vide crée"<<endl;
  cout<<"size: "<<l1.size()<<endl;

  //l= insert(l’,i,e) => size(l) = size(l’) +1
  l1.insert(0, 1.1);
  try{
    cout<<"1 elt ajouté: "<<l1[0]<<endl;
    cout<<"size: "<<l1.size()<<endl;
  }
  catch(ListeIterative<double>::ListLogicFault e){
    cout<<e.what()<<endl;
  }
  
  //l != liste_vide !( ) ET 1 <= i<k => ième(insérer(l,k, e) ,i) = ième(l,i)
  //k =i => ième(insérer(l,k, e) ,i) = e
  //k< i <= size(l)+1 => ième(insérer(l,k, e) ,i) = ième(l, i-1)
  l1.insert(1, 2.2);
  cout<<"1 elt ajouté: "<<l1[1]<<endl;
  cout<<"size: "<<l1.size()<<endl;
  cout<<"elt preexistant: "<<l1[0]<<endl;
  lister(l1);

  //retrait
  l1.remove(1);
  cout<<"retrait i=1 :"<<endl;
  cout<<"size: "<<l1.size()<<endl;
  lister(l1);

  l1.insert(1, 2.2);
  cout<<"1 elt ajouté: "<<l1[1]<<endl;
  cout<<"size: "<<l1.size()<<endl;
  lister(l1);
 
  cout<<"Ajout de 4 elts"<<endl;
  for(i=2; i < 6; i++){
    l1.insert(i, i*1.1);
  }
  cout<<"size: "<<l1.size()<<endl;
  lister(l1);

  l1.remove(0);
  cout<<"retrait i=0 :"<<endl;
  cout<<"size: "<<l1.size()<<endl;
  lister(l1);
  cout<<"AFECTATION"<<endl;
  l2 = l1;

  l1.remove(2);
  cout<<"retrait i=2 :"<<endl;
  cout<<"size: "<<l1.size()<<endl;
  lister(l1);
  cout<<"RECOPIE"<<endl;
  ListeIterative<double> l3(l1);

  cout<<"supressions: "<<endl;
  supr_list_tout(l1);
  if( l1.isEmpty() )
    cout<<"Liste vidée"<<endl;

  //test coplien
  cout<<"TEst coplien"<<endl<<"affectation"<<endl;
  cout<<"size: "<<l2.size()<<endl;
  lister(l2);
  cout<<"recopie"<<endl;
  cout<<"size: "<<l3.size()<<endl;
  lister(l3);


  return 0;
}
