//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe DemiDroite - Methode intersection
//
// Auteur : A. Thuaire
//
#include "DemiDroite.h"

// --- Calcule le point d'intersection d'une demi-droite avec une autre
//     demi-droite (quand ce point existe)
//
Point* DemiDroite::intersection(const DemiDroite& d) const {

   // Determiner le point d'intersection P des deux supports
   //
   Droite* pS1=support();
   if (pS1==NULL) return NULL;
	
   Droite* pS2=d.support();
   if (pS2==NULL) {delete pS1; return NULL;}

   Point* pP=pS1->intersection(*pS2);
   delete pS1; delete pS2;
   if (pP==NULL) return NULL;

   // Controler l'appartenance du point P a chaque demi-droite
   //
   if(!appartient(*pP)) {delete pP;return NULL;}
   if(!d.appartient(*pP)) {delete pP;return NULL;}

   // Restituer le resultat
   //
   return pP;	
}

// --- Calcule le point d'intersection d'une demi-droite avec une droite,
//     (quand ce point existe).
//
// ATTENTION : dans le cas particulier ou la droite D est le support
//             de la demi droite cible, le service retourne NULL.
//
Point* DemiDroite::intersection(const Droite& D) const {

   // Controler le cas d'une droite D parallele a la cible
   //
	if (this->parallele(D)) return NULL;

   // Controler le cas d'une droite D support de la cible
   //
   Droite* pW= support();
   if (pW==NULL) return NULL;

   if (*pW==D) {delete pW; return NULL;}

   // Calculer le point d'intersection P des deux droites
   //
   Point* pP=pW->intersection(D);
   delete pW;

   if (pP==NULL) return NULL;

   // Controler l'appartenance du point P a la demi-droite
   //
   if(!appartient(*pP)) {delete pP;return NULL;}

   // Restituer le resultat
   //
   return pP;	
}

// --- Calcule le point d'intersection d'une demi-droite avec un segment
//     (quand ce point existe)
//
Point* DemiDroite::intersection(const Segment& S) const {

   // Determiner la droite support du segment cible
   //
   Point** pE= S.extremites();
   Point* pA= pE[0];
   Point* pB= pE[1];

   Droite* pS1=new Droite(*pA, *pB);
   if (pS1==NULL) throw -1.0;
   delete[] pE; delete pA; delete pB;

   // Determiner la droite support de la demi droite
   //
   Droite* pS2=support();
   if (pS2==NULL) {delete pS1; throw -1.0;}

   // Determiner le point d'intersection P des deux supports
   //
   Point* pP=pS1->intersection(*pS2);
   delete pS1; delete pS2;
   if (pP==NULL) return NULL;

   // Controler l'appartenance du point P a la demi droite
   //
   if(!appartient(*pP)) {delete pP;return NULL;}

   // Controler l'appartenance du point P au segment cible
   //
   if(!S.appartient(*pP)) {delete pP;return NULL;}

   // Restituer le resultat
   //
   return pP;	
}
