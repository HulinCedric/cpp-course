//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe AgenceBancaire - Service totalDepots (seconde forme)
//
// Auteur : A. Thuaire
//
#include "AgenceBancaire.h"

// --- Calcul du total des depots d'un client sur des comptes 
// --- correspondant au type specifie
//
float AgenceBancaire::totalDepots (Titulaire& T, char type) {

   // Controler la validite de l'objet support
   //
   if (nok()) throw -2.0;

   // Controler la validite du premier parametre
   //
   if (T.nok()) throw -2.1;

   // Controler la validite du second parametre
   //
   if (type != 'C' && type != 'E') throw -2.2;

   // Construire la cle authentifiant le client
   //
   char* cleClient = T.toString();
   string cle = cleClient;

   // Liberer le buffer de travail
   //
   delete cleClient;

   // Restituer le resultat
   //
   return totalDepots (cle, type);
}







