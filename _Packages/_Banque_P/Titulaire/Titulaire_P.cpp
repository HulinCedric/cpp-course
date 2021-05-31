//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe Titulaire - Methode serialize
//
// Auteur : C. Fouco
//
#include "Titulaire.h"


// --- Serialisation des instances 
//
void Titulaire::serialize(Archive& ar) {

   if (ar.isStoring()) {
      ar << m_pNom << m_pPrenom << m_pDateNaissance << m_pAdresse;
   }
   else {
      ar >> m_pNom >> m_pPrenom >> m_pDateNaissance >> m_pAdresse;
   } 
}







   














   
















