#include <iostream>
#include "Duree.h"

using namespace std;

Duree::Duree(int heures, int minutes, int secondes) : m_heures(heures), m_minutes(minutes), m_secondes(secondes)
{
}

Duree Duree::operator+(const Duree &duree)
{
    int heures = m_heures;
    int minutes = m_minutes;
    int secondes = m_secondes;

    // 1 : ajout des secondes
    secondes += duree.m_secondes; // Exceptionnellement autorisÈ car mÍme classe
    // Si le nombre de secondes dÈpasse 60, on rajoute des minutes et on met un nombre de secondes infÈrieur ‡ 60
    minutes += secondes / 60;
    secondes %= 60;

    // 2 : ajout des minutes
    minutes += duree.m_minutes;
    // Si le nombre de minutes dÈpasse 60, on rajoute des heures et on met un nombre de minutes infÈrieur ‡ 60
    heures += minutes / 60;
    minutes %= 60;

    // 3 : ajout des heures
    heures += duree.m_heures;

    // CrÈation de l'objet resultat et retour
    Duree resultat(heures, minutes, secondes);
    return resultat;
}

bool Duree::operator==(const Duree &duree)
{
    if (m_heures == duree.m_heures && m_minutes == duree.m_minutes && m_secondes == duree.m_secondes)
        return true;
    else
        return false;
}

bool Duree::operator<(const Duree &duree)
{
    if (m_heures < duree.m_heures)
        return true;
    else if (m_heures == duree.m_heures && m_minutes < duree.m_minutes)
        return true;
    else if (m_heures == duree.m_heures && m_minutes == duree.m_minutes && m_secondes < duree.m_secondes)
        return true;
    else
        return false;
}

Duree Duree::operator=(const Duree &duree)
{
    m_heures = duree.m_heures;
    m_minutes = duree.m_minutes;
    m_secondes = duree.m_secondes;
	
	return *this;
}

void Duree::afficher(ostream &out)
{
    out << m_heures << "h" << m_minutes << "m" << m_secondes << "s";
}



