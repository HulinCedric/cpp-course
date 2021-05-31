//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe CompteEpargne - Surcharge de l'operateur -=
//
// Auteur : A. Thuaire
//
#include "CompteEpargne.h"

// --- Surcharge de l'operateur -=
//
CompteBancaire& CompteEpargne::operator -= (float montant) {

   // Executer l'operation en incluant la commission
   //
   if (montant < 200.0f) montant*= 1.008f;
   return CompteBancaire::operator-=(montant);

}









