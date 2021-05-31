//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe CompteBancaire : gestion des comptes de tout titulaire
//
// Edition A      : TP_6
//    + Version 1.0.0   : version initiale
//
// Auteur : A. Thuaire
//
#ifndef _Titulaire_
#include "../Titulaire/Titulaire.h"
#endif

#ifndef _OperationBancaire_
#include "../OperationBancaire/OperationBancaire.h"
#endif

#ifndef _Collection_
#include "T:/_Maths/Collection/Collection.h"
#endif


#define _CompteBancaire_

class CompteBancaire: public Object{
private :
Titulaire            m_titulaire;
int                  m_numero;
float                m_solde;
Collection			 m_pOperations;     // Historique des operations

//virtual bool operationValide(char);

void historiserOp (OperationBancaire*);


public :
// --- Constructeurs et destructeur
//
CompteBancaire();
CompteBancaire(const Titulaire&);
CompteBancaire(CompteBancaire&) {throw -3.1;}

// --- Predicats predefinis
//
inline bool neutre() {return m_titulaire.neutre();}
inline bool ok()     {return m_titulaire.ok() && m_numero >= 0;}
inline bool nok()    {return !ok();}

// --- Accesseurs
//
Titulaire&   titulaireCompte();
char*        identiteTitulaire();
char*        adresseTitulaire();
long int     numeroCompte();
float        soldeCompte();
int          nombreOperations();
char*		 dateDerniereOperation();

void  modifierAdresse (char *);

// --- Services
//

float executer(char, char*, float);
virtual CompteBancaire& operator -=(float);
virtual CompteBancaire& operator +=(float);
int nombreOperations(char*);

char*  toString();

void serialize (Archive&);

};


