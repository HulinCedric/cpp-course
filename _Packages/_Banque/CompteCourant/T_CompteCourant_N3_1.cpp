//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe CompteCourant - Tests unitaires de la methode executer
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
 
      Tests::Design("Controle du service executer", 3);

         Tests::Case("Cas d'un seul compte"); {     
         CompteCourant cpt(dupuy);

            cpt.executer(VERSEMENT, "Guichet 322455", 200);  
		 
            Tests::Unit(200.0f,  cpt.soldeCompte());
            Tests::Unit(1,       cpt.nombreOperations());

            cpt.executer(VERSEMENT, "Guichet 322455", 320.5f);  
		 
            Tests::Unit(520.5f,  cpt.soldeCompte());
            Tests::Unit(2,       cpt.nombreOperations());

            cpt.executer(RETRAIT, "Facture 2009-29", 400);  
		 
            Tests::Unit(120.5f,  cpt.soldeCompte());
            Tests::Unit(3,       cpt.nombreOperations());

            cpt.executer(VERSEMENT, "Guichet 322455", 100);  
		 
            Tests::Unit(220.5f,  cpt.soldeCompte());
            Tests::Unit(4,       cpt.nombreOperations());
         } 
		 
         Tests::Case("Cas de plusieurs comptes"); {     
         CompteCourant cpt_1(dupuy);
         CompteCourant cpt_2(durand);

            cpt_1.executer(VERSEMENT, "Guichet 322455", 200);  
            cpt_1.executer(VERSEMENT, "Guichet 322455", 320.5f);  
            cpt_1.executer(RETRAIT, "Facture 2009-29", 400);  
            cpt_1.executer(VERSEMENT, "Guichet 322455", 100);  
		 
            Tests::Unit(220.5f,  cpt_1.soldeCompte());
            Tests::Unit(4,       cpt_1.nombreOperations());

            cpt_2.executer(VERSEMENT, "Guichet 760999", 350);  
		 
            Tests::Unit(350.f,  cpt_2.soldeCompte());
            Tests::Unit(1,      cpt_2.nombreOperations());

            cpt_2.executer(RETRAIT, "Facture 2009-04", 300);

            Tests::Unit(50.f,  cpt_2.soldeCompte());
            Tests::Unit(2,     cpt_2.nombreOperations());
         } 

         Tests::Case("Cas de l'augmentation de la taille de l'historique"); {     
         CompteCourant cpt(dupuy);

            // Premiere serie de 10 operations
            //
            cpt.executer(VERSEMENT, "Guichet 322455", 200);  
            cpt.executer(VERSEMENT, "Guichet 322455", 320.5f);  
            cpt.executer(RETRAIT,   "Facture 2009-29", 400);  
            cpt.executer(VERSEMENT, "Guichet 322455", 100);
            cpt.executer(RETRAIT,   "Facture 2009-30", 20.5f);  
            cpt.executer(VERSEMENT, "Guichet 322455", 100);
            cpt.executer(RETRAIT,   "Facture 2009-31",100);  
            cpt.executer(VERSEMENT, "Guichet 322455", 100);
            cpt.executer(RETRAIT,   "Facture 2009-32",100);  
            cpt.executer(VERSEMENT, "Guichet 322455", 100);
			
            Tests::Unit(300.f,  cpt.soldeCompte());
            Tests::Unit(10,     cpt.nombreOperations());

            // Deuxième serie d'operations
            //
            cpt.executer(RETRAIT,   "Facture 2009-33",100);

            Tests::Unit(200.f,  cpt.soldeCompte());
            Tests::Unit(11,     cpt.nombreOperations());

            cpt.executer(VERSEMENT, "Guichet 322455", 100);
            cpt.executer(VERSEMENT, "Guichet 322455", 100);
            cpt.executer(VERSEMENT, "Guichet 322455", 100);
            cpt.executer(VERSEMENT, "Guichet 322455", 100);
            cpt.executer(VERSEMENT, "Guichet 322455", 100);
            cpt.executer(VERSEMENT, "Guichet 322455", 100);
            cpt.executer(VERSEMENT, "Guichet 322455", 100);
            cpt.executer(VERSEMENT, "Guichet 322455", 100);
            cpt.executer(VERSEMENT, "Guichet 322455", 100);
            cpt.executer(VERSEMENT, "Guichet 322455", 100);

            Tests::Unit(1200.f,  cpt.soldeCompte());
            Tests::Unit(21,      cpt.nombreOperations());
         } 

   Tests::End();
}

