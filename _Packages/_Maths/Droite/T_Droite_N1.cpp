//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Droite - Tests unitaires des constructeurs
//                 (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "Droite.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.Droite", "2.0.0");

      Tests::Design("Controle des constructeurs", 3);


         Tests::Case("Cas du constructeur par defaut"); {
         Droite d;

            Tests::Unit("[1, 0, 0]",  d.toString());
         }

         Tests::Case("Cas particulier d'une droite horizontale"); {
         Droite d1(1, 0, 0.5), d2(-2, 0, 1), d3(1.23, 0, 0);

            Tests::Unit("[1, 0, 0.5]",  d1.toString());
            Tests::Unit("[-2, 0, 1]",   d2.toString());
            Tests::Unit("[1.23, 0, 0]", d3.toString());
         }

         Tests::Case("Cas particulier d'une droite verticale"); {
         Droite d1(0, 1, -2.5), d2(0, -2, 1), d3(0, 1.25, 0);
         
            Tests::Unit("[0, 1, -2.5]", d1.toString());
            Tests::Unit("[0, -2, 1]",   d2.toString());
            Tests::Unit("[0, 1.25, 0]", d3.toString());
         }

         Tests::Case("Cas general d'une droite quelconque"); {
         Droite d1(2, 1, -2.5), d2(-3, -2, 1), d3(1.5, 1.25, 0);

            Tests::Unit("[2, 1, -2.5]",   d1.toString());
            Tests::Unit("[-3, -2, 1]",    d2.toString());
            Tests::Unit("[1.5, 1.25, 0]", d3.toString()); 
         }
     
   Tests::End();
}
