#ifndef _Banque_
#include "Banque.h"
#endif

float Banque::totalDepots(char type)
{
float resultat=0.f;
	
	if(nok())	throw -2.0;
	if (type != 'C' && type != 'E') throw -2.1;
	
	map	 <string, map <int, AgenceBancaire*> >::iterator i= m_regions.begin();
	map <int, AgenceBancaire*> temp;
	map <int, AgenceBancaire*>::iterator j;
	
	while (i != m_regions.end())
	{
		temp=i->second;
		j=temp.begin();
		while(j != temp.end())
		{
			resultat+=j->second->totalDepots(type);
			j++;
		}
		i++;
	}
	return resultat;
}

float Banque::totalDepots(char* pRegions, char type)
{
float resultat=0.f;
	
	if(nok())	throw -2.0;
	if(pRegions == NULL) throw -2.1;
	if (type != 'C' && type != 'E') throw -2.2;
	
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
				resultat+=j->second->totalDepots(type);
				j++;
			}
		}
		i++;
	}
	return resultat;
}