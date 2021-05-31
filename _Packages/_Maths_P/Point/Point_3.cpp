//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Point - Methodes projX, projY et distance
//
// Auteur : A. Thuaire
//
#include "Point.h"

// --- Projection sur l'axe des abscisses
//
Point* Point::projX () const {return new Point(abscisse(), 0);}

// --- Projection sur l'axe des ordonnees
//
Point* Point::projY () const {return new Point(0, ordonnee());}

// --- Calcul de la distance entre deux points
//
double Point::distance (const Point& P) const {
double a1= abscisse(), b1= ordonnee();
double a2= P.abscisse(), b2= P.ordonnee();
	
   return sqrt((a1-a2)*(a1-a2)+(b1-b2)*(b1-b2));
}	

















