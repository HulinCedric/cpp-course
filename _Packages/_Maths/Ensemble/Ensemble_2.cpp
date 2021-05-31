//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Ensemble - Accesseurs de consultation
//    
// Auteur : A. Thuaire
//
#include "Ensemble.h"

// --- Verification de l'appartenance d'un element a un ensemble
//
int Ensemble::appartient(void* const pElement) const {

   // Controler la validite de l'objet support
   //
   if (nok()) throw -2.0;

   // Controler la validite du parametre
   //
   if (pElement==NULL) return 0;

   // Traiter le cas particulier de l'ensemble vide
   //
   if (vide()) return 0;

   // Controler l'existence de la relation d'appartenance
   //
   if (m_pfEquals==NULL) throw -3.1;

   // Parcourir toute la collection et rechercher l'element cible
   //
   int nbElements= cardinal();
   for (int i=1; i <= nbElements; i++)
      if ((*m_pfEquals)((*this)[i], pElement)) return i;
  
   return 0;
} 


