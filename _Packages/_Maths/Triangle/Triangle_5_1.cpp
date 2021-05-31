/*
 *  Triangle_5_1.cpp
 *  Triangle
 *
 *  Created by TrAsHeUr on 08/04/09.
 *  Copyright 2009 Domicile. All rights reserved.
 *
 */
#include "Triangle.h"

bool Triangle::equilateral()
{	
	if(fabs(arete(1)->longueur() -  arete(2)->longueur()) < EPSILON)
	{
		return (fabs(arete(1)->longueur() - arete(3)->longueur()) < EPSILON);
	}
	return false;
}

bool Triangle::isocele ()
{
	if(fabs(arete(1)->longueur() -  arete(2)->longueur()) < EPSILON)	return true;
	if(fabs(arete(2)->longueur() -  arete(3)->longueur()) < EPSILON)	return true;
	if(fabs(arete(3)->longueur() -  arete(1)->longueur()) < EPSILON)	return true;
	
	return false;
}

bool Triangle::rectangle ()
{
	if (*angle(*sommet(1)) == PI/2)	return true;
	if (*angle(*sommet(2)) == PI/2)	return true;
	if (*angle(*sommet(3)) == PI/2)	return true;
		
	return false;
}

