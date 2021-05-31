//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe Banqye - Constructeurs et methode toString
//
// Auteur : C. Hulin
//
#include "Banque.h"

// --- Surcharge du constructeur par defaut
//
Banque::Banque()
{
	// Initialiser les attributs
	//
	m_nomBanque="-";
	m_codeBanque=0;
	m_adresseBanque="-";
	m_numeroSIRET="00000000000000";
	m_registreAgences= 10001;
	m_registreComptesCourants= 8000001;
	m_registreComptesEpargne= 4000001;
}

// --- Constructeur normal
//
Banque::Banque(string adresse, int numero, string siret)
{
	// Controler la validite du premier parametre
	//
	if (adresse.size() == 0)	throw -3.0;
	
	// Controler la validite du deuxieme parametre
	//
	if (numero < 0)	throw -3.0;
	
	// Controler la validite du troisieme parametre
	//
	if (siret.size() != 14)	throw -3.0;
	
	// Initialiser les attributs
	//
	m_nomBanque= "-";
	m_codeBanque= numero;
	m_adresseBanque= adresse;
	m_numeroSIRET= siret;
	m_registreAgences= 10001;
	m_registreComptesCourants= 8000001;
	m_registreComptesEpargne= 4000001;
}

// --- Restituer la description d'une agence pour les tests unitaires
//
char* Banque::toString()
{
	// Traiter le cas particulier du veto
	//
	if (nok()) {return "???";}
	
	// Traiter le cas particulier de l'element neutre
	//
	if (neutre()) {return "---";}
	
	// Traiter les proprietes "numeroGuichet" et "adresse"
	//
	char* pBuffer= new char[500];
	sprintf(pBuffer, "%.5d - %s - %s - %s -  %d - %d - %d", m_codeBanque, (char*)m_nomBanque.c_str(), (char*)m_adresseBanque.c_str(), (char*)m_numeroSIRET.c_str(), m_registreAgences, m_registreComptesCourants, m_registreComptesEpargne);
	
	return pBuffer;
}
	
	
