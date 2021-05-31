//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Archives
//
// Classe Object - Abstraction des objets persistants, toutes
//                 classes confondues
//
// Edition A    : specifications initiales de la persistance
//    + Version 1.0.0   : version initiale
//                        
// Auteur : A. Thuaire
//
#ifndef __Archives_
#include "..\_Archives\_Archives.h"
#endif

#ifndef _File_
#include "..\File\File.h"
#endif

#ifndef _Archive_
#include "..\Archive\Archive.h"
#endif

#define _Object_

class Object {
public :

void enregistrer(const char*);
void restaurer(const char*);

virtual void serialize(Archive&)=0;

};




