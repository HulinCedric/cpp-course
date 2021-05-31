//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Triangle - Methode Translation
//
// Auteur : C.Fouco
//
#include "Triangle.h"

Triangle* Triangle::translation(const Vecteur& V) const
{
	// Construire les points de travail
	//
	Point* P1 = sommet(1);
	Point* P2 = sommet(2);
	Point* P3 = sommet(3);

	// Effectuer la translation de chacun des points
	//
	P1 = P1->translation(V);
	P2 = P2->translation(V);
	P3 = P3->translation(V);
	
	// Retourner le nouveau triangle
	//
	return new Triangle(*P1,*P2,*P3);

}





		
		

	



