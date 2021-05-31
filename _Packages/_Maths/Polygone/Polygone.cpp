//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Polgygone - Constructeurs
//
// Auteur : C.Fouco
//

#include "Polygone.h"

// Constructeur par défaut
//
Polygone::Polygone() {

	list <Point>::iterator k = m_Sommets.begin();

	Point A(1, 1), B(-1, 1), C(-1, -1), D(1, -1);

	m_Sommets.insert(k, A);
	m_Sommets.insert(k, B);
	m_Sommets.insert(k, C);
	m_Sommets.insert(k, D);
	m_Sommets.insert(k, A);
}

// Constructeur avec trois points
//
Polygone::Polygone(const Point& A, const Point& B, const Point& C) {

	// Controler que les deux vecteurs ne sont pas colineaires
	//
	Vecteur AB(A, B), BC(B, C);
	if(AB.colineaire(BC)) throw -3.0;

	list <Point>::iterator k = m_Sommets.begin();

	m_Sommets.insert(k, A);
	m_Sommets.insert(k, B);
	m_Sommets.insert(k, C);
	m_Sommets.insert(k, A);
}

// Constructeur avec un triangle
//
Polygone::Polygone(const Triangle& T) {

	list <Point>::iterator k = m_Sommets.begin();

	m_Sommets.insert(k, *T.sommet(1));
	m_Sommets.insert(k, *T.sommet(2));
	m_Sommets.insert(k, *T.sommet(3));
	m_Sommets.insert(k, *T.sommet(1));
}

// Constructeur de copie
//
Polygone::Polygone(const Polygone& P) {

	m_Sommets = P.m_Sommets;
}

// Méthode toString
//
char* Polygone::toString() {
	
	char* pBuffer = new char[200];
	if(pBuffer == NULL) throw -1.0;

	sprintf(pBuffer, "[");

	list <Point>::iterator k = m_Sommets.begin();

	for(int i=1; i<m_Sommets.size()-1; i++)
		sprintf(pBuffer, "%s%s, ", pBuffer, (k++)->toString());

	sprintf(pBuffer, "%s%s]", pBuffer, k->toString());

	return pBuffer;
}