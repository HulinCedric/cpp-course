//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe CompteEpargne - Methode cloturer
//
// Auteur : A. Thuaire
//
#include "CompteEpargne.h"

// --- Cloture d'un compte courant
//
float CompteEpargne::cloturer () {

   // Controler la validite de l'objet support
   //
   if (nok()) throw -2.0;

   // Executer un retrait d'un montant egal au solde du compte
   //
   float solde= soldeCompte();
   if (solde < 200.0f) solde /= 1.008f;

   executer(RETRAIT, "Cloture du compte", solde);

   // Marquer la cloture du compte
   //
   m_cloture= true;

   // Retourner le montant de ce solde
   //
   return solde;
}









