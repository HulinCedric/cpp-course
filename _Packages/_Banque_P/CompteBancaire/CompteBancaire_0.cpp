//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe CompteBancaire - Methode privee operationValide et historiserOp
//
// Auteur : A. Thuaire
//
#include "CompteBancaire.h"

// --- Controle de la validite d'une operation bancaire
//
/*bool CompteBancaire::operationValide(char type) {
   
   if (type==VERSEMENT) return true;
   if (type==RETRAIT)   return true;

   return false;
}*/

// --- Historiser l'operation bancaire courante
//
void CompteBancaire::historiserOp(OperationBancaire* pOp) {

	this->m_pOperations += pOp;
}









