//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2007_2008 - Package _Maths
//
// Classe MatriceF - Tests unitaires de l'operateur -=
//                   (cas nominaux)
//
// Auteur : A. Thuaire
//
#include "MatriceF.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

Tests::Begin("_Maths.MatriceF", "2.1.0");

      Tests::Design("Surcharges de l'operateur -=", 2);

         Tests::Case("Soustraction de deux matrices / Matrices 2x2"); {

         MatriceF M1(2), M2(2), attendu(2);

         int T1[2][2]= {{-1, 2}, { 3, 4}};
         int T2[2][2]= {{5,  6}, {7, -8}};
         int T3[2][2]= {{ -6,  -4}, {-4, 12}};
	  
            M1.remplir(1, T1[0]); 
            M1.remplir(2, T1[1]);

            M2.remplir(1, T2[0]); 
            M2.remplir(2, T2[1]);

            attendu.remplir(1, T3[0]); 
            attendu.remplir(2, T3[1]);

            M1-= M2; Tests::Unit(attendu.toString(), M1.toString());
         }

         Tests::Case("Soustraction de deux matrices / Matrices 3x3"); {

         MatriceF M1(3), M2(3), attendu(3);

         int T1[3][3]= {{-1, 0, 1}, { 1, -1, 0}, {0, 1, -1}};
         int T2[3][3]= {{-1, 0, 0}, {0, -1, 0}, {0, 0, -1} };
         int T3[3][3]= {{ 0, 0, 1}, {1, 0, 0}, {0, 1, 0}};
	  
            M1.remplir(1, T1[0]); 
            M1.remplir(2, T1[1]);
            M1.remplir(3, T1[2]);

            M2.remplir(1, T2[0]); 
            M2.remplir(2, T2[1]);
            M2.remplir(3, T2[2]);

            attendu.remplir(1, T3[0]); 
            attendu.remplir(2, T3[1]);
            attendu.remplir(3, T3[2]);

            M1-= M2; Tests::Unit(attendu.toString(), M1.toString());
         }

         Tests::Case("Soustraction d'un scalaire a une matrice / Matrice 3x3"); {

         MatriceF M(3), attendu(3);

         int T[3][3]= {{ -2, 0, 1}, {1, -2, 0}, {0, 1, -2}};
         int W[3][3]= {{ -4, -2, -1}, {-1, -4, -2}, {-2, -1, -4}};
         
            M.remplir(1, T[0]); 
            M.remplir(2, T[1]);
            M.remplir(3, T[2]);

            attendu.remplir(1, W[0]); 
            attendu.remplir(2, W[1]);
            attendu.remplir(3, W[2]);

            M-= 2; Tests::Unit(attendu.toString(), M.toString());
         }

   Tests::End();
}
