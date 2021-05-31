//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Vecteur - Constructeurs et fonction toString
//
// Auteur : A. Thuaire
//
#include "Vecteur.h"

// --- Constructeur par defaut
//
Vecteur::Vecteur () {

   m_x= 0;
   m_y= 0;
}

// --- Premier Constructeur normal
//
Vecteur::Vecteur (double x, double y) {

   if (fabs(x) < fabs(EPSILON)) m_x= 0;
   else m_x= x;

   if (fabs(y) < fabs(EPSILON)) m_y= 0;
   else m_y= y;
}

// --- Second Constructeur normal
//
Vecteur::Vecteur (const RxR& A, const RxR& B) {

   m_x= B.abscisse() - A.abscisse();
   m_y= B.ordonnee() - A.ordonnee();
}

// --- Fonction toString pour les tests unitaires
//
char* Vecteur::toString() {
char* pBuffer;
double x, y;

   x= m_x;
   y= m_y;

   pBuffer= new char[40];
   if (pBuffer==NULL) return NULL;

   // Traiter le cas particulier d'un element de ZxZ
   //
   if (x == (int)x && y == (int)y ) {
      sprintf(pBuffer, "(%d, %d)", (int)x, (int)y);
      return pBuffer;
   }

   // Traiter le cas particulier d'un element de ZxR
   //
   if (x == (int)x && y != (int)y ) {
       sprintf(pBuffer, "(%d, %lg)",(int)x ,y);
       return pBuffer;
   }

   // Traiter le cas particulier d'un element de RxZ
   //
   if (x != (int)x && y == (int)y ) {
       sprintf(pBuffer, "(%lg, %d)",x, (int)y);
       return pBuffer;
   }

   // Traiter le cas general
   //
   sprintf(pBuffer, "(%lg, %lg)", x, y);
   return pBuffer;
}





