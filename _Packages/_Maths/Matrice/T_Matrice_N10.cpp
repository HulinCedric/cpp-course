//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2007_2008 - Package _Maths
//
// Classe Matrice - Tests unitaires de la methode transposee
//                  (cas nominaux)
//
// Auteur : A. Thuaire
//
#include "Matrice.h"
#include "T:\_Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.Matrice", "2.1.0");

      Tests::Design("Calcul de la transposee d'une matrice", 2);

         Tests::Case("Cas de matrices 2x2"); {
         Matrice M1(2), attendu_1(2), M2(2), attendu_2(2);

            { int T1[2][2]= {{-1, 2}, { 3, 4}};
              int W1[2][2]= {{-1, 3}, { 2, 4}};
	  
                 M1.remplir(1, T1[0]); 
                 M1.remplir(2, T1[1]);

                 attendu_1.remplir(1, W1[0]); 
                 attendu_1.remplir(2, W1[1]);
            }

            { int T2[2][2]= {{5,  6}, {7, -8}};
              int W2[2][2]= {{5,  7}, {6, -8}};

                 M2.remplir(1, T2[0]); 
                 M2.remplir(2, T2[1]);

                 attendu_2.remplir(1, W2[0]); 
                 attendu_2.remplir(2, W2[1]);
            }

            Tests::Unit(attendu_1.toString(), M1.transposee().toString());
            Tests::Unit(attendu_2.toString(), M2.transposee().toString());
         }

         Tests::Case("Cas de matrices 3x3"); {
         Matrice M1(3), attendu_1(3), M2(3);

            { int T1[3][3]= {{-1, 0, 2}, { 3, -4, 0}, {0, 5, -6}};
              int W1[3][3]= {{-1, 3, 0}, { 0, -4, 5}, {2, 0, -6}};

                 M1.remplir(1, T1[0]); 
                 M1.remplir(2, T1[1]);
                 M1.remplir(3, T1[2]);

                 attendu_1.remplir(1, W1[0]); 
                 attendu_1.remplir(2, W1[1]);
                 attendu_1.remplir(3, W1[2]);
            }

            { int T2[3][3]= {{-1, 0, 0}, {0, -1, 0}, {0, 0, -1} };
	  
                 M2.remplir(1, T2[0]); 
                 M2.remplir(2, T2[1]);
                 M2.remplir(3, T2[2]);
            }

            Tests::Unit(attendu_1.toString(), M1.transposee().toString());
            Tests::Unit(M2.toString(), M2.transposee().toString());
         }

   Tests::End();
}

