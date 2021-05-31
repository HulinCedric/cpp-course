#ifndef _Banque_
#include "Banque.h"
#endif

float Banque::depotsClient(long int compte)
{
int resultat=0;
	
	if(nok())	throw -2.0;
	if(compte < 4000001) throw -2.1;
	
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
			//	A IMPLEMENTER
			//
			
			j++;
		}
		i++;
	}
	return resultat;
}
