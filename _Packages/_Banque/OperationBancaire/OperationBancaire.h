//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe OperationBancaire : modelisation des flux financiers inter comptes
//
// Edition A    : TP_5
//    + Version 1.0.0  : version initiale
//    + Version 1.1.0  : introduction de la classe abstraite _Banque
//
// Auteur : A. Thuaire
//
#ifndef _Banque_
#include "..\_Banque\_Banque.h"
#endif

#define _OperationBancaire_

class OperationBancaire {
private :
char     m_typeOperation;
long int m_numeroOperation;
char*    m_intituleOperation;
char*    m_dateOperation;
float    m_montantOperation;

public :
OperationBancaire();
OperationBancaire(char, char*, float);
OperationBancaire(OperationBancaire&) {throw -3.0;}
~OperationBancaire();

inline bool neutre() {return m_numeroOperation == 1000000L && m_typeOperation==NEUTRE;}
inline bool ok()     {return m_numeroOperation >= 1000000L && m_montantOperation >= 0.0f;}
inline bool nok()    {return !ok();}

char     typeOperation();
long int numeroOperation();
char*    intituleOperation();
char*    dateOperation();
float    montantOperation();

char*  toString();

};



