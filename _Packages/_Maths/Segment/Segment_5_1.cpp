//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Segment - Methodes aligne et appartient
//
// Auteur : A. Thuaire
//
#include "Segment.h"

// --- Controle de l'alignement d'un point par rapport a un segment
//
bool Segment::aligne (const Point& P) const {

   // Controler la colinearite des vecteurs AP et PB
   //
   Vecteur AP(m_A, P), PB(P, m_B);
   if (AP.colineaire(PB)) return true;
   
   return false;
}

// --- Controle de l'appartenance d'un point a un segment
//
bool Segment::appartient (const Point& P) const {

   // Calculer le produit scalaire des vecteurs PA et PB
   //
   Vecteur AP(m_A, P), PB(P, m_B);
   double produitScalaire= AP*PB;

   // Controler le produit scalaire (cos(PI)= -1)
   //
   if (fabs(produitScalaire - AP.norme()*PB.norme()) < EPSILON) return true;
   return false;
}












