//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe LigneBrisee - Tests unitaires des surcharges de l'operateur +=
//                      (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "LigneBrisee.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.LigneBrisee", "3.0.0");

      Tests::Design("Controle des surcharges de l'operateur +=", 3);

         Tests::Case("Cas du premier sommet"); {
         Point O(0, 0);
         LigneBrisee L;

            L += O;

            Tests::Unit(1,         L.cardinal());
            Tests::Unit("(0, 0)",  L.premierSommet()->toString());
            Tests::Unit("(0, 0)",  L.dernierSommet()->toString());
            Tests::Unit(0.,        L.longueur());

         }

         Tests::Case("Cas de deux sommets"); {
         Point O(0, 0), A(1, 0);
         LigneBrisee L;

            L += O;
            L += A;

            Tests::Unit(2,         L.cardinal());
            Tests::Unit("(0, 0)",  L.premierSommet()->toString());
            Tests::Unit("(1, 0)",  L.dernierSommet()->toString());
            Tests::Unit(1.,        L.longueur());
         }

         Tests::Case("Cas de trois sommets"); {
         Point O(0, 0), A(1, 0), B(0, 1);
         LigneBrisee L;

            L += O;
            L += A;
            L += B;

            Tests::Unit(3,         L.cardinal());
            Tests::Unit("(0, 0)",  L.premierSommet()->toString());
            Tests::Unit("(0, 1)",  L.dernierSommet()->toString());
            Tests::Unit(2.414214,  L.longueur(), EPSILON);
         }

         Tests::Case("Cas de plusieurs sommets (premiere forme)"); {
         Point O(0, 0), A(1, 0), B(0, 1), C(-1, 0), D(0, -1);
         LigneBrisee L;

            L += O;
            L += A;
            L += B;
            L += C;
            L += D;

            Tests::Unit(5,         L.cardinal());
            Tests::Unit("(0, 0)",  L.premierSommet()->toString());
            Tests::Unit("(0, -1)", L.dernierSommet()->toString());
            Tests::Unit(5.242641,  L.longueur(), EPSILON);
         }

         Tests::Case("Cas de plusieurs (seconde forme)"); {
         Point* pM= new Point(2.5, -1.75);
         Point* pN= new Point(7, 1.5);
         Point* pO= new Point(0, 0);
         LigneBrisee L;

            L += pM;
            L += pN;
            L += pO;
            
            Tests::Unit(3,              L.cardinal());
            Tests::Unit("(2.5, -1.75)", L.premierSommet()->toString());
            Tests::Unit("(0, 0)",       L.dernierSommet()->toString());
            Tests::Unit(12.709811,      L.longueur(), EPSILON);
         }

         Tests::Case("Cas de plus de dix sommets"); {
         LigneBrisee L;

            for (int i= 0; i < 18; i++) L += new Point(i+1, i-1);

            Tests::Unit(18,         L.cardinal());
            Tests::Unit("(1, -1)",  L.premierSommet()->toString());
            Tests::Unit("(18, 16)", L.dernierSommet()->toString());
            Tests::Unit(24.0416,    L.longueur(), EPSILON);
         }

         Tests::Case("Cas de la reunion de deux lignes brisees"); {
         Point O(0, 0), A(1, 0), B(0, 1), C(-1, 0), D(0, -1);
         LigneBrisee L1;
         LigneBrisee L2;

            L1 += O;
            L1 += A;
            L1 += B;

            L2 += C;
            L2 += D;

            L1 += L2;

            Tests::Unit(5,         L1.cardinal());
            Tests::Unit("(0, 0)",  L1.premierSommet()->toString());
            Tests::Unit("(0, -1)", L1.dernierSommet()->toString());
            Tests::Unit(5.242641,  L1.longueur(), EPSILON);
         }
        
   Tests::End();
}
