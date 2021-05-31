//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Triangle - Methode distance
//
// Auteur : C.Fouco
//
#include "Triangle.h"

// --- Distance d'un point a un triangle
//
//     PSj (j=1,3) designe la distance de P a chacun des sommets
//     PHi (i=1,3) designe la distance de P a chacune des aretes
//
//     d= 0                   si le point appartient au triangle
//     d= min (min PSj), PHi  sinon  
//
double Triangle::distance (const Point& P) const {

   // Controler si le point P appartient au triangle
   //
   if (appartient(P)) return 0.;

   // Calculer le minimum des distances aux trois sommets
   //
   double minimum= -1., d;
   Point* pS;
   for (int i=1; i<=3; i++) {
      pS= sommet(i);
      if (pS==NULL) throw -1.0;
      d= P.distance(*pS);
      delete pS;
      if (minimum < 0 || minimum > d) minimum=d;  
   }

   // Calculer le minimum des projections sur les aretes
   //
   Segment* pArete;
   Point*   pH;

   for (int j=1; j<=3; j++) {
      pArete= arete(j);
      pH= pArete->projection(P);
      delete pArete;
      if (pH != NULL) { 
        d= pH->distance(P);
        delete pH;
        if (minimum > d) minimum=d;  
      }
   }

   // Restituer le resultat
   //
   return minimum;
}


