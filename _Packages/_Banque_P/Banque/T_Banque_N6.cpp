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

	banque1.creerRegion("Paris");
	banque1.creerRegion("Nord");
	
	banque1.ouvrirAgence("Paris", adresse_1);
	banque1.ouvrirAgence("Nord", adresse_2);

	Tests::Design("Controle de nombreClients", 3);
	{
		Tests::Case("Niveau Regional");
		{	
			Tests::Unit(0, banque1.nombreClients("Paris"));
		}
		
		Tests::Case("Niveau National");
		{	
			Tests::Unit(0, banque1.nombreClients());
		}
	}
	
	Tests::Design("Controle de nombreComptes", 3);
	{
		Tests::Case("Niveau Regional CompteCourant");
		{	
			Tests::Unit(0, banque1.nombreComptes("Paris", 'C'));
		}
		
		Tests::Case("Niveau Regional CompteEpargne");
		{	
			Tests::Unit(0, banque1.nombreComptes("Paris", 'E'));
		}
		
		Tests::Case("Niveau National CompteCourant");
		{	
			Tests::Unit(0, banque1.nombreComptes('C'));
		}
		
		Tests::Case("Niveau National CompteEpargne");
		{	
			Tests::Unit(0, banque1.nombreComptes('E'));
		}
	}
	
	Tests::Design("Controle de totalDepots", 3);
	{
		Tests::Case("Niveau Regional CompteCourant");
		{	
			Tests::Unit(0.f, banque1.totalDepots("Paris", 'C'));
		}
		
		Tests::Case("Niveau Regional CompteEpargne");
		{	
			Tests::Unit(0.f, banque1.totalDepots("Paris", 'E'));
		}
		
		Tests::Case("Niveau National CompteCourant");
		{	
			Tests::Unit(0.f, banque1.totalDepots('C'));
		}
		
		Tests::Case("Niveau National CompteEpargne");
		{	
			Tests::Unit(0.f, banque1.totalDepots('E'));
		}
	}
	
	Tests::Design("Controle de nombresOperations", 3);
	{
		Tests::Case("Niveau Regional cas aaaa/mm/jj");
		{	
			Tests::Unit(0, banque1.nombresOperations("Paris", "2009/06/01"));
		}
		
		Tests::Case("Niveau Regional cas aaaa/mm");
		{	
			Tests::Unit(0, banque1.nombresOperations("Paris", "2009/06"));
		}
		
		Tests::Case("Niveau Regional cas aaaa");
		{	
			Tests::Unit(0, banque1.nombresOperations("Paris", "2009"));
		}
		
		Tests::Case("Niveau National cas aaaa/mm/jj");
		{	
			Tests::Unit(0, banque1.nombresOperations("2009/06/01"));
		}
		
		Tests::Case("Niveau National cas aaaa/mm");
		{	
			Tests::Unit(0, banque1.nombresOperations("2009/06"));
		}
		
		Tests::Case("Niveau National cas aaaa");
		{	
			Tests::Unit(0, banque1.nombresOperations("2009"));
		}
	}
	
	Tests::End();	
}
