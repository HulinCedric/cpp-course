//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe LigneBrisee - Agregat de N points (N >=0), non necessairement distincts
//
// Edition A    : IE_1 
//    + Version 1.0.0  : version initiale
//    + version 1.1.0  : ajout du specificateur const aux predicats
//                       + ajout methode privee controlerTaille
//                       + modification des signatures des methodes
//                         premierSommet et dernierSommet
//
// Edition C    : introduction de la persistance des objets
//    + Version 3.0.0  : version initiale
//      
// Auteur : A. Thuaire
//
#include <string.h>
#ifndef _Point_
#include "..\Point\Point.h"
#endif

#define _LigneBrisee_

class LigneBrisee : public Object {
private :
Point** m_pSommets;

int controlerTaille();

public :
// ------ Constructeurs et destructeur
//
LigneBrisee();
LigneBrisee(const LigneBrisee&);
~LigneBrisee();

// ------ Predicats predefinis
//
inline bool neutre() const {return m_pSommets[0]==NULL;}
inline bool ok ()    const {return m_pSommets != NULL;}
inline bool nok()    const {return !ok();}

// ------ Accesseurs de consultation
//
int    cardinal      () const;
Point* premierSommet () const;
Point* dernierSommet () const;
double longueur      () const; 

// ------ Surcharges d'operateurs
//
LigneBrisee& operator =(const LigneBrisee&);

bool operator ==(const LigneBrisee&);
bool operator !=(const LigneBrisee&);

LigneBrisee& operator +=(const Point&);
LigneBrisee& operator +=(const Point*);
LigneBrisee& operator +=(const LigneBrisee&);

Point*       operator [](int);
LigneBrisee* operator ()(int, int);

// ------ Services
//
bool  appartient (const Point&) const;
bool  inclus     (const LigneBrisee&) const;
 
char* toString   ();

void serialize (Archive&);

};



