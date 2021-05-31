//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Droite - Constructeurs et methode toString
//
// Auteur : A. Thuaire
//
#include "Droite.h"

// --- Constructeur par defaut
//
Droite::Droite() {
   m_A= 1;
   m_B= 0;
   m_C= 0;
}

// --- Premier constructeur normal
//
Droite::Droite(double a, double b, double c) {

   // Controler le cas d'une equation invalide
   //
   if (a==0. && b==0 && c==0.) throw -3.0;

   m_A= a;
   m_B= b;
   m_C= c;
}

// --- Second constructeur normal
//
Droite::Droite(const Point& P1, const Point& P2) {

   // Controler le cas de deux points identiques
   //
   if (P1==P2) throw -3.0;

   // Traiter le cas particulier d'une droite // a l'axe des abscisses
   //
   if (P1.ordonnee() == P2.ordonnee()) {
      m_A=1; m_B=0; m_C=-P1.ordonnee(); 
      return;
   }

   // Traiter le cas particulier d'une droite // a l'axe des ordonnees
   //
   if (P1.abscisse() == P2.abscisse()) {
      m_A=0; m_B=1; m_C=-P1.abscisse();
      return;
   }

   // Traiter le cas general
   //
   m_A = 1; 
   m_B = (P1.ordonnee() - P2.ordonnee())/(P2.abscisse() - P1.abscisse());
   m_C = -P1.ordonnee() - m_B*P1.abscisse();
}

// --- Troisieme constructeur normal
//
Droite::Droite(const Point& P, const Vecteur& v) {

   // Traiter le cas particulier V // axe des ordonnees
   //
   if (v.abscisse()==0.) {
      m_A=0; m_B=1; m_C=-P.abscisse();
      return;
   }

   // Traiter le cas general
   //
   m_A = 1; 
   m_B = -v.ordonnee()/v.abscisse();
   m_C = -P.ordonnee()-m_B*P.abscisse();
}

// --- Methode toString pour les tests unitaires
//
char* Droite::toString() {
char* pBuffer= new char[80];

   sprintf(pBuffer, "[%lg, %lg, %lg]",m_A, m_B, m_C);
   return pBuffer;
}



