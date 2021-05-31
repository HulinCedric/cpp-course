//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Triangle - Methode homothetie
//
// Auteur : C.Fouco
//
#include "Triangle.h"

Triangle* Triangle::homothetie(double degres) const
{
	// Construire les points de travail
	//
	Point* P1 = sommet(1);
	Point* P2 = sommet(2);
	Point* P3 = sommet(3);

	// Effectuer l'homothetie de chacun des points
	//
	P1 = P1->homothetie(degres);
	P2 = P2->homothetie(degres);
	P3 = P3->homothetie(degres);
	
	// Retourner le nouveau triangle
	//
	return new Triangle(*P1,*P2,*P3);

}

Triangle* Triangle::homothetie(const Point& P, double degres) const
{
	// Construire les points de travail
	//
	Point* P1 = sommet(1);
	Point* P2 = sommet(2);
	Point* P3 = sommet(3);


	// Effectuer l'homothetie de chacun des points
	//
	P1 = P1->homothetie(P, degres);
	P2 = P2->homothetie(P, degres);
	P3 = P3->homothetie(P, degres);
	
	// Retourner le nouveau triangle
	//
	return new Triangle(*P1,*P2,*P3);

}





		
		

	



