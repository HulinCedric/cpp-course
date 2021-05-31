//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe DemiDroite - Surcharge des operateurs
//
// Auteur : A. Thuaire
//
#include "DemiDroite.h"

// --- Surcharge de l'operateur = 
//
DemiDroite& DemiDroite::operator = (const DemiDroite& d) {

   // Mettre a jour les attributs de l'objet support
   //
   m_O= d.m_O;
   m_V= d.m_V;
   return *this;
}

// --- Surcharge de l'operateur == 
//
bool DemiDroite::operator == (const DemiDroite& d) {

   // Comparer les deux points origines
   //
   if (m_O!=d.m_O) return false;

   // Controler la colinearite des deux vecteurs
   //
   if (!m_V.colineaire(d.m_V)) return false;

   // Controler le sens des deux vecteurs
   //
   if (!m_V.memeSens(d.m_V)) return false;

   return true;
}




