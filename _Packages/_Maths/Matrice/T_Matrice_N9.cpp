//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2007_2008 - Package _Maths
//
// Classe Matrice - Tests unitaires de la methode determinant
//                  (cas nominaux)
//
// Auteur : A. Thuaire
//
#include "Matrice.h"
#include "T:\_Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.Matrice", "2.1.0");

      Tests::Design("Calcul du determinant d'une matrice", 2);

         Tests::Case("Cas de matrices 2x2"); {

         Matrice M1(2), M2(2);

         int T1[2][2]= {{-1, 2}, { 3, 4}};
         int T2[2][2]= {{5,  6}, {7, -8}};
	  
            M1.remplir(1, T1[0]); 
            M1.remplir(2, T1[1]);

            M2.remplir(1, T2[0]); 
            M2.remplir(2, T2[1]);

            Tests::Unit(-10, M1.determinant());
            Tests::Unit(-82, M2.determinant());
         }

         Tests::Case("Cas de matrices 3x3"); {

         Matrice M1(3), M2(3);

         int T1[3][3]= {{-1, 0, 1}, { 1, -1, 0}, {0, 1, -1}};
         int T2[3][3]= {{-1, 0, 0}, {0, -1, 0}, {0, 0, -1} };
	  
            M1.remplir(1, T1[0]); 
            M1.remplir(2, T1[1]);
            M1.remplir(3, T1[2]);

            M2.remplir(1, T2[0]); 
            M2.remplir(2, T2[1]);
            M2.remplir(3, T2[2]);

            Tests::Unit(0,  M1.determinant());
            Tests::Unit(-1, M2.determinant());
         }

   Tests::End();
}

