//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe AgenceBancaire - Tests unitaires du service nombreClient
//                        
//
// Auteur : A. Thuaire
//
#include "AgenceBancaire.h"
#include "../../_Tests/Tests/Tests.h"

void main () {
	
	Tests::Begin("_Banque.AgenceBancaire", "1.4.0");
	
	char adresse_1[]= "Imm. Les Magnolias Bat. 2, 8 Bd Napoleon III - NICE (06000)";
	char adresse_2[]= "Villa Beau Sejour, 115 Av. de la Grande Armee - PARIS (75000)";
	char adresse_3[]= "Agence des bosquets 8, avenue Clemenceau - Toulon (83000)";
	
	Titulaire dupuy("DUPUY", "melanie", "1978/04/25", adresse_1);
	Titulaire durand("Durand", "Paul", "1981/01/03",  adresse_2);
	
	Tests::Design("Controle du service nombreComptes (premiere forme)", 3);
	
	Tests::Case("Cas de compte courant exclusif"); {
		AgenceBancaire ag1(adresse_3);

		ag1.ouvrirCompte(dupuy);
		ag1.ouvrirCompte(durand);
		
		Tests::Unit(2, ag1.nombreClients('C'));  
		Tests::Unit(0, ag1.nombreClients('E'));     

	}
	
	Tests::Case("Cas de compte epargne exclusif"); {
		AgenceBancaire ag1(adresse_3);

		ag1.ouvrirCompte(dupuy, 0.05f);
		ag1.ouvrirCompte(durand, 0.04f);
		
		Tests::Unit(0, ag1.nombreComptes('C'));     
		Tests::Unit(2, ag1.nombreComptes('E'));     
	}
	
	Tests::Case("Cas de plusieurs comptes par clients"); {
		AgenceBancaire ag1(adresse_3);

		ag1.ouvrirCompte(dupuy, 0.05f);
		ag1.ouvrirCompte(dupuy, 0.02f);
		ag1.ouvrirCompte(durand, 0.04f);
		ag1.ouvrirCompte(dupuy);
		ag1.ouvrirCompte(dupuy);
		
		Tests::Unit(1, ag1.nombreClients('C'));  
		Tests::Unit(2, ag1.nombreClients('E'));    
	}
	
	Tests::End();
}