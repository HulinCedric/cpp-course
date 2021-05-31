//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe _Banque - Service operationValide
//
// Auteur : A. Thuaire
//
#include "_Banque.h"

// --- Controle de la validite d'une operation bancaire
//
bool _Banque::operationValide(void* pCpt, char type) {
   
   if (type==VERSEMENT)    return true;
   if (type==RETRAIT)      return true;
   if (type==REMUNERATION) return true;

   return false;
}











