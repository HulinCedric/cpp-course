//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe Titulaire - Accesseurs de consultation et de modification
//
// Auteur : A. Thuaire
//
#include "Titulaire.h"

// Consultation du nom du titulaire
//
char* Titulaire::nom () const{
char* pResultat;

   // Controler la validite de l'objet support
   //
   if (nok()) throw -2.0;

   // Allouer le resultat
   //
   pResultat= new char[strlen(m_pNom)+1];
   if (pResultat==NULL) throw -1.0;

   // Restituer le resultat
   //
   strcpy(pResultat, m_pNom);
   return pResultat;
}

// Consultation du prenom du titulaire
//
char* Titulaire::prenom () const{
char* pResultat;

   // Controler la validite de l'objet support
   //
   if (nok()) throw -2.0;

   // Allouer le resultat
   //
   pResultat= new char[strlen(m_pPrenom)+1];
   if (pResultat==NULL) throw -1.0;

   // Restituer le resultat
   //
   strcpy(pResultat, m_pPrenom);
   return pResultat;
}

// Consultation de la date de naissance du titulaire
//
char* Titulaire::dateNaissance () const {
char* pResultat;

   // Controler la validite de l'objet support
   //
   if (nok()) throw -2.0;

   // Allouer le resultat
   //
   pResultat= new char[strlen(m_pDateNaissance)+1];
   if (pResultat==NULL) throw -1.0;

   // Restituer le resultat
   //
   strcpy(pResultat, m_pDateNaissance);
   return pResultat;
}

// Consultation de l'adresse du titulaire
//
char* Titulaire::adresse () const {
char* pResultat;

   // Controler la validite de l'objet support
   //
   if (nok()) throw -2.0;

   // Allouer le resultat
   //
   pResultat= new char[strlen(m_pAdresse)+1];
   if (pResultat==NULL) throw -1.0;

   // Restituer le resultat
   //
   strcpy(pResultat, m_pAdresse);
   return pResultat;
}

// Modification de l'adresse du titulaire
//
void Titulaire::modifierAdresse (char* const pAdresse) {

   // Controler la validite de l'objet support
   //
   if (nok()) throw -2.0;

   // Liberer la zone adresse existante
   //
   delete[] m_pAdresse;

   // Allouer la nouvelle adresse
   //
   m_pAdresse= new char[strlen(pAdresse)+1];
   if (m_pAdresse==NULL) throw -1.0;

   // Modifier l'attribut cible
   //
   strcpy(m_pAdresse, pAdresse);
}


 

