//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe CompteEpargne - Methode privee remunerer
//
// Auteur : A. Thuaire
//
#include "CompteEpargne.h"

// --- Execution des operations de remuneration pendantes a la date cible
//
float CompteEpargne::remunerer(char* pDateCible) {

   // Controler la validite de l'objet support
   //
   if(nok()) throw -2.0;

   // Controler la validite du parametre
   //
   if (!_Banque::validiteDate(pDateCible)) throw -2.1;

   // Obtenir la date de la derniere operation bancaire executee sur le
   // compte support
   //
   char* pDateDerniereOperation= dateDerniereOperation();

   // Traiter le cas particulier de l'absence d'operations anterieures
   //
   if (pDateDerniereOperation==NULL) return 0.0f;

   // Traiter le cas particulier d'une date cible identique 
   // a la date de la derniere operation bancaire
   //
   if (strcmp(pDateCible, pDateDerniereOperation) == 0) {
      delete[] pDateDerniereOperation;
      return CompteBancaire::soldeCompte();
   }

   // Controler que la date cible est posterieure a la date de la derniere
   // operation
   //
   if (!_Banque::posterieur(pDateCible, pDateDerniereOperation)) {
      delete[] pDateDerniereOperation;
      throw -2.1;
   }

   // Calculer l'ecart (en nombre de mois) avec la date cible
   //
   int nbMois= _Banque::deltaMois(pDateCible, pDateDerniereOperation);

   // Traiter le cas particulier du mois courant
   //
   if (nbMois == 0) {
      delete[] pDateDerniereOperation;
      return CompteBancaire::soldeCompte();
   }

   // Executer les operations de remuneration associees aux mois pendants
   //
   float montant;
   for (int i= 1; i<=nbMois; i++) {

      // Calculer le montant de la remuneration du mois pendant
      //
      montant= CompteBancaire::soldeCompte()*(m_taux/12);

      // Executer l'operation de remuneration du mois pendant
      //
      executer(VERSEMENT, "Remuneration mensuelle", montant);
   }

   // Restituer le resultat
   //
   delete[] pDateDerniereOperation;
   return CompteBancaire::soldeCompte();
}

// --- Execution des operations de remuneration pendantes a la date courante
//
float CompteEpargne::remunerer() {

   return remunerer(_Banque::dateCourante());
}
