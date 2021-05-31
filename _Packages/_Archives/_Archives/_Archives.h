//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Archives
//
// Classe _Archives - Classe abstraite du package
//
// Edition A    : cours_9
//    + Version 1.0.0   : version initiale
//
// Auteur : A. Thuaire
//
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <fstream.h>
#include <iostream.h>

#define __Archives_

#define WRITING 1
#define STORING 1
#define READING -1
#define LOADING -1

class _Archives
{
    friend class Object;

private:
    static int modeWrite;
    static int modeRead;
    static int modeStore;
    static int modeLoad;

public:
    static void init();
    static int getModeRead() { return modeRead; }
    static int getModeWrite() { return modeWrite; }
    static int getModeLoad() { return modeLoad; }
    static int getModeStore() { return modeStore; }

    virtual void muette() = 0;
};
