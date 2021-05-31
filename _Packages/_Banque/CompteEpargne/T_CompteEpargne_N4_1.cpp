//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe CompteEpargne - Tests unitaires de la methode executer
//                         (Cas nominaux)
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
 
      Tests::Design("Controle du service executer", 3);

         Tests::Case("Cas d'un seul compte / Retrait superieur ou egal a 200"); {     
         CompteEpargne cpt(dupuy, 0.05f);

            cpt.executer(VERSEMENT, "Guichet 322455", 1100);  
		 
            Tests::Unit(1100.0f,  cpt.soldeCompte());
            Tests::Unit(1,        cpt.nombreOperations()); 

            cpt.executer(RETRAIT, "Facture 2009-39", 200);  
		 
            Tests::Unit(900.0f,   cpt.soldeCompte());
            Tests::Unit(2,        cpt.nombreOperations());
         } 

         Tests::Case("Cas d'un seul compte / Retraits superieurs a 200"); {     
         CompteEpargne cpt(dupuy, 0.05f);

            cpt.executer(VERSEMENT, "Guichet 322455", 200);  
		 
            Tests::Unit(200.0f,   cpt.soldeCompte());
            Tests::Unit(1,        cpt.nombreOperations());

            cpt.executer(VERSEMENT, "Guichet 322455", 520);  
		 
            Tests::Unit(720.0f,   cpt.soldeCompte());
            Tests::Unit(2,        cpt.nombreOperations());

            cpt.executer(RETRAIT, "Facture 2009-29", 300);  
		 
            Tests::Unit(420.0f,   cpt.soldeCompte());
            Tests::Unit(3,        cpt.nombreOperations());

            cpt.executer(RETRAIT, "Facture 2009-30", 220);   
		 
            Tests::Unit(200.0f,   cpt.soldeCompte());
            Tests::Unit(4,        cpt.nombreOperations());
         } 

         Tests::Case("Cas d'un seul compte / Retrait inferieur a 200"); {     
         CompteEpargne cpt(dupuy, 0.05f);

            cpt.executer(VERSEMENT, "Guichet 322455", 100);  
		 
            Tests::Unit(100.0f,  cpt.soldeCompte());
            Tests::Unit(1,       cpt.nombreOperations());

            cpt.executer(RETRAIT, "Facture 2009-29", 50);  
		 
            Tests::Unit(49.599998f, cpt.soldeCompte());
            Tests::Unit(2,          cpt.nombreOperations());
         } 

         Tests::Case("Cas de plusieurs comptes"); {     
         CompteEpargne cpt_1(dupuy, 0.05f);
         CompteEpargne cpt_2(durand, 0.03f);

            cpt_1.executer(VERSEMENT, "Guichet 322455",  200);  
            cpt_1.executer(VERSEMENT, "Guichet 322455",  320.5f);  
            cpt_1.executer(RETRAIT,   "Facture 2009-29", 400);  
            cpt_1.executer(VERSEMENT, "Guichet 322455",  100);
		 
            Tests::Unit(220.5f,     cpt_1.soldeCompte());
            Tests::Unit(4,          cpt_1.nombreOperations());

            cpt_2.executer(VERSEMENT, "Guichet 760999", 350);  
		 
            Tests::Unit(350.f,      cpt_2.soldeCompte());
            Tests::Unit(1,          cpt_2.nombreOperations());

            cpt_2.executer(RETRAIT, "Facture 2009-04", 300);

            Tests::Unit(50.f,       cpt_2.soldeCompte());
            Tests::Unit(2,          cpt_2.nombreOperations());
         } 

         Tests::Case("Cas de l'augmentation de la taille de l'historique"); {     
         CompteEpargne cpt(dupuy, 0.05f);

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
			
            Tests::Unit(298.236023f,  cpt.soldeCompte());
            Tests::Unit(10,           cpt.nombreOperations());

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

            Tests::Unit(1298.236023f, cpt.soldeCompte());
            Tests::Unit(20,           cpt.nombreOperations());
         } 

   Tests::End();
}

