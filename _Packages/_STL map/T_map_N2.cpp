//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Librairie STL
//
// Classe map - Tests unitaires des methodes de modification
//              (Cas nominaux)
//
// Auteur : A. Thuaire
//
#pragma warning (disable : 4786)
#include <iostream>
#include <map>
#include <string>

using namespace std;

#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("STL.map", "?");
   
      Tests::Design("Controle des methodes de modification", 3);
	  map <string, int> D;

         D["bleu"] = 700;
         D["rouge"]= 200;
         D["jaune"]= 150;

         Tests::Case("Insertion d'un nouvel element"); {
         
            Tests::Unit(3, D.size());
	  
            D["vert"]= 1500;

            Tests::Unit(4, D.size());
         }

         Tests::Case("Modification de la valeur d'un associe"); {
         
            D["rouge"]= 450;
			
            Tests::Unit(450, D["rouge"]);
         }

         Tests::Case("Suppression d'un element"); {

            D.erase("bleu");
            Tests::Unit(3, D.size());

            D.erase("magenta");
            Tests::Unit(3, D.size());
         }

   Tests::End();
}

