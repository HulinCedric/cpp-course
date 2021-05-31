//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Ensemble - Surcharge de l'operateur +=
//    
// Auteur : A. Thuaire
//
#include "Ensemble.h"

// --- Surcharge de l'operateur +=
//
Ensemble& Ensemble::operator +=(void* const pElement) {

   // Controler la validite de l'objet support
   //
   if (nok())              throw -2.0;
   if (m_pfEquals == NULL) throw -3.1;

   // Controler la validite du parametre
   //
   if (pElement == NULL) throw -2.1;

   // Controler que l'element n'est pas deja dans l'ensemble
   //
   if (appartient(pElement)) throw -3.3; 

   // Ajouter le parametre a la collection sous jacente
   //
   Collection::operator+=(pElement);
 
   // Restituer le resultat
   //
   return *this;
}

