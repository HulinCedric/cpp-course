//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Librairie STL
//
// Classe map - Tests unitaires de l'operateur =
//              (Cas nominaux)
//
// Auteur : A. Thuaire
//
#pragma warning (disable : 4786)
#include <iostream>
#include <map>
#include <string>
#include <complex>

using namespace std;

#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("STL.map", "?");
   
      Tests::Design("Controle de la surcharge de l'operateur =", 3);

         Tests::Case("Cas d'un dictionnaire vide"); {
         map <string, int> D1, D2;

            D1["bleu"] = 700;
            D1["rouge"]= 200;
            D1["jaune"]= 150;
      
            Tests::Unit(0, D2.size());

            D2= D1;

            Tests::Unit(3, D2.size());
         }

         Tests::Case("Cas de cles complementaires"); {
         map <string, int> D1, D2;

            D1["bleu"] = 700;
            D1["rouge"]= 200;

            D2["jaune"]= -500;
            D2["vert"] = -300;

            D2= D1;

            Tests::Unit(2, D2.size());
         }

         Tests::Case("Cas de cles communes"); {
         map <string, int> D1, D2;

            D1["bleu"] = 700;
            D1["rouge"]= 200;
            D1["jaune"]= 150;
      
            D2["bleu"] = -700;
            D2["rouge"]= -200;
            D2["jaune"]= -150;
	  
            D2= D1;
            Tests::Unit(3, D2.size());
            Tests::Unit(700, D2["bleu"]);
         }

   Tests::End();
}

