//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe RxR - Surcharge de la methode serialize
//
// Auteur : A. Thuaire
//
#include "RxR.h"

// --- Serialisation des instances 
//
void RxR::serialize(Archive& ar) {

   if (ar.isStoring()) {
      ar << m_abscisse;
      ar << m_ordonnee;
   }
   else {
      ar >> m_abscisse;
      ar >> m_ordonnee;
   } 
}





