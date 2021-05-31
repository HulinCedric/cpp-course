//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Point - Tests unitaires de la translation 
//                (cas nominaux)
//
// Auteur : A. Thuaire
//
#include "Point.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.Point", "3.0.0");

      Tests::Design("Controle des services (2eme partie)", 3);

         Tests::Case("Translation de vecteur V quelconque"); {
         Point p1(2, 0), p2(3, 2), p3(0.5, -0.5);
         Vecteur V1(1,0), V2(1, 1), V3(-1, -1);
         Point* pImage;

            pImage= p1.translation(V1); Tests::Unit("(3, 0)",       pImage->toString());
            pImage= p2.translation(V2); Tests::Unit("(4, 3)",       pImage->toString());
            pImage= p3.translation(V3); Tests::Unit("(-0.5, -1.5)", pImage->toString());
         }
      
   Tests::End();
}
