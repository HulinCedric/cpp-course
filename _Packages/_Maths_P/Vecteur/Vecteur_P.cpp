//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Vecteur - Surcharge de la methode serialize
//
// Auteur : A. Thuaire
//
#include "Vecteur.h"

// --- Serialisation des instances 
//
void Vecteur::serialize(Archive& ar) {

   if (ar.isStoring()) {
      ar << m_x;
      ar << m_y;
   }
   else {
      ar >> m_x;
      ar >> m_y;
   } 
}





