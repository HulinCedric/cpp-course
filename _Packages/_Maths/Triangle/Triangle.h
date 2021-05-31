//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Triangle : Agregat de 3 points distincts, non alignes
//
// Edition A    : TD_7 
//    + Version 1.0.0  : version initiale
// 
// Edition B    : travaux simulateur Trafalgar
//    + Version 2.0.0  : version initiale
//    + Version 2.0.1  : correction bug methode appartient
//    + Version 2.1.0  : ajout predicats predefinis 
//                       + accesseurs isocele, rectangle et equilateral
//                       + methodes orthocentre et barycentre
//                       + methodes hauteur, mediatrice et mediane
//                       + transformations du plan
//   
// Auteur : A. Thuaire
//
#ifndef _DemiDroite_
#include "..\DemiDroite\DemiDroite.h"
#endif

#define _Triangle_

class Triangle {
private :
Point m_A;
Point m_B;
Point m_C;

public :
// ------ Constructeurs
//
Triangle ();
Triangle (const Point&, const Point&, const Point&);
Triangle (const Point&, const Vecteur&, const Vecteur&);

// ------ Accesseurs predefinis
//
inline bool neutre() {return m_A == Point(-1., 0.) && 
                             m_B == Point(1., 0.)  &&
                             m_C == Point(0., 1.);}

inline bool ok ()    {Vecteur AB(m_A, m_B), BC(m_B, m_C);
                      return !AB.colineaire(BC);  }

inline bool nok()    {return !ok();}

// ------ Accesseurs de consultation
//
bool      sommet    (const Point&) const;
Point*    sommet    (int) const;
double    perimetre () const;			
double    surface   () const ;
Angle*    angle     (const Point&) const;
Vecteur*  oppose    (const Point&) const;
Point*    plusProcheSommet (const Point&) const;
Segment*  arete     (int) const;

bool      isocele     ();	// FAIT	
bool      equilateral ();	// FAIT	
bool      rectangle   ();	// FAIT

// ------ Surcharges d'operateurs
//
Triangle& operator =  (const Triangle&);
bool      operator == (const Triangle&);
bool      operator != (const Triangle&);

// ------ Services
//
bool      appartient (const Point&) const;
double    distance   (const Point&) const;

Point*    intersection(const DemiDroite&) const;	// FAIT
Point*    orthocentre ();							// FAIT
Point*    barycentre  ();							// FAIT

Segment*  hauteur     (int) const;		// FAIT
Segment*  mediatrice  (int) const;		// FAIT
Segment*  mediane     (int) const;		// FAIT
	
char*     toString();

// ------ Transformations du plan
//
Triangle*  translation (const Vecteur&) const;			// FAIT

Triangle*  rotation    (double) const;					// FAIT
Triangle*  rotation    (const Point&, double) const;	// FAIT

Triangle*  symetrie    () const;						// FAIT
Triangle*  symetrie    (const Point&) const;			// FAIT

Triangle*  homothetie  (double) const;					// FAIT
Triangle*  homothetie  (const Point&, double) const;	// a coder

};



