//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe CompteBancaire - Constructeurs
//
// Auteur : A. Thuaire
//
#include "CompteBancaire.h"

// --- Surcharge du constructeur par defaut
//
CompteBancaire::CompteBancaire() {

   // Initialiser a neutre les attributs non values
   //
   Titulaire neutre;

   m_titulaire  = neutre;
   m_numero     = 0;
   m_solde      = 0.0f;
}

// --- Constructeur normal
//
CompteBancaire::CompteBancaire(const Titulaire& t) {

   // Controler la validite des parametres
   //
   if(t.nok()) throw -2.1;

   // Initialiser les attributs
   //
   m_titulaire = t;
   m_numero    = _Banque::numeroRegistreCpt();
   m_solde     = 0.0f;
}

// --- Restituer la description d'un compte bancaire pour les tests unitaires
//
char* CompteBancaire::toString() {
char* pBuffer;

   // Allouer le resultat
   //
   pBuffer= new char[150];
   if (pBuffer==NULL) return NULL;

   // Traiter le cas particulier de l'element neutre
   //
   if (neutre()) {sprintf(pBuffer, "---"); return pBuffer;}

   // Traiter le cas general
   //
   sprintf(pBuffer, "\n%s\n%ld - %7.2f", m_titulaire.toString(), 
                                         m_numero, 
                                         m_solde);
   return pBuffer;
}





