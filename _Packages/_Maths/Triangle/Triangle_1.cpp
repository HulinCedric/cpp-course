//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Triangle - Constructeurs et methode toString
//    
// Auteur : C.Fouco
//
#include "Triangle.h"

// Constructeur par defaut
//
Triangle::Triangle() {
	
   m_A= Point(-1., 0.); 
   m_B= Point(1., 0.);  
   m_C= Point(0., 1.);
}

// Premier constructeur normal
//
Triangle::Triangle(const Point& A, const Point& B, const Point& C) {

   // Controler que les trois points ne sont pas alignes
   //
   Vecteur AB(A, B), BC(B, C);
   if (AB.colineaire(BC)) throw -3.0;

   // Valuer les attributs
   //
   m_A= A; 
   m_B= B; 
   m_C= C; 
}

// Second constructeur normal
//
Triangle::Triangle(const Point& A, const Vecteur& AB, const Vecteur& AC) {

   // Controler que les deux vecteurs ne sont pas colineaires
   //
   if (AB.colineaire(AC)) throw -3.0;

   // Valuer le sommet A
   //
   m_A= A;

   // Determiner et valuer le sommet B
   //
   Point* pB= A.translation(AB);
   if (pB==NULL) throw -1.0;
   m_B= *pB;
   delete pB;

   // Determiner et valuer le sommet C
   // 
   Point* pC= A.translation(AC);
   if (pC==NULL) throw -1.0;
   m_C= *pC;
   delete pC;
}

// Methode toString pour les tests unitaires
//
char* Triangle::toString() {
char* pBuffer;

   // Allouer le resultat
   //
   pBuffer= new char[80];
   if (pBuffer==NULL) return NULL;

   sprintf(pBuffer, "[%s, %s, %s]", m_A.toString(), 
                                    m_B.toString(), 
                                    m_C.toString());

   return pBuffer;
}




