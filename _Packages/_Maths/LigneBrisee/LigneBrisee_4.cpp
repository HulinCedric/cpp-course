//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe LigneBrisee - Surcharge de l'op�rateur -=
//
// Auteurs : C.Fouco
//

#include "LigneBrisee.h"

// Surcharge de l'op�rateur -= (retrait d'une ligne bris�e � une autre ligne bris�e)
//
LigneBrisee* LigneBrisee:: operator -=(const LigneBrisee& L) {

	// V�rifier l'objet support et l'objet param�tre
	//
	if(cardinal() == 2) throw -2.0;
	if(L.cardinal() > cardinal()-2) throw -2.1;

	// Allouer le tableau de points
	//
	Point* pT = new Point[cardinal()];
	if(pT == NULL) throw -1.0;

	// D�clarer et initialiser le compteur du tableau de points
	//
	int compteur = 0;

	for(int i=0; i<cardinal(); i++) {

		// V�rifier que le point de l'objet support n'appartient � l'objet param�tre
		//
		if(!L.appartient(*m_pSommets[i])) {

			// Ajouter le point de l'objet support au tableau de points
			//
			pT[compteur++] = *m_pSommets[i];
		}
	}

	// D�clarer et initialiser une ligne bris�e avec le tableau de points
	//
	LigneBrisee LResultat(pT, compteur);

	// Utiliser de l'op�rateur = pour transf�rer la ligne bris�e dans l'objet support
	//
	*this = LResultat;

	// Lib�rer la m�moire allou�e pour le tableau de points
	//
	delete[] pT;

	// Retourner l'objet support
	//
	return this;
}

// Surcharge de l'op�rateur -= (retrait d'un point � une ligne bris�e)
//
LigneBrisee* LigneBrisee:: operator -=(const Point& P) {
	
	// V�rifier l'objet support
	//
	if(cardinal() == 2) throw -2.0;

	// Allouer le tableau de points
	//
	Point* pT = new Point[cardinal()];
	if(pT == NULL) throw -1.0;

	// D�clarer et initialiser le compteur du tableau de points
	//
	int compteur = 0;

	for(int i=0; i<cardinal(); i++) {

		// V�rifier que le point de l'objet support n'est pas �gal � l'objet param�tre
		//
		if(*m_pSommets[i] != P) {

			// Ajouter le point de l'objet support au tableau de points
			//
			pT[compteur++] = *m_pSommets[i];
		}
	}

	// D�clarer et initialiser une ligne bris�e avec le tableau de points
	//
	LigneBrisee LResultat(pT, compteur);

	// Utiliser de l'op�rateur = pour transf�rer la ligne bris�e dans l'objet support
	//
	*this = LResultat;

	// Lib�rer la m�moire allou�e pour le tableau de points
	//
	delete[] pT;

	// Retourner l'objet support
	//
	return this;
}

