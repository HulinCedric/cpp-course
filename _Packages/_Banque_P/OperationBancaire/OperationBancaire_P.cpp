//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe OperationBancaire - Methode serialize
//
// Auteur : C. Fouco
//
#include "OperationBancaire.h"


// --- Serialisation des instances 
//
void OperationBancaire::serialize(Archive& ar) {

   if (ar.isStoring()) {
      ar << m_typeOperation << m_numeroOperation << m_intituleOperation << m_dateOperation << m_montantOperation;
   }
   else {
      ar >> m_typeOperation >> m_numeroOperation >> m_intituleOperation >> m_dateOperation >> m_montantOperation;
   } 
}









   














   
















