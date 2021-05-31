//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Point - Methodes rotation
//
// Auteur : A. Thuaire
//
#include "Point.h"

// --- Rotation d'un angle teta par rapport a l'origine
//
Point* Point::rotation (double teta) const {

   // Traiter le cas particulier d'un angle nul
   //
   if (teta==0.0) return new Point(abscisse(), ordonnee());

   // Traiter le cas particulier d'un antecedant au centre de la rotation
   //
   Point O(0, 0);
   if (*this==O) return new Point(abscisse(), ordonnee());

   // Calculer l'affixe de la rotation
   //
   RxR z(cos(teta), sin(teta));

   // Allouer le resultat 
   //
   Point* pImage= new Point(abscisse(), ordonnee());
   if (pImage==NULL) return NULL;

   // Restituer le resultat 
   //
   *pImage *= z;
   return pImage;
}

// --- Rotation d'un angle teta par rapport a un centre quelconque
//
Point* Point::rotation (const Point& centre, double teta) const {

   // Traiter le cas particulier d'un angle nul
   //
   if (teta==0.0) return new Point(abscisse(), ordonnee());

   // Traiter le cas particulier d'un antecedant au centre de la rotation
   //
   if (*this==centre) return new Point(abscisse(), ordonnee());

   // Executer un changement d'origine au centre de la rotation
   //
   Vecteur V1(-centre.abscisse(), -centre.ordonnee());
   Point* pW1= translation(V1);
   if (pW1==NULL) return NULL;

   // Executer la rotation par rapport à la nouvelle origine
   //
   Point* pW2= pW1->rotation(teta);
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









