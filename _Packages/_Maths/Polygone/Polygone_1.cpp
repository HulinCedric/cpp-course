//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Polgygone - Surcharge de l'opérateur +=
//
// Auteur : C.Fouco
//

#include "Polygone.h"

Polygone& Polygone::operator +=(const Point& P) {

	m_Sommets.pop_back(); 

	list <Point>::iterator k;

	// Controler que les deux vecteurs ne sont pas colineaires (deux derniers points)
	//
	k = m_Sommets.end(); k--; k--;
	Vecteur AB(m_Sommets.back(), *k), BP(*k, P);
	if(AB.colineaire(BP)) throw -3.1;

	// Controler que les deux vecteurs ne sont pas colineaires (dernier et premier point)
	//
	Vecteur CD(m_Sommets.back(), m_Sommets.front());
	Vecteur DP(m_Sommets.front(), P);
	if(CD.colineaire(DP)) throw -3.2;

	// Controler que les deux vecteurs ne sont pas colineaires (deux premiers points)
	//
	k = m_Sommets.begin(); k++;
	Vecteur EF(m_Sommets.front(), *k), FP(*k, P);
	if(EF.colineaire(FP)) throw -3.3;

	m_Sommets.push_back(P);

	m_Sommets.push_back(m_Sommets.front());

	return *this;
}