//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2006_2007 - Package _Maths
//
// Classe MatriceF - Calcul du determinant d'une matrice carree NxN (N>=1)
//
// Auteur : A. Thuaire
//
#include "MatriceF.h"

// Calcul du determinant par la methode des cofacteurs
// Algorithme recursif !
//
Fraction* MatriceF::determinant() {
Fraction *pW1, *pW2;

   // Allouer la fraction resultante
   //
   Fraction* pResultat= new Fraction(0);
   if (pResultat==NULL) throw -1.0;

   // Traiter le cas particulier (N= 1)
   // 
   if (m_ordre==1) {
      *pResultat= (*this)(1, 1);
      return pResultat;
   }

   // Traiter le critere d'arret de la recursion (N= 2)
   // 
   if (m_ordre==2) {
      pW1= (*this)(1, 1)*(*this)(2, 2);
	  pW2= (*this)(1, 2)*(*this)(2, 1);
      pResultat= *pW1-*pW2; 
      return pResultat;
   }

   // Traiter le cas general de la recursion
   //
   MatriceF* pCoFacteurs;
   int signe= 1;
   int rang;
   Fraction* pDelta;

   for (int k=1; k<=m_ordre; k++) {

      // Controler le cas particulier M(1, k) nul
      //
      if ((*this)(1, k)==0) {signe *= -1; continue;}

      // Allouer la matrice courante des cofacteurs
      //
      pCoFacteurs = new MatriceF(m_ordre-1) ;
      if (pCoFacteurs==NULL) throw -1.0;

      // Renseigner la matrice courante des cofacteurs
      //
      for (int i=2; i<=m_ordre; i++) {
         rang= 1;
         for (int j=1; j<=m_ordre; j++)
            if (j != k) (*pCoFacteurs)(i-1, rang++)= (*this)(i, j);
      }

      // Calculer le determinant de la matrice courante des cofacteurs
      //
      pDelta= pCoFacteurs->determinant();
      if (pDelta==NULL) throw -1.0;

      // Detruire la matrice courante des cofacteurs
      //
      delete pCoFacteurs;

      // Cumuler le terme courant au resultat
      //
      pW1= (*this)(1, k)*(*pDelta);
      *pResultat += *((*pW1)*signe);
      delete pW1;

      // Changer le signe de cumul pour le prochain terme
      //
      signe *= -1;
   }

   // Restituer le resultat 
   // 
   return pResultat;
   
}

