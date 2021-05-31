//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Librairie STL
//
// Classe list - Tests unitaires de l'operateur =
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
   
      Tests::Design("Controle de la surcharge de l'operateur =", 3);
   
         Tests::Case("Cas d'une liste vide"); {
         list <float> L1, L2(3, 7.5f);
      
            Tests::Unit(3, L2.size());
            L2= L1;
            Tests::Unit(0, L2.size());
         }

         Tests::Case("Cas d'une liste d'entiers"); {
         list <int> L1, L2(15, 0);
      
            L1.push_back(-7);
            L1.push_back(3);
            L1.push_back(-1);
            L1.push_back(8);
            L1.push_back(0);
            L1.push_back(-7);
            L1.push_back(6);
	  
            Tests::Unit(15, L2.size());
            L2= L1;
            Tests::Unit(7, L2.size());
         }

         Tests::Case("Cas d'une liste de messages"); {
         list <string> L1, L2(9, string(""));

            L1.push_back(string("rouge"));       
            L1.push_back(string("jaune"));
            L1.push_back(string("vert"));
            L1.push_back(string("bleu"));       
            L1.push_back(string("blanc"));

            Tests::Unit(9, L2.size());
            L2= L1;
            Tests::Unit(5, L2.size());
         }

         Tests::Case("Cas d'une liste de pointeurs sur messages"); {
         list <char*> L1, L2(1, "...");

            L1.push_back("rouge");       
            L1.push_back("jaune");
            L1.push_back("vert");
            L1.push_back("bleu");       
            L1.push_back("blanc");

            Tests::Unit(1, L2.size());
            L2= L1;
            Tests::Unit(5, L2.size());
         }

   Tests::End();
}

