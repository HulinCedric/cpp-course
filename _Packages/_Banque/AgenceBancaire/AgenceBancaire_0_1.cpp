//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe AgenceBancaire - Methode privee nombreComptes
//
// Auteur : A. Thuaire
//
#include "AgenceBancaire.h"

// --- Calcul du nombre de comptes ouverts par un client identifie 
// --- par une chaine alphanumerique et correspondant au type de 
// --- compte specifie par parametre
//
int AgenceBancaire::nombreComptes (const string& cle, char type) {

   // Rechercher la cle dans le dictionnaire des clients 
   //
   map <string, list <CompteBancaire*> >::iterator i= m_clients.find(cle);

   // Traiter le cas ou la cle ne designe pas un client de l'agence
   //
   if (i == m_clients.end()) return 0;

   // Obtenir une copie de la liste des comptes ouverts
   // par ce client
   //
   list <CompteBancaire*> L = i->second;

   // Parcourir cette liste et comptabiliser le nombre de comptes 
   // suivant le type cible (usage du RTTI)
   //
   int compteur= 0;
   
   list <CompteBancaire*>::iterator j = L.begin();
   while (j != L.end())
   {
	   if (dynamic_cast<CompteCourant*>(*j) != NULL && type == 'C') compteur++;
	   if (dynamic_cast<CompteEpargne*>(*j) != NULL && type == 'E') compteur++;
	   j++;
   }
   

   // Restituer le resultat
   //
   return compteur;
}







