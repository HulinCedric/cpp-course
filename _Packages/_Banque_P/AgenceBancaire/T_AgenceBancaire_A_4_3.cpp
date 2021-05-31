//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe CompteBancaire - Tests unitaires des cas d'anomalies
//
// Auteur : A. Thuaire
//
#include "AgenceBancaire.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Banque.AgenceBancaire", "1.4.0");

   char adresse_1[]= "Imm. Les Magnolias Bat. 2, 8 Bd Napoleon III - NICE (06000)";
   char adresse_2[]= "Villa Beau Sejour, 115 Av. de la Grande Armee - PARIS (75000)";

   Titulaire dupuy("DUPUY", "melanie", "1978/04/25", adresse_1);
   Titulaire durand("Durand", "Paul", "1981/01/03",  adresse_2);

      Tests::Design("Controle des anomalies de totalDepots", 3);
      int compteur= 0;

	  AgenceBancaire ag1(adresse_2);

	  ag1.ouvrirCompte(dupuy);
      ag1.ouvrirCompte(dupuy, 0.05f);

  

         Tests::Case("Controle validite premier parametre"); {
         ag1.executer(8000001, VERSEMENT, "Cheque 567893", 220.f);

            try {ag1.totalDepots('X');}
            catch (double e) {  
               Tests::Unit(-2.1, e); compteur++;
            }
         }

		 Tests::Case("Controle validite second parametre"); {
         ag1.executer(8000001, VERSEMENT, "Cheque 567893", 220.f);

            try {ag1.totalDepots(dupuy, 'X');}
            catch (double e) {  
               Tests::Unit(-2.2, e); compteur++;
            }
         }

         Tests::Case("Synthese des controles d'anomalies"); {

            Tests::Unit(2, compteur);
         }

   Tests::End();
}

