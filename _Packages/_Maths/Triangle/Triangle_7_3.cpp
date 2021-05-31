//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Triangle - Methode Symétrie
//
// Auteur : C.Fouco
//
#include "Triangle.h"

Triangle* Triangle::symetrie() const
{
	// Construire les points de travail
	//
	Point* P1 = sommet(1);
	Point* P2 = sommet(2);
	Point* P3 = sommet(3);

	// Effectuer la symétrie de chacun des points
	//
	P1 = P1->symetrie();
	P2 = P2->symetrie();
	P3 = P3->symetrie();
	
	// Retourner le nouveau triangle
	//
	return new Triangle(*P1,*P2,*P3);

}

Triangle* Triangle::symetrie(const Point& P) const
{
	// Construire les points de travail
	//
	Point* P1 = sommet(1);
	Point* P2 = sommet(2);
	Point* P3 = sommet(3);

	// Effectuer la symétrie de chacun des points
	//
	P1 = P1->symetrie(P);
	P2 = P2->symetrie(P);
	P3 = P3->symetrie(P);
	
	// Retourner le nouveau triangle
	//
	return new Triangle(*P1,*P2,*P3);

}





		
		

	



