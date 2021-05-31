//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2007_2008 - Package _Maths
//
// Classe Segment - Methodes projX, projY et translation
//
// Auteur : A. Thuaire
//
#include "Segment.h"

// --- Projection du segment support sur l'axe des abscisses 
//
Segment* Segment::projX () {

   // Calculer l'image des deux extremites
   //
   Point* pImg_A= new Point (m_A.abscisse(),0);
   if (pImg_A==NULL) throw -1.0;

   Point* pImg_B= new Point (m_B.abscisse(), 0);
   if (pImg_B==NULL) {delete pImg_A; throw -1.0;}

   // Controler que les deux images sont deux points distincts
   //
   if (*pImg_A == *pImg_B) {
      delete pImg_A; delete pImg_B; 
      return NULL;
   }

   // Restituer le resultat
   //
   Segment* pResultat= new Segment(*pImg_A, *pImg_B);
   delete pImg_A; delete pImg_B;
   return pResultat;
}

// --- Projection du segment support sur l'axe des ordonnees 
//
Segment* Segment::projY () {

   // Calculer l'image des deux extremites
   //
   Point* pImg_A= new Point(0, m_A.ordonnee());
   if (pImg_A==NULL) throw -1.0;

   Point* pImg_B= new Point(0, m_B.ordonnee());
   if (pImg_B==NULL) {delete pImg_A; throw -1.0;}

   // Controler que les deux images sont deux points distincts
   //
   if (*pImg_A == *pImg_B) {
      delete pImg_A; delete pImg_B; 
      return NULL;
   }

   // Restituer le resultat
   //
   Segment* pResultat= new Segment(*pImg_A, *pImg_B);
   delete pImg_A; delete pImg_B;
   return pResultat;
}












