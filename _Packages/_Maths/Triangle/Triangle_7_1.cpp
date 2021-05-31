//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Triangle - Methode Rotation
//
// Auteur : C.Fouco
//
#include "Triangle.h"

Triangle* Triangle::rotation(double degres) const
{
	Triangle T = *this;

	Point* P1;
	Point* P2;
	Point* P3;

 
	P1 = sommet(1);
	P2 = sommet(2);
	P3 = sommet(3);

	P1 = P1->rotation(*T.orthocentre(),degres);
	P2 = P2->rotation(*T.orthocentre(),degres);
	P3 = P3->rotation(*T.orthocentre(),degres);



	return new Triangle(*P1,*P2,*P3);

}

Triangle* Triangle::rotation(const Point& P,double degres) const
{
	Point* P1;
	Point* P2;
	Point* P3;

 
	P1 = sommet(1);
	P2 = sommet(2);
	P3 = sommet(3);

	P1 = P1->rotation(P,degres);
	P2 = P2->rotation(P,degres);
	P3 = P3->rotation(P,degres);



	return new Triangle(*P1,*P2,*P3);
}



		
		

	



