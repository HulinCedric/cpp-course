//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Point - Methode homothetie
//
// Auteur : A. Thuaire
//
#include "Point.h"

// --- Homothetie par rapport a l'origine
//
Point* Point::homothetie (double rapport) const {

   // Controler la validite du rapport
   //
   if (rapport==0.0) throw -3.0;

   // Allouer et restituer le resultat
   //
   return new Point(abscisse()*rapport, ordonnee()*rapport);
}

// --- Homothetie par rapport a un centre quelconque
//
Point* Point::homothetie (const Point& centre, double rapport) const {

   // Controler la validite du rapport
   //
   if (rapport==0.) throw -3.0;

   // Controler le cas particulier d'un antecedant au centre de l'homothetie
   //
   if (*this==centre) return new Point(abscisse(), ordonnee());

   // Executer un changement d'origine au centre de l'homothetie
   //
   Vecteur V1(-centre.abscisse(), -centre.ordonnee());
   Point* pW1= translation(V1);
   if (pW1==NULL) return NULL;

   // Executer l'homothetie par rapport à la nouvelle origine
   //
   Point* pW2= pW1->homothetie(rapport);
   delete pW1;
   if (pW2==NULL) return NULL;

   // Executer le changement d'origine inverse du precedent
   //
   Vecteur V2(centre.abscisse(), centre.ordonnee());
   Point* pImage= pW2->translation(V2);
   delete pW2;

   // Restituer le resultat 
   //
   return pImage;
}










