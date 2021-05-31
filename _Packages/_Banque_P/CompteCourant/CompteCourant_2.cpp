//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe CompteCourant - Surcharge des accesseurs de consultation
//
// Auteur : A. Thuaire
//
#include "CompteCourant.h"

// --- Obtenir le numero du compte cible
//
long int CompteCourant::numeroCompte() {

   // Controler la validite de l'objet support
   //
   if(nok()) throw -2.0;

   // Restituer le resultat
   //
   return m_numero;
}












