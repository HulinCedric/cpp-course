//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe _Banque - Tests unitaires des methodes debutMoisSuivant et 
//                  debutAnneeSuivante (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "_Banque.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Banque", "1.5.0");
   
      Tests::Design("Controle de la methode debutMoisSuivant", 3);

         Tests::Case("Cas du dernier mois de l'annee"); {
	  
            Tests::Unit("2001/01/01", _Banque::debutMoisSuivant("2000/12/25"));
         }

         Tests::Case("Cas general"); {
	  
            Tests::Unit("2009/06/01", _Banque::debutMoisSuivant("2009/05/12"));
         }

      Tests::Design("Controle de la methode debutAnneeSuivante", 3);

         Tests::Case("Cas general"); {
	  
            Tests::Unit("2010/01/01", _Banque::debutAnneeSuivante("2009/05/07"));
         }

   Tests::End();
}

