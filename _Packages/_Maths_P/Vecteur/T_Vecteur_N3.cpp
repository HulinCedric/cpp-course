//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Vecteur - Tests unitaires des operateurs =, == et != 
//                  (cas nominaux)
//
// Auteur : A. Thuaire
//
#include "Vecteur.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.Vecteur", "3.0.0");

      Tests::Design("Controle des operateurs (1ere partie)", 3);

      Vecteur* pV0= new Vecteur ();
      Vecteur* pV1= new Vecteur (1, 2);
      Vecteur* pV2= new Vecteur (1, 2);
      Vecteur* pV3= new Vecteur (-1, 2.25);
      Vecteur* pV4= new Vecteur (-1, -2);

         Tests::Case("Operateur ="); {
         Vecteur V; 

            V= *pV1; Tests::Unit("(1, 2)", V.toString());
            V= *pV3; Tests::Unit("(-1, 2.25)", V.toString());	
            V= *pV4; Tests::Unit("(-1, -2)", V.toString());
         }

         Tests::Case("Operateur =="); {
         
            Tests::Unit(true,  *pV1==*pV2);
            Tests::Unit(false, *pV0==*pV1);
            Tests::Unit(false, *pV3==*pV4);
         }

         Tests::Case("Operateur !="); {
         
            Tests::Unit(false, *pV1!=*pV2);
            Tests::Unit(true,  *pV2!=*pV3);
            Tests::Unit(true,  *pV3!=*pV4);
         }

   Tests::End();

}
