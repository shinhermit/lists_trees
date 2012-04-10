#include "filei.hpp"
#include <iostream>

using namespace std;

void lister(FileIterative<double> f){
  int i;

  cout<<"( ";
  while( !f.isEmpty() ){
    cout<<f.front();
    cout<<" ";
    f.pop();
  }
  cout<<")"<<endl;
}

void supr_defile_tout(FileIterative<double> & f){
  int i, len;

  lister(f);
  while( !f.isEmpty() ){
    f.pop();
    lister(f);
  }
}

int main()
{
  FileIterative<double> f1;
  int j;
  double i;

  //Axiome:
  //l=liste_vide !( ) <=> size((l) =0
  if(f1.isEmpty())
    cout<<"File vide crée"<<endl;
 
  //l= push(l’,i,e) => size(l) = size(l’) +1
  f1.push(1.1);
  if(!f1.isEmpty()){
    cout<<"1 elt ajouté: "<<f1.front()<<endl;
  }

  //l != file_vide !( ) ET 1 <= i<k => ième(insérer(l,k, e) ,i) = ième(l,i)
  //k =i => ième(insérer(l,k, e) ,i) = e
  //k< i <= size(l)+1 => ième(insérer(l,k, e) ,i) = ième(l, i-1)
  f1.push(2.2);
  cout<<"2.2 ajouté;"<<endl<<" front: "<<f1.front()<<endl;
  lister(f1);

  //defilement
  f1.pop();
  cout<<"defilement."<<endl;
  lister(f1);

  f1.push(2.2);
  cout<<"1 elt ajouté: "<<endl;
  lister(f1);
 
  cout<<"Ajout de 3 elts"<<endl;
  for(i=3; i < 6; i++){
    f1.push(i*1.1);
  }
  lister(f1);

  cout<<"supressions: "<<endl;
  supr_defile_tout(f1);
  if( f1.isEmpty() )
    cout<<"Lile vidée"<<endl;

  return 0;
}
