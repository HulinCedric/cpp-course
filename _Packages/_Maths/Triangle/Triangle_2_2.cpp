//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Triangle - Accesseurs de consultation (2eme partie)
//
// Auteur : C.Fouco
//
#include "Triangle.h"

// --- Calcul de l'angle associe a un sommet d'un triangle
//
Angle* Triangle::angle (const Point& S) const {

   // Controler la validite du sommet
   // 
   if (!sommet(S)) return NULL;

   // Determiner les vecteurs adjacents
   //
   Vecteur *pW1, *pW2;
   if (S == m_A) {
      pW1= new Vecteur(m_A, m_B);
      pW2= new Vecteur(m_A, m_C);
   }
   else {
      if (S == m_B) {
         pW1= new Vecteur(m_B, m_A);
         pW2= new Vecteur(m_B, m_C);
	  }
      else {
         if (S == m_C) {
            pW1= new Vecteur(m_C, m_A);
            pW2= new Vecteur(m_C, m_B);
		 }
         else return NULL;
	  }
   }

   Angle* pAngle= pW1->angle(*pW2);
   delete pW1; delete pW2;
   return pAngle;
}

// --- Calcul du vecteur oppose a un sommet S d'un triangle
//
Vecteur* Triangle::oppose (const Point& S) const {

   // Controler la validite du sommet
   // 
   if (!sommet(S)) return NULL;

   // Determiner le vecteur oppose
   //
   Vecteur* pW;
   if (S == m_A) pW= new Vecteur(m_B, m_C);		
   else if (S == m_B) pW= new Vecteur(m_A, m_C);
      else if (S == m_C) pW= new Vecteur(m_A, m_B);
           else return NULL;
   return pW;
}

// --- Determiner le sommet le plus proche d'un sommet S d'un triangle
//
Point* Triangle::plusProcheSommet (const Point& S) const {

   // Determiner les deux autres sommets
   //
   Point S1, S2;
   if (S == m_A) {S1= m_B; S2= m_C;}
   else {
      if (S == m_B) {S1= m_A; S2= m_C;}
      else {
         if (S == m_C) {S1= m_B; S2= m_A;}			
         else return NULL;
	  }
   }

   // Comparer la distance de chacun
   //
   if (S.distance(S1) < S.distance(S2)) return new Point(S1);
   return new Point(S2);
}

// --- Restitution d'une arete d'un triangle
//
Segment* Triangle::arete (int rang) const {

   // Controler la validite du parametre
   //
   if (rang < 1 || rang > 3) throw -2.1;

   // Restituer le resultat
   //
   switch (rang) {
      case 1  : return new Segment(m_A, m_B);
      case 2  : return new Segment(m_B, m_C);
      case 3  : return new Segment(m_C, m_A);
      default : return NULL;
   }
}







