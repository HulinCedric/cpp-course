//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe CompteBancaire - Methode serialize
//
// Auteur : C. Fouco
//
#include "CompteBancaire.h"

// Serialisation 
//
void CompteBancaire::serialize(Archive& ar) {

  // Controler la validite de l'objet support
   //
   if (nok()) throw -2.0;

   // Traiter le cas des attributs composes
   //
   m_titulaire.serialize(ar);
   m_pOperations.serialize(ar);


   // Traiter le cas des attributs predefinis
   //
   if (ar.isStoring()) {
      ar << m_numero;
      ar << m_solde;
   }
   else {
      ar >> m_numero;
      ar >> m_solde;
   }
} 








