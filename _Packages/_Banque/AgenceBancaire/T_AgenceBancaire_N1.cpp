//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe AgenceBancaire - Tests unitaires des constructeurs
//                         (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "AgenceBancaire.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Banque.AgenceBancaire", "1.4.0");
   char adresse[]= "Agence des bosquets 8, avenue Clemenceau - Toulon (83000)";
   
      Tests::Design("Controle de la construction", 3);
   
         Tests::Case("Construction de l'element neutre"); {
         AgenceBancaire neutre;
	  
            Tests::Unit("---", neutre.toString());
         }

         Tests::Case("Constructeur normal"); {
         char attendu[]= "1002 - Agence des bosquets 8, avenue Clemenceau - Toulon (83000) / 0";
         AgenceBancaire ag1(adresse);

            Tests::Unit(attendu, ag1.toString());

         }

   Tests::End();
}

