//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe _Banque : constantes fonctionnelles et servitudes
//
// Edition  A   : TP_5
//    + Version 1.0.0  : version initiale
//    + Version 1.1.0  : ajout de l'attribut m_registreOp
//    + Version 1.2.0  : ajout de l'attribut m_registreCpt
//    + Version 1.3.0  : ajout de l'attribut m_registreCptC
//    + Version 1.4.0  : ajout de l'attribut m_registreCptE
//    + Version 1.5.0  : finalisation de validiteDate (IE_1)
//                       + methodes annee, mois, jour, 
//                       + methodes deltaAnnees et deltaMois,
//                       + predicats anterieur et posterieur,
//                       + ajout de l'attribut m_registreG
//                       + ajout service operationValide
//                          
// Auteur : A. Thuaire
//
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define NEUTRE       'N'
#define VERSEMENT    'V'
#define RETRAIT      'R'
#define REMUNERATION 'I'

#define _Banque_

class _Banque {
private :
static long int m_registreOp;
static long int m_registreCpt;
static long int m_registreCptC;
static long int m_registreCptE;
static int      m_registreG;

public :

// ------ Predicats
//
static bool validiteId   (char[]);
static bool validiteDate (char[]);

static bool operationValide(void*, char);

static bool anterieur  (char[], char[]); 
static bool posterieur (char[], char[]);

// ------ Services de gestion des dates
//
static  char* dateCourante();

static  int   annee (char[]);
static  int   mois  (char[]);
static  int   jour  (char[]);

static  int   deltaAnnees (char[], char[]);
static  int   deltaMois   (char[], char[]);
static char*  jourSuivant(char* pDate);
static char*  demain();
static char* debutMoisSuivant(char* );
static char* debutAnneeSuivante(char* );


// ------ Services de gestion des numeros de registres
//
static  long  int numeroRegistreOp();
static  long  int numeroRegistreCpt();
static  long  int numeroRegistreCptC();
static  long  int numeroRegistreCptE();
static  int       numeroRegistreG();

virtual void verrouiller()=0;

};

