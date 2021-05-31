#include"Banque.h"

//Controler les accesseurs

string Banque::nomBanque() 
{ 
	// Controler la validite de l'objet support
   //
   if(nok()) throw -2.0;

   // Restituer le resultat
   //
	return m_nomBanque;
}

int Banque::codeBanque()
{ 
	// Controler la validite de l'objet support
   //
   if(nok()) throw -2.0;

   // Restituer le resultat
   //
	return m_codeBanque;
}

string Banque::adresseBanque()
{ 
	// Controler la validite de l'objet support
   //
   if(nok()) throw -2.0;

   // Restituer le resultat
   //
	return m_adresseBanque;
}

string Banque::numeroSIRET()
{ 
	// Controler la validite de l'objet support
   //
   if(nok()) throw -2.0;

   // Restituer le resultat
   //
	return m_numeroSIRET;
}

int Banque::registreAgences()
{ 
	// Controler la validite de l'objet support
   //
   if(nok()) throw -2.0;

   // Restituer le resultat
   //
	return m_registreAgences;
}

long int Banque::registreComptesCourants()	
{ 
	// Controler la validite de l'objet support
   //
   if(nok()) throw -2.0;

   // Restituer le resultat
   //
	return m_registreComptesCourants;
}

long int Banque::registreComptesEpargne()	
{ 
	// Controler la validite de l'objet support
   //
   if(nok()) throw -2.0;

   // Restituer le resultat
   //
	return m_registreComptesEpargne;
}

list <string>* Banque::regions()
{
	// Controler la validite de l'objet support
   //
   if(nok()) throw -2.0;

	list <string>* resultat= new list <string>;
	if( resultat == NULL)	throw -1.0;
	
	map <string, map <int, AgenceBancaire*> >::iterator i= m_regions.begin();
	while (i != m_regions.end())
	{
		resultat->push_back(i->first);
		i++;
	}
	// Restituer le resultat
	//
	return resultat;
}