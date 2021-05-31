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

         Tests::Case("Ouverture d'un compte courant par deux clients"); {

            ag1.ouvrirCompte(dupuy);
            ag1.ouvrirCompte(durand);
            Tests::Unit(2, ag1.nombreComptes('C'));     
         }

         Tests::Case("Ouverture d'un compte epargne par chaque client"); {

            ag1.ouvrirCompte(dupuy, 0.05f);
            ag1.ouvrirCompte(durand, 0.04f);
            Tests::Unit(2, ag1.nombreComptes('E'));     
         }

         Tests::Case("Fermeture du premier compte epargne"); {

            ag1.fermerCompte(4000001);
            Tests::Unit(1, ag1.nombreComptes('E'));     
         }

         Tests::Case("Ouverture d'un troisieme compte courant"); {

            ag1.ouvrirCompte(durand);
            Tests::Unit(3, ag1.nombreComptes('C'));     
         }

         Tests::Case("Fermeture du second compte epargne"); {

            ag1.fermerCompte(4000002);
            Tests::Unit(0, ag1.nombreComptes('E'));     
         }

   Tests::End();
}

