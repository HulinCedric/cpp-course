#ifndef _Banque_
#include "Banque.h"
#endif

int Banque::nombreClients()
{
int resultat=0;
	
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
			resultat+=j->second->nombreClients();
			j++;
		}
		i++;
	}
	return resultat;
}

int Banque::nombreClients(char* pRegions)
{
int resultat=0;
	
	if(pRegions == NULL) throw -2.1;
	
	if(nok())	throw -2.0;
	
	map	 <string, map <int, AgenceBancaire*> >::iterator i= m_regions.begin();
	map <int, AgenceBancaire*> temp;
	map <int, AgenceBancaire*>::iterator j;
	
	while (i != m_regions.end())
	{
		if(i->first == pRegions)
		{
			temp=i->second;
			j=temp.begin();
			while(j != temp.end())
			{
				resultat+=j->second->nombreClients();
				j++;
			}
		}
		i++;
	}
	return resultat;
}
