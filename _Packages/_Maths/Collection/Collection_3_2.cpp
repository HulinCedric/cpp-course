//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Collection - Surcharge de l'operateur -=
//    
// Auteur : A. Thuaire
//
#include "Collection.h"

// --- Surcharge de l'operateur -=
//
Collection& Collection::operator -=(void* const pElement) {
int quantum= 10;

   // Controler la validite de l'objet support
   //
   if (m_pElements==NULL) throw -2.0;

   // Controler la validite du parametre
   //
   if (pElement==NULL) throw -2.1;

   // Traiter le cas particulier de l'ensemble vide
   //
   if (m_pElements[0] == NULL) throw -3.0;

   // Traiter le cas particulier d'un singleton
   //
   if (m_pElements[1] == NULL) {
      if (m_pElements[0] != pElement) throw -3.0;
      else {m_pElements[0]= NULL; return *this;}
   }

   // Parcourir la collection a la recherche de la cible
   //
   int rangCible;
   for (rangCible=0; m_pElements[rangCible] != NULL; rangCible++) {

      // Comparer la cible a l'element courant
      //
      if (m_pElements[rangCible] != pElement) continue;

      // Retirer la cible en decalant le contenu du conteneur
      // depuis le rang de cette derniere jusqu'a la marque de fin
      //
      for (int i= rangCible; m_pElements[i+1] != NULL; i++)
         m_pElements[i]= m_pElements[i+1];

      // Placer la nouvelle marque de fin
      //
      m_pElements[i]= NULL;

      // Calculer le cardinal courant de la collection
      //
      int nbElements= cardinal();

      // Controler le cardinal par rapport au quantum 
      // d'allocation dans le conteneur de la collection   
      //
      if (nbElements != 0 && nbElements%quantum != 0) return *this; 

      // Allouer un nouveau conteneur de taille inferieure 
      //
      void** pNew= new void*[nbElements+1];
      if (pNew == NULL) throw -1.0;

      // Recopier le contenu de l'ancien conteneur dans le nouveau 
      //
      for (int k=0; m_pElements[k] != NULL; k++) 
         pNew[k]= m_pElements[k];

      // Mettre en place la marque de fin du nouveau conteneur
      //
      pNew[k]= NULL;

      // Detruire l'ancien conteneur
      //
      delete[] m_pElements;

      // Mettre en place le nouveau conteneur
      //
      m_pElements= pNew;

      // Restituer le resultat
      //
      return *this;
   }

   // Traiter le cas ou l'element a retirer est absent
   //
   throw -3.0; 
}


