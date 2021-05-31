//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Triangle - Methode intersection
//
// Auteur : C.Fouco
//
#include "Triangle.h"

// --- Intersection d'une demi droite avec un triangle, en ne
//     conservant que le point du triangle le plus proche de 
//     l'origine de la demi droite
//     
//
Point* Triangle::intersection (const DemiDroite& d) const {
Segment* pArete;
Point* pI= NULL;

   // Obtenir l'origine de la demi droite
   //
   Point* pOrigine= d.origine();
   if (pOrigine==NULL) throw -1.0;

   // Traiter le cas particulier ou l'origine de la demi droite 
   // est un des sommets du triangle
   //
   if (sommet(*pOrigine)) return pOrigine;

   // Traiter le cas particulier ou l'origine de la demi droite 
   // appartient au triangle
   //  
   if (appartient(*pOrigine)) {

      // Determiner le point d'intersection unique avec les aretes
      //
      for (int i=1; i<3; i++) {
         pArete= arete(i);
         if (pArete==NULL) throw -1.0;
         pI= d.intersection(*pArete);
         if (pI != NULL) {delete pArete; return pI;}
         delete pArete;
      }

      throw -1.0;
   }

   // Traiter le cas particulier ou l'origine de la demi droite 
   // est dans le prolongement d'une arete
   // 
   bool alignement= false;
   for (int i=1; i<3; i++) {

      // Obtenir l'arete courante
      //
      pArete= arete(i);
      if (pArete==NULL) throw -1.0;

      // Controler si la demi droite porte l'arete
      //
      if (d.support(*pArete)) {alignement= true; break;}
      delete pArete;
   }

   if (alignement) {

      // Obtenir les extremites de l'arete 
      // 
      Point** pExtremites= pArete->extremites();
      delete pArete;
      if (pExtremites==NULL) throw -1.0;

      // Determiner le sommet du triangle le plus proche 
      // 
      double d1= pOrigine->distance(*pExtremites[0]);
      double d2= pOrigine->distance(*pExtremites[1]);
      delete pOrigine;

      if (d1 < d2) pI= new Point(*pExtremites[0]);
      else pI= new Point(*pExtremites[1]);

      // Restituer ce sommet 
      // 
      delete pExtremites[0];
      delete pExtremites[1];
      delete[] pExtremites;

	  return pI;
	}



   // Traiter le cas general en calculant les points d'intersection 
   // de la demi droite avec chacune des aretes du triangle et en
   // determinant le plus proche de l'origine de la demi droite
   //
   Point* pW;
   double dCourant= -1, dW;
   bool intersection= false;

   for (int k=1; k<=3; k++) {

      // Obtenir l'arete courante
      //
      pArete= arete(k);
      if (pArete==NULL) throw -1.0;

      // Calculer le point d'intersection avec l'arete courante
      //
      pW= d.intersection(*pArete);
      if (pW==NULL) {delete pArete;continue;}

      // Calculer la distance de l'origine de la demi droite
      // a l'intersection courante
      //
      intersection= true;
      dW= pOrigine->distance(*pW);

      // Traiter le cas de la premiere intersection
      //
      if (dCourant == -1) {
         dCourant= dW;
         pI= pW;
         delete pArete;
         continue;
      }

      // Traiter le cas d'intersections multiples en conservant
      // uniquement l'intersection la plus proche de l'origine
      // de la demi droite
      //
      if (dCourant > dW) {
         dCourant= dW;
         if (pI != NULL) delete pI; 
         pI= pW;
         delete pArete;
         continue;
      }

      delete pW; delete pArete;
   }

   // Restituer le resultat en presence d'une intersection 
   //
   if (intersection) return pI;

   // Traiter le cas particulier d'une intersection sur
   // un sommet du triangle

   for (int j=1; j<=3; j++) {

      // Obtenir le sommet courant
      //
      pI= sommet(j);
      if (pI==NULL) throw -1.0;

      // Determiner si le sommet appartient a la demi droite
      //
      if (d.appartient(*pI)) return pI;

      // Supprimer l'intersection courante
      //
      delete pI;
   }

   // Restituer le resultat en l'absence d'intersections
   //
   return NULL;
}


