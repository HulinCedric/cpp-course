//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2007_2008 - Package _Maths
//
// Classe MatriceF - Tests unitaires de l'operateur =
//                   (cas nominaux)
//
// Auteur : A. Thuaire
//
#include "MatriceF.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

Tests::Begin("_Maths.MatriceF", "2.1.0");

      Tests::Design("Surcharges de l'operateur =", 2);

         Tests::Case("Affectation d'une matrice / Matrices 2x2"); {

         MatriceF M1(2);
         MatriceF* pR= new MatriceF(2);

         int T1[2][2]= {{-1, 2},  { 3, 4}};
	  
            M1.remplir(1, T1[0]); 
            M1.remplir(2, T1[1]);

            *pR= M1; Tests::Unit(M1.toString(), pR->toString());
         }

         Tests::Case("Affectation d'une matrice / Matrices 3x3"); {

         MatriceF M1(3);
         MatriceF* pR= new MatriceF(3);

         int T1[3][3]= {{-1, 0, 1}, { 1, -1, 0}, {0, 1, -1}};
	  
            M1.remplir(1, T1[0]); 
            M1.remplir(2, T1[1]);
            M1.remplir(3, T1[1]);

            *pR= M1; Tests::Unit(M1.toString(), pR->toString());
         }

         Tests::Case("Affectation d'une matrice par un scalaire / Matrices 3x3"); {

         MatriceF attendu(3);
         MatriceF* pR= new MatriceF(3);

         int W[3][3]= {{ 3, 3, 3}, {3, 3, 3}, {3, 3, 3}};
         
            attendu.remplir(1, W[0]); 
            attendu.remplir(2, W[1]);
            attendu.remplir(3, W[1]);

            *pR= 3; Tests::Unit(attendu.toString(), pR->toString());
         }

   Tests::End();
}
