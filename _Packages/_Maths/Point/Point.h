//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Point : Geometrie euclidienne
//
// Edition A    : Cours_7
//    + Version 1.0.0  : version initiale
//
// Edition B    : travaux sur le simulateur Trafalgar
//    + Version 2.0.0  : version initiale
//                     
// Auteur : A. Thuaire
//
#ifndef _Vecteur_
#include "..\Vecteur\Vecteur.h"
#endif

#define _Point_

class Point : public RxR {
private :
int m_numero;

public :
// ------ Constructeurs
//
Point();
Point(double, double);
Point(int, double, double);

// ------ Services
//
inline int numero () const { return m_numero; }

// ------ Services
//
double distance (const Point&) const;         
Point* projX () const;
Point* projY () const;

Point* translation (const Vecteur&) const;

Point* rotation    (double) const;
Point* rotation    (const Point&, double) const;

Point* symetrie    () const;
Point* symetrie    (const Point&) const;

Point* homothetie  (double) const;
Point* homothetie  (const Point&, double) const;

char* toString();

};




