//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe AgenceBancaire - Methode privee totalDepots
//
// Auteur : A. Thuaire
//
#include "AgenceBancaire.h"

// --- Calcul du total des depots d'un client identifie par une 
// --- chaine alphanumerique et pour les comptes correspondant  
// --- au type de compte specifie par parametre
//
float AgenceBancaire::totalDepots (const string& cle, char type) {

   // Rechercher la cle dans le dictionnaire des clients 
   //
   map <string, list <CompteBancaire*> >::iterator i;
   i= m_clients.find(cle);

   // Traiter le cas ou la cle ne designe pas un client de l'agence
   //
   if (i == m_clients.end()) throw -3.5;

   // Obtenir une copie de la liste des comptes ouverts
   // par ce client
   //
   list <CompteBancaire*> L= i->second;

   // Parcourir cette liste et comptabiliser le total des depots 
   // suivant le type cible (usage du RTTI)
   //
   float total= 0.0f;
   CompteCourant* pCompteCourant;
   CompteEpargne* pCompteEpargne;

   list <CompteBancaire*>::iterator k= L.begin();
   while (k != L.end()) {

      // Traiter le cas d'un compte courant
      //
      if (dynamic_cast<CompteCourant*>(*k) != NULL && type == 'C')
	  {
		  pCompteCourant = (CompteCourant*)*k;
		  total += pCompteCourant->soldeCompte();
	  }

      // Traiter le cas d'un compte epargne
      //
	  if (dynamic_cast<CompteEpargne*>(*k) != NULL && type == 'E')
	  {
		  pCompteEpargne = (CompteEpargne*)*k;
		  total += pCompteEpargne->soldeCompte();
	  }

      // Passer au compte suivant
      //
      k++;
   }

   // Restituer le resultat
   //
   return total;
}







