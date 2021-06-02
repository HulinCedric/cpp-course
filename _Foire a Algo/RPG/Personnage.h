#ifndef DEF_PERSONNAGE
#define DEF_PERSONNAGE

#include "Arme.h"

class Personnage
{
    public:
	
	Personnage();
	Personnage(std::string nomArme, int degatsArme);
	Personnage(int vie, int mana, std::string nomArme, int degatsArme);
	Personnage(std::string nomPerso, std::string nomArme, int degatsArme);
	Personnage(std::string nomPerso);
	Personnage(std::string nomPerso, int vie, int mana, std::string nomArme, int degatsArme);
	~Personnage();
    void recevoirDegats(int nbDegats);
    void attaquer(Personnage &cible);
    void boirePotionDeVie(int quantitePotion);
    void changerArme(std::string nomNouvelleArme, int degatsNouvelleArme);
    bool estVivant();
	void afficherEtat();

    private:

	std::string  m_nomPerso;
    int m_vie;
    int m_mana;
	Arme m_arme;
};

#endif