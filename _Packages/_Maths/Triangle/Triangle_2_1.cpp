//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Triangle - Accesseurs de consultation (1ere partie)
//
// Auteur : C.Fouco
//
#include "Triangle.h"

// --- Controle d'un sommet d'un triangle
//
bool Triangle::sommet (const Point& P) const { 
	
   return (m_A == P || m_B == P || m_C == P);
}

// --- Restitution d'un sommet d'un triangle
//
Point* Triangle::sommet (int rang) const {

   // Controler la validite du parametre
   //
   if (rang < 1 || rang > 3) throw -2.1;

   // Restituer le resultat
   //
   switch (rang) {
      case 1  : return new Point(m_A);
      case 2  : return new Point(m_B);
      case 3  : return new Point(m_C);
      default : return NULL;
   }
}

// --- Calcul du perimetre d'un triangle
//
double Triangle::perimetre() const {

   return m_A.distance(m_B) + m_B.distance(m_C) + m_C.distance(m_A);
}

// --- Calcul de la surface du triangle (Formule de Poisson)
//
double Triangle::surface() const {

   double a = m_B.distance(m_C);
   double b = m_C.distance(m_A);
   double c = m_A.distance(m_B);

   double demiP= perimetre()/2;

   return sqrt(demiP*(demiP-a)*(demiP-b)*(demiP-c));
}






