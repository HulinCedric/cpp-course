//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe OperationBancaire - Accesseurs de consultation
//
// Auteur : A. Thuaire
//
#include "..\_Banque\_Banque.h"
#include "OperationBancaire.h"

// Obtenir le type de l'operation support
//
char OperationBancaire::typeOperation() {

   // Controler la validite de l'objet support
   //
   if(nok()) throw -2.0;

   // Restituer le resultat
   //
   return m_typeOperation;
}

// Obtenir le numero de l'operation support
//
long int OperationBancaire::numeroOperation() {

   // Controler la validite de l'objet support
   //
   if(nok()) throw -2.0;

   // Restituer le resultat
   //
   return m_numeroOperation;
}

// Obtenir l'intitule de l'operation support
//
char* OperationBancaire::intituleOperation() {

   // Controler la validite de l'objet support
   //
   if(nok()) throw -2.0;

   // Allouer et renseigner le resultat
   //
   char* pResultat= new char[strlen(m_intituleOperation)+1];
   if (pResultat==NULL) return NULL;
   strcpy(pResultat, m_intituleOperation);

   // Restituer le resultat
   //
   return pResultat;
}

// Obtenir la date de l'operation support
//
char* OperationBancaire::dateOperation() {

   // Controler la validite de l'objet support
   //
   if(nok()) throw -2.0;

   // Allouer la zone pour le resultat
   //
   char* pR= new char[12];
   if (pR==NULL) throw -1.0;
   
   // Copier la date de l'operation dans le resultat
   //
   strcpy(pR, m_dateOperation);

   // Restituer le resultat
   //
   return pR;
}

// Obtenir le montant du transfert
//
float OperationBancaire::montantOperation() {

   // Controler la validite de l'objet support
   //
   if(nok()) throw -2.0;

   // Restituer le resultat
   //
   return m_montantOperation;
}









