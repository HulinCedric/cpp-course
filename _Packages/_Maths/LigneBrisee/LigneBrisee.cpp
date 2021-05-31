//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe LigneBrisee - Constructeurs, Destructeur et m�thode toString
//
// Auteurs : C.Fouco
//

#include "LigneBrisee.h"

// Constructeur par d�faut
//
LigneBrisee:: LigneBrisee() {

	// Allouer le tableau interne
	//
	m_pSommets = new Point*[3];
	if(m_pSommets == NULL) throw -1.0;

	// Allouer et initialiser le premier �l�ment du tableau
	//
	m_pSommets[0] = new Point(0, 0);
	if(m_pSommets[0] == NULL) { delete[] m_pSommets; throw -1.0; }

	// Allouer et initialiser le deuxi�me �l�ment du tableau
	//
	m_pSommets[1] = new Point(0, 1);
	if(m_pSommets[1] == NULL) { delete m_pSommets[0]; delete[] m_pSommets; throw -1.0; }

	// Initialiser le dernier �lement du tableau � NULL
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

	// Allouer et initialiser le premier �l�ment du tableau
	//
	m_pSommets[0] = new Point(P1);
	if(m_pSommets[0] == NULL) { delete[] m_pSommets; throw -1.0; }

	// Allouer et initialiser le deuxi�me �l�ment du tableau
	//
	m_pSommets[1] = new Point(P2);
	if(m_pSommets[1] == NULL) { delete m_pSommets[0]; delete[] m_pSommets; throw -1.0; }

	// Initialiser le dernier �lement du tableau � NULL
	//
	m_pSommets[2] = NULL;
}

// Constructeur normal avec deux pointeurs de point
//
LigneBrisee:: LigneBrisee(Point* pP1, Point* pP2) {

	// Contr�ler la validit� des param�tres
	//
	if(pP1 == NULL) throw -2.1;
	if(pP2 == NULL) throw -2.2;

	// Allouer le tableau interne
	//
	m_pSommets = new Point*[3];
	if(m_pSommets == NULL) throw -1.0;

	// Allouer et initialiser le premier �l�ment du tableau
	//
	m_pSommets[0] = new Point(*pP1);
	if(m_pSommets[0] == NULL) { delete[] m_pSommets; throw -1.0; }

	// Allouer et initialiser le deuxi�me �l�ment du tableau
	//
	m_pSommets[1] = new Point(*pP2);
	if(m_pSommets[1] == NULL) { delete m_pSommets[0]; delete[] m_pSommets; throw -1.0; }

	// Initialiser le dernier �lement du tableau � NULL
	//
	m_pSommets[2] = NULL;
}

// Constructeur normal avec un tableau points
//
LigneBrisee:: LigneBrisee(Point P[], int taille) {

	// Contr�ler la validit� des param�tres
	//
	if(P == NULL) throw -2.1;
	if(taille < 2) throw -2.2;

	// Allouer le tableau interne
	//
	m_pSommets = new Point*[taille+1];
	if(m_pSommets == NULL) throw -1.0;

	for(int i=0; i<taille; i++) {

		// Allouer et initialiser chaque �l�ment du tableau
		//
		m_pSommets[i] = new Point(P[i]);
		if(m_pSommets[i] == NULL) {

			// Lib�rer chaque �l�ment d�j� allou�
			//
			for(int j=0; j<i; j++) delete m_pSommets[j];

			delete[] m_pSommets; throw -1.0;
		}
	}

	// Initialiser le dernier �lement du tableau � NULL
	//
	m_pSommets[taille] = NULL;
}

// Constructeur normal avec un tableau de pointeurs de point
//
LigneBrisee:: LigneBrisee(Point** pP) {

	// Contr�ler la validit� du param�tre
	//
	if(pP == NULL) throw -2.1;

	// Calculer la taille du tableau
	//
	int taille = 0;
	while(pP[taille] != NULL) taille++;

	// Contr�ler la validit� de la taille
	//
	if(taille < 2) throw -2.2;

	// Allouer le tableau interne
	//
	m_pSommets = new Point*[taille+1];
	if(m_pSommets == NULL) throw -1.0;

	for(int i=0; i<taille; i++) {
		
		// Allouer et initialiser chaque �l�ment du tableau
		//
		m_pSommets[i] = new Point(*pP[i]);
		if(m_pSommets[i] == NULL) {

			// Lib�rer chaque �l�ment d�j� allou�
			//
			for(int j=0; j<i; j++) delete m_pSommets[j];

			delete[] m_pSommets; throw -1.0;
		}
	}

	// Initialiser le dernier �lement du tableau � NULL
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

	// R�cup�rer les extr�mit�s du segment (les deux points)
	//
	Point** pP = S.extremites();

	// Allouer et initialiser le premier �l�ment du tableau
	//
	m_pSommets[0] = new Point(*pP[0]);
	if(m_pSommets[0] == NULL) { delete[] m_pSommets; throw -1.0; }

	// Allouer et initialiser le deuxi�me �l�ment du tableau
	//
	m_pSommets[1] = new Point(*pP[1]);
	if(m_pSommets[1] == NULL) { delete m_pSommets[0]; delete[] m_pSommets; throw -1.0; }

	// Initialiser le dernier �lement du tableau � NULL
	//
	m_pSommets[2] = NULL;

	// Lib�rer la m�moire allou�e par la m�thode extremites
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

		// Allouer et initialiser chaque �l�ment du tableau
		//
		m_pSommets[i] = new Point(*LB.m_pSommets[i]);
		if(m_pSommets[i] == NULL) {

			// Lib�rer chaque �l�ment d�j� allou�
			//
			for(int j=0; j<i; j++) delete m_pSommets[j];

			delete[] m_pSommets; throw -1.0;
		}
	}

	// Initialiser le dernier �lement du tableau � NULL
	//
	m_pSommets[LB.cardinal()] = NULL;
}

// Surcharge du destructeur
//
LigneBrisee:: ~LigneBrisee() {

	// Lib�rer chaque �lement
	//
	for(int i=0; i<cardinal(); i++) delete m_pSommets[i];

	// Lib�rer le tableau interne
	//
	delete[] m_pSommets;
}

// M�thode toString pour les tests unitaires
//
char* LigneBrisee:: toString() {

	// Allouer le buffer r�sultant
	//
	char* pBuffer = new char[cardinal()*80];
	if(pBuffer == NULL) throw -1.0;

	// Initialiser le buffer r�sultant avec le caract�re de d�but
	//
	strcpy(pBuffer, "[");

	for(int i=0; i<cardinal(); i++) {

		// Concat�ner chaque point dans le buffer
		//
		strcat(pBuffer, m_pSommets[i]->toString());

		// Concat�ner un caract�re de s�paration entre chaque point
		// sauf pour le dernier point
		//
		if(i<cardinal()-1) strcat(pBuffer, ", ");
	}

	// Concat�ner le caract�re de fin
	//
	strcat(pBuffer, "]");

	// Retourner le buffer r�sultant
	//
	return pBuffer;
}