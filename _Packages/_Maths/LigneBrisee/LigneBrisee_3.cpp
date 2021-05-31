//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe LigneBrisee - Surcharge de l'opérateur +=
//
// Auteurs : C.Fouco
//

#include "LigneBrisee.h"

// Surcharge de l'opérateur += (ajout des points d'une ligne brisée à une autre ligne brisée)
//
LigneBrisee* LigneBrisee:: operator +=(const LigneBrisee& L) {

	// Calculer la taille du tableau de points
	//
	int taille = cardinal()+L.cardinal();

	// Allouer le tableau de points
	//
	Point* pT = new Point[taille];
	if(pT == NULL) throw -1.0;

	// Déclarer et initialiser l'indice du tableau de points
	//
	int k = 0;

	// Ajouter au tableau de points les points de l'objet support
	//
	for(int i=0; i<cardinal(); i++)
		pT[k++] = *m_pSommets[i];

	// Ajouter au tableau de points, à la suite, les points de l'objet paramètre
	//
	for(i=0; i<L.cardinal(); i++)
		pT[k++] = *L.m_pSommets[i];

	// Déclarer et initialiser une ligne brisée avec le tableau de points
	//
	LigneBrisee LResultat(pT, taille);

	// Utiliser de l'opérateur = pour transférer la ligne brisée dans l'objet support
	//
	*this = LResultat;

	// Libérer la mémoire allouée pour le tableau de points
	//
	delete[] pT;
	
	// Retourner l'objet support
	//
	return this;
}

// Surcharge de l'opérateur += (ajout d'un point à une ligne brisée)
//
LigneBrisee* LigneBrisee:: operator +=(const Point& P) {

	// Calculer la taille du tableau de points
	//
	int taille = cardinal()+1;

	// Allouer le tableau de points
	//
	Point* pT = new Point[taille];
	if(pT == NULL) throw -1.0;

	// Ajouter au tableau de points les points de l'objet support
	//
	for(int i=0; i<cardinal(); i++)
		pT[i] = *m_pSommets[i];

	// Ajouter au tableau de points, à la fin, le point de l'objet paramètre
	//
	pT[cardinal()] = P;

	// Déclarer et initialiser une ligne brisée avec le tableau de points
	//
	LigneBrisee LResultat(pT, taille);

	// Utiliser de l'opérateur = pour transférer la ligne brisée dans l'objet support
	//
	*this = LResultat;

	// Libérer la mémoire allouée pour le tableau de points
	//
	delete[] pT;

	// Retourner l'objet support
	//
	return this;
}

LigneBrisee* LigneBrisee::operator +=(const Point* pP)
{
	if (pP == NULL) throw -1.0;
	
	return operator +=(*pP);
}
