//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2007_2008 - Package _Maths
//
// Classe Matrice : matrices carrees d'ordre N (N > 1) a coefficients entiers
//
// Edition B    : specifications techniques de la feuille 8
//    + Version 2.0.0  : version initiale
//    + Version 2.1.0  : suppression des methodes veto, ok et nok
//                       + modification du constructeur par defaut et
//                         du constructeur de copie
//
// Auteur : A. Thuaire
//
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream.h>

#define _Matrice_

class Matrice {
private :

int* m_pT;
int  m_ordre;

public :
Matrice();
Matrice(int);
Matrice(const Matrice&);
~Matrice();

inline int  ordre() const {return m_ordre;}

void*    remplir (int, int[]);
void*    remplir (int);

Matrice& operator + (const Matrice&);
Matrice& operator + (int);

Matrice& operator - (const Matrice&);
Matrice& operator - (int);
Matrice& operator - ();
 
Matrice& operator * (const Matrice&);
Matrice& operator * (int);

Matrice& operator = (const Matrice&);
Matrice& operator = (int);

bool     operator ==(const Matrice&);
bool     operator ==(int);

bool     operator !=(const Matrice&);
bool     operator !=(int);

Matrice& operator += (const Matrice&);
Matrice& operator += (int);

Matrice& operator -= (const Matrice&);
Matrice& operator -= (int);

Matrice& operator *= (const Matrice&);
Matrice& operator *= (int);

int&     operator () (int, int);
int*     operator () (int);
int*     operator [] (int);

int      determinant ();
Matrice& transposee  ();

char*    toString();

};

