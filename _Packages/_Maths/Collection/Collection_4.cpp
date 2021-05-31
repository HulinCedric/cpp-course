//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Collection - Methodes vider, cardinal et designe
//    
// Auteur : A. Thuaire
//
#include "Collection.h"

// --- Destruction de tous les elements du conteneur
//
void Collection::vider() const {

   // Controler la validite de l'objet support
   //
   if (m_pElements==NULL) throw -2.0;

   // Traiter le cas particulier d'une collection vide
   //
   if (neutre()) return;
 
   // Parcourir tout le conteneur
   //
   for (int i=0; m_pElements[i] != NULL; i++) delete m_pElements[i];

   m_pElements[0]= NULL;
}  

// --- Calcul du nombre d'elements d'une collection
//
int Collection::cardinal() const {
	
   // Controler la validite de l'objet support
   //
   if (m_pElements==NULL) throw -2.0;

   // Parcourir tout le conteneur
   //
   int cardinal;
   for (cardinal=0; m_pElements[cardinal] != NULL; cardinal++);

   return cardinal;  
}

// --- Controler la presence d'un pointeur dans le conteneur
//
bool Collection::designe(void* const pElement) const {

   // Controler la validite de l'objet support
   //
   if (m_pElements==NULL) throw -2.0;

   // Traiter le cas particulier d'une collection vide
   //
   if (neutre()) return false;

   // Parcourir tout le conteneur et restituer le resultat
   //
   for (int i=0; m_pElements[i] != NULL; i++)
      if (m_pElements[i] == pElement) return true;
  
   return false;
} 


