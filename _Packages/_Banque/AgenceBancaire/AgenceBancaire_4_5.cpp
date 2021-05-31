//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe AgenceBancaire - Service nombreClients deuxieme forme
//
// Auteur : A. Thuaire
//
#include "AgenceBancaire.h"

int AgenceBancaire::nombreClients(char type)
{	
	// Controler la validite de l'objet support
	//
	if (nok()) throw -2.0;
	
	// Controler la validite du parametre
	//
	if(type != 'E' && type != 'C')	throw -2.1;
	
	// Parcourir le dictionnaire des clients et comptabiliser tous les
	// client ayant un comptes de type cible pour l'ensemble des clients 
	//
	int resultat= 0;
	string cle;
	
	map <string, list <CompteBancaire*> >::iterator i= m_clients.begin();
	while (i != m_clients.end())
	{
		// Obtenir la cle courante
		//
		cle= i->first;
		
		// Comptabiliser les clients ayant un compte de type cible
		//
		if(nombreComptes(cle,type)>0)	resultat++;
		
		// Passer au compte suivant
		//
		i++;
	}
	// Restituer le resultat
	//
	return resultat;
}