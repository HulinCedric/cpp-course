//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Librairie STL
//
// Classe map - Tests unitaires de l'operateur ==
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
   
      Tests::Design("Controle de la surcharge de l'operateur ==", 3);
   
         Tests::Case("Cas de dictionnaires vides"); {
         map <string, int> D1, D2;

            Tests::Unit(true,  D1==D2);
         }

         Tests::Case("Cas de dictionnaires de meme taille"); {
         map <string, int> D1, D2;
      
            D1["bleu"] = 700;
            D2["bleu"] = 300;
	  
            Tests::Unit(false, D1==D2);

            D2["bleu"] = 700;
	  
            Tests::Unit(true,  D1==D2);
         }

         Tests::Case("Cas de dictionnaires de tailles differentes"); {
         map <string, int> D1, D2;
      
            D1["bleu"] = 700;
            D1["rouge"]= 300;

            D2["rouge"]= 300;
            Tests::Unit(false, D1==D2);

            D2["bleu"] = 700;
            Tests::Unit(true,  D1==D2);

            D1["jaune"] = -100;
            Tests::Unit(false,  D1==D2);
         }

         Tests::Case("Cas d'un dictionnaire de pointeurs !"); {
         map <string, char*> D1, D2;

            D1["bleu"]= "France";
            D1["vert"]= "Italie";

            D2["vert"]= "Italie";
            D1["bleu"]= "France";

            Tests::Unit(false, D1==D2);
         }

   Tests::End();
}

