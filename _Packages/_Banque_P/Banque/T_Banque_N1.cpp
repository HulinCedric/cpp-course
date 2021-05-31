#include "Banque.h"
#include "../../_Tests/Tests/Tests.h"

void main()
{
	Tests::Begin("Banque", "1.0.0");

	Banque banque1("Imm. Les Magnolias Bat. 2, 8 Bd Napoleon III - NICE (06000)",00001,"01254152631254");
	Banque banque2("Villa Beau Sejour, 115 Av. de la Grande Armee - PARIS (75000)",00002,"01239887765433");
	Tests::Design("Controle des accesseurs de consultation", 3);
	{
		Tests::Case("Accesseurs codeBanque");
		{
			Tests::Unit(1,banque1.codeBanque());
			
			Tests::Unit(2,banque2.codeBanque());
		}
		
		Tests::Case("Accesseurs adresseBanque");
		{
			Tests::Unit("Imm. Les Magnolias Bat. 2, 8 Bd Napoleon III - NICE (06000)",(char*)banque1.adresseBanque().c_str());
			
			Tests::Unit("Villa Beau Sejour, 115 Av. de la Grande Armee - PARIS (75000)",(char*)banque2.adresseBanque().c_str());
		}
		
		Tests::Case("Accesseurs numeroSIRET");
		{
			Tests::Unit("01254152631254",(char*)banque1.numeroSIRET().c_str());
			
			Tests::Unit("01239887765433",(char*)banque2.numeroSIRET().c_str());
		}
		
		Tests::Case("Accesseurs nomBanque");
		{
			//string Nom="Societe Generale";
			//banque1.nomBanque(Nom);
			//string Nom2="BNP";
			//banque2.nomBanque(Nom2);

			Tests::Unit("-",(char*)banque1.nomBanque().c_str());
			
			Tests::Unit("-",(char*)banque2.nomBanque().c_str());
		}
	}

	Tests::Design("Controle des predicats standards", 3);
	{
      Tests::Case("Controle du predicat neutre"); {
      Banque banque;
      
         Tests::Unit(true,  banque.neutre());     
      }

      Tests::Case("Controle du predicat ok"); {
      Banque cpt;
      
         Tests::Unit(true,  cpt.ok());     
      }
 
      Tests::Case("Controle du predicat nok"); {
      Banque cpt;
      
         //cpt.veto(); Tests::Unit(true,  cpt.nok());     
      }
	}
	
	Tests::End();	
}
