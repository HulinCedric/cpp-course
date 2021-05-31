#include "Banque.h"
#include "../../_Tests/Tests/Tests.h"

//Tester ouvrirAgence
//int Banque::ouvrirAgence(Identifiant& id, Adresse& ad)
void main()
{
	Tests::Begin("Banque", "1.0.0");
	
		
	char adresse_1[]= "Imm. Les Magnolias Bat. 2, 8 Bd Napoleon III - NICE (06000)";
	char adresse_2[]= "Villa Beau Sejour, 115 Av. de la Grande Armee - PARIS (75000)";
	
	Banque banque1(adresse_1,00001,"01254152631254");
	Banque banque2(adresse_2,00002,"01239887765433");

	banque1.creerRegion("Paris");
	banque1.creerRegion("Nord");
	
	banque2.creerRegion("Bretagne");
	banque2.creerRegion("Nord");
	
	
	Tests::Design("Controle de ouvrirAgence", 3);
	{
		Tests::Case("Premiere Agence de banque1");
		{	
			Tests::Unit(10001, banque1.ouvrirAgence("Paris", adresse_1));
			Tests::Unit(2, banque1.regions()->size());
			Tests::Unit(1, banque1.nombreAgences());
		}
		
		Tests::Case("Deuxieme Agence de banque1");
		{	
			Tests::Unit(10002, banque1.ouvrirAgence("Nord", adresse_2));
			Tests::Unit(2, banque1.regions()->size());
			Tests::Unit(2, banque1.nombreAgences());

		}
		
		Tests::Case("Premiere Agence de banque2");
		{	
			Tests::Unit(10001, banque2.ouvrirAgence("Bretagne", adresse_1));
			Tests::Unit(2, banque2.regions()->size());
			Tests::Unit(1, banque2.nombreAgences());
		}
		
		Tests::Case("Deuxieme Agence de banque2");
		{	
			Tests::Unit(10002, banque2.ouvrirAgence("Nord", adresse_2));
			Tests::Unit(2, banque2.regions()->size());
			Tests::Unit(2, banque2.nombreAgences());
		}
	}
	
	Tests::Design("Controle de fermerAgence", 3);
	{
		Tests::Case("Premiere Agence de banque1");
		{	
			banque1.transfererCompte(10001, 10002);
			banque1.fermerAgence(10001);			
			Tests::Unit(1, banque1.nombreAgences());
			Tests::Unit(2, banque1.regions()->size());
			
			banque1.supprimerRegion("Paris");
			Tests::Unit(1, banque1.nombreAgences());
			Tests::Unit(1, banque1.regions()->size());
		}
		
		Tests::Case("Deuxieme Agence de banque1");
		{	
			banque1.fermerAgence(10002);			
			Tests::Unit(0, banque1.nombreAgences());
			Tests::Unit(1, banque1.regions()->size());
			
			banque1.supprimerRegion("Nord");
			Tests::Unit(0, banque1.nombreAgences());
			Tests::Unit(0, banque1.regions()->size());
		}
		
		Tests::Case("Premiere Agence de banque2");
		{	
			banque2.fermerAgence(10001);			
			Tests::Unit(1, banque2.nombreAgences());
			Tests::Unit(2, banque2.regions()->size());
			
			banque2.supprimerRegion("Bretagne");
			Tests::Unit(1, banque2.nombreAgences());
			Tests::Unit(1, banque2.regions()->size());	
		}
		
		Tests::Case("Deuxieme Agence de banque2");
		{	
			banque2.fermerAgence(10002);			
			Tests::Unit(0, banque2.nombreAgences());
			Tests::Unit(1, banque2.regions()->size());
			
			banque2.supprimerRegion("Nord");
			Tests::Unit(0, banque2.nombreAgences());
			Tests::Unit(0, banque2.regions()->size());		
		}
	}
	
	Tests::End();	
}
