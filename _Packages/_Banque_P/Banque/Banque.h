//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe Banque : gestion d'un ensemble d'AgenceBancaire
//
// Edition A            : TP_13
//    + Version 1.0.0   : version initiale
//
// Auteur : A. Thuaire
//
#ifndef _AgenceBancaire_
#include "../AgenceBancaire/AgenceBancaire.h"
#endif

#define _Banque_

class Banque 
{
private:
	string				m_nomBanque;
	int					m_codeBanque;
	string				m_adresseBanque;
	string				m_numeroSIRET;
	map	 <string, map <int, AgenceBancaire*> >	m_regions;
	int					m_registreAgences;
	long int			m_registreComptesCourants;
	long int			m_registreComptesEpargne;
	
public:
	// ------ Constructeurs
	//	
	Banque();
	Banque(string, int, string);
	Banque(Banque&){throw -3.0;}
	
	// ------ Predicats predefinis
	//
	inline bool ok  ()  {return m_codeBanque>=00000 && m_registreComptesCourants>800000 && m_registreAgences>10000 && m_registreComptesEpargne>400000;}
	inline bool nok ()  {return !ok();}
	inline bool neutre(){return m_nomBanque == "-" && m_codeBanque==00000 && m_adresseBanque=="-" && m_numeroSIRET=="00000000000000" && m_registreAgences>10000 && m_registreComptesCourants>800000 && m_registreComptesEpargne>400000;}
	
	// ------ Accesseurs de consultation
	//
	string			nomBanque();
	int				codeBanque();
	string			adresseBanque();
	string		numeroSIRET();
	list <string>*	regions();
	int				registreAgences();
	long int		registreComptesCourants();
	long int		registreComptesEpargne();
	
	// ------ Accesseurs de modification
	//
	void			creerRegion		(char*);
	void			supprimerRegion	(char*);
	
	int				ouvrirAgence	(char*, char*);
	void			fermerAgence	(int);
	
	void			transfererCompte(long int,long int);
	
	// ------ Services Statistiques
	//
	int				nombreClients		();
	int				nombreComptes		(char);
	float			totalDepots			(char);
	int				nombresOperations	(char*);
	
	int				nombreClients		(char*);
	int				nombreComptes		(char*, char);
	float			totalDepots			(char*, char);
	int				nombresOperations	(char*, char*);
	
	// ------ Services Enquetes Administratives
	//
	list <CompteBancaire*>*	comptesClient	(Titulaire&);
	float					depotsClient	(long int);
	int						nombreAgences	();
	float					totalDepots		();

	char*			toString();
};