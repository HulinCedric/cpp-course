//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe AgenceBancaire - Tests unitaires de la methode fermerCompte
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
   
      Tests::Design("Controle de la methode fermerCompte", 3);
      AgenceBancaire ag1(adresse_3);

         Tests::Case("Creation de comptes courants et epargne"); {
		    
            Tests::Unit(8000001, (int)ag1.ouvrirCompte(dupuy));
            Tests::Unit(4000001, (int)ag1.ouvrirCompte(dupuy, 0.06f));
            Tests::Unit(8000002, (int)ag1.ouvrirCompte(durand));
            Tests::Unit(4000002, (int)ag1.ouvrirCompte(durand, 0.05f));

            Tests::Unit(4,   ag1.nombreComptes());
         }

         Tests::Case("Cas de fermeture de comptes courants"); {

            Tests::Unit(0.f, ag1.fermerCompte(8000001));
            Tests::Unit(0.f, ag1.fermerCompte(8000002));

            Tests::Unit(0,   ag1.nombreComptesCourant());
            Tests::Unit(2,   ag1.nombreComptesEpargne());
            Tests::Unit(2,   ag1.nombreComptesFermes());
            Tests::Unit(4,   ag1.nombreComptes());
         }

         Tests::Case("Cas de fermeture de comptes epargne"); {

            Tests::Unit(0.f, ag1.fermerCompte(4000001));
            Tests::Unit(0.f, ag1.fermerCompte(4000002));

            Tests::Unit(0,   ag1.nombreComptesCourant());
            Tests::Unit(0,   ag1.nombreComptesEpargne());
            Tests::Unit(4,   ag1.nombreComptesFermes());
            Tests::Unit(4,   ag1.nombreComptes());
         }

   Tests::End();
}

