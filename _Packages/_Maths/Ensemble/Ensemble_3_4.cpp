//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Ensemble - Surcharge de l'operateur ==
//    
// Auteur : A. Thuaire
//
#include "Ensemble.h"

// --- Surcharge de l'operateur ==
//
bool Ensemble::operator ==(const Ensemble& E) {

   // Controler la validite de l'objet support
   //
   if (nok()) throw -2.0;

   // Controler la validite du parametre
   //
   if (E.nok()) throw -2.1;
   if (!E.vide() && E.m_pfEquals == NULL) throw -3.1;

   // Traiter le cas particulier d'un ensemble support vide
   //
   if (vide()) {
      if(E.vide()) return true;
      return false;
   }

   // Traiter le cas particulier d'un ensemble cible vide
   //
   if (E.vide()) return false;

   // Calculer le cardinal de chaque ensemble
   //
   int nbElements = cardinal();
   int nbElementsE= E.cardinal();

   // Traiter le cas de cardinaux differents
   //
   if (nbElements != nbElementsE) return false;

   // Parcourir l'ensemble support
   //
   for (int i= 1; i<= nbElements; i++) {

      // Comparer l'element courant de chaque ensemble
      //
      //if (!(*m_pfEquals) ((*this)[i], E[i])) return false;
	   if( appartient( E[i] ) == 0) return false; 

   }
   
   return true;
}

