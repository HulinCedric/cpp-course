//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Angle - Constructeurs et methode toString
//
// Auteur : A. Thuaire
//
#include "Angle.h"

// --- Constructeur par defaut
//
Angle::Angle() {

   m_sin= 0;
   m_cos= 1;
}

// --- Premier constructeur normal
//
Angle::Angle(double x) {

   m_sin= sin(x);
   m_cos= cos(x);
}

// --- Second constructeur normal
//
Angle::Angle(double x, double y) {

   // Controler la validite du couple de parametres
   //
   if (fabs(x*x + y*y) < 1. - EPSILON) throw -3.0;
   if (fabs(x*x + y*y) > 1. + EPSILON) throw -3.1;
   m_sin= x;
   m_cos= y;
}

// --- Troisieme constructeur normal
//
Angle::Angle(const RxR& A, const RxR& B, const RxR& C) {
double x_A= A.abscisse();
double y_A= A.ordonnee();
double x_B= B.abscisse();
double y_B= B.ordonnee();
double x_C= C.abscisse();
double y_C= C.ordonnee();

   // Calculer la longueur BA
   //
   double x_BA= x_A - x_B;
   double y_BA= y_A - y_B;   
   double BA  = sqrt(x_BA*x_BA + y_BA*y_BA);

   // Calculer la longueur BC
   //
   double x_BC= x_C - x_B;
   double y_BC= y_C - y_B; 
   double BC  = sqrt(x_BC*x_BC + y_BC*y_BC);

   // Calculer le produit croise
   //
   double prodV= x_BA*y_BC - x_BC*y_BA;

   // Calculer le produit scalaire
   //
   double prodS= x_BA*x_BC + y_BA*y_BC;

   // Valuer les deux attributs
   //
   m_sin= prodV/(BA*BC);
   m_cos= prodS/(BA*BC);
}


// --- Methode toString pour les tests unitaires
//
char* Angle::toString() {
char* pBuffer;
double sinus, cosinus;

   pBuffer= new char[80];
   if (pBuffer==NULL) return NULL;

   if (fabs(m_sin) > EPSILON) sinus= m_sin;
   else sinus= 0.;

   if (fabs(m_cos) > EPSILON) cosinus= m_cos;
   else cosinus= 0.;

   sprintf(pBuffer, "{%lg, %lg}", sinus, cosinus);
   return pBuffer;
}





