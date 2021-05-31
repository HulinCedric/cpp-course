//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe CompteCourant - Methode cloturer
//
// Auteur : A. Thuaire
//
#include "CompteCourant.h"

// --- Cloture d'un compte courant
//
float CompteCourant::cloturer () {

   // Controler la validite de l'objet support
   //
   if (nok()) throw -2.0;

   // Executer un retrait d'un montant egal au solde du compte
   //
   float solde= soldeCompte();
   executer(RETRAIT, "Cloture du compte", solde);

   // Marquer la cloture du compte
   //
   m_cloture= true;

   // Retourner le montant de ce solde
   //
   return solde;
}









