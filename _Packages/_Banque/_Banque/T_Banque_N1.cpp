//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe _Banque - Tests unitaires des methodes numeroRegistreOp, 
//                  numeroRegistreCpt, numeroRegistreCptC, numeroRegistreCptE, 
//                  dateCourante et numeroRegistreG.
//                  (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "_Banque.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Banque", "1.5.0");
   
      Tests::Design("Controle des methodes de servitude (lot 1)", 3);
   
         Tests::Case("Controle de la methode numeroRegistreOp"); {
	  
            Tests::Unit(1000001, _Banque::numeroRegistreOp());
            Tests::Unit(1000002, _Banque::numeroRegistreOp());
            Tests::Unit(1000003, _Banque::numeroRegistreOp());
         }

         Tests::Case("Methode dateCourante"); {
	  
            Tests::Unit("2009/04/21", _Banque::dateCourante());
         }

         Tests::Case("Controle de la methode numeroRegistreCpt"); {
	  
            Tests::Unit(1, _Banque::numeroRegistreCpt());
            Tests::Unit(2, _Banque::numeroRegistreCpt());
            Tests::Unit(3, _Banque::numeroRegistreCpt());
         }

         Tests::Case("Methode numeroRegistreCptC"); {
	  
            Tests::Unit(8000001, _Banque::numeroRegistreCptC());
            Tests::Unit(8000002, _Banque::numeroRegistreCptC());
            Tests::Unit(8000003, _Banque::numeroRegistreCptC());
         }

         Tests::Case("Methode numeroRegistreCptE"); {
	  
            Tests::Unit(4000001, _Banque::numeroRegistreCptE());
            Tests::Unit(4000002, _Banque::numeroRegistreCptE());
            Tests::Unit(4000003, _Banque::numeroRegistreCptE());
         }

         Tests::Case("Methode numeroRegistreG"); {
	  
            Tests::Unit(1001, _Banque::numeroRegistreG());
            Tests::Unit(1002, _Banque::numeroRegistreG());
            Tests::Unit(1003, _Banque::numeroRegistreG());
         }

   Tests::End();
}

