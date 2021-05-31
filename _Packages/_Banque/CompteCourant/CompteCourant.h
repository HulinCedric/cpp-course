//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe CompteCourant : gestion des comptes non remuneres
//
// Edition A      : TP_7
//    + Version 1.0.0   : version initiale
//
// Auteur : A. Thuaire
//
#ifndef _CompteBancaire_
#include "..\CompteBancaire\CompteBancaire.h"
#endif

#define _CompteCourant_

class CompteCourant : public CompteBancaire {
private :
long int m_numero;
bool m_cloture;

public :
// --- Constructeurs et destructeur
//
CompteCourant();
CompteCourant(const Titulaire&);
CompteCourant(CompteCourant&) {throw -3.1;}

// --- Predicats predefinis
//
inline bool ok() {return titulaireCompte().ok() && 
                         m_numero > 8000000L   && 
                         soldeCompte() >= 0.0f;
                 }

// --- Accesseurs de consultation
//
long int numeroCompte();

// --- Services
//
float executer(char, char*, float);
float  cloturer();

};


