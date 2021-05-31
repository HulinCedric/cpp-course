//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Ensemble - Surcharges de l'operateur +
//    
// Auteur : A. Thuaire
//
#include "Ensemble.h"

// --- Premiere surcharge de l'operateur +
//
Ensemble* Ensemble::operator +(void* const pElement) const {
Ensemble* pResultat;

   // Controler la validite de l'objet support
   //
   if (nok()) throw -2.0;

   // Controler la validite du parametre
   //
   if (pElement == NULL) throw -2.1;

   // Traiter le cas particulier d'un ensemble vide
   //
   if (vide()) {
      pResultat= new Ensemble(m_pfEquals, m_pfNew);
      if(pResultat == NULL) throw -1.0;
      *pResultat += pElement;
      return pResultat;
   }

   // Controler l'absence du nouvel element dans l'ensemble
   //
   if (appartient(pElement)) throw -3.3;

   // Dupliquer l'ensemble support
   //
   pResultat= new Ensemble(*this);
   if (pResultat == NULL) throw -1.0;

   // Ajouter le nouvel element et restituer le resultat
   //
   *pResultat += pElement;

   return pResultat;
}

// --- Union de deux ensembles
//
Ensemble* Ensemble::operator +(const Ensemble& E) const {
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
      pResultat= new Ensemble(E);
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

      // Controler l'absence de l'element courant
      // dans le resultat
      //
      if (appartient(E[i])) continue;

      // Ajouter l'element courant au resultat
      //
      *pResultat += E[i];
   }

   // Restituer le resultat
   //
   return pResultat;
}
