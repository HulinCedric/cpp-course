//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Point - Tests unitaires de la rotation
//                (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "Point.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.Point", "3.0.0");

      Tests::Design("Controle des service (3eme partie)", 3);

         Tests::Case("Rotation par rapport a l'origine"); {
         Point p1(2, 0), p2(3, 2), p3(0.5, -0.5);
         Point* pImage;

            pImage= p1.rotation(PI); Tests::Unit("(-2, 0)",      pImage->toString());
            pImage= p2.rotation(PI); Tests::Unit("(-3, -2)",     pImage->toString());
            pImage= p3.rotation(PI); Tests::Unit("(-0.5, 0.5)",  pImage->toString());

            pImage= p1.rotation(PI/2); Tests::Unit("(0, 2)",     pImage->toString());
            pImage= p2.rotation(PI/2); Tests::Unit("(-2, 3)",    pImage->toString());
            pImage= p3.rotation(PI/2); Tests::Unit("(0.5, 0.5)", pImage->toString());

            pImage= p1.rotation(PI/4); Tests::Unit("(1.41421, 1.41421)",   pImage->toString());
            pImage= p2.rotation(PI/4); Tests::Unit("(0.707107, 3.53553)",  pImage->toString());
            pImage= p3.rotation(PI/4); Tests::Unit("(0.707107, 0)",        pImage->toString());
       
            pImage= p1.rotation(-PI); Tests::Unit("(-2, 0)",      pImage->toString());
            pImage= p2.rotation(-PI); Tests::Unit("(-3, -2)",     pImage->toString());
            pImage= p3.rotation(-PI); Tests::Unit("(-0.5, 0.5)",  pImage->toString());
         }
		 
         Tests::Case("Rotation par rapport a un centre quelconque"); {
         Point p0(0, 0), p1(1, 0), p2(0, 1), p3(-0.5, 0.5);
         Point centre_1(1, 1), centre_2(-1.75, 0);
         Point* pImage;

            pImage= p0.rotation(centre_1, PI); 
            Tests::Unit("(2, 2)",  pImage->toString());

            pImage= p1.rotation(centre_1, PI); 
            Tests::Unit("(1, 2)",  pImage->toString());

            pImage= p2.rotation(centre_1, PI); 
            Tests::Unit("(2, 1)",  pImage->toString());

            pImage= p3.rotation(centre_1, PI); 
            Tests::Unit("(2.5, 1.5)",  pImage->toString());

            pImage= p0.rotation(centre_2, PI/2); 
            Tests::Unit("(-1.75, 1.75)",  pImage->toString());

            pImage= p1.rotation(centre_2, -PI/2); 
            Tests::Unit("(-1.75, -2.75)",  pImage->toString());

            pImage= p2.rotation(centre_2, PI/3); 
            Tests::Unit("(-1.74103, 2.01554)",  pImage->toString());
         }
      
   Tests::End();
}
