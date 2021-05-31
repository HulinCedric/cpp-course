//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Ensemble - Surcharge de l'operateur -=
//    
// Auteur : A. Thuaire
//
#include "Ensemble.h"

// --- Surcharge de l'operateur -=
//
Ensemble& Ensemble::operator -=(void* const pElement) {

   // Controler la validite de l'objet support
   //
   if (nok())              throw -2.0;
   if (m_pfEquals == NULL) throw -3.1;

   // Controler la validite du parametre
   //
   if (pElement == NULL) throw -2.1;

   // Controler que l'element est dans l'ensemble support
   //
   int position= appartient(pElement);
   if (position==0) throw -3.4; 

   // Retirer le pointeur de la collection sous jacente
   //
   Collection::operator-=((*this)[position]);
 
   // Restituer le resultat
   //
   return *this;
}

