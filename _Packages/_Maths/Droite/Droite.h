//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Droite : droite du plan euclidien
//
// Edition A      : TD_9
//    + Version 1.0.0   : version initiale
//                        
// Auteur : A. Thuaire
//
#ifndef _Vecteur_
#include "..\Vecteur\Vecteur.h"
#endif

#ifndef _Point_
#include "..\Point\Point.h"
#endif

#define _Droite_

class Droite {

double m_A;
double m_B; 
double m_C;

public :

// ------ Constructeurs
//
Droite();
Droite(double, double, double);
Droite(const Point&, const Point&);
Droite(const Point&, const Vecteur&);

// ------ Predicats predefinis
//
inline bool neutre () {return (m_A==1. && m_B==0. && m_C==0.);}
inline bool ok  ()    {return !(m_A==0. && m_B==0. && m_C==0.);}
inline bool nok ()    {return !ok();}

// --- Accesseurs de consultation
//
inline Vecteur* directeur() {return new Vecteur(m_A, -m_B);}

// ------ Surcharges d'Operateurs
//
Droite&  operator =   (const Droite&);
bool     operator ==  (const Droite&);
bool     operator !=  (const Droite& d) {return !(*this==d);}

// ------ Services
//
bool     parallele    (const Droite&);
bool     orthogonale  (const Droite&);
bool     appartient   (const Point&);

Point*   projection   (const Point&);
double   distance     (const Point&);
Angle*   angle        (const Droite&);
Point*   intersection (const Droite&);

char*    toString();

};



