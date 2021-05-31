//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Archives
//
// Classe Object - Methodes enregistrer et restaurer
//                        
// Auteur : A. Thuaire
//
#include "Object.h"

// Enregistrer un objet dans un fichier
//
void Object::enregistrer (const char* pNomFichier) { 
File fichierSupport(pNomFichier, _Archives::modeWrite);
Archive arS(fichierSupport, _Archives::modeStore);

   serialize(arS);
   arS.close();
}

// Restaurer un objet depuis un fichier
//
void Object::restaurer (const char* pNomFichier) { 
File fichierSupport(pNomFichier, _Archives::modeRead);
Archive arL(fichierSupport, _Archives::modeLoad);

   serialize(arL);
   arL.close();
}
