//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Angle : angle du plan euclidien (unite : radian)
//
// Edition A    : specifications techniques initiales
//    + Version 1.0.0  : version initiale
//    + Version 1.1.0  : introduction des packages
//    + Version 1.2.0  : introduction des exceptions
//
// Edition B    : travaux simulateur Trafalgar
//    + Version 2.0.0  : version initiale
//    + Version 2.0.1  : evolution de la surcharge de l'operateur ==
//    + Version 2.1.0  : ajout du predicat neutre   
//
// Edition C    : introduction de la persistance des objets
//    + Version 3.0.0  : version initiale
//  
// Auteur : A. Thuaire
//
#ifndef _RxR_
#include "..\RxR\RxR.h"
#endif

#define _Angle_

class Angle : public Object {
private :
double m_sin;
double m_cos;

public :
// ------ Constructeurs
//
Angle();
Angle(double);
Angle(double, double);
Angle(const RxR&, const RxR&, const RxR&);

// ------ Predicats predefinis
//
inline bool neutre() {return (fabs(m_sin) < EPSILON) && (fabs(m_cos -1) < EPSILON);}
inline bool ok ()    {return fabs(m_sin*m_sin + m_cos*m_cos) < 1 + EPSILON && 
                             fabs(m_sin*m_sin + m_cos*m_cos) > 1 - EPSILON;   }
inline bool nok()    {return !ok();}

// ------ Accesseurs
//
inline double sinus ()   const {return (fabs(m_sin) < EPSILON) ? 0 : m_sin;}
inline double cosinus () const {return (fabs(m_cos) < EPSILON) ? 0 : m_cos;}        

// ------ Surcharges d'operateurs
//
Angle&  operator = (const Angle&);
bool    operator ==(const Angle&);
bool    operator !=(const Angle&);

Angle*  operator + (const Angle&);
Angle&  operator +=(const Angle&);

Angle*  operator - ();
Angle*  operator - (const Angle&);
Angle&  operator -=(const Angle&);

// ------ Services
//
char*  toString();

void serialize (Archive&);

};



