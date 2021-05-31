//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe DemiDroite - Tests unitaires de la methode intersection
//                     (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "DemiDroite.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.DemiDroite", "2.0.0");

      Tests::Design("Controle des methodes (lot 4)", 3);
      Point A(0,2), B(-2,0), C(2,0),  D(0,-2), I(2, -2);
      Point O(0,0), E(0,1),  F(5,5),  G(0,10), H(15,10);
      Vecteur AB(A,B), AC(A,C), BE(B,E), BA(B,A), DA(D,A), CB(C,B);
      Vecteur BD(B, D), BI(B, I);

         Tests::Case("Methode intersection / Cas de deux demi droites"); {

            DemiDroite d1(A, AB), d2(A, AC);
            Tests::Unit("(0, 2)", d1.intersection(d2)->toString());

            DemiDroite d3(A, AC), d4(B, BI);
            Tests::Unit("(6, -4)", d4.intersection(d3)->toString());

            DemiDroite d5(B, BA), d6(D, DA);
            Tests::Unit("(0, 2)", d5.intersection(d6)->toString());

            DemiDroite d7(A, AB), d8(B, CB);
            Tests::Unit("(-2, 0)", d7.intersection(d8)->toString());

            DemiDroite d9(A, AC), d10(B, BD);
            Tests::Unit(0, (int)d9.intersection(d10));
         }

         Tests::Case("Methode intersection / Cas d'une demi droite et d'une droite"); {
            
            Droite D1(A, AB);
            DemiDroite d1  = *new DemiDroite(A, AC);
            Tests::Unit("(0, 2)", d1.intersection(D1)->toString());

            Droite D2(B, BA);
            DemiDroite d2(D, DA);
            Tests::Unit("(0, 2)", d2.intersection(D2)->toString());

            Droite D3  = *new Droite(A, AB);
            DemiDroite d3(B, CB);
            Tests::Unit("(-2, 0)", d3.intersection(D3)->toString());

            Vecteur v1  = *new Vecteur (0,5);
            Droite D4(G,H);
            DemiDroite d4(F,v1);
            Tests::Unit("(5, 10)", d4.intersection(D4)->toString());

            Vecteur v2  = *new Vecteur (0,10);
            Droite D5(1, 0, 0);
            DemiDroite d5(F,v2);
            Tests::Unit(0, (int)d5.intersection(D5));      
         }

         Tests::Case("Methode intersection / Cas d'une demi droite et d'un segment"); {
         Vecteur AO(A, O);
         Segment BC(B, C);
         DemiDroite d1  = *new DemiDroite(A, AO);

            Tests::Unit("(0, 0)", d1.intersection(BC)->toString()); 
         }

   Tests::End();
}
