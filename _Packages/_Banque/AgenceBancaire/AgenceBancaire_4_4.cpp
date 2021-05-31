//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe AgenceBancaire - Service nombreOperations
//
// Auteur : A. Thuaire
//
#include "AgenceBancaire.h"

int	AgenceBancaire::nombreOperations(char* pDate)						
{	
	// Controler la validite de l'objet support
	//
	if (nok()) throw -2.0;
	
	// Controle validite du parametre
	//
	if (pDate == NULL)	throw -2.1;
	
	// Declarer la variable resultat
	//
	int resultat = 0;
		
	// Obtenir le nombre d'operations pour les comptes courants
	//
	map <long int, CompteCourant*>::iterator i= m_comptesCourant.begin();
	while (i != m_comptesCourant.end())
	{
			resultat += ((CompteBancaire*)i->second)->nombreOperations(pDate);
			i++;
	}
		
	// Obtenir le nombre d'operations pour les comptes epargnes
	//
	map <long int, CompteEpargne*>::iterator j= m_comptesEpargne.begin();
	while (j != m_comptesEpargne.end())
	{
		resultat += ((CompteBancaire*)j->second)->nombreOperations(pDate);
		j++;
	}
	
	// Obtenir le nombre d'operations pour les comptes fermÈs
	//
	map <long int, CompteBancaire*>::iterator k= m_comptesFermes.begin();
	while (k != m_comptesFermes.end())
	{
		resultat += k->second->nombreOperations(pDate);
		k++;
	}
	
	// Restituer le resultat
	//
	return resultat;
}
