//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Archives
//
// Classe _Archives - Methode init
//
// Auteur : A. Thuaire
//
#include "_Archives.h"

// Allocation memoire (Data segment) de tous les attributs de classe
//
int _Archives::modeWrite; // Fichier en mode ecriture
int _Archives::modeRead;  // Fichier en mode lecture
int _Archives::modeLoad;  // Archive en mode chargement
int _Archives::modeStore; // Archive en mode enregistrement

// Initialiser les attributs de classe
//
void _Archives::init()
{
   _Archives::modeWrite = 1;
   _Archives::modeRead = -1;
   _Archives::modeStore = 1;
   _Archives::modeLoad = -1;
}
