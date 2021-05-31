//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe LigneBrisee - Surcharge de l'op�rateur +=
//
// Auteurs : C.Fouco
//

#include "LigneBrisee.h"

// Surcharge de l'op�rateur += (ajout des points d'une ligne bris�e � une autre ligne bris�e)
//
LigneBrisee* LigneBrisee:: operator +=(const LigneBrisee& L) {

	// Calculer la taille du tableau de points
	//
	int taille = cardinal()+L.cardinal();

	// Allouer le tableau de points
	//
	Point* pT = new Point[taille];
	if(pT == NULL) throw -1.0;

	// D�clarer et initialiser l'indice du tableau de points
	//
	int k = 0;

	// Ajouter au tableau de points les points de l'objet support
	//
	for(int i=0; i<cardinal(); i++)
		pT[k++] = *m_pSommets[i];

	// Ajouter au tableau de points, � la suite, les points de l'objet param�tre
	//
	for(i=0; i<L.cardinal(); i++)
		pT[k++] = *L.m_pSommets[i];

	// D�clarer et initialiser une ligne bris�e avec le tableau de points
	//
	LigneBrisee LResultat(pT, taille);

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

// Surcharge de l'op�rateur += (ajout d'un point � une ligne bris�e)
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

	// Ajouter au tableau de points, � la fin, le point de l'objet param�tre
	//
	pT[cardinal()] = P;

	// D�clarer et initialiser une ligne bris�e avec le tableau de points
	//
	LigneBrisee LResultat(pT, taille);

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

LigneBrisee* LigneBrisee::operator +=(const Point* pP)
{
	if (pP == NULL) throw -1.0;
	
	return operator +=(*pP);
}
