//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe _Banque - Methodes opAnnees et opMois
//
// Auteur : A. Thuaire
//
#include "_Banque.h" 

// --- Calculer la difference entre deux dates, exprimee en nombre d'annees
//
int _Banque::deltaAnnees(char pDate1[], char pDate2[]) {

   // Controler la validite du premier parametre
   //
   if (!validiteDate(pDate1)) throw -2.1;

   // Controler la validite du second parametre
   //
   if (!validiteDate(pDate2)) throw -2.2;

   // Restituer le resultat
   //
   return abs(annee(pDate1) - annee(pDate2)); 
}

// --- Calculer la difference entre deux dates, exprimee en nombre de mois
//
int _Banque::deltaMois(char pDate1[], char pDate2[]) {

   // Controler la validite du premier parametre
   //
   if (!validiteDate(pDate1)) throw -2.1;

   // Controler la validite du second parametre
   //
   if (!validiteDate(pDate2)) throw -2.2;

   // Calculer et restituer le resultat
   //
   int nbAnnees= annee(pDate1) - annee(pDate2);
   int nbMois  = mois(pDate1)  - mois(pDate2);

   if (nbAnnees == 0) return abs(nbMois);
   if (nbMois == 0) return abs(nbAnnees)*12;
   if (nbAnnees > 0) return nbAnnees*12 + nbMois;

   return deltaMois(pDate2, pDate1); 
}




