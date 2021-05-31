//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe CompteBancaire - Surcharges des operateurs += , -= et nombreOperations
//
// Auteur : A. Thuaire
//
#include "CompteBancaire.h"

// --- Surcharge de l'operateur +=
//
CompteBancaire& CompteBancaire::operator += (float montant) {

   // Controler la validite de l'objet support
   //
   if (nok()) throw -2.0;

   // Controler la validite du parametre
   //
   if (montant < 0) throw -2.1;

   // Mettre a jour le solde du compte
   //
   m_solde += montant;

   return *this;
}

// --- Surcharge de l'operateur -=
//
CompteBancaire& CompteBancaire::operator -= (float montant) {

   // Controler la validite de l'objet support
   //
   if (nok()) throw -2.0;

   // Controler la validite du parametre
   //
   if (montant < 0) throw -2.1;
	
	// Controler la validite du parametre
	//
	if (montant > soldeCompte()) throw -3.0;
   
   // Mettre a jour le solde du compte
   //
   m_solde -= montant;

   return *this;
}

int	CompteBancaire::nombreOperations(char* pDate)
{
int size= strlen(pDate);
	
	// Controler la validite de l'objet support
	//
	if (nok()) throw -2.0;
	
	// Controle validité du parametre
	//
	if (pDate == NULL)	throw -2.1;
	
	// Declarer la variable resultat
	//
	int resultat = 0;
	
	// Cas d'une date aaaa/mm/jj
	//
	if (size == 10)
	{
		// Controler la validite du parametre
		//
		if (!_Banque::validiteDate(pDate)) throw -2.1;
	
		// Controler le nombre d'operation
		//
		if(nombreOperations()==0)	return 0;
		
		// Calcul du cardinal selon le type de date
		//
		for (int compteur=1; compteur<=nombreOperations() ; compteur++)
		{
			if (strcmp(((OperationBancaire*)m_pOperations[compteur])->dateOperation(), pDate) == 0) resultat++; 
		}
	}
	
	// Cas d'une date aaaa/mm
	//
	if(size == 7)
	{
		// Cree une date conforme
		//
		char* Date= new char[10];
		strcpy(Date, pDate);
		strcat(Date, "/01");
		
		// Controler la validite du parametre
		//
		if (!_Banque::validiteDate(Date)) throw -2.1;
		
		// Controler le nombre d'operation
		//
		if(nombreOperations()==0)	return 0;
		
		// Calcul du cardinal selon le type de date
		//
		for (int compteur=1; compteur<=nombreOperations() ; compteur++)
		{
			if (_Banque::mois(((OperationBancaire*)m_pOperations[compteur])->dateOperation()) == _Banque::mois(Date) && 
				_Banque::annee(((OperationBancaire*)m_pOperations[compteur])->dateOperation()) == _Banque::annee(Date)) resultat++; 
		}
		
		// Liberer la variable de travail
		//
		delete[] Date;
	}
	
	// Cas d'une date aaaa
	//
	if (size == 4)
	{
		// Cree une date conforme
		//
		char* Date= new char[10];
		strcpy(Date, pDate);
		strcat(Date, "/01/01");
		
		// Controler la validite du parametre
		//
		if (!_Banque::validiteDate(Date)) throw -2.1;
		
		// Controler le nombre d'operation
		//
		if(nombreOperations()==0)	return 0;
		
		// Calcul du cardinal selon le type de date
		//
		for (int compteur=1; compteur<=nombreOperations() ; compteur++)
		{
			if (_Banque::annee(((OperationBancaire*)m_pOperations[compteur])->dateOperation()) == _Banque::annee(Date)) resultat++; 
		}
		
		// Liberer la variable de travail
		//
		delete[] Date;
	}
	
	// Retourner le resultat
	//
	return resultat;
}