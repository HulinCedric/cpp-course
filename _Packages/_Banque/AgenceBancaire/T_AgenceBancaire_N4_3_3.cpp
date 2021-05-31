//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe AgenceBancaire - Tests unitaires du service totalDepots
//                         (Troisieme forme / cas nominaux)
//
// Auteur : A. Thuaire
//
#include "AgenceBancaire.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Banque.AgenceBancaire", "1.4.0");

   char adresse_1[]= "Imm. Les Magnolias Bat. 2, 8 Bd Napoleon III - NICE (06000)";
   char adresse_2[]= "Villa Beau Sejour, 115 Av. de la Grande Armee - PARIS (75000)";
   char adresse_3[]= "Agence des bosquets 8, avenue Clemenceau - Toulon (83000)";

   Titulaire dupuy("DUPUY", "melanie", "1978/04/25", adresse_1);
   Titulaire durand("Durand", "Paul", "1981/01/03",  adresse_2);
   
      Tests::Design("Controle du service totalDepots (troisieme forme)", 3);
      AgenceBancaire ag1(adresse_3);

      ag1.ouvrirCompte(dupuy);
      ag1.ouvrirCompte(dupuy);
      ag1.ouvrirCompte(dupuy, 0.05f);

      ag1.ouvrirCompte(durand, 0.04f);
      ag1.ouvrirCompte(durand, 0.03f);

         Tests::Case("Client dupuy"); {

            ag1.executer(8000001, VERSEMENT, "Cheque 567893", 220.f);       
            ag1.executer(8000002, VERSEMENT, "Guichet 1001",  500.f);
            ag1.executer(4000001, VERSEMENT, "Guichet 1001",  5000.f);

            Tests::Unit(5720.f, ag1.totalDepots(dupuy));
         }

         Tests::Case("Client durand"); {

            ag1.executer(4000002, VERSEMENT, "Cheque 430122", 1000.f);       
            ag1.executer(4000003, VERSEMENT, "Guichet 1001", 500.f);

            Tests::Unit(1500.f, ag1.totalDepots(durand));
         }

   Tests::End();
}

