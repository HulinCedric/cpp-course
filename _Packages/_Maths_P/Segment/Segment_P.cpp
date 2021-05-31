//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Segment - Surcharge de la methode serialize
//
// Auteur : A. Thuaire
//
#include "Segment.h"

// --- Serialisation des instances 
//
void Segment::serialize(Archive& ar) {

      m_A.serialize(ar);
      m_B.serialize(ar);
}





