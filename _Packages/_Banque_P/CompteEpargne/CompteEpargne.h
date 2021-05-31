//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe CompteEpargne : gestion des comptes remuneres
//
// Edition A      : TP_8
//    + Version 1.0.0   : version initiale
//    + Version 1.1.0   : modification des tests unitaires de la
//                        methode executer pour gerer le cas des
//                        retraits superieur ou egaux à 200 €
//                        + suppression methode privee operationValide
//                        + ajout methodes privees remunerer
//                        + introduction de la remuneration mensuelle
//                          des comptes au premier jour du mois 
//
// Auteur : A. Thuaire
//
#ifndef _CompteBancaire_
#include "..\CompteBancaire\CompteBancaire.h"
#endif

#define _CompteEpargne_

class CompteEpargne : public CompteBancaire {
private:
long int m_numero;
bool     m_cloture;
float    m_taux;

CompteBancaire& operator -=(float);
float           remunerer  ();


public :
// ------ Constructeurs
//
CompteEpargne();
CompteEpargne(const Titulaire&, float);
CompteEpargne(CompteEpargne&) {throw -3.1;}

// ------ Predicats predefinis
//
inline bool ok() {return titulaireCompte().ok() && 
                         m_numero > 4000000L    &&
                         m_numero < 8000000L    &&
                         soldeCompte() >= 0.0f;
                 }

// ------ Accesseurs
//
long int numeroCompte();
float    soldeCompte();

// ------ Services
//
float executer(char, char*, float);
float  cloturer();

float remunerer  (char*);

void serialize (Archive&);

};



