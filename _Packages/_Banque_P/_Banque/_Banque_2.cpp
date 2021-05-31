//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe _Banque - Methodes validiteId et validiteDate
//
// Auteur : A. Thuaire
//
#include "_Banque.h" 

// --- Controle de validite du nom ou du prenom d'un titulaire
//
bool _Banque::validiteId(char pT[]) {
int taille=strlen(pT);

   if (taille < 1) return false;

   for (int i=0;i<taille;i++)
      if (pT[i] != ' ' && pT[i] != '-' && pT[i] != '\''&& !isalpha(pT[i])) return false;
   return true;
}

// --- Controle de validite de la date de naissance d'un titulaire
//
bool _Banque::validiteDate(char pT[]) {
int  taille=strlen(pT), i;
char buffer[5];

   if (taille != 10) return false;
   if (pT[4] != '/') return false;
   if (pT[7] != '/') return false; 

   // Controler la syntaxe de l'annee
   //
   for (i=0;i<=3;i++) {
      if (!isdigit(pT[i])) return false;
      buffer[i]= pT[i];
   }

   // Placer le marqueur de fin de chaine
   //
   buffer[4]= '\0';  

   // Controler la validite de l'annee
   //
   int annee= atoi(buffer);
   if (annee <= 1850) return false;

   // Determiner si l'annee est bissextile
   //
   int nbJoursFevrier= 28;
   if (annee%400 == 0) nbJoursFevrier= 29;
   else if (annee%4 == 0 && annee%100 != 0) nbJoursFevrier= 29;

   // Controler la syntaxe du mois
   //
   for (i=5;i<=6;i++)
      if (!isdigit(pT[i])) return false;
      
   buffer[0]= pT[5];
   buffer[1]= pT[6];
   buffer[2]= '\0';

   // Controler la validite du mois
   //
   int mois= atoi(buffer);
   if (mois <= 0 || mois > 12) return false;

   // Controler la syntaxe du jour
   //
   for (i=8;i<=9;i++)
      if (!isdigit(pT[i])) return false;

   buffer[0]= pT[8];
   buffer[1]= pT[9];
   buffer[2]= '\0';

   // Controler la validite du jour
   //
   int jour= atoi(buffer);
   if (jour <= 0 || jour > 31) return false;

   if (mois==2 && jour > nbJoursFevrier) return false;

   if (jour > 30) {
      switch(mois) {
         case 4  : ;
         case 6  : ;
         case 9  : ;
         case 11 : return false;
      }
   }

   return true;
}
