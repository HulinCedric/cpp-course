//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe LigneBrisee - Surchage des op�rateurs =, == et !=
//
// Auteurs : C.Fouco
//

#include "LigneBrisee.h"

// Surcharge de l'operateur =
//
LigneBrisee& LigneBrisee:: operator =(const LigneBrisee& L){

	// D�truire le tableau de l'objet support
	//
	for(int i=0; i<cardinal(); i++) delete m_pSommets[i];
	delete[] m_pSommets;

	// Allouer le tableau avec la nouvelle dimension
	//
	m_pSommets = new Point*[L.cardinal()+1];
	if(m_pSommets == NULL) throw -1.0;

	for(i=0; i<L.cardinal(); i++) {

		// Allouer et initialiser chaque �l�ment du tableau
		//
		m_pSommets[i] = new Point(*L.m_pSommets[i]);
		if(m_pSommets[i] == NULL) {

			// Lib�rer chaque �l�ment d�j� allou�
			//
			for(int j=0; j<i; j++) delete m_pSommets[j];

			delete[] m_pSommets; throw -1.0;
		}
	}

	// Initialiser le dernier �lement du tableau � NULL
	//
	m_pSommets[L.cardinal()] = NULL;

	// Retourner l'objet support
	//
	return *this;
}

// Surcharge de l'operateur ==
//
bool LigneBrisee:: operator ==(const LigneBrisee& L) {

	// V�rifier que les deux lignes bris�es ont le m�me cardinal
	//
	if(cardinal() != L.cardinal()) return false;

	// Verifier que les points des deux lignes brisees sont �gaux
	//
	for(int i=0; i<cardinal(); i++)
		if(*m_pSommets[i] != *L.m_pSommets[i]) return false;

	// Retourner true dans le cas contraire
	//
	return true;
}

// Surchage de l'operateur !=
//
bool LigneBrisee:: operator !=(const LigneBrisee& L) {

	// Retourner le contraire de ce qu'aurait retourn� l'op�rateur ==
	//
	return !(*this == L);
}