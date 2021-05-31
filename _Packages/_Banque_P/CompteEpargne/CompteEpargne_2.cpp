//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe CompteEpargne - Surcharge des accesseurs de consultation
//
// Auteur : A. Thuaire
//
#include "CompteEpargne.h"

// --- Obtenir le numero du compte cible
//
long int CompteEpargne::numeroCompte() {

   // Controler la validite de l'objet support
   //
   if(nok()) throw -2.0;

   // Restituer le resultat
   //
   return m_numero;
}

// --- Calculer le solde courant en integrant le calcul
//     des remunerations eventuelles non encore appliquees
//
float CompteEpargne::soldeCompte() {

   // Controler la validite de l'objet support
   //
   if(nok()) throw -2.0;

   // Restituer le resultat
   //
   return remunerer();
}












