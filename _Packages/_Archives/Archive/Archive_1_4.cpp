//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Archives
//
// Classe Archive - Surcharges de l'operateur >> (2eme partie)
//                        
// Auteur : A. Thuaire
//
#include "Archive.h"

// Archivage d'une chaine de caractere
//
Archive& operator >> (Archive& arL, char*& pChaine) {

   // Controler la validite de l'archive
   //
   if (!arL.isLoading()) throw -3.4;

   // Restaurer la taille de la chaine
   //
   int taille;
   arL.m_fichierSupport.getInStream() >> taille;

   // Allouer l'espace memoire necessaire 
   //
   pChaine= new char[taille+1];
   if (pChaine==NULL) throw -1.0;

   // Transferer le flux sous jacent dans la valeur cible
   //
   char caractere;
   for (int i=0; i<taille; i++) {
      arL.m_fichierSupport.getInStream() >> caractere;
      if (caractere == '#') pChaine[i]= ' ';
      else if (caractere == '@') pChaine[i]= '\t';
	       else pChaine[i]= caractere;
   }

   pChaine[taille]= '\0';

   // Restituer l'archive support
   //
   return arL;
}


