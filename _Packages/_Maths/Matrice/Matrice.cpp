//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2007_2008 - Package _Maths
//
// Classe Matrice - Constructeurs, destructeur et 
//                  methodes toString et remplir
//
// Auteur : A. Thuaire
//
#include "Matrice.h"

// Constructeur par defaut
//
Matrice::Matrice () {

   // Fixer le rang de la matrice
   //
   m_ordre= 1;

   // Allouer le tableau interne
   //
   m_pT= new int [1];
   if (m_pT==NULL) throw -1.0;

   // Initialiser l'element a zero
   //
   m_pT[0]= 0;
}

// Constructeur normal
//
Matrice::Matrice (int ordre) {

   // Traiter le cas d'un rang invalide
   //
   if (ordre < 1) throw -2.1;

   // Fixer le rang de la matrice
   //
   m_ordre= ordre;

   // Allouer le tableau interne
   //
   int cardinal= ordre*ordre;
   m_pT= new int [ordre*ordre];
   if (m_pT==NULL) throw -1.0;

   // Initialiser tous les elements a zero
   //
   for (int i=0;i<cardinal;i++) m_pT[i]= 0;
}

// Surcharge du constructeur de copie
//
Matrice::Matrice (const Matrice& source) {

   // Fixer le rang de la copie
   //
   m_ordre= source.ordre();

   // Allouer le tableau interne
   //
   int cardinal= ordre()*ordre();
   m_pT= new int[cardinal];
   if (m_pT==NULL) throw -1.0;

   // Copier tous les elements de la source
   //
   for (int i=0;i<cardinal;i++) m_pT[i]= source.m_pT[i];
}

// Surcharge du destructeur
//
Matrice::~Matrice() {

   // Liberer le tableau interne
   //
   delete[] m_pT;
}

// Transcoder en chaine de caracteres une matrice
//
char* Matrice::toString() {
int debut=0;
char* pBuffer;
char* pW;

   // Allouer le buffer global resultant
   //
   pBuffer= new char[5*ordre()*ordre()];
   if (pBuffer==NULL) return NULL;

   // Allouer un buffer intermediaire pour le transcodage de chaque element
   //
   pW= new char[4];
   if (pW==NULL) {delete[] pBuffer; return NULL;}

   sprintf(pBuffer, "\n");
   for (int i=0;i<ordre();i++) {
      for (int j=0;j<ordre();j++) {
         sprintf(pW, "%3d\t", m_pT[debut+j]);
         strcat(pBuffer, pW);
      }
      strcat(pBuffer, "\n");
      debut+= ordre();
   }

   strcat(pBuffer, "\n");
   return pBuffer;
}

// Remplir une ligne d'une matrice a partir d'un tableau
//
void* Matrice::remplir(int rang, int ligne[]) {
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

// Remplir une matrice avec une constante
//
void* Matrice::remplir(int constante) {
int cardinal=ordre()*ordre();;

   // Remplir toute la matrice
   //
   for (int i=0;i<ordre()*ordre();i++) m_pT[i]=constante;

   return (void*)this;
}




