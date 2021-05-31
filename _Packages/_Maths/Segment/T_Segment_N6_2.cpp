//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Segment - Tests unitaires de la methode symetrie
//                  (cas nominaux)
//
// Auteur : A. Thuaire
//
#include "Segment.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.Segment", "2.0.0");

      Tests::Design("Controle des transformations du plan (2eme partie)", 3);

         Tests::Case("Symetrie centrale par rapport a l'origine"); {
         Point A(2, 0), B(3, 2), C(0.5, -0.5);	
         Segment AB(A, B), BC(B, C), AC(A, C);
         Segment* pImage;

            pImage= AB.symetrie();	 
            Tests::Unit("[(-2, 0), (-3, -2)]", pImage->toString());

            pImage= BC.symetrie(); 
            Tests::Unit("[(-3, -2), (-0.5, 0.5)]", pImage->toString());

            pImage= AC.symetrie(); 
            Tests::Unit("[(-2, 0), (-0.5, 0.5)]", pImage->toString());
         }

         Tests::Case("Symetrie centrale par rapport a un centre quelconque"); {
         Point O(0, 0), A(1, 0), B(0, 1), C(-0.5, 0.5);
         Segment OA(O, A), OB(O, B), AB(A, B), BC(B, C), AC(A, C);

         Point centre(1, 1);
         Segment* pImage;

            pImage= OA.symetrie(centre); 
            Tests::Unit("[(2, 2), (1, 2)]",  pImage->toString());

            pImage= OB.symetrie(centre); 
            Tests::Unit("[(2, 2), (2, 1)]",  pImage->toString());

            pImage= AB.symetrie(centre); 
            Tests::Unit("[(1, 2), (2, 1)]",  pImage->toString());

            pImage= BC.symetrie(centre); 
            Tests::Unit("[(2, 1), (2.5, 1.5)]",  pImage->toString());

            pImage= AC.symetrie(centre); 
            Tests::Unit("[(1, 2), (2.5, 1.5)]",  pImage->toString());
         }
 
   Tests::End();
}
