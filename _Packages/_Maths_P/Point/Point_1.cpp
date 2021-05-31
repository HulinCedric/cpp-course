//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Point - Constructeurs
//
// Auteur : A. Thuaire
//
#include "Point.h"

// --- Constructeur par defaut
//
Point::Point() : RxR() {
    m_numero=0;
}

// --- Premier constructeur normal
//
Point::Point(double abscisse, double ordonnee) : RxR(abscisse, ordonnee) {

   m_numero= 0;
}

// --- Second constructeur normal
//
Point::Point(int numero, double abscisse, double ordonnee) : RxR(abscisse, ordonnee) {

   if (numero <= 0) m_numero= 0;
   m_numero= numero;
}

// --- Methode toString pour les tests unitaires
//
char* Point::toString() {
char* pBuffer;

   // Construire l'affixe du point support
   //
   RxR z(abscisse(), ordonnee());

   // Construire la chaine associee
   //
   char* pS= z.toString();
   if (pS==NULL) return NULL;

   // Traiter le cas particulier du numero nul
   //
   if (m_numero==0) return pS;

   // Allouer le resultat
   //
   pBuffer= new char[40];
   if (pBuffer==NULL) return NULL;
   sprintf(pBuffer, "[%d] %s", m_numero, pS);

   // Restituer le resultat
   //
   delete[] pS;
   return pBuffer;
}






