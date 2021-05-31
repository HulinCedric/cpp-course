//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe _Banque - Methodes de classe annee, mois et jour
//
// Auteur : A. Thuaire
//
#include "_Banque.h" 

// --- Extraire l'annee de la date cible
//
int _Banque::annee(char pDate[]) {
char buffer[5];

   // Controler la validite de la date
   //
   if (!validiteDate(pDate)) throw -2.1;

   // Extraire les quatre premiers caracteres
   //
   for (int i=0;i<=3;i++) buffer[i]= pDate[i];
   buffer[4]= '\0';

   // Restituer le resultat
   //
   return atoi(buffer);
}

// --- Extraire le mois de la date cible
//
int _Banque::mois(char pDate[]) {
char buffer[3];

   // Controler la validite de la date
   //
   if (!validiteDate(pDate)) throw -2.1;

   // Extraire les positions 5 et 6 de la chaine origine
   //
   buffer[0]= pDate[5];
   buffer[1]= pDate[6];
   buffer[2]= '\0';

   // Restituer le resultat
   //
   return atoi(buffer);
}

// --- Extraire le jour de la date cible
//
int _Banque::jour(char pDate[]) {
char buffer[3];

   // Controler la validite de la date
   //
   if (!validiteDate(pDate)) throw -2.1;

   // Extraire les positions 8 et 9 de la chaine origine
   //
   buffer[0]= pDate[8];
   buffer[1]= pDate[9];
   buffer[2]= '\0';

   // Restituer le resultat
   //
   return atoi(buffer);
}


