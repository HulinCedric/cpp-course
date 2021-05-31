//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2007_2008 - Package _Maths
//
// Classe Matrice - Tests unitaires des surcharges des operateurs () et []
//                  (cas nominaux)
//
// Auteur : A. Thuaire
//
#include "Matrice.h"
#include "T:\_Tests\Tests.h"

void main () {
   
   Tests::Begin("_Maths.Matrice", "2.1.0");

      Tests::Design("Surcharges des operateurs () et []", 2);

      Matrice M1(2), M2(3);

      int T1[2][2]= {{-1, 2}, { 3, 4}};
      int T2[3][3]= {{-1, 0, 1}, { 1, -1, 0}, {0, 1, -1}};

         M1.remplir(1, T1[0]); 
         M1.remplir(2, T1[1]);

         M2.remplir(1, T2[0]); 
         M2.remplir(2, T2[1]);
         M2.remplir(3, T2[2]);

         Tests::Case("Operateur () - 1ere forme / Matrice 2x2"); {

            Tests::Unit(-1, M1(1, 1));
            Tests::Unit(2,  M1(1, 2));
            Tests::Unit(3,  M1(2, 1));
            Tests::Unit(4,  M1(2, 2));
         }

         Tests::Case("Operateur () - 1ere forme / Matrice 3x3"); {

            Tests::Unit(-1, M2(1, 1));
            Tests::Unit(0,  M2(1, 2));
            Tests::Unit(1,  M2(1, 3));

            Tests::Unit(-1, M2(2, 2));

            Tests::Unit(1,  M2(3, 2));
         }

         Tests::Case("Operateur () - 2eme forme / Matrice 2x2"); {
         int* pR;

            pR= M1(1); Tests::Unit(-1, pR[0]);
            pR= M1(2); Tests::Unit(4,  pR[1]);
         }

         Tests::Case("Operateur () - 2eme forme / Matrice 3x3"); {
         int* pR;

            pR= M2(1); Tests::Unit(-1, pR[0]);
            pR= M2(2); Tests::Unit(-1, pR[1]);
            pR= M2(3); Tests::Unit(-1, pR[2]);
                       Tests::Unit(1,  pR[1]);
         }

         Tests::Case("Operateur () - 3eme forme / Matrice 2x2"); {

                          Tests::Unit(-1, M1(1, 1));           
            M1(1, 1)= -4; Tests::Unit(-4, M1(1, 1));
			M1(1, 1)= -1;
         }

         Tests::Case("Operateur () - 3eme forme / Matrice 3x3"); {

            
                         Tests::Unit(1,  M2(1, 3));
            M2(1, 3)= 7; Tests::Unit(7,  M2(1, 3));
            M2(1, 3)= 1;
         }

         Tests::Case("Operateur [] / Matrice 2x2"); {
         int* pR;

            pR= M1[1]; Tests::Unit(-1, pR[0]);
            pR= M1[2]; Tests::Unit(4,  pR[1]);
         }

         Tests::Case("Operateur [] / Matrice 3x3"); {
         int* pR;         

            pR= M2[1]; Tests::Unit(-1, pR[0]);
            pR= M2[2]; Tests::Unit(-1, pR[1]);
            pR= M2[3]; Tests::Unit(-1, pR[2]);
                       Tests::Unit(1,  pR[0]);
         }

   Tests::End();
}
