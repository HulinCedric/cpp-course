//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Vecteur - Operateurs +, - et * 
//
// Auteur : A. Thuaire
//
#include "Vecteur.h"

// --- Surcharge de l'operateur +
//
Vecteur* Vecteur::operator + (const Vecteur& V) {
double x= abscisse() + V.abscisse();
double y= ordonnee() + V.ordonnee();

   return new Vecteur(x, y);
}

// --- Surcharge de l'operateur -
//
Vecteur* Vecteur::operator - (const Vecteur& V) {
double x= abscisse() - V.abscisse();
double y= ordonnee() - V.ordonnee();

   return new Vecteur(x, y);
}

Vecteur* Vecteur::operator - () {
double x= -abscisse();
double y= -ordonnee();

   return new Vecteur(x, y);
}

// --- Surcharge de l'operateur *
//
Vecteur* Vecteur::operator * (double k) {
double x= k*abscisse();
double y= k*ordonnee();

   return new Vecteur(x, y);
}

// --- Surcharge de l'operateur *
//
double Vecteur::operator * (const Vecteur& V) {
double x= abscisse()*V.abscisse();
double y= ordonnee()*V.ordonnee();

   return x+y;
}








