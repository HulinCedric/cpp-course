//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe _Banque - Methode de classe anterieur
//
// Auteur : A. Thuaire
//
#include "_Banque.h" 

// --- Controler l'anteriorite de la premiere date
//     par rapport a la seconde     
//
bool _Banque::anterieur(char pDate1[], char pDate2[]) {

   // Controler la validite du premier parametre
   //
   if (!validiteDate(pDate1)) throw -2.1;

   // Controler la validite du second parametre
   //
   if (!validiteDate(pDate2)) throw -2.2;

   // Comparer les annees
   //
   if (annee(pDate2) < annee(pDate1)) return false;
   if (annee(pDate2) > annee(pDate1)) return true;

   // Comparer les mois
   //
   if (mois(pDate2) < mois(pDate1)) return false;
   if (mois(pDate2) > mois(pDate1)) return true;

   // Comparer les jours
   //
   if (jour(pDate2) < jour(pDate1)) return false;
   if (jour(pDate2) > jour(pDate1)) return true;

   // Traiter le cas particulier de deux dates identiques
   //
   return false;
}

// --- Controler la posteriorite de la premiere date
//     par rapport a la seconde     
//
bool _Banque::posterieur(char pDate1[], char pDate2[]) {
   
   return !anterieur(pDate1, pDate2);
} 




