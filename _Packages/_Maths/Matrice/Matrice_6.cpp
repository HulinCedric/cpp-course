//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2007_2008 - Package _Maths
//
// Classe Matrice - Surcharge de l'operateur ==
//
// Auteur : A. Thuaire
//
#include "Matrice.h"

// Comparer deux matrices entre elles
//
bool Matrice::operator == (const Matrice& op2) {

   // Controler l'ordre des deux operandes
   //
   if (ordre() != op2.ordre()) false;

   // Comparer les elements de meme rang, deux a deux
   //
   int cardinal= ordre()*ordre(); 
   for (int i=0; i<cardinal; i++) if (m_pT[i] != op2.m_pT[i]) return false;

   return true;
}

// Comparer un scalaire et une matrice
//
bool Matrice::operator == (int op2) {

   // Comparer le scalaire avec chaque element de l'objet support
   //
   int cardinal= ordre()*ordre(); 
   for (int i=0; i<cardinal; i++) if (m_pT[i] != op2) return false;

   return true;
}

// Surcharges de l'operateur !=
//
bool Matrice::operator != (const Matrice& op2) {return !(*this==op2);}
bool Matrice::operator != (int op2) {return !(*this==op2);}







