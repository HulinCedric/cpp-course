//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe OperationBancaire - Constructeurs, destructeur et methode toString
//
// Auteur : A. Thuaire
//
#include "..\_Banque\_Banque.h"
#include "OperationBancaire.h"

// Surcharge du constructeur par defaut
//
OperationBancaire::OperationBancaire() {
   
   m_typeOperation     = NEUTRE;
   m_numeroOperation   = 1000000L;
   m_intituleOperation = NULL;
   m_dateOperation     = NULL;
   m_montantOperation  = 0.0f;
}

// Constructeur normal
//
OperationBancaire::OperationBancaire(char type, char* intitule, float montant) {

   // Controler la validite des parametres
   //
   if(type != VERSEMENT && type != RETRAIT && type != REMUNERATION) throw -2.1;
   if (intitule==NULL) throw -2.2;
   if (strlen(intitule) > 40) throw -2.2;
   if (montant < 0.0f) throw -2.3;

   // Allouer et renseigner l'intitule
   //
   m_intituleOperation= new char[strlen(intitule)+1];
   if (m_intituleOperation == NULL) throw -1.0;
   strcpy(m_intituleOperation, intitule);

   // Renseigner le type de l'operation
   //
   m_typeOperation   = type;

   // Renseigner le montant de l'operation
   //
   m_montantOperation= montant;
 
   // Obtenir le numero courant du registre
   //
   m_numeroOperation = _Banque::numeroRegistreOp();

   // Obtenir la date courante
   //
   m_dateOperation= _Banque::dateCourante(); 
}

// Surcharge du destructeur
//
OperationBancaire::~OperationBancaire() {

   if (m_intituleOperation != NULL) delete[] m_intituleOperation;
   if (m_dateOperation != NULL)     delete[] m_dateOperation;
}

// Restituer la description d'une operation bancaire pour les tests unitaires
//
char* OperationBancaire::toString() {
char* pBuffer= new char[80];

   // Allouer la chaine resultante
   //
   pBuffer= new char[150];
   if (pBuffer==NULL) throw -1.0;

   // Traiter le cas particulier de l'element neutre
   //
   if (neutre()) {sprintf(pBuffer, "---"); return pBuffer;}

   // Traiter le cas general
   //
   char typeOp[15];
   if(m_typeOperation==VERSEMENT)    strcpy(typeOp, "VERSEMENT");
   if(m_typeOperation==RETRAIT)      strcpy(typeOp, "RETRAIT");
   if(m_typeOperation==REMUNERATION) strcpy(typeOp, "REMUNERATION");

   sprintf(pBuffer, "%ld - %s - %s : %7.2f", m_numeroOperation,
                                             typeOp,
                                             m_intituleOperation,
                                             m_montantOperation);
   return pBuffer;
}





