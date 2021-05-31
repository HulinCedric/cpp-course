//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe LigneBrisee - Methode inclus
//
// Auteur : C. Hulin
//
#include "LigneBrisee.h"


bool LigneBrisee::inclus (const LigneBrisee& L) const
{
	// Initialisation des attributs
	//
	LigneBrisee LigneFille= L;
	LigneBrisee LigneMere= *this;
	int cpt=0, j, i;
	
	// Pour tous les points dans la LigneMere nous verifions
	// l'égalité avec le premier point de la Ligne MereFille
	//
	for (i=1; i<cardinal()+1; i++)
	{
		if (*LigneMere[i] == *LigneFille.premierSommet())
		{
			
			// Si un point de la LigneMere est egal a un point de
			// la Ligne Fille, nous allons parcourir la LigneFille afin
			// de verifier l'appartenance de tous ses points avec
			// la LigneMere dans un ordre croissant
			//
			for ( j=1; j<L.cardinal()+1; j++)
			{
				if ( (i-1)+j >= 1 && (i-1)+j <= cardinal())
				{
					if (*LigneMere[(i-1)+j] == *LigneFille[j])	cpt++;
				}
			}
			if (cpt == L.cardinal())	return true;
			else cpt=0;
		
			// Si un point de la LigneMere est egal a un point de
			// la Ligne Fille, nous allons parcourir la LigneFille afin
			// de verifier l'appartenance de tous ses points avec
			// la LigneMere dans un ordre decroissant
			//
			for ( j=1; j<L.cardinal()+1; j++)
			{
				if ( (i+1)-j >= 1 && (i+1)-j <= cardinal())
				{
					if (*LigneMere[(i+1)-j] == *LigneFille[j])	cpt++;
				}
			}
			if (cpt == L.cardinal())	return true;
			else cpt=0;
		
		}
	}
	
	// Nous retournons le Resultat
	//
	return false;
}
