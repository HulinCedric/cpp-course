//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2007_2008 - Package _Maths
//
// Classe Droite - Methodes intersection et appartient
//
// Auteur : A. Thuaire
//
#include "Droite.h"

// --- Calcul du point d'intersection de deux droites
//
Point* Droite::intersection(const Droite& D) {
double xS, yS;

   // Traiter le cas particulier de deux droites // a l'axe des abscisses
   //
   if(m_A == 0 && D.m_A ==0) return NULL;

   // Traiter le cas particulier d'une cible // a l'axe des abscisses
   //
   if(m_A == 0) {
      xS= -m_C/m_B;
      yS= (-D.m_B/D.m_A)*xS -D.m_C/D.m_A;
      return new Point(xS, yS); 
   }

   // Traiter le cas particulier de l'autre droite // a l'axe des abscisses
   //
   if(D.m_A == 0) {
      xS= -D.m_C/D.m_B;
      yS= (-m_B/m_A)*xS -m_C/m_A;
      return new Point(xS, yS); 
   }

   // Traiter le cas particulier des deux droites //
   //
   if(m_B/m_A == D.m_B/D.m_A) return NULL;

   // Calculer les coordonnees du point d'intersection S
   //
   xS= (m_C/m_A - D.m_C/D.m_A) / (-m_B/m_A + D.m_B/D.m_A);
   yS=(-D.m_B/D.m_A)*xS-(D.m_C/D.m_A);

   return new Point(xS, yS); 
}

// --- Determine si un point donne appartient ou pas a la droite cible
//
bool Droite::appartient(const Point& p) {

   return fabs(m_A*p.ordonnee()+m_B*p.abscisse()+m_C) < EPSILON;
}



