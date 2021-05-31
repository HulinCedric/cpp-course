//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Triangle - Methode Médiatrice
//
// Auteur : C.Fouco
//
#include "Triangle.h"

Segment* Triangle::mediatrice (int rang) const
{
	// Controler la validite du parametre
	//
	if (rang < 1 || rang > 3) throw -2.1;
	
	Segment* pResultat = NULL;

	for(int i=1; i <= 3; i++)
	{
			
		if(i == rang) 
		{
			pResultat = arete(i);
		
			Point* P = new Point(*pResultat->milieu());

			return pResultat->rotation(*P,PI/2);
		}

	}
	return pResultat;

}

Segment* Triangle::mediane(int rang) const
{
	// Controler la validite du parametre
	//
	if (rang < 1 || rang > 3) throw -2.1;

	Segment* pResultat;
	

	for(int i=1; i <= 3; i++)
	{
			
		if(i == rang) 
		{
			if(i+1 > 3) pResultat = arete(1);
			else pResultat = arete(i+1);

			Point* P = new Point(*pResultat->milieu());

			pResultat = new Segment(*sommet(rang),*P);
		}

	}
	

	return pResultat;
}

Segment* Triangle::hauteur (int rang) const
{
	Triangle Support= *this;
	
	// Controler la validite du parametre
	//
	if (rang < 1 || rang > 3) throw -2.1;

	// Cas particulier du triangle rectangle
	//
	if (Support.rectangle())
	{
		if (*angle(*Support.sommet(rang)) != PI/2)	throw -2.1;
	}
	
	Segment *pP;
	
	if (rang == 1) pP=  Support.arete(2);
	if (rang == 2) pP=  Support.arete(3);
	if (rang == 3) pP=  Support.arete(1);
	
	Segment *pResultat= new Segment(*Support.sommet(rang), *pP->projection(*Support.sommet(rang)));
	if (pResultat == NULL)	throw -1.0;
	
	return pResultat;
}	

	



