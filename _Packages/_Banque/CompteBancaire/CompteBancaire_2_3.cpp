//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe CompteBancaire - Accesseurs de modification
//
// Auteur : A. Thuaire
//
#include "CompteBancaire.h"

// --- Modifier l'adresse du titulaire du compte
//
void CompteBancaire::modifierAdresse (char* pAdr) {

   // Controler la validite de l'objet support
   //
   if(nok()) throw -2.0;

   // Controler la validite du parametre
   //
   if(pAdr==NULL) throw -2.1;

   // Modifier l'attribut "adresse" du titulaire
   //
   m_titulaire.modifierAdresse(pAdr);
}









