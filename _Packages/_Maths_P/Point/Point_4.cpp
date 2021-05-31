//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Point - Methode translation
//
// Auteur : A. Thuaire
//
#include "Point.h"

// --- Translation du point support d'un vecteur V quelconque
//
Point* Point::translation (const Vecteur& V) const {

   // Additionner le parametre a l'affixe du support
   //
   Vecteur* pSomme= Vecteur(abscisse(), ordonnee()) + V;

   // Allouer et restituer le resultat
   //
   return new Point(pSomme->abscisse(), pSomme->ordonnee());
}










