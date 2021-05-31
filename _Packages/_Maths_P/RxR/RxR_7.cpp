//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe RxR - Operateurs / et /=
//
// Auteur : A. Thuaire
//
#include "RxR.h"

// --- Surcharges de l'operateur /
//
RxR* RxR::operator / (double reel) {
double a= m_abscisse;
double b= m_ordonnee;

   // Controler la validite de la division
   //
   if (reel==0.0f) throw -2.1;

   // Allouer le resultat
   //
   RxR* pResultat= new RxR(a/reel, b/reel);
   if (pResultat==NULL) throw -1.0;
	   
   // Restituer le resultat
   //
   return pResultat;
}

RxR* RxR::operator / (RxR& z) {
double a= z.m_abscisse;
double b= z.m_ordonnee;

   // Controler la validite de la division
   //
   if (a==0.0 && b==0.0) throw -2.1;

   // Controler le cas particulier d'un denominateur reel
   //
   if (b==0.0) return *this/a;

   // Calculer le conjugue du denominateur
   //
   RxR conjugue= RxR(a, -b);

   // Multiplier le numerateur et le denominateur par le conjugue
   //
   RxR* pNum= (*this)*conjugue;
   RxR* pDen= z*conjugue;

   // Calculer le resultat
   //
   RxR* pW= (*pNum/pDen->m_abscisse);
   RxR* pResultat= new RxR(pW->m_abscisse, pW->m_ordonnee);

   // Liberer les resultats des calculs intermediaires
   //
   delete pNum; delete pDen; delete pW;

   // Restituer le resultat
   //
   return pResultat;
}

// --- Surcharges de l'operateur /=
//
RxR& RxR::operator /= (double reel) {
double a= m_abscisse;
double b= m_ordonnee;

   // Controler la validite de la division
   //
   if (reel==0.0f) throw -2.1;

   m_abscisse /= reel;
   m_ordonnee /= reel;

   return *this;
}

RxR& RxR::operator /= (RxR& z) {
double a= z.m_abscisse;
double b= z.m_ordonnee;

   // Controler la validite de la division
   //
   if (a==0.0 && b==0.0) throw -2.1;

   // Controler le cas particulier d'un denominateur reel
   //
   if (b==0.0) {*this/=a; return *this;}

   // Calculer le conjugue du denominateur
   //
   RxR conjugue= RxR(a, -b);

   // Multiplier le numerateur et le denominateur par le conjugue
   //
   RxR* pNum= (*this)*conjugue;
   RxR* pDen= z*conjugue;

   // Modifier l'objet support
   //
   m_abscisse= pNum->abscisse()/pDen->abscisse();
   m_ordonnee= pNum->ordonnee()/pDen->abscisse();

   // Liberer les resultats des calculs intermediaires
   //
   delete pNum; delete pDen;

   // Restituer le resultat
   //
   return *this;
}









