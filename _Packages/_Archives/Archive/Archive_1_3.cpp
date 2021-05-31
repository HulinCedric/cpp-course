//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Archives
//
// Classe Archive - Surcharges de l'operateur << (deuxieme partie)
//                        
// Auteur : A. Thuaire
//
#include "Archive.h"

Archive& operator << (Archive& arS, const char* pChaine) {

   // Controler la validite de l'archive
   //
   if (!arS.isStoring()) throw -3.3;

   // Calculer et archiver la taille de la chaine
   //
   int taille= strlen(pChaine);
   arS.m_fichierSupport.getOutStream() << taille << '\n';

   // Transferer la chaine de caracteres dans le flux sous jacent
   //
   for (int i=0;i< taille; i++)
	  if (pChaine[i] == ' ') arS.m_fichierSupport.getOutStream() << '#';
	  else if (pChaine[i] == '\t') arS.m_fichierSupport.getOutStream() << '@'; 
	       else arS.m_fichierSupport.getOutStream() << pChaine[i];

   arS.m_fichierSupport.getOutStream() << '\n';

   // Restituer l'archive support
   //
   return arS;
}