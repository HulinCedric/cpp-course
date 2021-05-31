//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe _Banque - Methode jourSuivant
//
// Auteur : A. Thuaire
//
#include "_Banque.h" 

// --- Calculer la date du jour suivant la date fournie en parametre
//
char* _Banque::jourSuivant(char* pDate) {

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
   if (jour < 28 || (mois != 2 && jour < 30)) {
      sprintf(pResultat,"%2.2d/%2.2d/%2.2d", annee, mois, jour+1);
      return pResultat;
   }

   // Traiter le cas particulier du dernier jour de l'annee
   //
   if (mois == 12 && jour == 31) {
      sprintf(pResultat,"%2.2d/%2.2d/%2.2d", annee+1, 1, 1);
      return pResultat;
   }

   // Traiter le cas du dernier jour des mois de 30 jours
   //
   int dernierJour= 31;
   switch(mois) {
         case 4  : dernierJour= 30; break;
         case 6  : dernierJour= 30; break;
         case 9  : dernierJour= 30; break;
         case 11 : dernierJour= 30; break;
   }

   if (jour == dernierJour) {
      sprintf(pResultat,"%2.2d/%2.2d/%2.2d", annee, mois+1, 1);
      return pResultat;
   }

   // Traiter le cas du dernier jour du mois de fevrier
   //
   if (mois == 2) {
      int dernierJour= 28;

      // Traiter le cas particulier des annees bissextiles
      //
      if (annee%400 == 0) dernierJour= 29;
      else if (annee%4 == 0 && annee%100 != 0) dernierJour= 29;

	  if (jour==dernierJour) {
         sprintf(pResultat,"%2.2d/%2.2d/%2.2d", annee, 3, 1);
         return pResultat;
      }
   }

   return pDate;
}


char* _Banque::demain()
{
	return _Banque::jourSuivant(dateCourante());
}





