//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe _Banque - Methodes numeroRegistreOp, numeroRegistreCpt,
//                  numeroRegistreCpt et dateCourante
//
// Auteur : A. Thuaire
//
#include "_Banque.h" 

// Obtenir le numero de la prochaine operation
//
long int _Banque::numeroRegistreOp() {

   return ++m_registreOp;
}

// Obtenir le numero du prochain compte bancaire
//
long int _Banque::numeroRegistreCpt() {

   return ++m_registreCpt;
}

// Obtenir le numero du prochain compte courant
//
long int _Banque::numeroRegistreCptC() {

   return ++m_registreCptC;
}

// Obtenir le numero du prochain compte epargne
//
long int _Banque::numeroRegistreCptE() {

   return ++m_registreCptE;
}

// Obtenir le numero du prochain guichet d'agence
//
int _Banque::numeroRegistreG() {

   return ++m_registreG;
}

// Recueillir et mettre en forme la date courante (origine : systeme d'exploitation)
//
char* _Banque::dateCourante() {
char* pResultat;

   // Allouer la chaine resultante
   //
   pResultat= new char[12];
   if (pResultat==NULL) throw -1.0;

   // Recueillir la date du systeme d'exploitation
   //
   struct tm dateSyst;
   time_t aujourdhui;

   time(&aujourdhui);
   dateSyst = *localtime(&aujourdhui);
   
   // Mettre en forme la date courante
   //
   sprintf(pResultat, "%2.2d/%2.2d/%2.2d", dateSyst.tm_year + 1900, 
                                           dateSyst.tm_mon + 1, 
                                           dateSyst.tm_mday);
   // Restituer le resultat
   //
   return pResultat;
}