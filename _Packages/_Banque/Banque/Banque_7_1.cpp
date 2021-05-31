#ifndef _Banque_
#include "Banque.h"
#endif

list <CompteBancaire*>*	Banque::comptesClient(Titulaire& T)
{
	
	if(nok())	throw -2.0;
	if (T.nok()) throw -2.1;
	
	list <CompteBancaire*>*	resultat=new list <CompteBancaire*>;
	if (resultat == NULL)	throw -1.0;
	
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
			//resultat=(*j->second)[T];	// erreur cause de methode privee
			//
			j++;
		}
		i++;
	}
	return resultat;
}
