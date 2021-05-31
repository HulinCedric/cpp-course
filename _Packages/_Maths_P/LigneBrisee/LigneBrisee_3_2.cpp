//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe LigneBrisee - Surcharge de l'operateur =
//
// Auteur : A. Thuaire
//
#include "LigneBrisee.h"

// --- Affectation d'une ligne brisee a une autre
//
LigneBrisee& LigneBrisee::operator =(const LigneBrisee& L) {

   // Controler la validite de l'objet support
   //
   if (nok()) throw -2.0;

   // Controler la validite du parametre
   //
   if (L.nok()) throw -2.1;

   // Liberer tous les sommets de l'objet support
   //
   for (int i= 0; m_pSommets[i] != NULL; i++) delete m_pSommets[i];

   // Marquer la fin du conteneur sous jacent
   //
   m_pSommets[0]= NULL;

   // Ajouter au conteneur chacun des sommets de la source
   //
   for (int j= 0; L.m_pSommets[j] != NULL; j++) *this += L.m_pSommets[j];

   // Restituer le resultat
   //
   return *this;
}





   




