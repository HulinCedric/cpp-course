//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe LigneBrisee - Constructeurs, Destructeur et méthode toString
//
// Auteurs : C.Fouco
//

#include "LigneBrisee.h"

// Constructeur par défaut
//
LigneBrisee:: LigneBrisee() {

	// Allouer le tableau interne
	//
	m_pSommets = new Point*[3];
	if(m_pSommets == NULL) throw -1.0;

	// Allouer et initialiser le premier élément du tableau
	//
	m_pSommets[0] = new Point(0, 0);
	if(m_pSommets[0] == NULL) { delete[] m_pSommets; throw -1.0; }

	// Allouer et initialiser le deuxième élément du tableau
	//
	m_pSommets[1] = new Point(0, 1);
	if(m_pSommets[1] == NULL) { delete m_pSommets[0]; delete[] m_pSommets; throw -1.0; }

	// Initialiser le dernier élement du tableau à NULL
	//
	m_pSommets[2] = NULL;
}

// Constructeur normal avec deux points
//
LigneBrisee:: LigneBrisee(const Point& P1, const Point& P2) {

	// Allouer le tableau interne
	//
	m_pSommets = new Point*[3];
	if(m_pSommets == NULL) throw -1.0;

	// Allouer et initialiser le premier élément du tableau
	//
	m_pSommets[0] = new Point(P1);
	if(m_pSommets[0] == NULL) { delete[] m_pSommets; throw -1.0; }

	// Allouer et initialiser le deuxième élément du tableau
	//
	m_pSommets[1] = new Point(P2);
	if(m_pSommets[1] == NULL) { delete m_pSommets[0]; delete[] m_pSommets; throw -1.0; }

	// Initialiser le dernier élement du tableau à NULL
	//
	m_pSommets[2] = NULL;
}

// Constructeur normal avec deux pointeurs de point
//
LigneBrisee:: LigneBrisee(Point* pP1, Point* pP2) {

	// Contrôler la validité des paramètres
	//
	if(pP1 == NULL) throw -2.1;
	if(pP2 == NULL) throw -2.2;

	// Allouer le tableau interne
	//
	m_pSommets = new Point*[3];
	if(m_pSommets == NULL) throw -1.0;

	// Allouer et initialiser le premier élément du tableau
	//
	m_pSommets[0] = new Point(*pP1);
	if(m_pSommets[0] == NULL) { delete[] m_pSommets; throw -1.0; }

	// Allouer et initialiser le deuxième élément du tableau
	//
	m_pSommets[1] = new Point(*pP2);
	if(m_pSommets[1] == NULL) { delete m_pSommets[0]; delete[] m_pSommets; throw -1.0; }

	// Initialiser le dernier élement du tableau à NULL
	//
	m_pSommets[2] = NULL;
}

// Constructeur normal avec un tableau points
//
LigneBrisee:: LigneBrisee(Point P[], int taille) {

	// Contrôler la validité des paramètres
	//
	if(P == NULL) throw -2.1;
	if(taille < 2) throw -2.2;

	// Allouer le tableau interne
	//
	m_pSommets = new Point*[taille+1];
	if(m_pSommets == NULL) throw -1.0;

	for(int i=0; i<taille; i++) {

		// Allouer et initialiser chaque élément du tableau
		//
		m_pSommets[i] = new Point(P[i]);
		if(m_pSommets[i] == NULL) {

			// Libérer chaque élément déjà alloué
			//
			for(int j=0; j<i; j++) delete m_pSommets[j];

			delete[] m_pSommets; throw -1.0;
		}
	}

	// Initialiser le dernier élement du tableau à NULL
	//
	m_pSommets[taille] = NULL;
}

// Constructeur normal avec un tableau de pointeurs de point
//
LigneBrisee:: LigneBrisee(Point** pP) {

	// Contrôler la validité du paramètre
	//
	if(pP == NULL) throw -2.1;

	// Calculer la taille du tableau
	//
	int taille = 0;
	while(pP[taille] != NULL) taille++;

	// Contrôler la validité de la taille
	//
	if(taille < 2) throw -2.2;

	// Allouer le tableau interne
	//
	m_pSommets = new Point*[taille+1];
	if(m_pSommets == NULL) throw -1.0;

	for(int i=0; i<taille; i++) {
		
		// Allouer et initialiser chaque élément du tableau
		//
		m_pSommets[i] = new Point(*pP[i]);
		if(m_pSommets[i] == NULL) {

			// Libérer chaque élément déjà alloué
			//
			for(int j=0; j<i; j++) delete m_pSommets[j];

			delete[] m_pSommets; throw -1.0;
		}
	}

	// Initialiser le dernier élement du tableau à NULL
	//
	m_pSommets[taille] = NULL;
}

// Constructeur normal avec un segment
//
LigneBrisee:: LigneBrisee(const Segment& S) {

	// Allouer le tableau interne
	//
	m_pSommets = new Point*[3];
	if(m_pSommets == NULL) throw -1.0;

	// Récupérer les extrémités du segment (les deux points)
	//
	Point** pP = S.extremites();

	// Allouer et initialiser le premier élément du tableau
	//
	m_pSommets[0] = new Point(*pP[0]);
	if(m_pSommets[0] == NULL) { delete[] m_pSommets; throw -1.0; }

	// Allouer et initialiser le deuxième élément du tableau
	//
	m_pSommets[1] = new Point(*pP[1]);
	if(m_pSommets[1] == NULL) { delete m_pSommets[0]; delete[] m_pSommets; throw -1.0; }

	// Initialiser le dernier élement du tableau à NULL
	//
	m_pSommets[2] = NULL;

	// Libérer la mémoire allouée par la méthode extremites
	//
	delete pP[0];
	delete pP[1];
	delete[] pP;
}

// Surcharge du constructeur de copie
//
LigneBrisee:: LigneBrisee(const LigneBrisee& LB) {

	// Allouer le tableau de l'objet support
	//
	m_pSommets = new Point*[LB.cardinal()+1];
	if(m_pSommets == NULL) throw -1.0;

	for(int i=0; i<LB.cardinal(); i++) {

		// Allouer et initialiser chaque élément du tableau
		//
		m_pSommets[i] = new Point(*LB.m_pSommets[i]);
		if(m_pSommets[i] == NULL) {

			// Libérer chaque élément déjà alloué
			//
			for(int j=0; j<i; j++) delete m_pSommets[j];

			delete[] m_pSommets; throw -1.0;
		}
	}

	// Initialiser le dernier élement du tableau à NULL
	//
	m_pSommets[LB.cardinal()] = NULL;
}

// Surcharge du destructeur
//
LigneBrisee:: ~LigneBrisee() {

	// Libérer chaque élement
	//
	for(int i=0; i<cardinal(); i++) delete m_pSommets[i];

	// Libérer le tableau interne
	//
	delete[] m_pSommets;
}

// Méthode toString pour les tests unitaires
//
char* LigneBrisee:: toString() {

	// Allouer le buffer résultant
	//
	char* pBuffer = new char[cardinal()*80];
	if(pBuffer == NULL) throw -1.0;

	// Initialiser le buffer résultant avec le caractère de début
	//
	strcpy(pBuffer, "[");

	for(int i=0; i<cardinal(); i++) {

		// Concaténer chaque point dans le buffer
		//
		strcat(pBuffer, m_pSommets[i]->toString());

		// Concaténer un caractère de séparation entre chaque point
		// sauf pour le dernier point
		//
		if(i<cardinal()-1) strcat(pBuffer, ", ");
	}

	// Concaténer le caractère de fin
	//
	strcat(pBuffer, "]");

	// Retourner le buffer résultant
	//
	return pBuffer;
}