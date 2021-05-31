//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe RxR : modelisation du corps des nombres complexes
//
// Edition A    : preparation du package _Maths
//    + Version 1.0.0  : version initiale
//    + Version 1.1.0  : introduction des packages
//    + Version 1.2.0  : introduction des exceptions
//    + Version 1.3.0  : introduction du fichier header _Maths.h
//
// Edition B    : travaux sur le simulateur Trafalgar
//    + Version 2.0.0  : version initiale
//
// Edition C    : introduction de la persistance des objets
//    + Version 3.0.0  : version initiale
//                       
// Auteur : A. Thuaire
//
#ifndef _Maths_
#include "..\_Maths\_Maths.h"
#endif

#ifndef _Object_
#include "T:\_Archives\Object\Object.h"
#endif

#define _RxR_

class RxR : public Object {

private :
double m_abscisse;
double m_ordonnee;

public :

// ------ Constructeurs
//
RxR() {m_abscisse= 0.0; m_ordonnee= 0.0;}
RxR(double, double);
RxR(double);

// ------ Accesseurs
//
inline double abscisse () const {return m_abscisse;}
inline double ordonnee () const {return m_ordonnee;}
          
double rho  () const;
double teta () const;

// ------ Operateurs
//
RxR& operator =(const RxR&);
RxR& operator =(double);

RxR* operator +(const RxR&);
RxR* operator +(double);
RxR& operator +=(const RxR&);
RxR& operator +=(double);

RxR* operator -(const RxR&);
RxR* operator -(double);
RxR* operator -();
RxR& operator -=(const RxR&);
RxR& operator -=(double);

RxR* operator *(const RxR&);
RxR* operator *(double);
RxR& operator *=(const RxR&);
RxR& operator *=(double);

RxR* operator /(RxR&);
RxR* operator /(double);
RxR& operator /=(RxR&);
RxR& operator /=(double);

bool operator == (const RxR&) const;
bool operator ==(double) const;
 
bool operator !=(const RxR&) const;
bool operator !=(double) const;

// ------ Services
//
RxR** racines (int);

char* toString();

void serialize (Archive&);

};




