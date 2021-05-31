//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Angle - Operateurs =, == et !=
//
// Auteur : A. Thuaire
//
#include "Angle.h"

// --- Surcharge de l'operateur =
//
Angle& Angle::operator = (const Angle& A) {

   m_sin = A.m_sin;
   m_cos = A.m_cos;
   return *this;
}

// --- Surcharge de l'operateur ==
//
bool Angle::operator == (const Angle& A) {
   return fabs(m_sin - A.m_sin) < fabs(EPSILON) && 
          fabs(m_cos - A.m_cos) < fabs(EPSILON);
}

// --- Surcharge de l'operateur !=
//
bool Angle::operator != (const Angle& A) {
	return !(*this==A);
}