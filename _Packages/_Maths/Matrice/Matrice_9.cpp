//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2006_2007 - Package _Maths
//
// Classe Matrice : calcul du determinant d'une matrice carree NxN
//
// Auteur : A. Thuaire
//
#include "Matrice.h"

// Calcul du determinant par la methode des cofacteurs
// Algorithme recursif !
//
int Matrice::determinant() {
int resultat= 0;

   // Traiter le cas particulier N=1
   // 
   if (m_ordre==1) return m_pT[0];

   // Traiter le critere d'arret de la recursion (N= 2)
   // 
   if (m_ordre==2)    
      return (*this)(1, 1)*(*this)(2, 2) - (*this)(1, 2)*(*this)(2, 1);

   // Traiter le cas general de la recursion
   //
   Matrice * pCoFacteurs;
   int signe= 1;
   int rang, delta;

   for (int k=1; k<=m_ordre; k++) {

      // Controler le cas particulier M(1, k) nul
      //
      if ((*this)(1, k)==0) {signe *= -1; continue;}

      // Allouer la matrice courante des cofacteurs
      //
      pCoFacteurs = new Matrice(m_ordre-1) ;
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
      delta= pCoFacteurs->determinant();

      // Detruire la matrice courante des cofacteurs
      //
      delete pCoFacteurs;

      // Cumuler le terme courant au resultat
      //
      resultat += signe*(*this)(1, k)*delta;

      // Changer le signe de cumul pour le prochain terme
      //
      signe *= -1;
   }

   // Restituer le resultat 
   // 
   return resultat;
   
}

