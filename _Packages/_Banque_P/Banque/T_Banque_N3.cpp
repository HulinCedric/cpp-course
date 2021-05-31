#include "Banque.h"
#include "../../_Tests/Tests/Tests.h"

//Tester creerRÈgion
void main()
{
	Tests::Begin("Banque", "1.0.0");
	
	Banque banque1("Imm. Les Magnolias Bat. 2, 8 Bd Napoleon III - NICE (06000)",00001,"01254152631254");
	Banque banque2("Villa Beau Sejour, 115 Av. de la Grande Armee - PARIS (75000)",00002,"01239887765433");

	Tests::Design("Controle de creerRegion", 3);
	{
		Tests::Case("Premiere Region de banque1");
		{	
		banque1.creerRegion("Paris");
		Tests::Unit(1,banque1.regions()->size());
		}

		Tests::Case("Deuxieme Region de banque1");
		{	
		banque1.creerRegion("Nice");
		Tests::Unit(2,banque1.regions()->size());
		}

		Tests::Case("Premiere Region de banque2");
		{	
		banque2.creerRegion("Nice");
		Tests::Unit(1,banque2.regions()->size());
		}
	}
	
	Tests::Design("Controle de supprimerRegion", 3);
	{
		Tests::Case("Premiere Region de banque1");
		{	
			banque1.supprimerRegion("Paris");
			Tests::Unit(1,banque1.regions()->size());
		}
		
		Tests::Case("Deuxieme Region de banque1");
		{	
			banque1.supprimerRegion("Nice");
			Tests::Unit(0,banque1.regions()->size());
		}
		
		Tests::Case("Premiere Region de banque2");
		{	
			banque2.supprimerRegion("Nice");
			Tests::Unit(0,banque2.regions()->size());
		}
	}

	Tests::End();	
}
