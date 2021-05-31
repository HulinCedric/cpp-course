//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe LigneBrisee - Constructeurs, destructeur et methode toString
//
// Auteur : A. Thuaire
//
#include "LigneBrisee.h"

// --- Constructeur par defaut
//
LigneBrisee::LigneBrisee() {

   // Allouer un tableau vide, bornee par NULL
   //
   m_pSommets= new Point*[11];
   if (m_pSommets==NULL) throw -1.0;

   // Placer le marqueur de fin
   //
   m_pSommets[0]= NULL;
}

// --- Constructeur de copie
//
LigneBrisee::LigneBrisee(const LigneBrisee& L) {

   // Allouer le tableau des points successifs
   //
   for(int taille= 0; L.m_pSommets[taille] != NULL; taille++);

   m_pSommets= new Point*[taille+1];
   if (m_pSommets==NULL) throw -1.0;

   // Remplir le tableau des sommets
   // 
   for (int j= 0; j< taille; j++) m_pSommets[j]= new Point(*L.m_pSommets[j]);

   // Placer la marque de fin
   //
   m_pSommets[taille]= NULL;
}

// --- Surcharge du destructeur
//
LigneBrisee::~LigneBrisee() {

   // Detruire chacun des points de la ligne brisee
   // 
   for(int taille= 0; m_pSommets[taille] != NULL; taille++);

   for (int j= 0; j< taille; j++) delete m_pSommets[j];

   // Detruire le tableau des points
   //
   delete[] m_pSommets;
}

// --- Methode toString pour les tests unitaires
//
char* LigneBrisee:: toString() {
	
   // Allouer le buffer résultant
   //
   for(int taille= 0; m_pSommets[taille] != NULL; taille++);

   char* pBuffer = new char[taille*22];
   if(pBuffer == NULL) throw -1.0;

   // Initialiser le buffer résultant avec le caractere de debut
   //
   strcpy(pBuffer, "[");

   for(int i=0; i<taille; i++) {

      // Enregistrer chaque point dans le buffer
      //
      strcat(pBuffer, m_pSommets[i]->toString());

      // Enregistrer le caractere de separation entre chaque point
      // (excepte pour le dernier point)
      //
      if(i<taille-1) strcat(pBuffer, " - ");
   }

   // Enregistrer le caractere de fin
   //
   strcat(pBuffer, "]");

   // Restituer le buffer resultant
   //
   return pBuffer;
}




   




