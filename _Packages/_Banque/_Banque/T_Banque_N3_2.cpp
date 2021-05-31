//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe _Banque - Tests unitaires des predicats anterieur et posterieur
//                  (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "_Banque.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Banque", "1.5.0");
   
      Tests::Design("Controle des methodes de servitude (lot 4)", 3);

         Tests::Case("Methode anterieur"); {
	  
            Tests::Unit(true, _Banque::anterieur("2009/03/05", "2009/03/06"));
            Tests::Unit(true, _Banque::anterieur("1996/04/02", "1996/04/05"));
            Tests::Unit(true, _Banque::anterieur("1934/08/15", "1949/08/15"));

            Tests::Unit(false, _Banque::anterieur("2009/08/15", "2009/08/15"));
            Tests::Unit(false, _Banque::anterieur("2010/08/15", "2009/08/15"));
         }

         Tests::Case("Methode posterieur"); {
	  
            Tests::Unit(false, _Banque::posterieur("2009/03/05", "2009/03/06"));
            Tests::Unit(false, _Banque::posterieur("1996/04/02", "1996/04/05"));

            Tests::Unit(true, _Banque::posterieur("2010/08/15", "2009/08/15"));
         }

   Tests::End();
}

