//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe _Banque - Tests unitaires des methodes annee, mois et jour
//                  (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "_Banque.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Banque", "1.5.0");
   
      Tests::Design("Controle des methodes de servitude (lot 3)", 3);

         Tests::Case("Methode annee"); {
	  
            Tests::Unit(2009, _Banque::annee("2009/03/05"));
            Tests::Unit(1996, _Banque::annee("1996/10/02"));
            Tests::Unit(1934, _Banque::annee("1934/08/15"));
         }

         Tests::Case("Methode mois"); {
	  
            Tests::Unit(3,  _Banque::mois("2009/03/05"));
            Tests::Unit(10, _Banque::mois("1996/10/02"));
            Tests::Unit(8,  _Banque::mois("1934/08/15"));
         }

         Tests::Case("Methode jour"); {
	  
            Tests::Unit(5,  _Banque::jour("2009/03/05"));
            Tests::Unit(2,  _Banque::jour("1996/10/02"));
            Tests::Unit(15, _Banque::jour("1934/08/15"));
         }

   Tests::End();
}

