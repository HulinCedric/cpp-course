//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe CompteCourant - Methode serialize
//
// Auteur : C. Fouco
//
#include "CompteCourant.h"

// Serialisation 
//
void CompteCourant::serialize(Archive& ar) {

   // Controler la validite de l'objet support
   //
   if (nok()) throw -2.0;


   // Traiter le cas de la relation d'heritage
   //
   CompteBancaire::serialize(ar);


   // Traiter le cas des attributs predefinis
   //
   if (ar.isStoring()) {
      ar << m_numero;
   }
   else {
      ar >> m_numero;
   }
} 








