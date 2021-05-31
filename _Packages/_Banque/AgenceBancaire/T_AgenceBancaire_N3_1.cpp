//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe AgenceBancaire - Tests unitaires de l'operateur [] (premiere forme)
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

      Tests::Design("Controle de l'operateur [] (premiere forme)", 3); 
      AgenceBancaire ag1(adresse_3);

         ag1.ouvrirCompte(dupuy);
         ag1.ouvrirCompte(durand);
         ag1.ouvrirCompte(durand, 0.05f);
         
         Tests::Case("Cas de l'absence de comptes"); {
         AgenceBancaire ag2;
         CompteBancaire* pC;

            pC= ag2[8000001];
            Tests::Unit(NULL, (int)pC);
         }

         Tests::Case("Cas d'un compte inexistant"); {
         CompteBancaire* pC;

            pC= ag1[8000009];
            Tests::Unit(NULL, (int)pC);
         }

         Tests::Case("Cas d'un compte courant"); {
         CompteBancaire* pC;

            pC= ag1[8000001];
            Tests::Unit("DUPUY", pC->titulaireCompte().nom());

            pC= ag1[8000002];
            Tests::Unit("DURAND", pC->titulaireCompte().nom());
         }

         Tests::Case("Cas d'un compte epargne"); {
         CompteBancaire* pC;

            pC= ag1[4000001];
            Tests::Unit("DURAND", pC->titulaireCompte().nom());
         }

   Tests::End();
}

