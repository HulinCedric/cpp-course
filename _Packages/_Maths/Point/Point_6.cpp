//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Point - Methodes symetrie
//
// Auteur : A. Thuaire
//
#include "Point.h"

// --- Symetrie centrale par rapport a l'origine
//
Point* Point::symetrie () const {return rotation(PI);}

// --- Symetrie centrale par rapport a un centre quelconque
//
Point* Point::symetrie (const Point& centre) const {return rotation(centre, PI);}










