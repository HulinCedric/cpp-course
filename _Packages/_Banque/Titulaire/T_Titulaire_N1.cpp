//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe Titulaire - Tests unitaires des constructeurs et du destructeur
//                    (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "Titulaire.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Banque.Titulaire", "1.1.0");

   char adresse_1[]= "Imm. Les Magnolias Bat. 2, 8 Bd Napoleon III - NICE (06000)";
   char adresse_2[]= "Villa Beau Sejour, 115 Av. de la Grande Armee - PARIS (75000)";

      Tests::Design("Controle des constructeurs", 3);

         Tests::Case("Controle du constructeur par defaut"); {
         Titulaire neutre;   

            Tests::Unit(true,  neutre.ok());
            Tests::Unit("---", neutre.toString());    
         }

         Tests::Case("Controle du constructeur normal"); {
         Titulaire dupuy("DUPUY", "melanie", "1978/04/25", adresse_1);
         Titulaire durand("Durand", "Paul", "1981/01/03",  adresse_2);
		 
         char attendu_1[]= "DUPUY Melanie (1978/04/25) - Imm. Les Magnolias Bat. 2, 8 Bd Napoleon III - NICE (06000)";
         char attendu_2[]= "DURAND Paul (1981/01/03) - Villa Beau Sejour, 115 Av. de la Grande Armee - PARIS (75000)";

            Tests::Unit(attendu_1, dupuy.toString());
            Tests::Unit(attendu_2, durand.toString());     
         }

         Tests::Case("Controle du constructeur de copie"); {
         Titulaire durand("Durand", "Paul", "1981/01/03",  adresse_2);
         Titulaire copie(durand);
		 
         char attendu[]= "DURAND Paul (1981/01/03) - Villa Beau Sejour, 115 Av. de la Grande Armee - PARIS (75000)";

            Tests::Unit(attendu, copie.toString());     
         }

      Tests::Design("Controle du destructeur", 3);

         Tests::Case("Instances dynamiques"); {
         Titulaire* pNeutre= new Titulaire;
         Titulaire* pDupuy = new Titulaire("DUPUY", "Melanie", "1978/04/25", adresse_1);    

            delete pNeutre;
            delete pDupuy;    
         }

   Tests::End();
}

