//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Edition B      : preparation du package _Maths
//    + Version 2.0.0   : version initiale
//    + Version 2.1.0   : introduction de nouveaux constructeurs
//    + Version 2.2.0   : introduction d'un element neutre et
//                        protection des parametres reference
//    + Version 2.3.0   : suppression des fractions invalides
//                        + simplification de l'operateur <<
//  
// Auteur : C.Fouco
//
#include <stdio.h>
#include <math.h>
#include <iostream.h>

#define _Fraction_

// Fonctions publiques de servitudes
//
int PGCD (int, int);
int PPCM (int, int);

class Fraction {
private :
int m_numerateur;
int m_denominateur;

inline void neutre() {m_numerateur=0; m_denominateur=1;}
void  reduire ();

public :
Fraction () {neutre();}
Fraction(int, int);
Fraction(int);
Fraction(const Fraction&);

inline bool ok()  const {return (m_denominateur==0 ? false : true);}
inline bool nok() const {return !ok();}

inline int Fraction::numerateur()   const {return m_numerateur;}
inline int Fraction::denominateur() const {return m_denominateur;}

Fraction* operator +(const Fraction&);
Fraction* operator +(int);

Fraction* operator -(const Fraction&);
Fraction* operator -(int);

Fraction* operator *(const Fraction&);
Fraction* operator *(int);

Fraction* operator /(const Fraction&);
Fraction* operator /(int);

bool operator ==(const Fraction&);
bool operator ==(int);
 
bool operator !=(const Fraction&);
bool operator !=(int);

bool operator <(const Fraction&);
bool operator <(int);

bool operator <=(const Fraction&);
bool operator <=(int);

bool operator >(const Fraction&);
bool operator >(int);

bool operator >=(const Fraction&);
bool operator >=(int);

Fraction& operator =(const Fraction&);
Fraction& operator =(int);

Fraction& operator +=(const Fraction&);
Fraction& operator +=(int);

Fraction& operator -=(const Fraction&);
Fraction& operator -=(int);

Fraction& operator *=(const Fraction&);
Fraction& operator *=(int);

Fraction& operator /=(const Fraction&);
Fraction& operator /=(int);

friend ostream& operator <<(ostream&, const Fraction&);

char* toString() const;

};



