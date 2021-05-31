//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe RxR - Operateurs + et +=
//
// Auteur : A. Thuaire
//
#include "RxR.h"

// --- Surcharges de l'operateur +
//
RxR* RxR::operator + (const RxR& z) {
double a1= m_abscisse;
double b1= m_ordonnee;
double a2= z.m_abscisse;
double b2= z.m_ordonnee;

   // Allouer le resultat
   //
   RxR* pResultat= new RxR(a1+a2, b1+b2);
   if (pResultat==NULL) throw -1.0;

   // Restituer le resultat
   //
   return pResultat;
}

RxR* RxR::operator + (double reel) {
double a= m_abscisse;
double b= m_ordonnee;

   // Allouer le resultat
   //
   RxR* pResultat= new RxR(a+reel, b);
   if (pResultat==NULL) throw -1.0;

   // Restituer du resultat
   //
   return pResultat;
}

// --- Surcharges de l'operateur +=
//
RxR& RxR::operator += (const RxR& z) { 

   m_abscisse += z.m_abscisse;
   m_ordonnee += z.m_ordonnee;
	
   return *this;
}

RxR& RxR::operator += (double reel) {

   m_abscisse += reel;
   return *this;
}










