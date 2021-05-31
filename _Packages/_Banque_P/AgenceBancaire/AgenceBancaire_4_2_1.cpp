//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe AgenceBancaire - Service nombreComptes (premiere forme)
//
// Auteur : A. Thuaire
//
#include "AgenceBancaire.h"

// --- Calcul du nombre de comptes ouverts correspondant au type specifie
//
int AgenceBancaire::nombreComptes (char type) {

   // Controler la validite de l'objet support
   //
   if (nok()) throw -2.0;

   // Controler la validite du parametre
   //
   if (type != 'E' && type != 'C') throw -2.1;

   // Parcourir le dictionnaire des clients et comptabiliser tous
   // les comptes de type cible sur l'ensemble des clients 
   //
   int compteur= 0;
   string cle;

   map <string, list <CompteBancaire*> >::iterator i= m_clients.begin();
   while (i != m_clients.end()) {

      // Obtenir la cle courante
      //
      cle = i->first;

      // Calculer le nombre de comptes du client courant 
      // correspondant au type cible 
      //
      int nbCpt = nombreComptes (cle, type);

      // Comptabiliser le resultat du calcul precedent
      //
      compteur += nbCpt;

      // Passer au compte suivant
      //
      i++;
   }

   // Restituer le resultat
   //
   return compteur;
}







