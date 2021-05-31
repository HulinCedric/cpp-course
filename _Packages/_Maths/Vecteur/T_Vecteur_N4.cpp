//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Vecteur - Tests unitaires des operateurs +, - et * 
//                  (cas nominaux)
//
// Auteur : A. Thuaire
//
#include "Vecteur.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.Vecteur", "2.0.0");

      Tests::Design("Controle des operateurs (2eme partie)", 3);

      Vecteur* pV0= new Vecteur ();
      Vecteur* pV1= new Vecteur (1, 2);
      Vecteur* pV2= new Vecteur (1, 2);
      Vecteur* pV3= new Vecteur (-1, 2.25);
      Vecteur* pV4= new Vecteur (-1, -2);

         Tests::Case("Operateur +"); {
         Vecteur* pV;

            pV= *pV0 + *pV1; Tests::Unit("(1, 2)",    pV->toString());
            pV= *pV2 + *pV4; Tests::Unit("(0, 0)",    pV->toString());
            pV= *pV1 + *pV3; Tests::Unit("(0, 4.25)", pV->toString());
         }

         Tests::Case("Operateur -"); {
         Vecteur* pV;

            pV= *pV1 - *pV0; Tests::Unit("(1, 2)",     pV->toString());
            pV= *pV1 - *pV2; Tests::Unit("(0, 0)",     pV->toString());
            pV= *pV1 - *pV3; Tests::Unit("(2, -0.25)", pV->toString());
         }

         Tests::Case("Operateur * : produit par un reel"); {
         Vecteur* pV;

            pV= *pV0 * 2;    Tests::Unit("(0, 0)",           pV->toString());
            pV= *pV1 * 2.5;  Tests::Unit("(2.5, 5)",         pV->toString());
            pV= *pV3 * 4.75; Tests::Unit("(-4.75, 10.6875)", pV->toString());
         }

         Tests::Case("Operateur * : produit scalaire"); {

            Tests::Unit(0.,*pV0 * *pV1);
            Tests::Unit(5.,*pV2 * *pV1);
            Tests::Unit(-3.5,*pV3 * *pV4);
         }

   Tests::End();

}
