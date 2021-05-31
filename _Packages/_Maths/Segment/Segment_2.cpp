//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Segment - Accesseurs de consultation
//
// Auteur : A. Thuaire
//
#include "Segment.h"

// --- Restituer le tableau des extremites du segment support
//
Point** Segment::extremites () const {

   // Allouer le tableau resultant
   //
   Point** pR= new Point*[2];
   if (pR==NULL) return NULL;

   // Dupliquer les extremites
   //
   pR[0]= new Point(m_A);
   if (pR[0]==NULL) {delete[] pR; return NULL;}

   pR[1]= new Point(m_B);
   if (pR[1]==NULL) {delete pR[0]; delete pR; return NULL;}

   // Restituer le resultat
   //
   return pR;
}

// --- Controle de la coincidence avec une extremite
//
bool Segment::extremite (const Point& P) {

   if (P == m_A) return true;
   if (P == m_B) return true;
   
   return false;
}

// --- Controle de l'horizontalite du segment support
//
bool Segment::horizontal () {

   if (m_A.ordonnee() == m_B.ordonnee()) return true;
   
   return false;
}

// --- Controle de la verticalite du segment support
//
bool Segment::vertical () {

   if (m_A.abscisse() == m_B.abscisse()) return true;
   
   return false;
}

// --- Calculer la longueur du segment support
//
double Segment::longueur() const {
double a= m_A.abscisse() - m_B.abscisse();
double b= m_A.ordonnee() - m_B.ordonnee();
	
	return sqrt(a*a+b*b);
}

// --- Calculer le point milieu du segment support
//
Point* Segment::milieu() const {

   return new Point((m_A.abscisse() + m_B.abscisse())/2, 
                    (m_A.ordonnee() + m_B.ordonnee())/2);
}
   














