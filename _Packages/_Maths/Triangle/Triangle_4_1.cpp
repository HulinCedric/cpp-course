//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Triangle - Methode appartient
//
// Auteur : C.Fouco
//
#include "Triangle.h"

// --- Appartenance d'un point P a un triangle
//
//   vrai   si P est un des sommets
//   vrai   si P appartient a une des aretes
//   vrai   si l'aire du triagnle est egale a la somme des aires 
//             des triangles formes par P les sommets
//   faux   sinon
// 
bool Triangle::appartient (const Point& P) const {

   // Controler si le point P est un sommet du triangle
   //
   if (sommet(P)) return true;

   // Controler si P appartient a une des aretes du triangle
   //
   Segment* pArete;
   for (int i=1; i<=3; i++) {
      pArete= arete(i);
      if (pArete->appartient(P)) {delete pArete; return true;}
      delete pArete;
   }

   // Obtenir les trois sommets du triangle
   //
   Point* pA= sommet(1);
   Point* pB= sommet(2);
   Point* pC= sommet(3);

   // Controler l'alignement eventuel de P avec deux
   // des sommets du triangle
   //
   Segment AB(*pA, *pB), BC(*pB, *pC), CA(*pC, *pA);
   if (AB.aligne(P)) return false;
   if (BC.aligne(P)) return false;
   if (CA.aligne(P)) return false;

   // Construire les triangles formes par P et chacun des sommets
   //
   Triangle APB(*pA, P, *pB);
   Triangle BPC(*pB, P, *pC);
   Triangle CPA(*pC, P, *pA);

   // Detruire les sommets de travail
   //
   delete pA; delete pB; delete pC;

   // Calculer la somme des aires des trois triangles
   //
   double somme= 0;

   somme=APB.surface() + BPC.surface() + CPA.surface();

   // Restituer le resultat
   //
   return fabs(somme-surface()) < EPSILON;
}




