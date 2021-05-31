//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe RxR - Accesseurs de consultation
//
// Auteur : A. Thuaire
//
#include "RxR.h"

// --- Calcul du module
//
double RxR::rho () const {
double a=m_abscisse;
double b=m_ordonnee;

   return sqrt(a*a+b*b);
}

// --- Calcul de l'argument
//
double RxR::teta () const {

   // Traiter le cas particulier de l'axe des ordonnees
   //
   if (m_abscisse == 0.0) 
   if (m_ordonnee >= 0.0) return PI/2;
   else return -PI/2;

   // Traiter le cas general
   //
   double teta_1= atan(m_ordonnee/m_abscisse);

   if (m_abscisse > 0.0f) return teta_1;    
   return teta_1+PI;
}















