//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe LigneBrisee - Méthode longueur et méthode appartient
//
// Auteurs : C.Fouco
//

#include "LigneBrisee.h"

// Calcul de la longueur de la ligne brisée
//
double LigneBrisee::longueur() const{

	// Déclarer et initialiser la variable longueur
	//
	double longueur = 0.0;

	// Ajouter la distance entre chaque point à la variable longueur
	//
	for(int i=0; i<cardinal()-1; i++)
		longueur += m_pSommets[i]->distance(*m_pSommets[i+1]);

	// Retourner la variable longueur
	//
	return longueur;
}

// Appartenance d'un point ou non à une ligne brisée
//
bool LigneBrisee:: appartient(const Point& P) const {

	Point A, B;
	Segment* pS;

	// Verifier si le point appartient aux segments de la ligne brisée
	//
	for(int i=0; i<cardinal()-1; i++) {

		A = *m_pSommets[i];
		B = *m_pSommets[i+1];

		pS = new Segment(A, B);
		if(pS == NULL) throw -1.0;

		if(pS->appartient(P))
			return true;
	}

	// Retourner false dans le cas contraire
	//
	return false;
}