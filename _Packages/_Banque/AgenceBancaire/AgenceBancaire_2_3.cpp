//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe AgenceBancaire - Methode fermerCompte
//
// Auteur : A. Thuaire
//
#include "AgenceBancaire.h"

// --- Fermeture d'un compte existant dans une agence
//
float AgenceBancaire::fermerCompte (long int numeroCible) {
float solde;

   // Controler la validite du parametre
   //
   if (numeroCible < 4000001) throw -2.1;

   // Controler la presence du numero cible dans le dictionnaire des comptes courants
   //
   CompteBancaire* pCompte;

   map <long int, CompteCourant*>::iterator k= m_comptesCourant.begin();
   while (k != m_comptesCourant.end()) {

      // Traiter le cas ou la cle courante est la cle cible
      //
      if (k->first == numeroCible) {

         // Obtenir une vue sur le compte courant cible
         //
         pCompte = k->second;

		 // Cloturer le compte 
		 //
		 try {solde= k->second->cloturer();}
		 catch(double) {throw -3.2;}

		 // Placer le compte bancaire cible dans les compte fermes
	   	 //
	     m_comptesFermes[numeroCible] = pCompte;

		 // Supprimer le compte cible de la liste des comptes dans le dictionnaire des clients
		 //
		 m_clients[k->second->titulaireCompte().toString()].remove(k->second);

		 // Supprimer le comtpte cible du dictionnaire des comptes courants
         //
         m_comptesCourant.erase(numeroCible);		 

         // Restituer le resultat
         //
         return solde;

      }
   
      // Traiter le cas ou la cle courante n'est pas la cle cible
      //
      k++;
   }
   
   // Controler la presence du numero cible dans le dictionnaire des comptes epargnes
   //
   map <long int, CompteEpargne*>::iterator i= m_comptesEpargne.begin();
   while (i != m_comptesEpargne.end()) {

      // Traiter le cas ou la cle courante est la cle cible
      //
      if (i->first == numeroCible) {

         // Obtenir une vue sur le compte epargne cible
         //
         pCompte = i->second;

         // Cloturer le compte cible
         //
         try {solde= i->second->cloturer();}
		 catch(double) {throw -3.2;}

		 // Ajouter le compte cible au dictionnaire des comptes fermés
		 //
		 m_comptesFermes[numeroCible] = pCompte;

		 // Supprimer le compte cible de la liste des comptes dans le dictionnaire des clients
		 //
		 m_clients[i->second->titulaireCompte().toString()].remove(i->second);

		 // Supprimer le comtpte cible du dictionnaire des comptes courants
         //
         m_comptesEpargne.erase(numeroCible);

         // Restituer le resultat
         //
         return solde;

      }
   
      // Traiter le cas ou la cle courante n'est pas la cle cible
      //
      i++;
   }

   // Traiter le cas ou le numero cible n'est pas dans le dictionnaire
   //
   throw -3.1;
}







