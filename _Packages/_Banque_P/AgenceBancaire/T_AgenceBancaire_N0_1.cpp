//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe AgenceBancaire - Tests unitaires de la methode privee nombreComptes
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
   
      Tests::Design("Controle de la methode privee nombreComptes", 3);
      AgenceBancaire ag1(adresse_3);

         Tests::Case("Client dupuy / Ouverture d'un premier compte"); {

            ag1.ouvrirCompte(dupuy);
            Tests::Unit(1, ag1.nombreComptes(dupuy.toString(), 'C'));
            Tests::Unit(0, ag1.nombreComptes(dupuy.toString(), 'E'));
         }

         Tests::Case("Client dupuy / Ouverture d'un second compte"); {

            ag1.ouvrirCompte(dupuy, 0.05f);
            Tests::Unit(1, ag1.nombreComptes(dupuy.toString(), 'C'));
            Tests::Unit(1, ag1.nombreComptes(dupuy.toString(), 'E'));
         }

         Tests::Case("Client dupuy / Fermeture du second compte"); {

            ag1.fermerCompte(4000001);
            Tests::Unit(0, ag1.nombreComptes(dupuy.toString(), 'E'));     
         }

         Tests::Case("Client dupuy / Fermeture du second compte"); {

            ag1.fermerCompte(8000001);
            Tests::Unit(0, ag1.nombreComptes(dupuy.toString(), 'C'));     
         }

   Tests::End();
}

