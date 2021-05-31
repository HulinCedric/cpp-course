#ifndef _Banque_
#include "Banque.h"
#endif

void Banque::transfererCompte(long int origine,long int destination)
{
	if(nok()) throw -2.0;
	if(origine < 10000 || origine > 99999)	throw -2.1;
	if(destination < 10000 || destination > 99999)	throw -2.2;
	
	map	 <string, map <int, AgenceBancaire*> >::iterator i= m_regions.begin();
	map <int, AgenceBancaire*> tempOrigine;
	map <int, AgenceBancaire*>::iterator j;
	map	 <string, map <int, AgenceBancaire*> >::iterator k= m_regions.begin();
	map <int, AgenceBancaire*> tempDest;
	map <int, AgenceBancaire*>::iterator d;

	while (i != m_regions.end())
	{
		tempOrigine=i->second;
		j=tempOrigine.begin();
		while(j != tempOrigine.end())
		{
			if(j->first == origine && j->second->nombreComptes() != 0)
			{
				while(k != m_regions.end())
				{
					tempDest= k->second;
					d=tempDest.begin();
					while(d != tempDest.end())
					{
						if(d->first == destination)
						{
							swap(d->second,j->second); return;
						}
						d++;
					}
					k++;
				}
			}
			j++;
		}
		i++;
	}

}
