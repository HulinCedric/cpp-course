//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Collection - Surcharge de l'operateur -=
//    
// Auteur : A. Thuaire
//
#include "Collection.h"

// --- Surcharge de l'operateur -=
//
void* Collection::operator [](int rang) const
{
	// Controler la validité du parametre
	//
	if( rang <= 0 || rang > cardinal()) throw -2.1;

	// Retourner le pointeur vers l'objet
	//
	return m_pElements[rang-1];
}


