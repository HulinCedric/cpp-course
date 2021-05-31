//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2007_2008 - Package _Maths
//
// Classe MatriceF : matrices carrees d'ordre N (N > 1) a coefficients
//                   fractionnaires (classe Fraction)
//
// Edition B    : specifications techniques de la feuille 8
//    + Version 2.0.0   : version initiale
//    + Version 2.1.0   : supression des methodes veto, ok et nok
//
// Auteur : A. Thuaire
//
#include "..\Fraction\Fraction.h"
#include <string.h>

#define _MatriceF_

class MatriceF {
private :

Fraction* m_pT;
int  m_ordre;

public :
MatriceF();
MatriceF(int);
MatriceF(const MatriceF&);
MatriceF(const MatriceF&, int, int);
~MatriceF();

inline int  ordre() const {return m_ordre;}

void*  remplir (int, int[]);
void*  remplir (int);
void*  remplir (int, Fraction[]);

MatriceF& operator + (const MatriceF&);
MatriceF& operator + (int);
MatriceF& operator + (const Fraction&);

MatriceF& operator - (const MatriceF&);
MatriceF& operator - (int);
MatriceF& operator - (const Fraction&);
MatriceF& operator - ();
 
MatriceF& operator * (const MatriceF&);
MatriceF& operator * (int);
MatriceF& operator * (const Fraction&);

MatriceF& operator = (const MatriceF&);
MatriceF& operator = (int);
MatriceF& operator = (const Fraction&);

bool operator ==(const MatriceF&);
bool operator ==(int);
bool operator ==(const Fraction&);

bool operator !=(const MatriceF&);
bool operator !=(int);
bool operator !=(const Fraction&);

MatriceF& operator += (const MatriceF&);
MatriceF& operator += (int);
MatriceF& operator += (const Fraction&);

MatriceF& operator -= (const MatriceF&);
MatriceF& operator -= (int);
MatriceF& operator -= (const Fraction&);

MatriceF& operator *= (const MatriceF&);
MatriceF& operator *= (int);
MatriceF& operator *= (const Fraction&);

Fraction& operator () (int, int);
Fraction* operator () (int);
Fraction* operator [] (int);

Fraction* determinant ();
MatriceF& transposee  ();
MatriceF& inverse();

char*    toString();

};

