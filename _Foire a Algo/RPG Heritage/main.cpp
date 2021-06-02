#include <iostream>
#include <string>
#include "Personnage.h" // Ne pas oublier
#include "Guerrier.h"
#include "Magicien.h"

using namespace std;

int main()
{
	Personnage monPersonnage;
	Guerrier monGuerrier;
	Magicien merlin;
 
	monPersonnage.coupDePoing(monGuerrier);
	monGuerrier.coupDePoing(monPersonnage);
	merlin.bouleDeGlace(monGuerrier);
}