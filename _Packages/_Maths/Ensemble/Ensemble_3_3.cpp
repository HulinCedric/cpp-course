//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Ensemble - Surcharge de l'operateur =
//    
// Auteur : A. Thuaire
//
#include "Ensemble.h"

// --- Surcharge de l'operateur =
//
Ensemble& Ensemble::operator =(const Ensemble& E) {
void* pElement;

   // Controler la validite de l'objet support
   //
   if (nok()) throw -2.0;

   // Controler la validite du parametre
   //
   if (E.nok()) throw -2.1;
   if (!E.vide() && E.m_pfNew == NULL) throw -3.2;

   // Vider l'ensemble support
   //
   if (!vide()) vider();

   // Copier les pointeurs de fonctions
   //
   m_pfEquals= E.m_pfEquals;
   m_pfNew   = E.m_pfNew;  

   // Traiter le cas particulier d'un ensemble source vide
   //
   if (E.vide()) return *this;

   // Parcourir l'ensemble source
   //
   int nbElements= E.cardinal();
   for (int i= 1; i<= nbElements; i++) {

      // Dupliquer l'element courant
      //
      pElement= (*E.m_pfNew)(E[i]);
      if (pElement==NULL) throw -1.0;

      // Ajouter le duplicata a l'ensemble support
      //
      *this += pElement;
   }

   // Restituer le resultat
   //
   return *this;
}

