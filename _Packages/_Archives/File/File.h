//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Archives
//
// Classe File - Abstraction des fichiers physiques, independante
//               du systeme d'exploitation support
//
// Edition A    : specifications initiales de la persistance
//    + Version 1.0.0   : version initiale
//                        
// Auteur : A. Thuaire
//
#ifndef __Archives_
#include "..\_Archives\_Archives.h"
#endif

#define _File_

class File {
private :
ofstream m_ofs;
ifstream m_ifs;
int m_mode;

public :
File() {m_mode= 0;}
File(const char*, int);
File(const File& f) {throw -3.1;}

inline ofstream getOutStream() {return m_ofs;}
inline ifstream getInStream () {return m_ifs;}

inline bool isClosed()  {return m_mode==0;}
inline bool isReading() {return m_mode==READING;}
inline bool isWriting() {return m_mode==WRITING;}

void close();

};




