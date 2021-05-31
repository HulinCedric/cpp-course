//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Ensemble - Surcharges de l'operateur -
//    
// Auteur : A. Thuaire
//
#include "Ensemble.h"

// --- Premiere surcharge de l'operateur -
//
Ensemble* Ensemble::operator -(void* const pElement) const {
Ensemble* pResultat;

   // Controler la validite de l'objet support
   //
   if (nok()) throw -2.0;

   // Controler la validite du parametre
   //
   if (pElement == NULL) throw -2.1;

   // Traiter le cas particulier d'un ensemble vide
   //
   if (vide()) throw -3.4;

   // Controler la presence de l'element dans l'ensemble
   //
   if (!appartient(pElement)) throw -3.4;

   // Dupliquer l'ensemble support
   //
   pResultat= new Ensemble(*this);
   if (pResultat == NULL) throw -1.0;

   // Retirer l'element cible et restituer le resultat
   //
   *pResultat -= pElement;

   return pResultat;
}

// --- Soustraction d'un ensemble
//
Ensemble* Ensemble::operator -(const Ensemble& E) const {
Ensemble* pResultat;

   // Controler la validite de l'objet support
   //
   if (nok()) throw -2.0;

   // Controler la validite du parametre
   //
   if (E.nok()) throw -2.1;

   // Traiter le cas particulier du premier operande vide
   //
   if (vide()) {
      pResultat= new Ensemble(*this);
      if(pResultat == NULL) throw -1.0;
      return pResultat;
   }

   // Traiter le cas particulier d'un second operande vide
   //
   if (E.vide()) {
      pResultat= new Ensemble(*this);
      if(pResultat == NULL) throw -1.0;
      return pResultat;
   }

   // Dupliquer le premier operande
   //
   pResultat= new Ensemble(*this);
   if(pResultat == NULL) throw -1.0;

   // Parcourir le second operande
   //
   int nbElementsOp2= E. cardinal();
   for (int i=1; i <= nbElementsOp2; i++) {

      // Controler la presence de l'element courant
      // dans le resultat
      //
      if (appartient(E[i])) *pResultat -= E[i];
   }

   // Restituer le resultat
   //
   return pResultat;
}

