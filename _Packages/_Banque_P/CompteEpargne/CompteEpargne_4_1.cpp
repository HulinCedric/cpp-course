//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe CompteEpargne - Surcharge de la methode executer
//
// Auteur : A. Thuaire
//
#include "CompteEpargne.h"

// --- Execution d'une operation bancaire
//
float CompteEpargne::executer (char type, char* libelle, float montant) {

   // Controler la validite de l'objet support
   //
   if (nok()) throw -2.0;

   // Controler que le compte courant est toujours actif
   //
   if (m_cloture) throw -3.3;

   // Remunerer le compte pour tous les mois pendants
   //
   remunerer();

   // Executer l'operation sur le compte bancaire sous jacent
   //
   return CompteBancaire::executer(type, libelle, montant);
}









