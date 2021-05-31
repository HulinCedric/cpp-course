//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe LigneBrisee - Surcharge de l'operateur ==
//
// Auteur : A. Thuaire
//
#include "LigneBrisee.h"

// --- Comparaison de deux lignes brisees
//
bool LigneBrisee::operator ==(const LigneBrisee& L) {

   // Controler la validite de l'objet support
   //
   if (nok()) throw -2.0;

   // Controler la validite du parametre
   //
   if (L.nok()) throw -2.1;

   // Parcourir en parallele les deux operandes
   //
   int i;
   for (i= 0; m_pSommets[i] != NULL && L.m_pSommets[i] != NULL; i++)
      if (*m_pSommets[i] != *L.m_pSommets[i]) return false;

   // Traiter le cas de deux operandes de meme taille
   //
   if (m_pSommets[i] == NULL && L.m_pSommets[i] == NULL) return true;

   // Traiter le cas de deux operandes de taille differente
   //
   if (m_pSommets[i] == NULL && L.m_pSommets[i] != NULL) return false;
   if (L.m_pSommets[i] == NULL && m_pSommets[i] != NULL) return false;

   // Restituer le resultat
   //
   if (*m_pSommets[i] == *L.m_pSommets[i]) return true;
   return false;
}





   




