//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Triangle - Tests unitaires des operateurs
//                   (Cas nominaux)
//
// Auteur : C.Fouco
//
#include "Triangle.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.Triangle", "2.1.0");

      Tests::Design("Controle des operateurs", 3);

         Tests::Case("Controle de l'operateur ="); {
         Point O(0,0), A(0,2), B(-2,0), C(2, 0), D(0,-2);
         Triangle ABC(A, B, C), CDB(C, D, B);
         Triangle W= *new Triangle(O, A, B);
         Triangle T;

            W= ABC; Tests::Unit("[(0, 2), (-2, 0), (2, 0)]",  W.toString());
            W= CDB; Tests::Unit("[(2, 0), (0, -2), (-2, 0)]", W.toString());
         }

         Tests::Case("Controles de base de l'operateur =="); {
         Point O(0,0), A(0,2), B(-2,0), C(2, 0), D(0,-2);
         Triangle ABC(A, B, C), CDB(C, D, B);
         Triangle W= *new Triangle(O, A, B);
         Triangle T1, T2;

            W= ABC; Tests::Unit(1, (W   == ABC));
                    Tests::Unit(0, (W   == CDB));
                    Tests::Unit(0, (ABC == CDB));
                    Tests::Unit(0, (W   == T1));
                    Tests::Unit(1, (T1  == T2));
         }

         Tests::Case("Controles approfondis de l'operateur =="); {
         Point O(0,0), A(0,2), B(-2,0), C(2, 0), D(0,-2);
         Triangle ABC(A, B, C), CDB(C, D, B);
         Triangle** ppT= new Triangle*[6];

            ppT[0]= new Triangle(A, B, C);
            ppT[1]= new Triangle(A, C, B);
            ppT[2]= new Triangle(B, A, C);
            ppT[3]= new Triangle(B, C, A);
            ppT[4]= new Triangle(C, A, B);
            ppT[5]= new Triangle(C, B, A);
	
            for (int i=0, compteur= 0; i<6; i++) 
               if (*ppT[0]==*ppT[i]) compteur++;
                 
            Tests::Unit(6, compteur);
         }

         Tests::Case("Controle de l'operateur !="); {
         Point O(0,0), A(0,2), B(-2,0), C(2, 0), D(0,-2);
         Triangle ABC(A, B, C), CDB(C, D, B);
         Triangle W= *new Triangle(O, A, B);
         Triangle T1, T2;

            W= ABC; Tests::Unit(0, (W   != ABC));
                    Tests::Unit(1, (W   != CDB));
                    Tests::Unit(1, (ABC != CDB));
                    Tests::Unit(1, (W   != T1));
                    Tests::Unit(0, (T1  != T2));
         }
      
   Tests::End();
}
