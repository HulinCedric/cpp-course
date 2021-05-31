//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Archives
//
// Classe Archive - Surcharges de l'operateur >> (premiere partie)
//                        
// Auteur : A. Thuaire
//
#include "Archive.h"

// Archivage d'un caractere
//
Archive& operator >> (Archive& arL, char& valeur) {

   // Controler la validite de l'archive
   //
   if (!arL.isLoading()) throw -3.4;

   // Transferer le flux sous jacent dans la valeur cible
   //
   arL.m_fichierSupport.getInStream() >> valeur;

   // Restituer l'archive support
   //
   return arL;
}

// Archivage d'un entier
//
Archive& operator >> (Archive& arL, int& valeur) {

   // Controler la validite de l'archive
   //
   if (!arL.isLoading()) throw -3.4;

   // Transferer le flux sous jacent dans la valeur cible
   //
   arL.m_fichierSupport.getInStream() >> valeur;

   // Restituer l'archive support
   //
   return arL;
}

// Archivage d'un entier long
//
Archive& operator >> (Archive& arL, long int& valeur) {

   // Controler la validite de l'archive
   //
   if (!arL.isLoading()) throw -3.4;

   // Transferer le flux sous jacent dans la valeur cible
   //
   arL.m_fichierSupport.getInStream() >> valeur;

   // Restituer l'archive support
   //
   return arL;
}

// Archivage d'un nombre reel flottant
//
Archive& operator >> (Archive& arL, float& valeur) {

   // Controler la validite de l'archive
   //
   if (!arL.isLoading()) throw -3.4;

   // Transferer le flux sous jacent dans la valeur cible
   //
   arL.m_fichierSupport.getInStream() >> valeur;

   // Restituer l'archive support
   //
   return arL;
}

// Archivage d'un nombre reel double
//
Archive& operator >> (Archive& arL, double& valeur) {

   // Controler la validite de l'archive
   //
   if (!arL.isLoading()) throw -3.4;

   // Transferer le flux sous jacent dans la valeur cible
   //
   arL.m_fichierSupport.getInStream() >> valeur;

   // Restituer l'archive support
   //
   return arL;
}



