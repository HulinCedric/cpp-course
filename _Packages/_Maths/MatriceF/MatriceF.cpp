//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2007_2008 - Package _Maths
//
// Classe MatriceF - Constructeurs, destructeur et 
//                   methodes toString et remplir
//
// Auteur : A. Thuaire
//
#include "MatriceF.h"

// Constructeur par defaut
//
MatriceF::MatriceF () {

   // Fixer le rang de la matrice
   //
   m_ordre= 1;

   // Allouer le tableau interne
   //
   m_pT= new Fraction [1];
   if (m_pT==NULL) throw -1.0;

   // Initialiser l'element a zero
   //
   m_pT[0]= Fraction(0);
}
 
// Constructeur normal
//
MatriceF::MatriceF (int ordre) {

   // Traiter le cas d'un rang invalide
   //
   if (ordre < 1) throw -2.1;

   // Fixer le rang de la matrice
   //
   m_ordre= ordre;

   // Allouer le tableau interne
   //
   int cardinal= ordre*ordre;
   m_pT= new Fraction [ordre*ordre];
   if (m_pT==NULL) throw -1.0;

   // Initialiser tous les elements a zero
   //
   for (int i=0;i<cardinal;i++) m_pT[i]= 0;
}

// Surcharge du constructeur de copie
//
MatriceF::MatriceF (const MatriceF& source) {

   // Fixer le rang de la copie
   //
   m_ordre= source.ordre();

   // Allouer le tableau interne
   //
   int cardinal= ordre()*ordre();
   m_pT= new Fraction[cardinal];
   if (m_pT==NULL) throw -1.0;

   // Copier tous les elements de la source
   //
   for (int i=0;i<cardinal;i++) m_pT[i]= source.m_pT[i];
}

// Surcharge du destructeur
//
MatriceF::~MatriceF() {

   // Liberer le tableau interne
   //
   delete[] m_pT;
}

// Transcoder en chaine de caracteres une matrice
//
char* MatriceF::toString() {
int debut=0;
char* pBuffer;
char* pW;

   // Allouer le buffer global resultant
   //
   pBuffer= new char[10*ordre()*ordre()];
   if (pBuffer==NULL) return NULL;

   // Allouer un buffer intermediaire pour le transcodage de chaque element
   //
   pW= new char[4];
   if (pW==NULL) {delete[] pBuffer; return NULL;}

   sprintf(pBuffer, "\n");
   for (int i=0;i<ordre();i++) {
      for (int j=0;j<ordre();j++) {
         sprintf(pW, "%s\t", m_pT[debut+j].toString());
         strcat(pBuffer, pW);
      }
      strcat(pBuffer, "\n");
      debut+= ordre();
   }

   strcat(pBuffer, "\n");
   return pBuffer;
}

// Remplir une ligne d'une matrice a partir d'un tableau d'entiers
//
void* MatriceF::remplir(int rang, int ligne[]) {
int debut;

   // Controler le rang d'insertion
   //
   if (rang<1 || rang > ordre()) return NULL;

   // Remplir la ligne cible de la matrice
   //
   debut=(rang-1)*ordre();
   for (int i=0;i<ordre();i++) m_pT[debut+i]=Fraction(ligne[i]);

   return (void*)this;
}

// Remplir une matrice avec une constante
//
void* MatriceF::remplir(int constante) {
int cardinal=ordre()*ordre();;

   // Remplir toute la matrice
   //
   for (int i=0;i<ordre()*ordre();i++) m_pT[i]=constante;

   return (void*)this;
}

// Remplir une ligne d'une matrice a partir d'un tableau de fractions
//
void* MatriceF::remplir(int rang, Fraction ligne[]) {
int debut;

   // Controler le rang d'insertion
   //
   if (rang<1 || rang > ordre()) return NULL;

   // Remplir la ligne cible de la matrice
   //
   debut=(rang-1)*ordre();
   for (int i=0;i<ordre();i++) m_pT[debut+i]=ligne[i];

   return (void*)this;
}


