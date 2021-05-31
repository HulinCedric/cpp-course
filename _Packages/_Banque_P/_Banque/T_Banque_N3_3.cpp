//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe _Banque - Tests unitaires des methodes deltaAnnee et deltaMois
//                  (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "_Banque.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Banque", "1.5.0");
   
      Tests::Design("Controle des methodes de servitude (lot 5)", 3);

         Tests::Case("Methode deltaAnnees"); {
	  
            Tests::Unit(13, _Banque::deltaAnnees("2009/03/05", "1996/10/02"));
            Tests::Unit(13, _Banque::deltaAnnees("1996/10/02", "2009/03/05"));
            Tests::Unit(0,  _Banque::deltaAnnees("1934/08/15", "1934/08/15"));
         }

         Tests::Case("Methode deltaMois"); {
	  
            Tests::Unit(5,   _Banque::deltaMois("1997/03/05", "1996/10/02"));
            Tests::Unit(5,   _Banque::deltaMois("1996/10/02", "1997/03/05"));
            Tests::Unit(0,   _Banque::deltaMois("1934/08/15", "1934/08/15"));
            Tests::Unit(12,  _Banque::deltaMois("2008/08/15", "2009/08/15"));
            Tests::Unit(1,   _Banque::deltaMois("1934/08/15", "1934/09/15"));
            Tests::Unit(12,  _Banque::deltaMois("1935/09/15", "1934/09/15"));
            Tests::Unit(11,  _Banque::deltaMois("1935/08/15", "1934/09/15"));
            Tests::Unit(108, _Banque::deltaMois("2009/01/15", "2000/01/15"));
            Tests::Unit(119, _Banque::deltaMois("2009/12/15", "2000/01/15"));
            Tests::Unit(97,  _Banque::deltaMois("2009/01/15", "2000/12/15"));
            Tests::Unit(97,  _Banque::deltaMois("2000/12/15", "2009/01/15"));
         }

   Tests::End();
}

