//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe AgenceBancaire - Methode ouvrirCompte
//
// Auteur : A. Thuaire
//
#include "AgenceBancaire.h"

// Ouverture d'un compte courant
//
long int AgenceBancaire::ouvrirCompte (const Titulaire& T) {

   // Controler la validite de l'objet support
   //
   if(nok()) throw -2.0;

   // Controler la validite du parametre
   //
   if(T.nok()) throw -2.1;

   // Creer le compte courant
   //
   CompteCourant* pCC = new CompteCourant(T);

   // Obtenir le numero du compte courant
   //
   long int numeroCC = pCC->numeroCompte();

   // Ajouter le compte courant au dictionnaire des comptes
   //
   m_comptesCourant[numeroCC] = pCC;

   // Mettre à jour le dictionnaire des titulaires
   //
   Titulaire e= T;
   m_clients[e.toString()].push_back(pCC);

   // Restituer le resultat
   //
   return numeroCC;
}

// Ouverture d'un compte epargne
//
long int AgenceBancaire::ouvrirCompte (const Titulaire& T, float taux) {

   // Controler la validite de l'objet support
   //
   if (nok()) throw -2.0;

   // Controler la validite du premier parametre
   //
   if (T.nok()) throw -2.1;

   // Controler la validite du second parametre
   //
   if (taux <= 0) throw -2.2;

   // Creer le compte epargne
   //
   CompteEpargne* pCE = new CompteEpargne (T, taux);

   // Obtenir le numero du compte epargne
   //
   long int numeroCE = pCE->numeroCompte();

   // Ajouter le compte epargne au dictionnaire des comptes
   //
   m_comptesEpargne[numeroCE] = pCE;

   // Mettre à jour le dictionnaire des titulaires
   //
   Titulaire e= T;
	m_clients[e.toString()].push_back(pCE);

   // Restituer le resultat
   //
   return numeroCE;
}







