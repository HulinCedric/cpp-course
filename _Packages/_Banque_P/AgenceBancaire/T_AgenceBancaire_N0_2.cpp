//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe AgenceBancaire - Tests unitaires de la methode privee totalDepots
//                         (Cas nominaux)
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
   
      Tests::Design("Controle de la methode privee totalDepots", 3);
      AgenceBancaire ag1(adresse_3);

         Tests::Case("Operations sur un premier compte courant"); {

            ag1.ouvrirCompte(dupuy);
            
            ag1.executer(8000001, VERSEMENT, "Cheque 567893", 220.f);
            Tests::Unit(220.f, ag1.totalDepots(dupuy.toString(), 'C'));

            ag1.executer(8000001, VERSEMENT, "Cheque 567893", 1000.f);
            Tests::Unit(1220.f, ag1.totalDepots(dupuy.toString(), 'C'));
         }

         Tests::Case("Operations sur un second compte courant"); {

            ag1.ouvrirCompte(dupuy);
            
            ag1.executer(8000002, VERSEMENT, "Cheque 567894", 100.f);
            Tests::Unit(1320.f, ag1.totalDepots(dupuy.toString(), 'C'));

            ag1.executer(8000002, VERSEMENT, "Cheque 567900", 600.f);
            Tests::Unit(1920.f, ag1.totalDepots(dupuy.toString(), 'C'));
         }

         Tests::Case("Operations sur un premier compte epargne"); {

            ag1.ouvrirCompte(durand, 0.04f);
            
            ag1.executer(4000001, VERSEMENT, "Cheque 411200", 2000.f);
            Tests::Unit(2000.f, ag1.totalDepots(durand.toString(), 'E'));

            ag1.executer(4000001, VERSEMENT, "Cheque 567893", 3000.f);
            Tests::Unit(5000.f, ag1.totalDepots(durand.toString(), 'E'));
         }

         Tests::Case("Operations sur un second compte epargne"); {

            ag1.ouvrirCompte(dupuy, 0.05f);
            
            ag1.executer(4000002, VERSEMENT, "Cheque 567900", 500.f);
            Tests::Unit(500.f, ag1.totalDepots(dupuy.toString(), 'E'));
         }

   Tests::End();
}

