//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe LigneBrisee - Surcharge de l'opérateur -=
//
// Auteurs : C.Fouco
//

#include "LigneBrisee.h"

// Surcharge de l'opérateur -= (retrait d'une ligne brisée à une autre ligne brisée)
//
LigneBrisee* LigneBrisee:: operator -=(const LigneBrisee& L) {

	// Vérifier l'objet support et l'objet paramètre
	//
	if(cardinal() == 2) throw -2.0;
	if(L.cardinal() > cardinal()-2) throw -2.1;

	// Allouer le tableau de points
	//
	Point* pT = new Point[cardinal()];
	if(pT == NULL) throw -1.0;

	// Déclarer et initialiser le compteur du tableau de points
	//
	int compteur = 0;

	for(int i=0; i<cardinal(); i++) {

		// Vérifier que le point de l'objet support n'appartient à l'objet paramètre
		//
		if(!L.appartient(*m_pSommets[i])) {

			// Ajouter le point de l'objet support au tableau de points
			//
			pT[compteur++] = *m_pSommets[i];
		}
	}

	// Déclarer et initialiser une ligne brisée avec le tableau de points
	//
	LigneBrisee LResultat(pT, compteur);

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

// Surcharge de l'opérateur -= (retrait d'un point à une ligne brisée)
//
LigneBrisee* LigneBrisee:: operator -=(const Point& P) {
	
	// Vérifier l'objet support
	//
	if(cardinal() == 2) throw -2.0;

	// Allouer le tableau de points
	//
	Point* pT = new Point[cardinal()];
	if(pT == NULL) throw -1.0;

	// Déclarer et initialiser le compteur du tableau de points
	//
	int compteur = 0;

	for(int i=0; i<cardinal(); i++) {

		// Vérifier que le point de l'objet support n'est pas égal à l'objet paramètre
		//
		if(*m_pSommets[i] != P) {

			// Ajouter le point de l'objet support au tableau de points
			//
			pT[compteur++] = *m_pSommets[i];
		}
	}

	// Déclarer et initialiser une ligne brisée avec le tableau de points
	//
	LigneBrisee LResultat(pT, compteur);

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

