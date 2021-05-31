//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2007_2008 - Package _Maths
//
// Classe Segment - Tests unitaires de la methode rotation
//                  (cas nominaux)
//
// Auteur : A. Thuaire
//
#include "Segment.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.Segment", "2.0.0");

      Tests::Design("Controle des transformations du plan (1ere partie)", 3);

         Tests::Case("Rotation d'un segment par rapport a l'origine"); {
         Point A(2, 0), B(3, 2), C(0.5, -0.5);	
         Segment AB(A, B), BC(B, C), AC(A, C);
         Segment* pImage;

            pImage= AB.rotation(PI);	 
            Tests::Unit("[(-2, 0), (-3, -2)]",     pImage->toString());

            pImage= BC.rotation(PI); 
            Tests::Unit("[(-3, -2), (-0.5, 0.5)]", pImage->toString());

            pImage= AC.rotation(PI); 
            Tests::Unit("[(-2, 0), (-0.5, 0.5)]",  pImage->toString());

            pImage= AB.rotation(PI/2); 
            Tests::Unit("[(0, 2), (-2, 3)]",       pImage->toString());

            pImage= BC.rotation(PI/2);
            Tests::Unit("[(-2, 3), (0.5, 0.5)]",   pImage->toString());

            pImage= AC.rotation(PI/2); 
            Tests::Unit("[(0, 2), (0.5, 0.5)]",    pImage->toString());
         }

         Tests::Case("Cas de l'IE du 22 Mars 2008"); {
         Point O(0, 0), A(0, 2), B(-2, 0), C(2, 0);	
         Segment OA(O, A), OB(O, B), AB(A, B), AC(A, C);
         Segment* pImage;

            pImage= OA.rotation(PI);	 
            Tests::Unit("[(0, 0), (0, -2)]", pImage->toString());

            pImage= OB.rotation(-PI);	 
            Tests::Unit("[(0, 0), (2, 0)]",  pImage->toString());

            pImage= AB.rotation(PI/2);	 
            Tests::Unit("[(-2, 0), (0, -2)]", pImage->toString());

            pImage= AC.rotation(PI/2);	 
            Tests::Unit("[(-2, 0), (0, 2)]", pImage->toString());

            pImage= OB.rotation(-PI/4);	 
            Tests::Unit("[(0, 0), (-1.41421, 1.41421)]", pImage->toString());
         }

         Tests::Case("Rotation d'un segment par rapport un centre quelconque"); {
         Point A(2, 0), B(3, 2), C(0.5, -0.5), D(2.5, -0.5);
         Segment AB(A, B), BC(B, C), CD(C, D);
         
         Point centre(2.5, -0.5); 
         Segment* pImage;

         pImage= AB.rotation(centre, PI);    
         Tests::Unit("[(3, -1), (2, -3)]", pImage->toString());

         pImage= BC.rotation(centre, PI);    
         Tests::Unit("[(2, -3), (4.5, -0.5)]", pImage->toString());

         pImage= CD.rotation(centre, PI);    
         Tests::Unit("[(4.5, -0.5), (2.5, -0.5)]", pImage->toString());

         pImage= AB.rotation(centre, PI/2);    
         Tests::Unit("[(2, -1), (0, 0)]", pImage->toString());

         pImage= BC.rotation(centre, PI/2);    
         Tests::Unit("[(0, 0), (2.5, -2.5)]", pImage->toString());

         pImage= AB.rotation(centre, -PI/4);    
         Tests::Unit("[(2.5, 0.207107), (4.62132, 0.914214)]", pImage->toString());

         pImage= BC.rotation(centre, -PI/4);    
         Tests::Unit("[(4.62132, 0.914214), (1.08579, 0.914214)]", pImage->toString());

         pImage= AB.rotation(centre, 2*PI);    
         Tests::Unit("[(2, 0), (3, 2)]", pImage->toString());

         pImage= BC.rotation(centre, 2*PI);    
         Tests::Unit("[(3, 2), (0.5, -0.5)]", pImage->toString());
      }

 
   Tests::End();
}
