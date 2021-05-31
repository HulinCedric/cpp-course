//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe Titulaire - Surcharge des operateurs =, == et !=
//
// Auteur : A. Thuaire
//
#include "Titulaire.h"

// Surcharge de l'operateur =
//
Titulaire& Titulaire::operator = (const Titulaire& source) {
int taille;

   // Controler la validite de l'objet support
   //
   if (nok()) throw -2.0;

   // Controler la validite de la source
   //
   if (source.nok()) throw -2.1;

   // Liberer les attributs de la cible
   //
   delete[] m_pNom;
   delete[] m_pPrenom;
   delete[] m_pDateNaissance;
   delete[] m_pAdresse;

   // Allouer et initialiser le nom
   //
   taille= strlen(source.nom());
   m_pNom= new char[taille+1];
   if (m_pNom == NULL) throw -1.0;
   strcpy(m_pNom, source.nom());

   // Allouer et initialiser le prenom
   //
   taille= strlen(source.prenom());
   m_pPrenom= new char[taille+1];
   if (m_pPrenom == NULL) {
      delete m_pNom;
      throw -1.0;
   }
   strcpy(m_pPrenom, source.prenom());

   // Allouer et initialiser la date de naissance
   //
   taille= strlen(source.dateNaissance());
   m_pDateNaissance= new char[taille+1];
   if (m_pDateNaissance == NULL) {
      delete m_pNom;
      delete m_pPrenom;
      throw -1.0;
   }
   strcpy(m_pDateNaissance, source.dateNaissance());

   // Allouer et initialiser l'adresse
   //
   taille= strlen(source.m_pAdresse);
   m_pAdresse= new char[taille+1];
   if (m_pAdresse == NULL) {
      delete m_pNom;
      delete m_pPrenom;
      delete m_pDateNaissance;
      throw -1.0;
   }
   strcpy(m_pAdresse, source.m_pAdresse);

   return *this;
}

// Surcharge de l'operateur ==
//
bool Titulaire::operator == (const Titulaire& op2) {

   // Controler la validite de l'objet support
   //
   if (nok()) throw -2.0;

   // Controler la validite de la source
   //
   if (op2.nok()) throw -2.1;

   // Controler l'identite des noms
   //
   if (strcmp(nom(), op2.nom())) return false;

   // Controler l'identite des prenoms
   //
   if (strcmp(prenom(), op2.prenom())) return false;

   // Controler l'identite des dates de naissance
   //
   if (strcmp(dateNaissance(), op2.dateNaissance())) return false;

   return true;
}

// Surcharge de l'operateur !=
//
bool Titulaire::operator != (const Titulaire& op2) { return !(*this == op2);}




 