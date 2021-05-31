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
	int compteur=0, j=0, i=0;
	
	// Pour tous les points dans la LigneMere nous verifions
	// l'égalité avec le premier point de la Ligne MereFille
	//
	for ( i=1; i<cardinal()+1; i++)
	{
		if (*m_pSommets[i-1] == *L.premierSommet())
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
					if (*m_pSommets[((i-1)+j)-1] == *L.m_pSommets[j-1])	compteur++;
				}
			}
			if (compteur == L.cardinal())	return true;
			else compteur=0;
		
			// Si un point de la LigneMere est egal a un point de
			// la Ligne Fille, nous allons parcourir la LigneFille afin
			// de verifier l'appartenance de tous ses points avec
			// la LigneMere dans un ordre decroissant
			//
			for (j=1; j<L.cardinal()+1; j++)
			{
				if ( (i+1)-j >= 1 && (i+1)-j <= cardinal())
				{
					if (*m_pSommets[((i+1)-j)-1] == *L.m_pSommets[j-1])	compteur++;
				}
			}
			if (compteur == L.cardinal())	return true;
			else compteur=0;
		
		}
	}
	
	// Nous retournons le Resultat
	//
	return false;
}
