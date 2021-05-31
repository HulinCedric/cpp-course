//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe CompteBancaire - Accesseurs de consultation
//
// Auteur : A. Thuaire
//
#include "CompteBancaire.h"

// --- Obtenir la description complete du titulaire du compte
//
Titulaire& CompteBancaire::titulaireCompte() {

   // Controler la validite de l'objet support
   //
   if(nok()) throw -2.0;

   // Restituer le resultat
   //
   return m_titulaire;
}

// --- Obtenir l'identite du titulaire du compte
//
char* CompteBancaire::identiteTitulaire() {

   // Controler la validite de l'objet support
   //
   if(nok()) throw -2.0;

   // Allouer le buffer resultant
   //
   char* pResultat;
   pResultat= new char[80];
   if (pResultat==NULL) throw -1.0;

   // Construire l'identite du titulaire
   //
   char* pNom   = m_titulaire.nom();
   char* pPrenom= m_titulaire.prenom();
   sprintf(pResultat, "%s %s", pNom, pPrenom);
   delete[] pNom; delete[] pPrenom;
   
   // Restituer le resultat
   //
   return pResultat;
}

// --- Obtenir l'adresse du titulaire du compte
//
char* CompteBancaire::adresseTitulaire() {

   // Controler la validite de l'objet support
   //
   if(nok()) throw -2.0;

   // Restituer le resultat
   //
   return titulaireCompte().adresse();
}

// --- Obtenir le numero du compte cible
//
long int CompteBancaire::numeroCompte() {

   // Controler la validite de l'objet support
   //
   if(nok()) throw -2.0;

   // Restituer le resultat
   //
   return m_numero;
}

// --- Obtenir le solde du compte cible
//
float CompteBancaire::soldeCompte() {

   // Controler la validite de l'objet support
   //
   if(nok()) throw -2.0;

   // Restituer le resultat
   //
   return m_solde;
}

// --- Obtenir le nombre d'operations realisees sur le compte
//
int CompteBancaire::nombreOperations() {

 
   // Restituer le cardinal de l'ensemble
   //
   return m_pOperations.cardinal();
}

char* CompteBancaire::dateDerniereOperation()
{
	if(nok()) throw -2.0;

	int n = m_pOperations.cardinal();

	if( n == 0 ) return NULL;
	return(( OperationBancaire*) m_pOperations[n])->dateOperation();
}










