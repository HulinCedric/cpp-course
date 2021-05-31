//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe Titulaire - Tests unitaires des operateurs
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

      Tests::Design("Controle des operateurs", 3);

         Tests::Case("Controle de l'operateur ="); {
         Titulaire dupuy("DUPUY", "melanie", "1978/04/25", adresse_1);
         Titulaire durand("Durand", "Paul", "1981/01/03", adresse_2);
         Titulaire copie;     

            copie= dupuy;
            Tests::Unit(dupuy.toString(), copie.toString());
			
            copie= durand;
            Tests::Unit(durand.toString(), copie.toString()); 
         }

         Tests::Case("Controle de l'operateur =="); {
         Titulaire dupuy_1("DUPUY", "melanie", "1978/04/25", adresse_1);
         Titulaire dupuy_2("DUPUY", "edouard", "1988/04/25", adresse_2);
         Titulaire dupuy_3("DUPUY", "melanie", "1978/04/25", adresse_1);
         Titulaire durand("Durand", "Paul", "1981/01/03", adresse_2);    

            Tests::Unit(true,  dupuy_1==dupuy_1);
            Tests::Unit(false, dupuy_1==dupuy_2);
            Tests::Unit(true,  dupuy_1==dupuy_3);
            Tests::Unit(false, dupuy_1==durand);
         }

         Tests::Case("Controle de l'operateur !="); {
         Titulaire dupuy_1("DUPUY", "melanie", "1978/04/25", adresse_1);
         Titulaire dupuy_2("DUPUY", "edouard", "1988/04/25", adresse_2);
         Titulaire dupuy_3("DUPUY", "melanie", "1978/04/25", adresse_1);
         
            Tests::Unit(false, dupuy_1!=dupuy_1);
            Tests::Unit(true,  dupuy_1!=dupuy_2);
            Tests::Unit(false, dupuy_1!=dupuy_3);
         }
         
   Tests::End();
}

