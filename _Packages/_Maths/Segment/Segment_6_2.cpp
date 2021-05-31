//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Segment - Symetrie centrale d'un segment
//
// Auteur : A. Thuaire
//
#include "Segment.h"

// --- Symetrie centrale d'un segment par rapport a O(0,0)
//
Segment* Segment::symetrie () const {

   // Restituer le resultat
   //
   return rotation(PI);
}

// --- Symetrie centrale d'un segment par rapport a un centre quelconque
//
Segment* Segment::symetrie (const Point& centre) const {

   // Restituer le resultat
   //
   return rotation(centre, PI);
}












