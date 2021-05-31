//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2007_2008 - Package _Maths
//
// Classe Matrice - Tests unitaires des constructeurs
//                  (cas nominaux)
//
// Auteur : A. Thuaire
//
#include "Matrice.h"
#include "T:\_Tests\Tests.h"

void main () {
   
   Tests::Begin("_Maths.Matrice", "2.1.0");

      Tests::Design("Controle des constructeurs", 2);

         Tests::Case("Constructeur par defaut / Matrice 1x1"); {
         Matrice M;

            Tests::Unit(1, M.ordre());
         }

         Tests::Case("Constructeur normal / Matrice 2x2"); {
         Matrice M(2);

         int T[2][2]= {{-1, 2}, { 3, 4}};
	  
            M.remplir(1, T[0]); M.remplir(2, T[1]);

            Tests::Unit(2, M.ordre());
         }

	     Tests::Case("Constructeur normal / Matrice 3x3"); {
         Matrice M(3);

         int T[3][3]= {{-1, 0, 1}, { 1, -1, 0}, {0, 1, -1}};
	  
            M.remplir(1, T[0]); M.remplir(2, T[1]); M.remplir(3, T[2]);

            Tests::Unit(3, M.ordre());
         }

         Tests::Case("Constructeur de copie / Matrice 2x2"); {
         Matrice M1(2);
		 Matrice* pM;

         int T[2][2]= {{-1, 2}, { 3, 4}};
	  
            M1.remplir(1, T[0]); M1.remplir(2, T[1]);

            pM= new Matrice(M1); Tests::Unit(M1.toString(), pM->toString());
         }

         Tests::Case("Constructeur de copie / Matrice 3x3"); {
         Matrice M1(3);
         Matrice* pM;

         int T[3][3]= {{-1, 0, 1}, { 1, -1, 0}, {0, 1, -1}};
	  
            M1.remplir(1, T[0]); M1.remplir(2, T[1]); M1.remplir(3, T[2]);

            pM= new Matrice(M1); Tests::Unit(M1.toString(), pM->toString());
         }

   Tests::End();
}
