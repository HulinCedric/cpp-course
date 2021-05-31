//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Segment - Couple de points distincts du plan euclidien
//
// Edition A    : TD_6 
//    + Version 1.0.0  : version initiale
//
// Edition B    : travaux simulateur Trafalgar
//    + Version 2.0.0  : version initiale
//
// Auteur : A. Thuaire
//
#ifndef _Point_
#include "..\Point\Point.h"
#endif

#define _Segment_

class Segment {
private :
Point m_A;
Point m_B;

public :
// --- Constructeurs
//
Segment();
Segment(const Point&, const Point&);

// --- Accesseurs
//
Point**  extremites () const;
bool     extremite  (const Point&);
double   longueur   () const;
Point*   milieu     () const;
bool     horizontal ();
bool     vertical   ();

// --- Operateurs
//
Segment& operator =(const Segment&);
bool operator ==(const Segment&);
bool operator !=(const Segment&);

// --- Services
//
Segment*  projX(); 
Segment*  projY();
bool      aligne      (const Point&) const;
bool      appartient  (const Point&) const;
Point*    projection  (const Point&) const;
double    distance    (const Point&) const;

// --- Transformations du plan
//
Segment*  translation (const Vecteur&) const;

Segment*  rotation    (double) const;
Segment*  rotation    (const Point&, double) const;

Segment*  symetrie    () const;
Segment*  symetrie    (const Point&) const;

Segment*  homothetie  (double) const;
Segment*  homothetie  (const Point&, double) const;

char*     toString();

};



