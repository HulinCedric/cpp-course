//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe AgenceBancaire - Constructeurs et methode toString
//
// Auteur : A. Thuaire
//
#include "AgenceBancaire.h"

// --- Surcharge du constructeur par defaut
//
AgenceBancaire::AgenceBancaire() {

   // Initialiser les attributs
   //
   m_numeroGuichet = _Banque::numeroRegistreG();
   m_adresseAgence = "-";
}

// --- Constructeur normal
//
AgenceBancaire::AgenceBancaire(char* pAdresse) {

   // Controler la validite du parametre
   //
   if (_Banque::validiteDate(pAdresse)) throw -2.1;

   // Initialiser les attributs
   //
   m_numeroGuichet = _Banque::numeroRegistreG();
   m_adresseAgence = pAdresse;
}

// --- Restituer la description d'une agence pour les tests unitaires
//
char* AgenceBancaire::toString() {
char* pBuffer; 

   // Allouer le buffer resultant
   //
   pBuffer= new char[100];
   if (pBuffer == NULL) throw -1.0;

   // Traiter le cas particulier de l'element neutre
   //
   if (neutre()) {sprintf(pBuffer, "---"); return pBuffer;}

   // Traiter uniquement les proprietes "numeroGuichet", "adresse"
   // et le nombre total de comptes
   //
   sprintf(pBuffer, "%d - %s / %d", m_numeroGuichet,
                                    m_adresseAgence.c_str(), 
                                    nombreComptes());
   return pBuffer;
}







