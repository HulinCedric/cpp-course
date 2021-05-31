//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Fraction - Surcharges des operateurs > et >=
//
// Auteur : C.Fouco
//
#include "Fraction.h"

// Surcharges de l'operateur >
//
bool Fraction::operator > (const Fraction& op2) {return !(*this<=op2);}
bool Fraction::operator > (int op2) {return !(*this<=op2);}
bool Fraction::operator >=(const Fraction& op2) {return !(*this<op2);}
bool Fraction::operator >=(int op2) {return !(*this<op2);}
