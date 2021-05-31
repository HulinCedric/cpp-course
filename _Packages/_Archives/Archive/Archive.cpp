//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Archives
//
// Classe Archive - Constructeur et methode close
//                        
// Auteur : A. Thuaire
//
#include "Archive.h"

// Constructeur normal
//
Archive::Archive(const File& fichierSupport, int modeEchange) {

   // Controler la validite du second parametre
   //
   if (modeEchange != LOADING && modeEchange != STORING) throw -2.2;

   // Valuer les deux attributs
   //
   m_fichierSupport= fichierSupport;
   m_mode= modeEchange;

}

// Fermeture logique de l'archive cible et du fichier logique sous-jacent
//
void Archive::close() { 

   m_fichierSupport.close();
   m_mode= 0;
}
