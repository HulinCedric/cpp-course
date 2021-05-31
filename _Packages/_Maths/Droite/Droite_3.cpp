//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Droite - Surcharges des operateurs = et ==
//
// Auteur : A. Thuaire
//
#include "Droite.h"

// --- Surcharge de l'operateur =
//
Droite& Droite::operator = (const Droite& d) {

   m_A = d.m_A;
   m_B = d.m_B;
   m_C = d.m_C;

   return *this;
}

// --- Surcharge de l'operateur ==
//
bool Droite::operator == (const Droite& d) {

   // Traiter le cas particulier d'une seule droite // a l'axe des abscisses
   //
   if (m_A == 0   && d.m_A != 0) return false;
   if (d.m_A == 0 && m_A != 0)   return false;

   // Traiter le cas particulier de deux droites // a l'axe des abscisses
   //
   if (m_A == 0 && d.m_A == 0) {
      if (m_C/m_B != d.m_C/d.m_B) return false;
      else return true;
   }

   // Traiter le cas general
   //
   if (m_B/m_A != d.m_B/d.m_A) return false;
   if (m_C/m_A != d.m_C/d.m_A) return false;
	
   return true;
}





