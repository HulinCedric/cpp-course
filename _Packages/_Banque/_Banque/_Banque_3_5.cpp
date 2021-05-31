//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe _Banque - Methodes debutMoisSuivant et debutAnneeSuivante
//
// Auteur : A. Thuaire
//
#include "_Banque.h" 

// --- Calculer la date de debut du mois suivant
//
char* _Banque::debutMoisSuivant(char* pDate) {

   // Controler la validite du parametre
   //
   if (!validiteDate(pDate)) throw -2.1;

   // Allouer le buffer resultant
   //
   char* pResultat= new char[11];
   if (pResultat==NULL) throw -1.0;

   // Extraire les trois composantes de la date cible
   //
   int annee= _Banque::annee(pDate);
   int mois = _Banque::mois(pDate);
   int jour = _Banque::jour(pDate);

   // Traiter le cas particulier du mois de decembre
   //
   if (mois == 12) {
      sprintf(pResultat,"%2.2d/%2.2d/%2.2d", annee+1, 1, 1);
      return pResultat;
   }

   // Traiter le cas general
   //
   sprintf(pResultat,"%2.2d/%2.2d/%2.2d", annee, mois+1, 1);
   return pResultat;
}

char* _Banque::debutAnneeSuivante(char* pDate) {

   // Controler la validite du parametre
   //
   if (!validiteDate(pDate)) throw -2.1;

   // Allouer le buffer resultant
   //
   char* pResultat= new char[11];
   if (pResultat==NULL) throw -1.0;

   // Extraire les trois composantes de la date cible
   //
   int annee= _Banque::annee(pDate);
   int mois = _Banque::mois(pDate);
   int jour = _Banque::jour(pDate);

   // Traiter le cas general
   //
   sprintf(pResultat,"%2.2d/%2.2d/%2.2d", annee+1, 1, 1);
   return pResultat;
}









