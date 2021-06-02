/*
Personnage.h
*/
 
#ifndef DEF_PERSONNAGE // Pour éviter les inclusions multiples
#define DEF_PERSONNAGE // (revoir au besoin cours C, partie II, ch. 5)
 
#include <iostream>
#include <string>
 
class Personnage
{
    public:
        Personnage();
		Personnage(std::string);
        void recevoirDegats(int);
        void coupDePoing(Personnage&);
 
    private:
        int m_vie;
        std::string m_nom;
};
 
#endif