//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe AgenceBancaire - Tests unitaires du service executer
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
   
      Tests::Design("Controle du service executer", 3);
      AgenceBancaire ag1(adresse_3);
		    
         ag1.ouvrirCompte(dupuy);
         ag1.ouvrirCompte(dupuy, 0.06f);
         ag1.ouvrirCompte(durand);
         ag1.ouvrirCompte(durand, 0.05f);

         Tests::Case("Operations sur des comptes courants"); {
         float solde;

            solde= ag1.executer(8000001, VERSEMENT, "Cheque 567893", 220.f);
            Tests::Unit(220.f, solde);

            solde= ag1.executer(8000002, VERSEMENT, "Guichet 1001", 500.f);
            Tests::Unit(500.f, solde);

            solde= ag1.executer(8000001, RETRAIT, "Cheque 100543", 120.f);
            Tests::Unit(100.f, solde);

            solde= ag1.executer(8000002, RETRAIT, "Cheque 76543", 450.f);
            Tests::Unit(50.f, solde);
         }

         Tests::Case("Operations sur des comptes epargne"); {
         float solde;

            solde= ag1.executer(4000001, VERSEMENT, "Cheque 567893", 220.f);
            Tests::Unit(220.f, solde);

            solde= ag1.executer(4000002, VERSEMENT, "Guichet 1001", 500.f);
            Tests::Unit(500.f, solde);

            solde= ag1.executer(4000001, RETRAIT, "Cheque 100543", 120.f);
            Tests::Unit(99.040001f, solde);

            solde= ag1.executer(4000002, RETRAIT, "Cheque 76543", 450.f);
            Tests::Unit(50.f, solde);
         }

   Tests::End();
}

