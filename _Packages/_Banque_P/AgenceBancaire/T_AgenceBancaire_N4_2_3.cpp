//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe AgenceBancaire - Tests unitaires du service nombreComptes
//                         (Premiere forme / cas nominaux)
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
   
      Tests::Design("Controle du service nombreComptes (premiere forme)", 3);
      AgenceBancaire ag1(adresse_3);

         Tests::Case("Client dupuy / Ouverture d'un premier compte"); {

            ag1.ouvrirCompte(dupuy);
            Tests::Unit(1, ag1.nombreComptes(dupuy));     
         }

         Tests::Case("Client dupuy / Ouverture d'un second compte"); {

            ag1.ouvrirCompte(dupuy, 0.05f);
            Tests::Unit(2, ag1.nombreComptes(dupuy));     
         }

         Tests::Case("Client dupuy / Fermeture du second compte"); {

            ag1.fermerCompte(4000001);
            Tests::Unit(1, ag1.nombreComptes(dupuy));     
         }

         Tests::Case("Client durand / Ouverture de deux comptes"); {

            ag1.ouvrirCompte(durand);
            ag1.ouvrirCompte(durand, 0.04f);
            Tests::Unit(2, ag1.nombreComptes(durand));     
         }

         Tests::Case("Client dupuy / Fermeture du second compte"); {

            ag1.fermerCompte(8000001);
            Tests::Unit(0, ag1.nombreComptes(dupuy));     
         }

         Tests::Case("Client durand / Fermeture du premier compte"); {

            ag1.fermerCompte(8000002);
            Tests::Unit(1, ag1.nombreComptes(durand));     
         }

   Tests::End();
}

