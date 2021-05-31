//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Segment - Methode distance
//
// Auteur : A. Thuaire
//
#include "Segment.h"

// --- Distance orthogonale d'un point a un segment
//
double Segment::distance (const Point& P) const {

   // Projeter le point sur le segment
   //
   Point* pH= projection(P);
   if (pH== NULL) throw -3.1;

   // Calculer la distance PH
   //
   Vecteur PH(P, *pH);
   double resultat= PH.norme();

   // Restituer le resultat
   //
   delete pH; 
   return resultat;
}












