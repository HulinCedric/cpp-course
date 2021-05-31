//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Angle - Operateurs + et +=
//
// Auteur : A. Thuaire
//
#include "Angle.h"

// --- Surcharge de l'operateur +
//
Angle* Angle::operator + (const Angle& A) {

   // Calculer le sinus et le cosinus de l'angle resultant
   //
   double dSin = m_sin*A.m_cos + m_cos*A.m_sin;
   double dCos = m_cos*A.m_cos - m_sin*A.m_sin;
   if (fabs(dSin) <= EPSILON) dSin =0;
   if (fabs(dCos) <= EPSILON) dCos =0;

   // Allouer dynamiquement du resultat
   //
   Angle* pResultat= new Angle(dSin, dCos);
   if (pResultat==NULL) throw -1.0;

   // Restituer du resultat
   //
   return pResultat;
}

// --- Surcharge de l'operateur +=
//
Angle& Angle::operator += (const Angle& A) { 

   // Sauvegarder les valeurs initiales
   //
   double dSin= m_sin;

   // Calculer le resultat
   //
   m_sin = m_sin*A.m_cos + m_cos*A.m_sin;
   m_cos = m_cos*A.m_cos - dSin*A.m_sin;
	
   return *this;
}











