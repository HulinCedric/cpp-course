//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Segment - Tests unitaires de l'operateur =
//                  (cas nominaux)
//
// Auteur : A. Thuaire
//
#include "Segment.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.Segment", "3.0.0");

      Tests::Design("Controle des operateurs", 3);

         Tests::Case("Operateur ="); {
         Point A(1, 0), B(3, 2), C(-1, 0), D(0.5, -0.5);
         Segment AB(A, B), BC(B, C), AC(A, C), BD(B, D);
         Segment s;
 
            s= AB; Tests::Unit("[(1, 0), (3, 2)]",  s.toString());
            s= BC; Tests::Unit("[(3, 2), (-1, 0)]", s.toString());
            s= AC; Tests::Unit("[(1, 0), (-1, 0)]", s.toString());
            s= BD; Tests::Unit("[(3, 2), (0.5, -0.5)]", s.toString());
         }

         Tests::Case("Operateur =="); {
         Point A(1, 0), B(3, 2), C(-1, 0), D(0.5, -0.5);
         Segment AB(A, B), BC(B, C), AC(A, C), BD(B, D);
         Segment s;
 
            s= AC; 
            Tests::Unit(false, AB==BC);
            Tests::Unit(false, AC==BD);
            Tests::Unit(true,  AB==AB);
            Tests::Unit(true,  s==AC);
         }

         Tests::Case("Operateur !="); {
         Point A(1, 0), B(3, 2), C(-1, 0), D(0.5, -0.5);
         Segment AB(A, B), BC(B, C), AC(A, C), BD(B, D);
         Segment s;
 
            s= AC; 
            Tests::Unit(true,  AB!=BC);
            Tests::Unit(true,  AC!=BD);
            Tests::Unit(false, AB!=AB);
            Tests::Unit(false, s!=AC);
         }
 
   Tests::End();
}
