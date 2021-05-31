//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe AgenceBancaire - Surcharges de l'operateur [] (seconde forme)
//
// Auteur : A. Thuaire
//
#include "AgenceBancaire.h"

// --- Obtenir une liste de vues sur tous les comptes d'un titulaire
//
list <CompteBancaire*>* AgenceBancaire::operator [] (const Titulaire& T) {

   // Controler la validite de l'objet support
   //
   if(nok()) throw -2.0;

   // Controler la validite du parametre
   //
   if(T.nok()) throw -2.1;

   // Allouer la liste resultante
   //
   list <CompteBancaire*>* pResultat= new list <CompteBancaire*>;
   if (pResultat == NULL) throw -1.0;

   // Parcourir le dictionnaire des comptes courants
   //
   CompteBancaire* pCompte;

   map <long int, CompteCourant*>::iterator i= m_comptesCourant.begin();
   while (i != m_comptesCourant.end()) {

      // Obtenir le compte courant designe par l'iterateur
      //
      pCompte= i->second;

      // Controler le titulaire de ce compte
      //
      if (pCompte->titulaireCompte() == T) pResultat->push_back(pCompte);

      // Passer a la cle suivante
      //
      i++;
   }

   // Parcourir le dictionnaire des comptes epargne
   //
   map <long int, CompteEpargne*>::iterator j= m_comptesEpargne.begin();
   while (j != m_comptesEpargne.end()) {

      // Obtenir le compte epargne designe par l'iterateur
      //
      pCompte= j->second;

      // Controler le titulaire de ce compte
      //
      if (pCompte->titulaireCompte() == T) pResultat->push_back(pCompte);

      // Passer a la cle suivante
      //
      j++;
   }

   // Restituer le resultat
   //
   return pResultat;
}







