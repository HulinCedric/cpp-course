//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe point - Tests unitaires de l'homothetie 
//                (cas nominaux)
//
// Auteur : A. Thuaire
//
#include "Point.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.Point", "2.0.0");

      Tests::Design("Controle des services (5eme partie)", 3);

         Tests::Case("Homothetie par rapport a l'origine"); {
         Point p1(2, 0), p2(3, 2), p3(0.5, -0.5);
         Point* pImage;

            pImage= p1.homothetie(0.5); Tests::Unit("(1, 0)",      pImage->toString());
            pImage= p2.homothetie(2);   Tests::Unit("(6, 4)",      pImage->toString());
            pImage= p3.homothetie(-3);  Tests::Unit("(-1.5, 1.5)", pImage->toString());
         }

         Tests::Case("Homothetie par rapport a un centre quelconque"); {
         Point p1(2, 1), p2(0.5, -0.5), p3(1.25, -0.5);
         Point centre_1(1, 1);
         Point* pImage;

            pImage= p1.homothetie(centre_1, 2);   
            Tests::Unit("(3, 1)",  pImage->toString());

            pImage= p2.homothetie(centre_1, -2);   
            Tests::Unit("(2, 4)",  pImage->toString());

            pImage= p3.homothetie(centre_1, -0.5);   
            Tests::Unit("(0.875, 1.75)",  pImage->toString());
         }
      
    Tests::End();
}
