//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Librairie STL
//
// Classe map - Tests unitaires des services unique et sort
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
   
      Tests::Design("Controle des services / Methode find", 3);
   
         Tests::Case("Cas d'une cle absente"); {
         map <string, int> D;
         map <string, int>::iterator i;

            i= D.find("bleu");
            Tests::Unit(true, i==D.end());
         }

         Tests::Case("Cas d'une cle presente"); {
         map <string, int> D;
         map <string, int>::iterator i;

            D["bleu"] = 700;
            D["rouge"]= 300;
            D["blanc"]= 100;

            i= D.find("blanc");
            Tests::Unit(100, i->second);
         }

   Tests::End();
}

