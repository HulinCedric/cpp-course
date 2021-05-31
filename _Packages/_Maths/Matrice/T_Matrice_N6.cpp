//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2007_2008 - Package _Maths
//
// Classe Matrice - Tests unitaires de l'operateur == (cas nominaux)
//
// Auteur : A. Thuaire
//
#include "Matrice.h"
#include "T:\_Tests\Tests.h"

void main () {

Tests::Begin("_Maths.Matrice", "2.1.0");

      Tests::Design("Surcharges des operateurs == et !=", 2);

         Tests::Case("Comparaison de deux matrices / Matrices 2x2"); {

         Matrice M1(2), M3(2);
         Matrice* pR= new Matrice(2);

         int T1[2][2]= {{-1, 2},  { 3, 4}};
	  
            M1.remplir(1, T1[0]); 
            M1.remplir(2, T1[1]);

            *pR= M1; Tests::Unit(true,  *pR==M1);
                     Tests::Unit(false, M3==M1);
         }

         Tests::Case("Comparaison de deux matrices / Matrices 3x3"); {

         Matrice M1(3), M3(3);
         Matrice* pR= new Matrice(3);

         int T1[3][3]= {{-1, 0, 1}, { 1, -1, 0}, {0, 1, -1}};
	  
            M1.remplir(1, T1[0]); 
            M1.remplir(2, T1[1]);
            M1.remplir(3, T1[1]);

            *pR= M1; Tests::Unit(true,  *pR==M1);
                     Tests::Unit(false, M3==M1);
         }

         Tests::Case("Comparaison d'une matrice par un scalaire"); {

         Matrice M1(3), M2(3);

         int T[3][3]= {{ -2, -1, 1}, {1, -2, 0}, {0, 1, -2}};
         
            M1.remplir(1, T[0]); 
            M1.remplir(2, T[1]);
            M1.remplir(3, T[1]);

            Tests::Unit(false, M1==1);
            Tests::Unit(true,  M2==0);
         }

      Tests::Design("Surcharge de l'operateur !=", 2);

         Tests::Case("Comparaison de deux matrices / Matrices 2x2"); {

         Matrice M1(2), M3(2);
         Matrice* pR= new Matrice(2);

         int T1[2][2]= {{-1, 2},  { 3, 4}};
	  
            M1.remplir(1, T1[0]); 
            M1.remplir(2, T1[1]);

            *pR= M1; Tests::Unit(false,  *pR!=M1);
                     Tests::Unit(true, M3!=M1);
         }

   Tests::End();
}
