//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe AgenceBancaire - Service nombreComptes (troisieme forme)
//
// Auteur : A. Thuaire
//
#include "AgenceBancaire.h"

// --- Calcul du nombre total de comptes ouverts par un client
//
int AgenceBancaire::nombreComptes (Titulaire& T) {

   // Controler la validite de l'objet support
   //
   if (nok()) throw -2.0;

   // Controler la validite du parametre
   //
   if (T.nok()) throw -2.1;

   // Calculer le nombre de comptes courants du client cible
   //
   int resultat = nombreComptes (T, 'C');

   // Ajouter au nombre precedent le nombre de comptes epargne
   //
   resultat += nombreComptes (T, 'E');

   // Restituer le resultat
   //
   return resultat;
}






