//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe RxR - Constructeurs et methode toString
//
// Auteur : A. Thuaire
//
#include "RxR.h"

// --- Premier constructeur normal
//
RxR::RxR(double abscisse, double ordonnee) {

   if (fabs(abscisse) < fabs(EPSILON)) m_abscisse= 0.;
   else m_abscisse= abscisse;

   if (fabs(ordonnee) < fabs(EPSILON))  m_ordonnee= 0.;
   else m_ordonnee= ordonnee;
}

// --- Second constructeur normal
//
RxR::RxR(double abscisse) {

   if (fabs(abscisse) < fabs(EPSILON)) m_abscisse= 0.;
   else m_abscisse= abscisse;
   m_ordonnee= 0.;
}

// --- Methode toString pour les tests unitaires
//
char* RxR::toString() {
char* pBuffer;

   pBuffer= new char[40];
   if (pBuffer==NULL) return NULL;

   if (m_abscisse == (int)m_abscisse && m_ordonnee == (int)m_ordonnee ) {
      sprintf(pBuffer, "(%d, %d)",(int)m_abscisse, (int)m_ordonnee);
      return pBuffer;
   }

   if (m_abscisse == (int)m_abscisse && m_ordonnee != (int)m_ordonnee ) {
       sprintf(pBuffer, "(%d, %lg)",(int)m_abscisse, m_ordonnee);
       return pBuffer;
   }

   if (m_abscisse != (int)m_abscisse && m_ordonnee == (int)m_ordonnee ) {
       sprintf(pBuffer, "(%lg, %d)",m_abscisse, (int)m_ordonnee);
       return pBuffer;
   }

   sprintf(pBuffer, "(%lg, %lg)",m_abscisse, m_ordonnee);
   return pBuffer;
}





