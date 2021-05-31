//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe AgenceBancaire - Surcharge de l'operateur +=
//
// Auteur : A. Thuaire
//
#include "AgenceBancaire.h"

// --- Mettre a jour le dictionnaire des clients
//
AgenceBancaire& AgenceBancaire::operator += (CompteBancaire* pCompte) {

	// Controler la validite du parametre
	//
	if(pCompte == NULL)	throw -2.1;

	// Controler la validite de l'objet support
	//
	if(nok()) throw -2.0;
	
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

   if ( i != m_clients.end()) {
  
      // Traiter le cas d'un client existant en obtenant
      // une copie de la liste courante des comptes
      //
      list <CompteBancaire*> CompteClient = i->second;

      // Ajouter le nouveau compte a cette copie
      //
	  CompteClient.push_back(pCompte);

      // Modifier l'associe de la cle cible
      //
      m_clients[cle] = CompteClient;

	  if(pCompte->numeroCompte() > 8000000) m_comptesCourant[pCompte->numeroCompte()] = (CompteCourant*)pCompte;
	  else m_comptesEpargne[pCompte->numeroCompte()] = (CompteEpargne*)pCompte;
   }

   else {

      // Allouer une nouvelle liste de comptes
      //
      list <CompteBancaire*> CompteClient;

      // Ajouter le compte cible a la nouvelle liste
      //
	  CompteClient.push_back(pCompte);

      // Ajouter le nouveau client
      //
      m_clients[cle] = CompteClient;
	  if(pCompte->numeroCompte() > 8000000) m_comptesCourant[pCompte->numeroCompte()] = (CompteCourant*)pCompte;
	  else m_comptesEpargne[pCompte->numeroCompte()] = (CompteEpargne*)pCompte;
   }

   // Restituer le resultat
   //
   return *this;
}









