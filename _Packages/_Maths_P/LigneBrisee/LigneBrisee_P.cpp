//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe LigneBrisee - Surcharge de la methode serialize
//
// Auteur : A. Thuaire
//
#include "LigneBrisee.h"

// --- Serialisation des instances 
//
void LigneBrisee::serialize(Archive& ar) {

   if (ar.isStoring()) {

      // Sauvegarder le nombre de sommets
      //
      ar << cardinal();

      // Sauvegarder chacun des sommets
      //
      for (int compteur= 0; m_pSommets[compteur] != NULL; compteur++) 
         m_pSommets[compteur]->serialize(ar);
   }

   else {
      
      // Restaurer le nombre de sommets
      //
      int cardinal;

      ar >> cardinal;

      // Allouer le conteneur de restauration
      //
      m_pSommets= new Point*[cardinal+1];
      if (m_pSommets == NULL) throw -1.0;

      // Marquer la fin du conteneur
      //
      m_pSommets[cardinal]= NULL;

      // Allouer et restaurer chacun des sommets
      //
      Point* pSommet;
      for (int compteur= 0; m_pSommets[compteur] != NULL; compteur++) {
         pSommet= new Point;
         if (pSommet == NULL) throw -1.0;
          
         pSommet->serialize(ar);
         m_pSommets[compteur]= pSommet;
      }
   }
}





