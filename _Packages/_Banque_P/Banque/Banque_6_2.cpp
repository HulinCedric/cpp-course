#ifndef _Banque_
#include "Banque.h"
#endif

int	Banque::nombreComptes(char type)
{
int resultat=0;

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
			resultat+=j->second->nombreComptes(type);
			j++;
		}
		i++;
	}
	return resultat;
}

int	Banque::nombreComptes(char* pRegions, char type)
{
int resultat=0;
	
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
				resultat+=j->second->nombreComptes(type);
				j++; 
			}
		}
		i++;
	}
	return resultat;
}
