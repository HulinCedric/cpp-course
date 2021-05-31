//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe CompteCourant - Constructeurs et destructeur
//
// Auteur : A. Thuaire
//
#include "CompteCourant.h"

// --- Surcharge du constructeur par defaut
//
CompteCourant::CompteCourant():CompteBancaire() {

   // Initialiser les attributs propres aux comptes courants
   //
   m_numero  = _Banque::numeroRegistreCptC();
   m_cloture  = false;
}

// --- Constructeur normal
//
CompteCourant::CompteCourant(const Titulaire& t):CompteBancaire(t) {

   // Initialiser les attributs propres aux comptes courants
   //
   m_numero   = _Banque::numeroRegistreCptC();
   m_cloture  = false;
}






