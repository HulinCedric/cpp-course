//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe AgenceBancaire - Service totalDepots (premiere forme)
//
// Auteur : A. Thuaire
//
#include "AgenceBancaire.h"

// --- Calcul du total des depots sur les comptes correspondant 
// --- au type specifie
//
float AgenceBancaire::totalDepots (char type) {

   // Controler la validite de l'objet support
   //
   if (nok()) throw -2.0;

   // Controler la validite du parametre
   //
   if (type != 'C' && type != 'E') throw -2.1;

   // Parcourir le dictionnaire des clients et comptabiliser tous les
   // depots sur les comptes de type cible pour l'ensemble des clients 
   //
   float resultat= 0.0f;
   string cle;

   map <string, list <CompteBancaire*> >::iterator i= m_clients.begin();
   while (i != m_clients.end()) {

      // Obtenir la cle courante
      //
      cle = i->first;

      // Comptabiliser le total des depots sur les comptes du client  
      // courant qui correspondent au type cible 
      //
      resultat += totalDepots (cle, type);

      // Passer au compte suivant
      //
      i++;
   }

   // Restituer le resultat
   //
   return resultat;
}







