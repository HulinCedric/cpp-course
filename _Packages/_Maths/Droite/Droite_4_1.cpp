//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2007_2008 - Package _Maths
//
// Classe Droite - Methodes parallele, orthogonale et appartient
//
// Auteur : A. Thuaire
//
#include "Droite.h"

// --- Determine si une droite cible est parallele a une seconde
//
bool Droite::parallele(const Droite& d) {

   // Traiter les cas particuliers
   //
   if (m_A==0 && d.m_A==0) return true;
   if (m_A==0 && d.m_A!=0) return false;
   if (m_A!=0 && d.m_A==0) return false;

   // Traiter le cas general
   //
   return fabs(m_B/m_A - d.m_B/d.m_A) < EPSILON;
}

// --- Determine si une droite cible est orthogonale a une seconde
//
bool Droite::orthogonale(const Droite& d) {

   // Traiter les cas particuliers
   //
   if (m_A==0 && d.m_B==0) return true;
   if (m_A==0 && d.m_B!=0) return false;
   if (m_B==0 && d.m_A==0) return true;
   if (m_B==0 && d.m_A!=0) return false;

   // Traiter le cas general
   //
   double coef1= -m_B/m_A;
   double coef2= -d.m_B/d.m_A;

   return fabs(coef1*coef2 + 1) < EPSILON;
}




