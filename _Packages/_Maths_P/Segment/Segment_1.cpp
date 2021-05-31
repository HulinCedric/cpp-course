//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Segment - Constructeurs et methode toString
//
// Auteur : A. Thuaire
//
#include "Segment.h"

// --- Constructeur par defaut
//
Segment::Segment() {
	
   m_A= Point(0,0);
   m_B= Point(0,1);
}
   
// --- Constructeur normal
//
Segment::Segment(const Point& A, const Point& B) {

   // Controler le cas d'un segment invalide
   //
   if (A==B) throw -3.0;

   // Valuer les deux attributs
   //
   m_A= A; m_B= B;
}

// --- Methode toString pour les tests unitaires
//
char* Segment::toString() {
char* pBuffer;

   pBuffer= new char[40];
   if (pBuffer==NULL) return NULL;

   sprintf(pBuffer, "[%s, %s]",m_A.toString(), m_B.toString());
   return pBuffer;
}


