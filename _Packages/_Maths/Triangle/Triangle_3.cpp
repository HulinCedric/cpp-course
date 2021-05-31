//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Triangle - Surcharge des operateurs
//
// Auteur : C.Fouco
//
#include "Triangle.h"

// Surcharge des operateurs
//
Triangle& Triangle::operator = (const Triangle& T) {

   // Affecter les trois attributs
   //
   m_A = T.m_A;
   m_B = T.m_B;
   m_C = T.m_C;

   return *this;
}

bool Triangle::operator == (const Triangle& T) {

   // Comparer les sommets deux a deux
   //
   if (m_A == T.m_A && m_B == T.m_B && m_C == T.m_C) return true;
   if (m_A == T.m_A && m_B == T.m_C && m_C == T.m_B) return true;
   if (m_A == T.m_B && m_B == T.m_A && m_C == T.m_C) return true;
   if (m_A == T.m_B && m_B == T.m_C && m_C == T.m_A) return true;
   if (m_A == T.m_C && m_B == T.m_A && m_C == T.m_B) return true;
   if (m_A == T.m_C && m_B == T.m_B && m_C == T.m_A) return true;
   
   return false;
}

bool Triangle::operator != (const Triangle& T) {return !(*this == T);}




