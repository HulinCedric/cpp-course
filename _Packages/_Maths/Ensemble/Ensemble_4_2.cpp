//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Ensemble - Service intersection -
//    
// Auteur : C.Fouco
//

#include "Ensemble.h"


Ensemble* Ensemble::intersection (const Ensemble& E) const {
	Ensemble* pResultat;

	// Test this ensemble vide
	//
   if(vide()) return new Ensemble;
  
	// Cas particulier : E ensemble vide
	// 
   if (E.vide()) return new Ensemble;

	// Construire l'ensemble résultat
   //
	pResultat= new Ensemble(m_pfEquals, m_pfNew);
	if(pResultat == NULL) throw -1.0;

	// Traiter le cas d'une intersection non vide
	//
	for(int i=1;i<=cardinal();i++)
	{
		if(E.appartient((*this)[i])) *pResultat += (*this)[i];

	}

	return pResultat;


}
