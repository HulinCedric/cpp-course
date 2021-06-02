#include <iostream>
#include <string>
#include "Personnage.h" // Ne pas oublier

using namespace std;


int main()
{
    Personnage david("Nina"), goliath("Cédric", "Hache d'odin", 10);// Création de 2 objets de type Personnage : david et goliath
	
	david.afficherEtat();
	goliath.afficherEtat();
    goliath.attaquer(david); // goliath attaque david
    david.boirePotionDeVie(20); // david boit une potion de vie qui lui rapporte 20 de vie
    goliath.attaquer(david); // goliath réattaque david
    david.attaquer(goliath); // david contre-attaque... c'est assez clair non ? ^^
    goliath.changerArme("Double hache tranchante vénéneuse de la mort", 20);
    goliath.attaquer(david);
	david.afficherEtat();
	goliath.afficherEtat();
	david.changerArme("Monstre d'Olympe", 50);
	david.attaquer(goliath);
	david.afficherEtat();
	goliath.afficherEtat();

    return 0;
}