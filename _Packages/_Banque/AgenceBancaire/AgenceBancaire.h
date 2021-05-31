//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe AgenceBancaire : gestion d'un ensemble de clients, titulaires de comptes
//
// Edition A            : TP_11
//    + Version 1.0.0   : version initiale
//    + Version 1.1.0   : mise en place de deux dictionnaires des comptes
//                        + ajout accesseur nombreComptesCourant
//                        + ajout accesseur nombreComptesEpargne
//    + Version 1.2.0   : mise en place d'un dictionnaire des comptes fermes
//                        + ajout accesseur nombreComptesFermes
//    + Version 1.3.0   : mise en place du dictionnaire des clients
//    + Version 1.4.0   : mise en place des qualifications privees 
//
// Auteur : A. Thuaire
//
#pragma warning (disable : 4786)

#include <exception>
#include <iostream>
#include <string>
#include <list>
#include <map>

#ifndef _CompteCourant_
#include "..\CompteCourant\CompteCourant.h"
#endif

#ifndef _CompteEpargne_
#include "..\CompteEpargne\CompteEpargne.h"
#endif

#define _AgenceBancaire_

using namespace std;

class AgenceBancaire {

private :
int                                   m_numeroGuichet;
string                                m_adresseAgence;
map <long int, CompteCourant*>        m_comptesCourant;
map <long int, CompteEpargne*>        m_comptesEpargne;
map <long int, CompteBancaire*>       m_comptesFermes;
map <string, list <CompteBancaire*> > m_clients;

// ------ Methodes privees
//
/*int    nombreComptes (const string&, char);
float  totalDepots   (const string&, char);

CompteBancaire*         operator [] (long int);
list <CompteBancaire*>* operator [] (const Titulaire&);

list <CompteBancaire*>* operator () (const Titulaire&, char);*/

public :
int    nombreComptes (const string&, char);
float  totalDepots   (const string&, char);

CompteBancaire*         operator [] (long int);
list <CompteBancaire*>* operator [] (const Titulaire&);

list <CompteBancaire*>* operator () (const Titulaire&, char);
// ------ Constructeurs
//
AgenceBancaire();
AgenceBancaire(char*);
AgenceBancaire(AgenceBancaire&) {throw -3.0;}

// ------ Predicats predefinis
//
inline bool neutre() const {return m_adresseAgence == "-";}
inline bool ok()     const {return m_numeroGuichet > 1000;}
inline bool nok()    const {return !ok();}

// ------ Accesseurs de consultation
//
inline int    nombreComptes () const {return nombreComptesCourant() +
                                             nombreComptesEpargne() +
                                             nombreComptesFermes();}
inline int    numeroGuichet () const {return m_numeroGuichet;}
inline string adresseAgence () const {return m_adresseAgence;}

inline int    nombreComptesCourant () const {return m_comptesCourant.size();}
inline int    nombreComptesEpargne () const {return m_comptesEpargne.size();}
inline int    nombreComptesFermes ()  const {return m_comptesFermes.size();}

// ------ Accesseurs de modification
//
long int ouvrirCompte (const Titulaire&);
long int ouvrirCompte (const Titulaire&, float);
float    fermerCompte (long int);

// ------ Surcharges d'operateurs
//
AgenceBancaire& operator += (CompteBancaire*);
AgenceBancaire& operator -= (CompteBancaire*);

// ------ Services
//
float  executer      (long int, char, char*, float);

inline int nombreClients  () {return m_clients.size();}
int        nombreClients (char);

int    nombreComptes (char);
int    nombreComptes (Titulaire&);
int    nombreComptes (Titulaire&, char);

float  totalDepots   (char);
float  totalDepots   (Titulaire&);
float  totalDepots   (Titulaire&, char);

int    nombreOperations (char*);

char*  toString();

};


