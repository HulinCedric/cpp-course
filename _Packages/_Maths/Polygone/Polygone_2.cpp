//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Polgygone - Méthode appartient
//
// Auteur : C.Fouco
//

#include "Polygone.h"

bool Polygone::appartient(const Point& P) {

	list <Point>::iterator k = m_Sommets.begin();

	Point A, B;
	Segment* pS;

	//Verifier si le point appartient au perimetre du polygone
	//
	for(int i=1; i<m_Sommets.size(); i++){

		A = *k++;
		B = *k;

		pS = new Segment(A, B);
		if(pS == NULL) throw -1.0;

		if(pS->appartient(P))
			return true;
	}

	// Récupérer le milieu du premier segment
	//
	k = m_Sommets.begin();

	A = *k++;
	B = *k;

	pS = new Segment(A, B);
	if(pS == NULL) throw -1.0;

	if(pS->aligne(P)) {

		delete pS;

		A = *k++;
		B = *k;

		pS = new Segment(A, B);
		if(pS == NULL) throw -1.0;
	}

	Point* pP = pS->milieu();
	if(pP == NULL) throw -1.0;
	
	// Créer le vecteur porteur de la demi droite
	//
	Vecteur V(*pP, P);

	// Créer la demi droite
	//
	DemiDroite DD(P, V);
	
	Droite* pD;

	k = m_Sommets.begin();

	delete pP;

	float nbIntersection = 0.0f;
	bool estDejaCompte = false;

	for(i=1; i<m_Sommets.size(); i++) {

		A = *k++;
		B = *k;

		// Allouer le segment de 2 points successifs
		//
		pS = new Segment(A, B);
		if(pS == NULL) throw -1.0;

		// Allouer la droite porteuse du segment
		//
		pD = new Droite(A, B);
		if(pD == NULL) throw -1.0;

		// Calculer le point d'intersection de la demi droite avec cette droite
		//
		pP = DD.intersection(*pD);

		// Déterminer si le point d'intersection appartient au segment
		//
		if(pP != NULL) {

			if(pS->appartient(*pP)) {

				if(!estDejaCompte) {

					if(*pP == A || *pP == B)
						estDejaCompte = true;

					nbIntersection++;
				}

				else estDejaCompte = false;
			}

			delete pP;
		} 

		delete pS;
		delete pD;
	}

	// Déterminer si le nombre d'intersection est pair ou impaire
	//
	if((int)(nbIntersection/2) == nbIntersection/2)
		return false;

	return true;
}