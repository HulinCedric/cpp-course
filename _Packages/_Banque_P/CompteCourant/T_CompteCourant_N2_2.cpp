//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe CompteCourant - Tests unitaires des accesseurs de consultation
//                         (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "CompteCourant.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Banque.CompteCourant", "1.1.0");

   char adresse_1[]= "Imm. Les Magnolias Bat. 2, 8 Bd Napoleon III - NICE (06000)";
   char adresse_2[]= "Villa Beau Sejour, 115 Av. de la Grande Armee - PARIS (75000)";

   Titulaire dupuy("DUPUY", "melanie", "1978/04/25", adresse_1);
   Titulaire durand("Durand", "Paul", "1981/01/03",  adresse_2);

   char titulaire_1[]= "DUPUY Melanie (1978/04/25) - Imm. Les Magnolias Bat. 2, 8 Bd Napoleon III - NICE (06000)";
   char titulaire_2[]= "DURAND Paul (1981/01/03) - Villa Beau Sejour, 115 Av. de la Grande Armee - PARIS (75000)";

   CompteCourant cpt_1(dupuy), cpt_2(durand); 

      Tests::Design("Controle des accesseurs de consultation", 3);

         Tests::Case("Accesseur titulaireCompte"); {
          
            Tests::Unit(titulaire_1, cpt_1.titulaireCompte().toString());
            Tests::Unit(titulaire_2, cpt_2.titulaireCompte().toString());     
         }

         Tests::Case("Accesseur identiteTitulaire"); {     

            Tests::Unit("DUPUY Melanie", cpt_1.identiteTitulaire());
            Tests::Unit("DURAND Paul",   cpt_2.identiteTitulaire());      
         }

         Tests::Case("Accesseur adresseTitulaire"); {    
	  
            Tests::Unit(adresse_1, cpt_1.adresseTitulaire());
            Tests::Unit(adresse_2, cpt_2.adresseTitulaire());
         }

         Tests::Case("Accesseur numeroCompte"); { 
	  
            Tests::Unit(8000001, cpt_1.numeroCompte());
            Tests::Unit(8000002, cpt_2.numeroCompte());
         }

         Tests::Case("Accesseur soldeCompte"); {
	  
            Tests::Unit(0.0f, cpt_1.soldeCompte());
            Tests::Unit(0.0f, cpt_2.soldeCompte());
         }

         Tests::Case("Accesseur nombreOperations"); {
	  
            Tests::Unit(0, cpt_1.nombreOperations());
            Tests::Unit(0, cpt_2.nombreOperations());
         }

   Tests::End();
}

