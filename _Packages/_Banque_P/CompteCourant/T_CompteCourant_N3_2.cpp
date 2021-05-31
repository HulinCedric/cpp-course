//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe CompteCourant - Tests unitaires de la methode cloturer
//                        (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "CompteCourant.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Banque.CompteCourant", "1.1.0");
   char adresse[]= "Villa Beau Sejour, 115 Av. de la Grande Armee - PARIS (75000)";
   Titulaire durand("Durand", "Paul", "1981/01/03",  adresse);
 
      Tests::Design("Controle du service cloturer", 3);
			
         Tests::Case("Methode cloturer"); {     
         CompteCourant cpt(durand);

            cpt.executer(VERSEMENT, "Guichet 322455", 200);  
            cpt.executer(VERSEMENT, "Guichet 322455", 320.5f);  
            cpt.executer(RETRAIT,   "Facture 2009-29", 400);

            Tests::Unit(3, cpt.nombreOperations());

            Tests::Unit(120.5f, cpt.cloturer());
            Tests::Unit(0.f,    cpt.soldeCompte());
            Tests::Unit(4,      cpt.nombreOperations());
         }     
	  
   Tests::End();
}

