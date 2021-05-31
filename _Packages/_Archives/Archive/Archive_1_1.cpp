//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Archives
//
// Classe Archive - Surcharges de l'operateur <<
//                        
// Auteur : A. Thuaire
//
#include "Archive.h"

// Surcharge de l'operateur <<
//
Archive& operator << (Archive& arS, char valeur) {

   // Controler la validite de l'archive
   //
   if (!arS.isStoring()) throw -3.3;

   // Transferer la valeur du second parametre dans le flux sous jacent
   //
   arS.m_fichierSupport.getOutStream() << valeur << '\t';

   // Restituer l'archive support
   //
   return arS;
}


Archive& operator << (Archive& arS, int valeur) {

   // Controler la validite de l'archive
   //
   if (!arS.isStoring()) throw -3.3;

   // Transferer la valeur du second parametre dans le flux sous jacent
   //
   arS.m_fichierSupport.getOutStream() << valeur << '\t';

   // Restituer l'archive support
   //
   return arS;
}

Archive& operator << (Archive& arS, long int valeur) {

   // Controler la validite de l'archive
   //
   if (!arS.isStoring()) throw -3.3;

   // Transferer la valeur du second parametre dans le flux sous jacent
   //
   arS.m_fichierSupport.getOutStream() << valeur << '\t';

   // Restituer l'archive support
   //
   return arS;
}

Archive& operator << (Archive& arS, float valeur) {

   // Controler la validite de l'archive
   //
   if (!arS.isStoring()) throw -3.3;

   // Transferer la valeur du second parametre dans le flux sous jacent
   //
   arS.m_fichierSupport.getOutStream() << valeur << '\t';

   // Restituer l'archive support
   //
   return arS;
}

Archive& operator << (Archive& arS, double valeur) {

   // Controler la validite de l'archive
   //
   if (!arS.isStoring()) throw -3.3;

   // Transferer la valeur du second parametre dans le flux sous jacent
   //
   arS.m_fichierSupport.getOutStream() << valeur << '\t';

   // Restituer l'archive support
   //
   return arS;
}