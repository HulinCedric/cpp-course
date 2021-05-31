//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Fraction : construction et visualisation
//
// Auteur : C.Fouco
//
#include "Fraction.h"

// Premier constructeur normal
//
Fraction::Fraction(int num, int den) {

   // Controler la validite du denominateur
   //
   if (den==0) throw -3.0;

   // Fixer les deux attributs de la fraction
   //
   m_numerateur= num; 
   m_denominateur= den;

   // Reduire la fraction resultante
   //
   reduire();
}

// Second constructeur normal
//
Fraction::Fraction(int num) {

   // Fixer les deux attributs de la fraction
   //
   m_numerateur= num; 
   m_denominateur= 1;
}

// Constructeur de copie
//
Fraction::Fraction(const Fraction& f) {

   // Fixer les deux attributs de la fraction
   //
   m_numerateur= f.m_numerateur; 
   m_denominateur= f.m_denominateur;
}

// Reduction d'une fraction
//
void Fraction::reduire() {
int signe, pgcd;

   // Traiter le cas particulier d'une fraction nulle
   //
   if (numerateur()==0) {
      m_denominateur= abs(denominateur()); 
      return;
   }
   
   // Determiner le signe du resultat
   //
   if (numerateur()>0)
      if (denominateur()>0) signe= 1;
      else signe= -1;
   else if (denominateur()>0) signe= -1;
        else signe= 1;

   // Calculer le PGCD des deux membres
   //
   pgcd= PGCD(abs(numerateur()), abs(denominateur()));

   // Diviser chaque membre par le PGCD
   //
   m_numerateur  = signe*abs(numerateur())/pgcd;
   m_denominateur= abs(denominateur())/pgcd;
}

// Visualiser une fraction sous la forme <Num>/<Den>
//
ostream& operator << (ostream& os, const Fraction& f) {
char* pF;

    pF= f.toString();
	os << pF;
	delete pF;
    return os;
}

// Methode toString pour les tests unitaires
//
char* Fraction::toString() const {
char* pBuffer= new char[80];

    // Traiter le cas d'une fraction invalide
    //
    if (denominateur()==0) {sprintf(pBuffer, "???");return pBuffer;}

    // Traiter le cas particulier d'une fraction nulle
    //
    if (numerateur()==0)   {sprintf(pBuffer, "0");return pBuffer;}

    // Traiter le cas particulier d'un entier
    //
    if (denominateur()==1) {sprintf(pBuffer, "%d", numerateur());return pBuffer;}

    // Traiter le cas general
    //
    sprintf(pBuffer, "%d/%d", numerateur(), denominateur());
    return pBuffer;
}