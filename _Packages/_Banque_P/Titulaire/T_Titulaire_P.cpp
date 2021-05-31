//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Titulaire - Tests unitaires de la persistance
//                    (Cas nominaux)
// 
// Auteur : C. Fouco
//
#include "Titulaire.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("Titulaire.Serialisation", "1.1.0");

      Tests::Design("Controle de la persistance", 3);
	
         Tests::Case("Persistance dans le repertoire courant"); {
        

		 char adresse_1[]= "Imm. Les Magnolias Bat. 2, 8 Bd Napoleon III - NICE (06000)";
		 char adresse_2[]= "Villa Beau Sejour, 115 Av. de la Grande Armee - PARIS (75000)";

		 Titulaire dupuy("DUPUY", "melanie", "1978/04/25", adresse_1);
         Titulaire durand("Durand", "Paul", "1981/01/03", adresse_2);
		 Titulaire resultat;

		 
		 _Archives::init();

		 
           dupuy.enregistrer("z1.txt"); resultat.restaurer("z1.txt");
		   Tests::Unit(dupuy.toString(), resultat.toString());

		   durand.enregistrer("z2.txt"); resultat.restaurer("z2.txt");    		   
           Tests::Unit(durand.toString(), resultat.toString());
            
         }

   Tests::End();
}
