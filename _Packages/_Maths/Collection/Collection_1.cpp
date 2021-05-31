//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Collection - Constructeur, destructeur et methode toString
//    
// Auteur : A. Thuaire
//
#include "Collection.h"

// --- Surcharge du constructeur par defaut
//
Collection::Collection() {
	
   m_pElements= new void*[11]; 
   if (m_pElements==NULL) throw -1.0;
 
   m_pElements[0]= NULL;
}

// --- Surcharge du constructeur de copie
//
Collection::Collection(const Collection& C) {

   // Controler la validite du parametre
   //
   if (!C.neutre()) throw -2.1;

   // Allouer un conteneur initial
   // 	
   m_pElements= new void*[11]; 
   if (m_pElements==NULL) throw -1.0;
 
   m_pElements[0]= NULL;
}

// --- Surcharge du destructeur
//
Collection::~Collection() {

   // Detruire le conteneur, sans toucher aux elements pointes !!
   //
   //delete[] m_pElements;
}

// --- Methode toString pour les tests unitaires
//
char* Collection::toString(fToString* pF) {

   // Calculer la taille totale du buffer resultant
   //
   int taille=0, cardinal= 0;
   char* pChaine;

   for (int i= 0; m_pElements[i] != NULL; i++) {
      pChaine= (*pF)(m_pElements[i]);
      if (pChaine==NULL) throw -1.0;
      taille+= strlen(pChaine);
      delete[] pChaine;
      cardinal++;
   }    

   // Allouer le buffer résultant
   //
   char* pBuffer = new char[taille+3];
   if(pBuffer == NULL) throw -1.0;

   // Initialiser le buffer resultant
   //
   strcpy(pBuffer, "{");

   // Remplir le buffer resultant
   //
   for(int j=0; m_pElements[j] != NULL; j++) {

      // Enregistrer l'element courant dans le buffer
      //
      strcat(pBuffer, (*pF)(m_pElements[j]));

      // Enregistrer le caractere de separation de chaque element
      // (excepte pour le dernier)
      //
      if(j<cardinal-1) strcat(pBuffer, ", ");
   }

   // Finaliser le buffer resultant
   //
   strcat(pBuffer, "}");

   // Restituer le buffer resultant
   //
   return pBuffer;
}




