//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe LigneBrisee - Surcharges de l'operateur +=
//                      (avec retour this)
//
// Auteur : A. Thuaire
//
#include "LigneBrisee.h"

// --- Ajout d'un sommet a une ligne brisee (premiere forme)
//
LigneBrisee& LigneBrisee::operator +=(const Point& P) {

   // Controler la validite de l'objet support
   //
   if (nok()) throw -2.0;

   // Allouer le nouveau sommet
   //
   Point* pNew= new Point(P.abscisse(), P.ordonnee());
   if (pNew == NULL) throw -1.0;

   // Controler et adapter eventuellement la taille du tableau sous jacent
   //
   int taille= controlerTaille();

   // Ajouter le nouveau sommet en fin de la ligne brisee
   //
   m_pSommets[taille]  = pNew;
   m_pSommets[taille+1]= NULL;

   // Restituer le resultat
   //
   return *this;
}

// --- Ajout d'un sommet a une ligne brisee (seconde forme)
//
LigneBrisee& LigneBrisee::operator +=(const Point* pP) {

   // Controler la validite de l'objet support
   //
   if (nok()) throw -2.0;

   // Controler la validite du parametre
   //
   if (pP == NULL) throw -2.1;

   // Allouer le nouveau sommet
   //
   Point* pNew= new Point(pP->abscisse(), pP->ordonnee());
   if (pNew == NULL) throw -1.0;

   // Controler et adapter eventuellement la taille du tableau sous jacent
   //
   int taille= controlerTaille();

   // Ajouter le sommet en fin de la ligne brisee
   //
   m_pSommets[taille]  = pNew;
   m_pSommets[taille+1]= NULL;

   // Restituer le resultat
   //
   return *this;
}

// --- Reunion de deux lignes brisees
//
LigneBrisee& LigneBrisee::operator +=(const LigneBrisee& B) {

   // Controler la validite de l'objet support
   //
   if (nok()) throw -2.0;

   // Controler la validite du parametre
   //
   if (B.nok()) throw -2.1;

   // Parcourir les sommets de la ligne brisee B
   //
   Point* pNew;
   int taille;
   for (int i= 0; B.m_pSommets[i] != NULL; i++) {

      // Dupliquer le sommet courant
      //
      pNew= new Point(B.m_pSommets[i]->abscisse(), B.m_pSommets[i]->ordonnee());
      if (pNew == NULL) throw -1.0;

      // Ajouter le duplicata a l'objet support
      //
	  taille= controlerTaille();
      m_pSommets[taille]  = pNew;
      m_pSommets[taille+1]= NULL;
   }

   // Restituer le resultat
   //
   return *this;
}








   




