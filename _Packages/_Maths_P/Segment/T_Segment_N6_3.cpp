//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Segment - Tests unitaires de la methode homothetie
//                  (cas nominaux)
//
// Auteur : A. Thuaire
//
#include "Segment.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.Segment", "3.0.0");

      Tests::Design("Controle des transformations du plan (3eme partie)", 3);

         Tests::Case("Homothetie par rapport a l'origine"); {
         Point A(2, 0), B(3, 2), C(0.5, -0.5);	
         Segment AB(A, B), BC(B, C), AC(A, C);
         Segment* pImage;

            pImage= AB.homothetie(2);	 
            Tests::Unit("[(4, 0), (6, 4)]", pImage->toString());

            pImage= BC.homothetie(0.5); 
            Tests::Unit("[(1.5, 1), (0.25, -0.25)]", pImage->toString());

            pImage= AC.homothetie(-1.5); 
            Tests::Unit("[(-3, 0), (-0.75, 0.75)]", pImage->toString());
         }

         Tests::Case("Homothetie par rapport a un centre quelconque"); {
         Point A(2, 1), B(0.5, -0.5), C(1.25, -0.5);
         Segment AB(A, B), BC(B, C), AC(A, C);

         Point centre(1, 1);
         Segment* pImage;

            pImage= AB.homothetie(centre, 2);   
            Tests::Unit("[(3, 1), (0, -2)]",    pImage->toString());

            pImage= AC.homothetie(centre, 2);   
            Tests::Unit("[(3, 1), (1.5, -2)]",  pImage->toString());

            pImage= BC.homothetie(centre, 2);   
            Tests::Unit("[(0, -2), (1.5, -2)]", pImage->toString());

            pImage= AB.homothetie(centre, -2);   
            Tests::Unit("[(-1, 1), (2, 4)]",  pImage->toString());

            pImage= BC.homothetie(centre, -0.5);   
            Tests::Unit("[(1.25, 1.75), (0.875, 1.75)]",  pImage->toString());
         }
 
   Tests::End();
}
