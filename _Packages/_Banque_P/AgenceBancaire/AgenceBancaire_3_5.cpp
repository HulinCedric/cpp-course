//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe AgenceBancaire - Surcharges de l'operateur ()
//
// Auteur : A. Thuaire
//
#include "AgenceBancaire.h"

// --- Obtenir une liste de vues sur les comptes d'un titulaire
// --- suivant le type cible designe par parametre
//
list <CompteBancaire*>* AgenceBancaire::operator () (const Titulaire& T,
                                                     char type) {

   // Controler la validite de l'objet support
   //
   if (nok()) throw -2.0;

   // Controler la validite du premier parametre
   //
   if (T.nok()) throw -2.1;

   // Controler la validite du second parametre
   //
   if (type != 'C' && type != 'E') throw -2.2;

   // Allouer la liste resultante
   //
   list <CompteBancaire*>* pResultat = new list <CompteBancaire*>;
   if(pResultat == NULL) throw -1.0;

   // Construire la liste resultante en fonction du second parametre
   //
   CompteBancaire* pCompte;

   if (type == 'C') {

      // Parcourir le dictionnaire des comptes courants
      //
      map <long int, CompteCourant*>::iterator i= m_comptesCourant.begin();
      while (i != m_comptesCourant.end()) {

         // Obtenir le compte courant designe par l'iterateur
         //
         pCompte = i->second;

         // Controler le titulaire de ce compte
         //
         if (pCompte->titulaireCompte() == T) pResultat->push_back(pCompte);

         // Passer a la cle suivante
         //
         i++;
      }
   }
   else {

      // Parcourir le dictionnaire des comptes epargne
      //
      map <long int, CompteEpargne*>::iterator i= m_comptesEpargne.begin();
      while (i != m_comptesEpargne.end()) {

         // Obtenir le compte epargne designe par l'iterateur
         //
         pCompte = i->second;

         // Controler le titulaire de ce compte
         //
         if (pCompte->titulaireCompte() == T) pResultat->push_back(pCompte);

         // Passer a la cle suivante
         //
         i++;
      }
   }

   // Restituer le resultat
   //
   return pResultat;
}







