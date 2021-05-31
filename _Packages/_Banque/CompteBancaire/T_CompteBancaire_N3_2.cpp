//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe CompteBancaire - Tests unitaires de la methode dateDerniereOperation
//                         (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "CompteBancaire.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Banque.CompteBancaire", "1.2.0");

   char adresse_1[]= "Imm. Les Magnolias Bat. 2, 8 Bd Napoleon III - NICE (06000)";
   char adresse_2[]= "Villa Beau Sejour, 115 Av. de la Grande Armee - PARIS (75000)";

   Titulaire dupuy("DUPUY", "melanie", "1978/04/25", adresse_1);
   Titulaire durand("Durand", "Paul", "1981/01/03",  adresse_2);
 
      Tests::Design("Controle de la methode dateDerniereOperation", 3);

         Tests::Case("Cas d'un seule operation"); {     
         CompteBancaire cpt(dupuy);

            cpt.executer(VERSEMENT, "Guichet 322455", 200);  
		 
            Tests::Unit(200.0f,  cpt.soldeCompte());
            Tests::Unit(_Banque::dateCourante(), cpt.dateDerniereOperation());
         } 
		 
         Tests::Case("Cas de plusieurs operations"); {     
         CompteBancaire cpt_1(dupuy);
         CompteBancaire cpt_2(durand);

            cpt_1.executer(VERSEMENT, "Guichet 322455", 200);  
            cpt_1.executer(VERSEMENT, "Guichet 322455", 320.5f);  
            cpt_1.executer(RETRAIT, "Facture 2009-29", 400);  
            cpt_1.executer(VERSEMENT, "Guichet 322455", 100);  
		 
            Tests::Unit(_Banque::dateCourante(), cpt_1.dateDerniereOperation());

            cpt_2.executer(VERSEMENT, "Guichet 760999", 350); 
            cpt_2.executer(RETRAIT, "Facture 2009-04", 300);

            Tests::Unit(_Banque::dateCourante(), cpt_2.dateDerniereOperation());
         } 

   Tests::End();
}

