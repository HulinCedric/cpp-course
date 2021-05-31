//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe RxR - Operateurs =, == et !=
//
// Auteur : A. Thuaire
//
#include "RxR.h"

// --- Surcharges de l'operateur =
//
RxR& RxR::operator =(const RxR& z) {

   m_abscisse= z.m_abscisse;
   m_ordonnee= z.m_ordonnee;

   return *this;
}

RxR& RxR::operator =(double reel) {

   m_abscisse= reel;
   m_ordonnee= 0.0;

   return *this;
}

// --- Surcharges de l'operateur ==
//
bool RxR::operator ==(const RxR& z) const {

   if (m_abscisse != z.m_abscisse) return false;
   if (m_ordonnee != z.m_ordonnee) return false;

   return true;
}

bool RxR::operator ==(double reel) const {

   if (m_abscisse != reel) return false;
   if (m_ordonnee != 0.0) return false;

   return true;
}

// --- Surcharges de l'operateur !=
//
bool RxR::operator !=(const RxR& z) const {return !(*this==z);}

bool RxR::operator !=(double reel) const {return !(*this==reel);}










