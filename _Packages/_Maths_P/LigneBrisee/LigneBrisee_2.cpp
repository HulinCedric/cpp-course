//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe LigneBrisee - Accesseurs de consultation
//
// Auteur : A. Thuaire
//
#include "LigneBrisee.h"

// --- Calcul du nombre de sommets
//
int LigneBrisee::cardinal() const {

   // Controler la validite de l'objet support
   //
   if (nok()) throw -2.0;;

   // Parcourir le tableau des sommets
   //
   for (int compteur= 0; m_pSommets[compteur] != NULL; compteur++);

   // Restituer le resultat
   //
   return compteur;
}

// --- Obtenir le premier sommet
//
Point* LigneBrisee::premierSommet() const {

   // Controler la validite de l'objet support
   //
   if (nok()) throw -2.0;

   // Controler le cas particulier d'une ligne brisee vide
   //
   if (m_pSommets[0] == NULL) return NULL;

   // Allouer le resultat
   //
   Point* pResultat= new Point(m_pSommets[0]->abscisse(),
                               m_pSommets[0]->ordonnee());
   if (pResultat == NULL) throw -1.0;

   // Restituer le resultat
   //
   return pResultat;
}

// --- Obtenir le dernier sommet
//
Point* LigneBrisee::dernierSommet() const {

   // Controler la validite de l'objet support
   //
   if (nok()) throw -2.0;

   // Controler le cas particulier d'une ligne brisee vide
   //
   if (m_pSommets[0] == NULL) return NULL;

   // Allouer le resultat
   //
   Point* pResultat= new Point(m_pSommets[cardinal()-1]->abscisse(),
                               m_pSommets[cardinal()-1]->ordonnee());
   if (pResultat == NULL) throw -1.0;

   // Restituer le resultat
   //
   return pResultat;
}

// --- Calcul de la longueur d'une ligne brisee
//
double LigneBrisee::longueur() const {

   // Controler la validite de l'objet support
   //
   if (nok()) throw -2.0;

   // Traiter les cas particuliers
   //
   int taille= cardinal();
   if (taille < 2) return 0.;

   // Parcourir le tableau des sommets
   //
   double resultat= 0.;
   for (int compteur= 0; m_pSommets[compteur+1] != NULL; compteur++)
      resultat+= m_pSommets[compteur]->distance(*m_pSommets[compteur+1]);

   // Restituer le resultat
   //
   return resultat;
}






   




