//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Segment - Rotation d'un segment
//
// Auteur : A. Thuaire
//
#include "Segment.h"

// --- Rotation d'un segment par rapport a O(0,0)
//
Segment* Segment::rotation (double teta) const {

   // Traiter le cas particulier d'un angle nul
   //
   if (teta==0.0) return new Segment(*this);

   // Calculer l'image des deux extremites
   //
   Point* pImg_A= m_A.rotation(teta);
   if (pImg_A==NULL) throw -1.0;

   Point* pImg_B= m_B.rotation(teta);
   if (pImg_B==NULL) {delete pImg_A; throw -1.0;}

   // Restituer le resultat
   //
   Segment* pResultat= new Segment(*pImg_A, *pImg_B);
   delete pImg_A; delete pImg_B;
   return pResultat;
}

// --- Rotation d'un segment par rapport a un centre quelconque
//
Segment* Segment::rotation (const Point& centre, double teta) const {

   // Traiter le cas particulier d'un angle nul
   //
   if (teta==0.0) return new Segment(*this);

   // Calculer l'image des deux extremites
   //
   Point* pImg_A= m_A.rotation(centre, teta);
   if (pImg_A==NULL) throw -1.0;

   Point* pImg_B= m_B.rotation(centre, teta);
   if (pImg_B==NULL) {delete pImg_A; throw -1.0;}

   // Restituer le resultat
   //
   Segment* pResultat= new Segment(*pImg_A, *pImg_B);
   delete pImg_A; delete pImg_B;
   return pResultat;
}












