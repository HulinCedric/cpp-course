/*
Magicien.h
*/
 
#ifndef DEF_MAGICIEN
#define DEF_MAGICIEN
 
#include <iostream>
#include <string>
#include "Personnage.h"
 
class Magicien : public Personnage
{
    public:
		Magicien();
		Magicien(std::string);
        void bouleDeFeu(Personnage&);
        void bouleDeGlace(Personnage&);
 
    private:
        int m_mana;
};
 
#endif