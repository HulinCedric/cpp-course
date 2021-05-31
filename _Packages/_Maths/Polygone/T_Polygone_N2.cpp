//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Polgygone - Tests unitaire de la metohde appartient
//
// Auteur : C.Fouco
//


#include "Polygone.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {
	
	Tests::Begin("_Maths.Polygone", "1.0.0");
	
		Tests::Design("Controle de la methode appartient", 3);
		
			Tests::Case("Controle de la methode appartient");{
			/*	Point A(0, 0), B(2, 2), C(-2, 2), D(-3, -2), E(0, -3), F(2, -2), G(0,2), H(0,4);
				Polygone P(A,B,C);
				P += D;
				P += E;
				P += F;
				P += G;
				Tests::Unit(false, P.appartient(H));*/
				Point A(1, 2), B(0.5, 2), C(0, 0), D(1, 1), E(1, 0), F(0.25, 1.5), G(-1,3);
				Polygone P;
				Polygone P1(G, B, C);

				Tests::Unit(false, P.appartient(A));
				Tests::Unit(false, P.appartient(B));
				Tests::Unit(false, P1.appartient(D));
				Tests::Unit(false, P1.appartient(E));

				Tests::Unit(true, P.appartient(C));
				Tests::Unit(true, P.appartient(D));
				Tests::Unit(true, P.appartient(E));
				Tests::Unit(true, P1.appartient(F));

				Point H(2,2), I(-2, 2), J(0,0), K(0,3), L(0,-1), M(0, 3);
				Polygone P2(I ,H, J);
				P2 += L;

				Tests::Unit(false, P2.appartient(M));
				Tests::Unit(false, P2.appartient(K));
			}

	Tests::End();
}