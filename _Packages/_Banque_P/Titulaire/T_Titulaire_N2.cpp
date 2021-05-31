//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe Titulaire - Tests unitaires des accesseurs
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

      Tests::Design("Controle des accesseurs de consultation", 3);

         Tests::Case("Controle de l'accesseur nom"); {
         Titulaire dupuy("DUPUY", "melanie", "1978/04/25", adresse_1);
         Titulaire durand("Durand", "Paul", "1981/01/03", adresse_2);

         char attendu_1[]= "DUPUY";
         char attendu_2[]= "DURAND";      

            Tests::Unit(attendu_1, dupuy.nom());
            Tests::Unit(attendu_2, durand.nom());     
         }

         Tests::Case("Controle de l'accesseur prenom"); {     
         Titulaire dupuy("DUPUY", "melanie", "1978/04/25", adresse_1);
         Titulaire durand("Durand", "Paul", "1981/01/03", adresse_2);

         char attendu_1[]= "Melanie";
         char attendu_2[]= "Paul";

            Tests::Unit(attendu_1, dupuy.prenom());
            Tests::Unit(attendu_2, durand.prenom());      
         }

         Tests::Case("Controle de l'accesseur dateNaissance"); {
         Titulaire dupuy("DUPUY", "melanie", "1978/04/25", adresse_1);
         Titulaire durand("Durand", "Paul", "1981/01/03", adresse_2);
	  
         char attendu_1[]= "1978/04/25";
         char attendu_2[]= "1981/01/03";
	  
            Tests::Unit(attendu_1, dupuy.dateNaissance());
            Tests::Unit(attendu_2, durand.dateNaissance());
         }

         Tests::Case("Controle de l'accesseur adresse"); {
         Titulaire dupuy("DUPUY", "melanie", "1978/04/25", adresse_1);
         Titulaire durand("Durand", "Paul", "1981/01/03", adresse_2); 
	  
            Tests::Unit(adresse_1, dupuy.adresse());
            Tests::Unit(adresse_2, durand.adresse());
         }
 
      Tests::Design("Controle des accesseurs de modification", 3);

         Tests::Case("Controle de l'accesseur modifierAdresse"); {         
         char auSoleil[]= "Imm. Les Sardines, 3 Avenue de la Canebiere - MARSEILLE (13000)";
      
         Titulaire dupuy("DUPUY", "melanie", "1978/04/25", adresse_1);
      
            dupuy.modifierAdresse(auSoleil);
            Tests::Unit(auSoleil, dupuy.adresse());
         }

   Tests::End();
}

