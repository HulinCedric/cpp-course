//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Vecteur - Tests unitaires des constructeurs 
//                  (cas nominaux)
//
// Auteur : A. Thuaire
//
#include "Vecteur.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.Vecteur", "3.0.0");

      Tests::Design("Controle des constructeurs", 3);

         Tests::Case("Constructeur par defaut"); {
         Vecteur* pV0= new Vecteur();

            Tests::Unit("(0, 0)",  pV0->toString());
         }

         Tests::Case("Premier constructeur normal"); {
         Vecteur* pV1= new Vecteur (1, 2);
         Vecteur* pV2= new Vecteur (1.5, -2);
         Vecteur* pV3= new Vecteur (-1, 2.25);
         Vecteur* pV4= new Vecteur (-1, -2);
         Vecteur* pV5= new Vecteur (-7.25, 8.45);

            Tests::Unit("(1, 2)",        pV1->toString());
            Tests::Unit("(1.5, -2)",     pV2->toString());
            Tests::Unit("(-1, 2.25)",    pV3->toString());
            Tests::Unit("(-1, -2)",      pV4->toString());
            Tests::Unit("(-7.25, 8.45)", pV5->toString());
         }

         Tests::Case("Second constructeur normal"); {
         RxR z1(1, -2), z2(3, 3);
         Vecteur* pV1= new Vecteur (z1, z2);

            Tests::Unit("(2, 5)",        pV1->toString());
         }

         Tests::Case("Constructeur de copie"); {
         Vecteur* pV1= new Vecteur (1, 2);
         Vecteur* pV2= new Vecteur (1.5, -2);
         Vecteur* pV3= new Vecteur (-1, 2.25);
         Vecteur* pV4= new Vecteur (-1, -2);
         Vecteur* pV5= new Vecteur (-7.25, 8.45);

         Vecteur* pV;

            pV= new Vecteur(*pV1);
            Tests::Unit("(1, 2)", pV->toString());
       
            pV= new Vecteur(*pV2);
            Tests::Unit("(1.5, -2)", pV->toString());

            pV= new Vecteur(*pV3);
            Tests::Unit("(-1, 2.25)", pV->toString());

            pV= new Vecteur(*pV4);
            Tests::Unit("(-1, -2)", pV->toString());

            pV= new Vecteur(*pV5);       
            Tests::Unit("(-7.25, 8.45)", pV->toString());
         }

   Tests::End();       
}
