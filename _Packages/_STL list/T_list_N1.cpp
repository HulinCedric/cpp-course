//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Librairie STL
//
// Classe list - Tests unitaires des constructeurs
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
   
      Tests::Design("Controle de la construction", 3);
   
         Tests::Case("Creer une liste vide"); {
         list <int> L;
	  
            Tests::Unit(0, L.size());
            Tests::Unit(true, L.empty());
         }

         Tests::Case("Creer une liste de nombres entiers"); {
         list <int> L;
         list <int>::iterator i=L.begin();

            L.push_back(-7);
            L.push_back(3);
            L.push_back(-1);
            L.push_back(8);
            L.push_back(0);
            L.push_back(-7);
            L.push_back(6);
	  
            Tests::Unit(7, L.size());
            Tests::Unit(-7,L.front());
            Tests::Unit(6, L.back());

            for (int rang=1; rang<=4; rang++, i++);

            Tests::Unit(8, *i);
         }

         Tests::Case("Creer une liste de messages"); {
         list <string> L;
         list <string>::iterator i=L.begin();

         char* pM=NULL;

            L.push_back(string("rouge"));
            L.push_back(string("jaune"));
            L.push_back(string("vert"));
            L.push_back(string("bleu"));
            L.push_back(string("blanc"));
	  
            Tests::Unit(5, L.size());

            pM= (char*)(*++i).c_str();
            Tests::Unit("rouge", pM);

            i=L.end(); i--;
            pM= (char*)(*--i).c_str();
            Tests::Unit("bleu", pM);
         }

         Tests::Case("Creer une liste de nombres complexes"); {
         complex <double> z1(3.5, 2), z2(0, -1), z3(1, 1), z4(1.25, 4);
         list < complex <double> > L;
         complex <double> z;

            L.push_back(z1);
            L.push_back(z2);
            L.push_back(z3);
            L.push_back(z4);
	  
            Tests::Unit(4, L.size());

            z=L.front();
            Tests::Unit(3.5, z.real());
            Tests::Unit(2, (int)z.imag());

            z=L.back();
            Tests::Unit(1.25, z.real());
            Tests::Unit(4, (int)z.imag());
         }

   Tests::End();
}

