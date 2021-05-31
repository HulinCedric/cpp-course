#ifndef _Banque_
#include "Banque.h"
#endif

float Banque::totalDepots()
{
float resultat=0.f;
	
	if(nok())	throw -2.0;
	
	map	 <string, map <int, AgenceBancaire*> >::iterator i= m_regions.begin();
	map <int, AgenceBancaire*> temp;
	map <int, AgenceBancaire*>::iterator j;
	
	while (i != m_regions.end())
	{
		temp=i->second;
		j=temp.begin();
		while(j != temp.end())
		{
			//
			//resultat+=j->second->totalDepots();			//Probleme de Private methode
			//
			j++;
		}
		i++;
	}
	return resultat;
}
