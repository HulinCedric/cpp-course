//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Collection - Surcharge de l'operateur +=
//    
// Auteur : A. Thuaire
//
#include "Collection.h"

// --- Surcharge de l'operateur +=
//
Collection& Collection::operator +=(void* const pElement) {
int quantum= 10;

   // Controler la validite de l'objet support
   //
   if (m_pElements==NULL) throw -2.0;

   // Controler la validite du parametre
   //
   if (pElement==NULL) throw -2.1;

   // Controler la taille courante du conteneur
   //
   int nbElements= cardinal();
   if (nbElements == 0 || nbElements%quantum != 0) {

      // Ajouter le nouvel element dans le conteneur
      //
      m_pElements[nbElements]  = pElement;
      m_pElements[++nbElements]= NULL;
      return *this;
   }

   // Allouer un nouveau conteneur plus grand 
   //
   void** pNew= new void*[nbElements+quantum+1];
   if (pNew==NULL) throw -1.0;

   // Recopier le contenu du conteneur precedent
   //
   for (int i=0; m_pElements[i] != NULL; i++) 
      pNew[i]= m_pElements[i];

   // Liberer le conteneur precedent
   //
   delete[] m_pElements;

   // Ajouter le nouvel element dans le nouveau conteneur
   //
   pNew[nbElements]  = pElement;
   pNew[++nbElements]= NULL;

   // Substituer le nouveau conteneur a l'ancien
   //
   m_pElements= pNew;
 
   // Restituer le resultat
   //
   return *this;
}

