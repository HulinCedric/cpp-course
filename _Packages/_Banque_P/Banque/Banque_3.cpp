#include"Banque.h"

void Banque::creerRegion(char* pRegions)
{
	if(nok()) throw -2.0;
	if(pRegions == NULL) throw -2.1;

	map	<string, map <int, AgenceBancaire*> >::iterator i= m_regions.begin();
	while (i != m_regions.end()) {
		if(i->first == pRegions)	throw -3.9;
		i++;
	}

	m_regions[pRegions];
}

void Banque::supprimerRegion(char* pRegions)
{
	if(nok()) throw -2.0;
	if(pRegions == NULL) throw -2.1;
	
	map <string, map <int, AgenceBancaire*> >::iterator i= m_regions.begin();
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
				if(j->second->nombreComptes('C') != 0 || j->second->nombreComptes('E') != 0)	throw -3.10;
				j++;
			}
			m_regions.erase(i);	
			return;
		}
		i++;
	}
	
	throw -3.10;
}