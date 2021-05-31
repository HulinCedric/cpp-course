//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2007_2008 - Package _Maths
//
// Classe Droite - Methodes projection et distance
//
// Auteur : A. Thuaire
//
#include "Droite.h"

// --- Calcul de la projection H d'un point donne P sur la droite cible
//
// On utilise les deux proprietes suivantes :
//
// 1) produit scalaire nul entre PH et un vecteur directeur de la droite cible
// 2) le point H appartient a la droite cible
//
Point* Droite::projection(const Point& P) {

   // Traiter le cas particulier ou le point P appartient a la droite
   //
   if (appartient(P)) return new Point(P.abscisse(), P.ordonnee());
	
   // Traiter le cas particulier d'une droite cible // aux ordonnnees (a=0)
   //
   if (m_A==0) return new Point(-m_C/m_B, P.ordonnee());

   // Traiter le cas particulier d'une droite cible // aux ordonnees (b=0)
   //
   if (m_B==0) return new Point(P.ordonnee(), -m_C/m_A);

   // Traiter le cas particulier d'une droite 

   // Determiner la droite passant par P et perpendiculaire a la droite cible
   //
   Droite PH(1, -m_A/m_B, -P.ordonnee()+m_A/m_B*P.abscisse());

   // Calculer les coordonnees du point H
   //
   return intersection(PH);
}

// --- Calcul de la distance d'un point P a la droite cible
//
double Droite::distance(const Point& P) {

double resultat;

   // Projeter le point P sur la droite
   //
   Point* pH=projection(P);
   if (pH==NULL) throw -1.0;

   // Traiter le cas particulier ou le point appartient a la droite cible
   //
   if (appartient(P)) {delete pH;return 0;}

   // Calculer et restituer la distance PH
   //
   resultat= pH->distance (P); 
   delete pH;

   return resultat;
}



