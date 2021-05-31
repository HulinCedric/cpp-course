//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe CompteCourant - Tests unitaires de la persistance
//                         (Cas nominaux)
// 
// Auteur : C. Fouco
//
#include "CompteCourant.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("CompteCourant.Serialisation", "1.1.0");

      Tests::Design("Controle de la persistance", 3);
	
         Tests::Case("Persistance dans le repertoire courant"); {

		   char adresse_1[]= "Imm. Les Magnolias Bat. 2, 8 Bd Napoleon III - NICE (06000)";
		   char adresse_2[]= "Villa Beau Sejour, 115 Av. de la Grande Armee - PARIS (75000)";

		   Titulaire dupuy("DUPUY", "melanie", "1978/04/25", adresse_1);
		   Titulaire durand("Durand", "Paul", "1981/01/03",  adresse_2);
        
		 CompteCourant cpt_1(dupuy);
         CompteCourant cpt_2(durand);
		 CompteCourant resultat;

            cpt_1.executer(VERSEMENT, "Guichet 322455", 200);  
            cpt_1.executer(VERSEMENT, "Guichet 322455", 320.5f);  
            cpt_1.executer(RETRAIT, "Facture 2009-29", 400);  
            cpt_1.executer(VERSEMENT, "Guichet 322455", 100); 
			
			cpt_2.executer(VERSEMENT, "Guichet 760999", 350); 
            cpt_2.executer(RETRAIT, "Facture 2009-04", 300);

		 
		 _Archives::init();

		 
           cpt_1.enregistrer("z1.txt"); resultat.restaurer("z1.txt"); 
		   Tests::Unit(cpt_1.toString(), resultat.toString());

		   cpt_2.enregistrer("z2.txt"); resultat.restaurer("z2.txt");    		   
           Tests::Unit(cpt_2.toString(), resultat.toString());

            
         }

   Tests::End();
}
