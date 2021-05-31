//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe _Banque - Attributs de classe
//
// Auteur : A. Thuaire
//
#include "_Banque.h"

long int _Banque::m_registreOp  = 1000000L;  // Registre central des operations
long int _Banque::m_registreCpt = 0;         // Registre central des comptes
long int _Banque::m_registreCptC= 8000000L;  // Registre central des comptes courants 
long int _Banque::m_registreCptE= 4000000L;  // Registre central des comptes epargne
int      _Banque::m_registreG   = 1000L;     // Registre central des guichets d'agences 

