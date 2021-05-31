//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Archives
//
// Classe Archive - Couche logicielle de transit des objets persistants
//
// Edition A    : cours_9
//    + Version 1.0.0   : version initiale
//                        
// Auteur : A. Thuaire
//
#ifndef _File_
#include "..\File\File.h"
#endif

#include <string>

#define _Archive_

class Archive {
private :
File m_fichierSupport;
int m_mode;

public :
Archive() {}
Archive(const File&, int);
Archive(const Archive& ar) {throw -3.1;}

inline bool isStoring() const {return m_mode==STORING;}
inline bool isLoading() const {return m_mode==LOADING;}

friend Archive& operator << (Archive&, char);
friend Archive& operator << (Archive&, int);
friend Archive& operator << (Archive&, long int);
friend Archive& operator << (Archive&, float);
friend Archive& operator << (Archive&, double);
friend Archive& operator << (Archive&, const char*);

friend Archive& operator >> (Archive&, char&);
friend Archive& operator >> (Archive&, int&);
friend Archive& operator >> (Archive&, long int&);
friend Archive& operator >> (Archive&, float&);
friend Archive& operator >> (Archive&, double&);
friend Archive& operator >> (Archive&, char*&);

void close();

};




