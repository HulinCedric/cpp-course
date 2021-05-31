//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe CompteEpargne - Tests unitaires des accesseurs de modification
//                        (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "CompteEpargne.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Banque.CompteEpargne", "1.2.0");

   char adresse_1[]= "Imm. Les Magnolias Bat. 2, 8 Bd Napoleon III - NICE (06000)";
   char adresse_2[]= "Villa Beau Sejour, 115 Av. de la Grande Armee - PARIS (75000)";

   Titulaire dupuy("DUPUY", "melanie", "1978/04/25", adresse_1);
   Titulaire durand("Durand", "Paul", "1981/01/03",  adresse_2);

   CompteEpargne cpt_1(dupuy, 0.05f), cpt_2(durand, 0.0F); 

      Tests::Design("Controle des accesseurs de modification", 3);

         Tests::Case("Accesseur modifierAdresse"); {
         char auSoleil[]= "Imm. Les Sardines, 3 Avenue de la Canebiere - MARSEILLE (13000)";

            cpt_1.modifierAdresse(auSoleil);
            Tests::Unit(auSoleil,  cpt_1.adresseTitulaire());     
         }

   Tests::End();
}

