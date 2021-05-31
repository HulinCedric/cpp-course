//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Polgygone - Méthode distance
//
// Auteur : C.Fouco
//

#include "Polygone.h"

double Polygone::distance(const Point& P) {

	// Vérifier si le point appartient au polygone
	//
	if(appartient(P)) return 0.0;

	list <Point>::iterator k = m_Sommets.begin();

	double minS = 0.0, minP = 0.0, distance;

	Point A, B;
	Segment* pS;

	for(int i=1; i<m_Sommets.size(); i++) {

		A = *k++;
		B = *k;

		// Allouer le segment de 2 points successifs
		//
		pS = new Segment(A, B);
		if(pS == NULL) throw -1.0;

		// Vérifier si le point a un projeté orthogonal sur le segment
		//
		try {
			distance = pS->distance(P);
			
			// Sauvegarder la distance entre le point et son projeté si inférieur à la précédente ou si c'est la première
			//
			if(distance < minS || minS == 0.0)
				minS = distance;
		}

		// Continuer si pas de projeté
		//
		catch(double e) { delete pS; continue; }

		delete pS;
	}


	k = m_Sommets.begin();

	for(i=1; i<m_Sommets.size(); i++) {

		A = *k++;

		// Sauvegarder la distance entre le point est le sommet si inférieure à la précédente ou si c'est la première
		//
		if(A.distance(P) < minP || minP == 0.0)
			minP = A.distance(P);
	}

	// Vérifier s'il n'y a pas eu de projeté, on renvoit la distance au sommet le plus proche dans ce cas
	//
	if((minP < minS && minP != 0.0) || minS == 0.0)
		return minP;
	
	return minS;
}