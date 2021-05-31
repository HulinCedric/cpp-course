//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Ensemble - Service Inclue -
//    
// Auteur : C.Fouco
//

#include "Ensemble.h"


bool Ensemble::inclus (const Ensemble& E) const {

	// Controler l'objet support
	//
   if (nok()) throw -2.0;


	// Controler le parametre
	//
   if (E.nok()) throw -2.1;

	// Test this ensemble vide
	//
   if(vide()) return false;
  
	// Cas particulier : E ensemble vide
	// 
   if (E.vide()) return true;


	// Verifier l'inclusion
	//
	if(E.cardinal()>cardinal()) return false;
	
	for(int i=1;i<=E.cardinal();i++)
	{
		if(!(this->appartient(E[i])))return false;

	}

	return true;


}
