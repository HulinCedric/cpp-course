//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe DemiDroite : demiDroite du plan euclidien
//
// Edition A      : TD_9
//    + Version 1.0.0   : version initiale
//                        
// Auteur : A. Thuaire
//
#ifndef _Droite_
#include "..\Droite\Droite.h"
#endif

#ifndef _Segment_
#include "..\Segment\Segment.h"
#endif

#define _Demi_Droite_

class DemiDroite {

Point   m_O;
Vecteur m_V;

public :
// ------ Constructeurs
//
DemiDroite();
DemiDroite(const Point&, const Vecteur&);

// ------ Predicats predefinis
//
inline bool neutre () {return m_O == Point(0, 0) && m_V == Vecteur(1, 1);}
inline bool ok  ()    {return m_V != Vecteur(0, 0);}
inline bool nok ()    {return !ok();}

// ------ Accesseurs de consultation
//
inline Point*   origine  () const {return new Point(m_O);}
inline Vecteur* directeur() const {return new Vecteur(m_V);}


// ------ Surcharges d'operateurs
//
DemiDroite&  operator =  (const DemiDroite&);
bool         operator == (const DemiDroite&);
inline bool  operator != (const DemiDroite& d) {return !(*this==d);}

// ------ Services
//
Droite*  support     ()                  const;
bool     support     (const Segment&)    const;

bool     parallele   (const Droite&)     const;
bool     parallele   (const DemiDroite&) const;

bool     orthogonale (const Droite&)     const;
bool     orthogonale (const DemiDroite&) const;

bool     appartient  (const Point&)      const;

Point*   intersection (const DemiDroite&) const;
Point*   intersection (const Droite&)     const;
Point*   intersection (const Segment&)    const;

char*    toString();

};



