//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe AgenceBancaire - Surcharge de l'operateur -=
//
// Auteur : A. Thuaire
//
#include "AgenceBancaire.h"

// --- Mettre a jour le dictionnaire des clients
//
AgenceBancaire& AgenceBancaire::operator -= (CompteBancaire* pCompte) {
list<CompteBancaire*> L;

   // Controler la validite du parametre
   //
   if(pCompte == NULL) throw -2.1;

   // Obtenir le titulaire du compte
   //
   Titulaire T= pCompte->titulaireCompte();

   // Construire la cle authentifiant le client
   //
   string cle= T.toString();

   // Rechercher ce client dans le dictionnaire des clients 
   //
   map <string, list <CompteBancaire*> >::iterator i;   
   i= m_clients.find(cle);

   if (i == m_clients.end()) throw -3.5;
  
   // Obtenir une copie de la liste courante des 
   // comptes de ce client
   //
   L = i->second;

   // Retirer le compte cible de cette liste
   //
   L.remove(pCompte);

   if(pCompte->numeroCompte() > 8000000) m_comptesCourant.erase(pCompte->numeroCompte());
   else m_comptesEpargne.erase(pCompte->numeroCompte());

   m_comptesFermes[pCompte->numeroCompte()] = pCompte;

   // Controler la taille de la liste
   //
   if (L.size() == 0) {
 
      // Traiter le cas de la suppression du client cible
      // (liste des comptes devenue vide)
      //
      m_clients.erase(i);
   }
   else {

      // Mettre a jour l'associe de la cle cible
      //
      i->second = L;
   }
      
   // Restituer le resultat
   //
   return *this;
}









