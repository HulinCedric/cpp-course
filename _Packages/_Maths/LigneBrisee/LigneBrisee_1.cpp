//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe LigneBrisee - Accesseurs
//
// Auteurs : C.Fouco
//

#include "LigneBrisee.h"

// Accesseur de consultation du cardinal
//
int LigneBrisee:: cardinal() const {

	// D�clarer et initialiser la variable cardinal
	//
	int cardinal = 0;

	// Calculer le cardinal
	//
	while(m_pSommets[cardinal] != NULL) cardinal++;

	// Retourner la variable cardinal
	//
	return cardinal;
}

// Accesseur de consultation du premier sommet
//
Point* LigneBrisee:: premierSommet() const {
	
	// Retourner le premier sommet
	//
	return m_pSommets[0];
}

// Accesseur de consultation du dernier sommet
//
Point* LigneBrisee:: dernierSommet() const {
	
	// Retourner le dernier sommet
	//
	return m_pSommets[cardinal()-1];
}

// Accesseur de consultation du sommet pr�cis� en param�tre par son indice
//
Point* LigneBrisee:: operator [](const int indice) {

	// Contr�ler la validit� du param�tre
	//
	if(indice < 1 || indice > cardinal()) throw -2.1;
	
	// Retourner le sommet pr�cis� en param�tre par son indice
	//
	Point* pP = new Point(*m_pSommets[indice-1]);
	if(pP == NULL) throw -1.0;

	return pP;
}

LigneBrisee* LigneBrisee::operator ()(const int indice1, const int indice2)
{
	int i=0, j=0, k=0;

	// Contr�ler la validit� du premier param�tre
	//
	if(indice1 < 1 || indice1 > cardinal()) throw -2.1;

	// Contr�ler la validit� du second param�tre
	//
	if(indice2 < 1 || indice2 > cardinal()) throw -2.1;

	// Contr�ler la validit� entre les deux param�tre
	//
	if(indice1 >= indice2) throw -2.1;


	// Calculer le cardinal
	//
	int cardinal = indice2 - indice1 +1;


	// Allouer le tableau avec la nouvelle dimension
	//
	Point* pT = new Point[cardinal];
	if(pT == NULL) throw -1.0;

	

	for(j=indice1; j <= indice2; j++)
	{
		// Allouer et initialiser chaque �l�ment du tableau
		//
		pT[i++] = *m_pSommets[j-1];
	}
	
	
	LigneBrisee *LResultat= new LigneBrisee(pT,cardinal);
	if(LResultat == NULL) throw -1.0;

	

	// Lib�rer la m�moire allou�e pour le tableau de points
	//
	delete[] pT;
	
	// Retourner l'objet support
	//
	return LResultat;
}
