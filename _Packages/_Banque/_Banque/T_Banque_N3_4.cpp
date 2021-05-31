//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe _Banque - Tests unitaires des methodes jourSuivant et demain 
//                  (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "_Banque.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Banque", "1.5.0");
   
      Tests::Design("Controle de la methode jourSuivant", 3);

         Tests::Case("Cas du dernier jour de l'annee"); {
	  
            Tests::Unit("2001/01/01", _Banque::jourSuivant("2000/12/31"));
         }

         Tests::Case("Cas du dernier jour des mois de 31 jours"); {
	  
            Tests::Unit("2009/04/01", _Banque::jourSuivant("2009/03/31"));
         }

         Tests::Case("Cas du dernier jour des mois de 30 jours"); {
	  
            Tests::Unit("2009/05/01", _Banque::jourSuivant("2009/04/30"));
         }

         Tests::Case("Cas du dernier jour de fevrier des annees bissextiles"); {
	  
            Tests::Unit("2000/03/01", _Banque::jourSuivant("2000/02/29"));
         }

         Tests::Case("Cas du dernier jour de fevrier des annees non bissextiles"); {
	  
            Tests::Unit("2001/03/01", _Banque::jourSuivant("2001/02/28"));
         }

         Tests::Case("Cas general"); {
	  
            Tests::Unit("2009/05/05", _Banque::jourSuivant("2009/05/04"));
         }

      Tests::Design("Controle de la methode demain", 3);

         Tests::Case("Cas general"); {
	  
            Tests::Unit(_Banque::demain(), _Banque::jourSuivant(_Banque::dateCourante()));
         }

   Tests::End();
}

