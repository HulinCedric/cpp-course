//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Point - Tests unitaires de la symetrie centrale
//                (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "Point.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.Point", "3.0.0");

      Tests::Design("Controle des services (4eme partie)", 3);

         Tests::Case("Symetrie centrale par rapport a l'origine"); {
         Point p1(2, 0), p2(3, 2), p3(0.5, -0.5);
         Point* pImage;

            pImage= p1.symetrie(); Tests::Unit("(-2, 0)",     pImage->toString());
            pImage= p2.symetrie(); Tests::Unit("(-3, -2)",    pImage->toString());
            pImage= p3.symetrie(); Tests::Unit("(-0.5, 0.5)", pImage->toString());
         }

         Tests::Case("Symetrie centrale par rapport a un centre quelconque"); {
         Point p0(0, 0), p1(1, 0), p2(0, 1), p3(-0.5, 0.5);
         Point centre_1(1, 1), centre_2(-1.75, 0);
         Point* pImage;

            pImage= p0.symetrie(centre_1); 
            Tests::Unit("(2, 2)",  pImage->toString());

            pImage= p1.symetrie(centre_1); 
            Tests::Unit("(1, 2)",  pImage->toString());

            pImage= p2.symetrie(centre_1); 
            Tests::Unit("(2, 1)",  pImage->toString());

            pImage= p3.symetrie(centre_1); 
            Tests::Unit("(2.5, 1.5)",  pImage->toString());

            pImage= p0.symetrie(centre_2); 
            Tests::Unit("(-3.5, 0)",  pImage->toString());
         }
      
   Tests::End();
}
