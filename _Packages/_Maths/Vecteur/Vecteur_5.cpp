//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Vecteur - Services colineaire, orthogonal et memeSens  
//
// Auteur : A. Thuaire
//
#include "Vecteur.h"

// --- Colinearite de deux vecteurs
//
bool Vecteur::colineaire (const Vecteur& V) const {

   return (fabs(m_x*V.m_y - V.m_x*m_y) < EPSILON);
}

// --- Orthogonalite de deux vecteurs
//
bool Vecteur::orthogonal (const Vecteur& V) const {

   return (fabs(m_x*V.m_x + m_y*V.m_y) < EPSILON);
}

// --- Vecteurs de meme sens
//
bool Vecteur::memeSens (const Vecteur& V) const {

   // Controler la direction
   //
   if (!colineaire(V)) return false;

   // Controler le sens
   //
   return ((m_x*V.m_x >=0) && (m_y*V.m_y >=0));
}

// --- Angle forme par deux vecteurs
//
Angle* Vecteur::angle (const Vecteur& V) const {

   // Traiter le cas particulier de deux vecteurs orthogonaux
   //
   if (orthogonal(V)) return new Angle(1., 0.);

   // Traiter le cas particulier de deux vecteurs colineaires
   //
   if (colineaire(V) && memeSens(V)) return new Angle(0., 1.);
   if (colineaire(V) && !memeSens(V)) return new Angle(0., -1.);

   // Calculer le produit des normes des deux vecteurs
   //
   double prodN= V.norme()*norme();

   // Calculer le produit vectoriel des deux vecteurs
   //
   double dX1= abscisse(),   dY1= ordonnee();
   double dX2= V.abscisse(), dY2 = V.ordonnee();
   double prodV= dX1*dY2 - dX2*dY1;

   // Calculer le produit scalaire des deux vecteurs
   //
   double prodS= dX1*dX2 + dY1*dY2;

   // Restituer le resultat
   //
   return new Angle(prodV/prodN, prodS/prodN);
}








