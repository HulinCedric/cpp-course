//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Librairie STL
//
// Classe map - Tests unitaires des constructeurs
//               (Cas nominaux)
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
   
      Tests::Design("Controle de la construction", 3);
   
         Tests::Case("Creer un dictionnaire vide"); {
         map <string, int> D;
	  
            Tests::Unit(0, D.size());
            Tests::Unit(true, D.empty());
         }

         Tests::Case("Creer un dictionnaire d'abonnes"); {
         map <string, char*> abonnes;

            abonnes["Dupond"]= "04.93.60.20.14";
            abonnes["Durand"]= "04.93.70.30.27";
            abonnes["Dupuy"] = "04.93.36.22.11";
	  
            Tests::Unit(3, abonnes.size());
            Tests::Unit("04.93.70.30.27", abonnes["Durand"]);
            Tests::Unit("04.93.60.20.14", abonnes["Dupond"]);
         }

         Tests::Case("Creer un dictionnaire de nombres reels"); {
         map <string, double> D;

            D["ASR2"]   = 12.5;
            D["API"]    = 17;
            D["Anglais"]= 14.25;
            D["OMGL_1"] = 10;

            Tests::Unit(4, D.size());
            Tests::Unit(17., D["API"]);
         }

         Tests::Case("Creer un dictionnaire de points du plan"); {
         complex <double> z0(0, 0), z1(3.5, 2), z2(0, -1), z3(1, 1), z4(1.25, 4);
         map <string, complex <double> > D;
         complex <double> z;

            D["O"]= z0;
            D["A"]= z1;
            D["B"]= z2;
            D["C"]= z3;
	  
            Tests::Unit(4, D.size());

            z= D["O"];
            Tests::Unit(0., z.real());
            Tests::Unit(0, (int)z.imag());

            z= D["A"];
            Tests::Unit(3.5, z.real());
            Tests::Unit(2.,  z.imag());
         }
/*
		 Tests::Case("Creer le dictionnaire inverse du precedent"); {
         complex <double> z0(0, 0), z1(3.5, 2), z2(0, -1), z3(1, 1), z4(1.25, 4);
         map <complex <double>, string> inverse;

            inverse[z0]= "O";
            inverse[z1]= "A";
            inverse[z2]= "B";

            Tests::Unit(3, inverse.size());
         }
*/
   Tests::End();
}

