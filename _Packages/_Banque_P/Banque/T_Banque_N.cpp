#include "Banque.h"
#include "../../_Tests/Tests/Tests.h"

void main()
{
	Tests::Begin("Banque", "1.0.0");
	
	Tests::Design("Controle de la construction", 3);
	{
		Tests::Case("Constructeur Normal");
		{
			Banque banque1("Imm. Les Magnolias Bat. 2, 8 Bd Napoleon III - NICE (06000)",00001,"01254152631254");
			Banque banque2("Villa Beau Sejour, 115 Av. de la Grande Armee - PARIS (75000)",00002,"01239887765433");

			char* pBuffer= new char[200];

			sprintf(pBuffer, "%.5d - %s - %s - %s -  %d - %d - %d", 00001, "-", "Imm. Les Magnolias Bat. 2, 8 Bd Napoleon III - NICE (06000)", "01254152631254",  10001, 8000001, 4000001);
			Tests::Unit(pBuffer,banque1.toString());
			
			sprintf(pBuffer, "%.5d - %s - %s - %s -  %d - %d - %d", 00002, "-", "Villa Beau Sejour, 115 Av. de la Grande Armee - PARIS (75000)", "01239887765433",  10001, 8000001, 4000001);
			Tests::Unit(pBuffer,banque2.toString());
		}

		Tests::Case("Contructeur par defaut");
		{
			Banque banque1;
			Tests::Unit("---",banque1.toString());
		}
	}
	Tests::End();
	
}
