//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Librairie STL
//
// Classe list - Tests unitaires des services unique et sort
//               (Cas nominaux)
//
// Auteur : A. Thuaire
//
#pragma warning (disable : 4786)
#include <iostream>
#include <list>
#include <string>
#include <complex>

using namespace std;

#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("STL.list", "?");
   
      Tests::Design("Controle des services", 3);
   
         Tests::Case("Methode unique / Cas d'une liste vide"); {
         list <int> L;

            L.unique();
            Tests::Unit(0,L.size());
         }

         Tests::Case("Methode unique / Cas d'une liste d'entiers"); {
         list <int> L;

            L.push_back(-7);
            L.push_back(3);
            L.push_back(3);
            L.push_back(8);
            L.push_back(8);
            L.push_back(8);
            L.push_back(-6);
	  
            L.unique();
            Tests::Unit(4,L.size());
         }

         Tests::Case("Methode unique / Cas d'une liste de messages"); {
         list <string> L;

            L.push_back(string("rouge"));
            L.push_back(string("jaune"));
            L.push_back(string("jaune"));
            L.push_back(string("jaune"));
            L.push_back(string("rouge"));

            L.unique();
            Tests::Unit(3,L.size());
         }

         Tests::Case("Methode sort / Cas d'une liste d'entiers"); {
         list <int> L;

            L.push_back(-7);
            L.push_back(3);
            L.push_back(-1);
            L.push_back(8);
            L.push_back(0);
            L.push_back(-7);
            L.push_back(6);
	  
            L.sort();
            Tests::Unit(8,L.back());
         }

         Tests::Case("Methode sort / Cas d'une liste de messages"); {
         list <string> L;

            L.push_back(string("rouge"));
            L.push_back(string("jaune"));
            L.push_back(string("vert"));
            L.push_back(string("bleu"));
            L.push_back(string("blanc"));

            L.sort();
            Tests::Unit("blanc",(char*)L.front().c_str());
            Tests::Unit("vert", (char*)L.back().c_str());
         }

   Tests::End();
}

