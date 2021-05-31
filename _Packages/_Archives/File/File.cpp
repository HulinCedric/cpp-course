//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Archives
//
// Classe File - Constructeur et methode close
//                        
// Auteur : A. Thuaire
//
#include "File.h"

// Constructeur normal
//
File::File(const char* pNomFichier, int modeEchange) {

   // Controler la validite du premier parametre
   //
   if (pNomFichier==NULL) throw -2.1;

   // Controler la validite du second parametre
   //
   if (modeEchange != READING && modeEchange != WRITING) throw -2.2;

   // Valuer l'attribut relatif au mode d'echange
   //
   m_mode= modeEchange;

   // Ouvrir le flux sous jacent
   //
   if (m_mode==READING) m_ifs.open(pNomFichier);
   else m_ofs.open(pNomFichier); 
}

// Fermeture logique du fichier cible et du flux sous-jacent
//
void File::close () { 

   if (m_mode==0) return;
   if (m_mode==READING) m_ifs.close();
   else m_ofs.close();
   m_mode= 0; 
}
