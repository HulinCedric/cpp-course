//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Segment - Homothetie d'un segment
//
// Auteur : A. Thuaire
//
#include "Segment.h"

// --- Homothetie d'un segment par rapport a O(0,0)
//
Segment* Segment::homothetie (double rapport) const {

   // Traiter le cas particulier d'un coefficient nul
   //
   if (rapport==0.0) throw -3.0;

   // Calculer l'image des deux extremites
   //
   Point* pImg_A= m_A.homothetie(rapport);
   if (pImg_A==NULL) throw -1.0;

   Point* pImg_B= m_B.homothetie(rapport);
   if (pImg_B==NULL) {delete pImg_A; throw -1.0;}

   // Restituer le resultat
   //
   Segment* pResultat= new Segment(*pImg_A, *pImg_B);
   delete pImg_A; delete pImg_B;
   return pResultat;
}

// --- Homothetie d'un segment par rapport a un centre quelconque
//
Segment* Segment::homothetie (const Point& centre, double rapport) const {

   // Traiter le cas particulier d'un coefficient nul
   //
   if (rapport==0.0) throw -3.0;

   // Calculer l'image des deux extremites
   //
   Point* pImg_A= m_A.homothetie(centre, rapport);
   if (pImg_A==NULL) throw -1.0;

   Point* pImg_B= m_B.homothetie(centre, rapport);
   if (pImg_B==NULL) {delete pImg_A; throw -1.0;}

   // Restituer le resultat
   //
   Segment* pResultat= new Segment(*pImg_A, *pImg_B);
   delete pImg_A; delete pImg_B;
   return pResultat;
}











