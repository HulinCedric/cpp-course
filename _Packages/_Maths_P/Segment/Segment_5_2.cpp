//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Segment - Methode projection
//
// Auteur : A. Thuaire
//
#include "Segment.h"

// --- Projection orthogonale H d'un point P sur un segment [AB]
//
Point* Segment::projection (const Point& P) const {
double xH, yH;
Point* pResultat;

   // Traiter le cas ou le point P appartient au segment
   //
   if (appartient(P)) return new Point(P);

   // Traiter le cas ou les trois points A, B et P sont alignes
   //
   if (aligne(P)) return NULL;

   // Initialiser les coordonnees des trois points A, B et P
   //
   double xA= m_A.abscisse();
   double yA= m_A.ordonnee();
   double xB= m_B.abscisse();
   double yB= m_B.ordonnee();
   double xP= P.abscisse();
   double yP= P.ordonnee();

   // Traiter le cas particulier d'un segment vertical
   //
   if (fabs(xA - xB) < EPSILON) {
      xH= xA;
      yH= yP;
      pResultat= new Point(xH, yH);
      if (pResultat==NULL) throw -1.0;
      if (appartient(*pResultat)) return pResultat;
      return NULL;
   }
    
   // Traiter le cas particulier d'un segment horizontal
   //
   if (fabs(yA - yB) < EPSILON) {
      xH= xP;
      yH= yA;
      pResultat= new Point(xH, yH);
      if (pResultat==NULL) throw -1.0;
      if (appartient(*pResultat)) return pResultat;
      return NULL;
   }

   // Calculer les coefficients a, b et c de la droite (AB)
   //
   // Equation de (AB) : ay + bx + c = 0
   //
   double a= 1;
   double b= (yB - yA) / (xA - xB);
   double c= -yA - b*xA;

   // Calculer les coordonnees du point H
   //
   xH= (xP*(xB - xA) + yP*(yB - yA)+ c*(yB - yA)) / ((xB - xA) - b *(yB - yA));
   yH= -b*xH - c;

   // Allouer et restituer le resultat
   //
   pResultat= new Point(xH, yH);
   if (appartient(*pResultat)) return pResultat;
   delete pResultat;
   return NULL;
}













