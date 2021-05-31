//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Droite - Tests unitaires des methodes intersection et appartient
//                 (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "Droite.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.Droite", "2.0.0");

      Tests::Design("Controle des methodes intersection et appartient", 3);
      Point O(0,0), A(0,2), B(-2,0), C(2,0),   D(0,-2);
      Point E(0,1), F(5,5), G(0,10), H(15,10), I(-1, 2);
      Point J(2, -2), K(2,2), L(-2,-2);
   
      Point* pP;

         Tests::Case("Methode intersection / Cas general"); {
         Droite AB(A,B), BC(B,C), AC(A,C);
         Droite OA(O,A), BD(B,D), CD(C,D);
         Droite IH(I,H), FD(F,D), OI(O,I);

            pP= AB.intersection(AC); Tests::Unit("(0, 2)",  pP->toString()); 
            pP= OA.intersection(BC); Tests::Unit("(0, 0)",  pP->toString());
            pP= IH.intersection(FD); Tests::Unit("(5, 5)",  pP->toString());
            pP= CD.intersection(BD); Tests::Unit("(0, -2)", pP->toString());

            pP= OI.intersection(CD); Tests::Unit("(0.666667, -1.33333)", pP->toString());
         }

         Tests::Case("Methode intersection / Cas de deux droites // a l'axe des abscisses"); {
         Droite OC= *new Droite(O,C), DJ= *new Droite(D,J);
         Droite AK= *new Droite(A,K);

            pP= OC.intersection(DJ); Tests::Unit(0, (int)pP);
            pP= OC.intersection(AK); Tests::Unit(0, (int)pP);
            pP= DJ.intersection(AK); Tests::Unit(0, (int)pP);		 
         }

         Tests::Case("Methode intersection / Cas de deux droites // a l'axe des ordonnees"); {
         Droite CK= *new Droite(C,K), OD= *new Droite(O,D);
         Droite BL= *new Droite(B,L); 

            pP= CK.intersection(OD); Tests::Unit(0, (int)pP);
            pP= OD.intersection(BL); Tests::Unit(0, (int)pP);
            pP= CK.intersection(BL); Tests::Unit(0, (int)pP);		 		 
         }
      
         Tests::Case("Methode intersection / Cas de deux droites // entre elles"); {
         Droite AB= *new Droite(A,B), CD= *new Droite(C,D);
         Droite BD= *new Droite(B,D), AC= *new Droite(A,C);

            pP= AB.intersection(CD); Tests::Unit(0, (int)pP);
            pP= BD.intersection(AC); Tests::Unit(0, (int)pP);		 		 
         }

         Tests::Case("Methode appartient"); {
         Droite AB(A,B), BC(B,C), AD(A,D);

            Tests::Unit(true,  AB.appartient(A));
            Tests::Unit(true,  AB.appartient(B));
            Tests::Unit(false, AB.appartient(C));
            Tests::Unit(true,  BC.appartient(O));
            Tests::Unit(false, AB.appartient(O));
            Tests::Unit(true,  AD.appartient(O));
         }

   Tests::End();
}
