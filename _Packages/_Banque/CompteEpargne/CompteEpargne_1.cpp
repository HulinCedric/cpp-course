//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe CompteEpargne - Constructeurs
//
// Auteur : A. Thuaire
//
#include "CompteEpargne.h"

// --- Surcharge du constructeur par defaut
//
CompteEpargne::CompteEpargne():CompteBancaire() {

   // Initialiser l'attribut surcharge
   //
   m_numero= _Banque::numeroRegistreCptE();

   // Initialiser par defaut le premier attribut supplementaire
   //
   m_cloture  = false;

   // Initialiser par defaut le seoond attribut supplementaire
   //
   m_taux= 0.0f;

   
}

// --- Constructeur normal
//
CompteEpargne::CompteEpargne(const Titulaire& t, float taux):CompteBancaire(t) {

   // Initialiser l'attribut surcharge
   //
   m_numero= _Banque::numeroRegistreCptE();

   // Initialiser par defaut le premier attribut supplementaire
   //
   m_cloture  = false;

   // Initialiser le second attribut supplementaire
   //
   m_taux= taux;
}





