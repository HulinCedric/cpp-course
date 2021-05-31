//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Point - Tests unitaires des constructeurs 
//                (cas nominaux)
//
// Auteur : A. Thuaire
//
#include "Point.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.Point", "2.0.0");

      Tests::Design("Controle de la construction", 3);

         Tests::Case("Constructeur par defaut"); {
         Point p0;

            Tests::Unit("(0, 0)",   p0.toString());
         }
	
         Tests::Case("Premier constructeur normal"); {
         Point p1(1,2), p2(1, -2), p3(-1, 2), p4(-1, -2);
         Point p5(-7.25, 8.45);

            Tests::Unit("(1, 2)",   p1.toString());
            Tests::Unit("(1, -2)",  p2.toString());
            Tests::Unit("(-1, 2)",  p3.toString());
            Tests::Unit("(-1, -2)", p4.toString());

            Tests::Unit("(-7.25, 8.45)", p5.toString());
         }

		 Tests::Case("Second constructeur normal"); {
         Point p1(1,1,2), p2(2, 1, -2), p3(3, -1, 2), p4(4, -1, -2);
         Point p5(5, -7.25, 8.45);

            Tests::Unit("[1] (1, 2)",   p1.toString());
            Tests::Unit("[2] (1, -2)",  p2.toString());
            Tests::Unit("[3] (-1, 2)",  p3.toString());
            Tests::Unit("[4] (-1, -2)", p4.toString());
            Tests::Unit("[5] (-7.25, 8.45)", p5.toString());
         }

   Tests::End();
}
