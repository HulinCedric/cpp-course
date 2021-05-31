//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Angle - Surcharge de la methode serialize
//
// Auteur : A. Thuaire
//
#include "Angle.h"

// --- Serialisation des instances 
//
void Angle::serialize(Archive& ar) {

   if (ar.isStoring()) {
      ar << m_sin;
      ar << m_cos;
   }
   else {
      ar >> m_sin;
      ar >> m_cos;
   } 
}





