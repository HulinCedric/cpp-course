//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Vecteur - Tests unitaires des services colineaire, orthogonal,
//                  memeSens ey angle (cas nominaux)
//
// Auteur : A. Thuaire
//
#include "Vecteur.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

Tests::Begin("_Maths.Vecteur", "2.0.0");

      Tests::Design("Controle des services", 3);

      Vecteur* pV0= new Vecteur ();
      Vecteur* pV1= new Vecteur (1, 2);
      Vecteur* pV2= new Vecteur (-2, -4);
      Vecteur* pV3= new Vecteur (-1, 1);
      Vecteur* pV4= new Vecteur (1, 1);
      Vecteur* pV5= new Vecteur (2.75, 2.75);
      Vecteur* pV6= new Vecteur (1, 0);

         Tests::Case("Service colineaire"); {

            Tests::Unit(true,  pV0->colineaire(*pV1));
            Tests::Unit(true,  pV1->colineaire(*pV2));
            Tests::Unit(false, pV3->colineaire(*pV4));
         }

         Tests::Case("Service orthogonal"); {

            Tests::Unit(false, pV1->orthogonal(*pV1));
            Tests::Unit(true,  pV0->orthogonal(*pV1));
            Tests::Unit(false, pV1->orthogonal(*pV2));
            Tests::Unit(true,  pV3->orthogonal(*pV4));
         }

         Tests::Case("Service memeSens"); {

            Tests::Unit(true,  pV0->memeSens(*pV1));
            Tests::Unit(false, pV1->memeSens(*pV2));
            Tests::Unit(true,  pV4->memeSens(*pV5));
         }

         Tests::Case("Service angle"); {
         Angle nul(0, 1), plat(0, -1), droit(1, 0);
         Angle a(PI/4), b(-PI/4), c(3*PI/4);

            Tests::Unit(nul.toString(),   pV1->angle(*pV1)->toString());
            Tests::Unit(plat.toString(),  pV1->angle(*pV2)->toString());
            Tests::Unit(droit.toString(), pV3->angle(*pV4)->toString());
            Tests::Unit(a.toString(),     pV6->angle(*pV4)->toString());
            Tests::Unit(b.toString(),     pV4->angle(*pV6)->toString());
            Tests::Unit(c.toString(),     pV6->angle(*pV3)->toString());
         }

   Tests::End();

}

