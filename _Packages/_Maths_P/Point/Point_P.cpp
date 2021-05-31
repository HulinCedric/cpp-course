//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Point - Surcharge de la methode serialize
//
// Auteur : A. Thuaire
//
#include "Point.h"

// --- Serialisation des instances 
//
void Point::serialize(Archive& ar) {

   RxR::serialize(ar);

   if (ar.isStoring()) ar << m_numero;
   else ar >> m_numero;
}





