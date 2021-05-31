//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe AgenceBancaire - Tests unitaires des predicats predefinis
//                         (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "AgenceBancaire.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Banque.AgenceBancaire", "1.4.0");
   
      Tests::Design("Controle des predicats predefinis", 3);
      char adresse[]= "Agence des bosquets 8, avenue Clemenceau - Toulon (83000)";
         
         Tests::Case("Methode ok"); {
         AgenceBancaire neutre, ag1(adresse);

            Tests::Unit(true, neutre.ok());
            Tests::Unit(true, ag1.ok());
         }

         Tests::Case("Methode neutre"); {
         AgenceBancaire neutre, ag1(adresse);

            Tests::Unit(true,  neutre.neutre());
            Tests::Unit(false, ag1.neutre());
         }

   Tests::End();
}

