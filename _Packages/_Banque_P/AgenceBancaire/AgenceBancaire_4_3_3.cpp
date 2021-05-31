//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe AgenceBancaire - Service totalDepots (troisieme forme)
//
// Auteur : A. Thuaire
//
#include "AgenceBancaire.h"

// --- Calcul du montant total des depots sur les comptes 
// --- ouverts par un client
//
float AgenceBancaire::totalDepots (Titulaire& T) {

   // Controler la validite de l'objet support
   //
   if (nok()) throw -2.0;

   // Controler la validite du parametre
   //
   if (T.nok()) throw -2.1;

   // Calculer le montant des depots du client cible sur les 
   // comptes courants
   //   
   float resultat = totalDepots (T, 'C');

   // Ajouter au montant precedent celui des depots sur les
   // comptes epargne
   //
   resultat += totalDepots (T, 'E');

   // Restituer le resultat
   //
   return resultat;
}






