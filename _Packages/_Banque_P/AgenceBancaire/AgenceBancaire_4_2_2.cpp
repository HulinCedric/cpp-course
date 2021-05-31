//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe AgenceBancaire - Service nombreComptes (seconde forme)
//
// Auteur : A. Thuaire
//
#include "AgenceBancaire.h"

// --- Calcul du nombre de comptes ouverts par un client 
// --- correspondant au type specifie
//
int AgenceBancaire::nombreComptes (Titulaire& T, char type) {

   // Controler la validite de l'objet support
   //
   if (nok()) throw -2.0;

   // Controler la validite du premier parametre
   //
   if (T.nok()) throw -2.1;

   // Controler la validite du second parametre
   //
   if (type != 'C' && type != 'E') throw -2.2;

   // Construire la liste des comptes suivant le type cible
   //
   list <CompteBancaire*>* k= (*this)(T,type);

   // Obtenir le cardinal de cette liste
   //
   int resultat= k->size();

   // Detruire le conteneur de la liste de travail
   //
   delete k;

   // Restituer le resultat
   //
   return resultat;
}







