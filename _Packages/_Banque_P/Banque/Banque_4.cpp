#ifndef _Banque_
#include "Banque.h"
#endif

int Banque::ouvrirAgence(char* pRegions, char* pAdresseAgence)
{
	if(nok()) throw -2.0;
	if(pRegions == NULL) throw -2.1;
	if(pAdresseAgence == NULL) throw -2.2;
	
	bool regionNOK=true;
	map <string, map <int, AgenceBancaire*> >::iterator i=m_regions.begin();
	while(i != m_regions.end())	{if(pRegions == i->first)	regionNOK=false;	i++;}
	
	if	(regionNOK)	throw -3.11;
	
	int registre= m_registreAgences++;
	
	AgenceBancaire*	agence=new AgenceBancaire(pAdresseAgence);
	
	map <int ,AgenceBancaire*> temp= m_regions[pRegions];
	
	temp[registre]=agence;
	
	m_regions[pRegions]=temp;
	
	return registre;
}

void Banque::fermerAgence(int numero)
{
	if(nok()) throw -2.0;
	if(numero<10000 || numero > 99999)	throw -2.1;
	
	map <string, map <int, AgenceBancaire*> >::iterator i=m_regions.begin();
	map <int, AgenceBancaire*> temp;
	map <int, AgenceBancaire*>::iterator j;
	while(i != m_regions.end())
	{
		temp=i->second;
		j=temp.begin();
		while(j != temp.end())
		{
			if(j->first == numero)
			{
				if(j->second->nombreComptes('C') != 0 || j->second->nombreComptes('E') != 0)	throw -3.12;
				
				temp.erase(j);
				i->second=temp; 
				return;
			}
			j++;
		}
		i++;
	}
}