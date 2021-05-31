//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Vecteur - Tests unitaires des accesseurs de consultation 
//                  (cas nominaux)
//
// Auteur : A. Thuaire
//
#include "Vecteur.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.Vecteur", "3.0.0");

      Tests::Design("Controle des accesseurs", 3);

      Vecteur* pV0= new Vecteur ();
      Vecteur* pV1= new Vecteur (1, 2);
      Vecteur* pV2= new Vecteur (1.5, -2);
      Vecteur* pV3= new Vecteur (-1, 2.25);
      Vecteur* pV4= new Vecteur (-1, -2);

         Tests::Case("Accesseur abscisse"); {

         Tests::Unit(0,   (int)pV0->abscisse());
         Tests::Unit(1,   (int)pV1->abscisse());      
         Tests::Unit(1.5, pV2->abscisse()); 
      }

      Tests::Case("Accesseur ordonnee"); {

         Tests::Unit(0,  (int)pV0->ordonnee());
         Tests::Unit(2,  (int)pV1->ordonnee());      
         Tests::Unit(-2, (int)pV2->ordonnee()); 
      }

      Tests::Case("Accesseur norme"); {

         Tests::Unit(0,       (int)pV0->norme());
         Tests::Unit(sqrt(5), pV1->norme());      
         Tests::Unit(2.5,     pV2->norme()); 
      }

   Tests::End();       
}
