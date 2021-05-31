//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe AgenceBancaire - Tests unitaires de la persistance
//                         (Cas nominaux)
// 
// Auteur : C. Fouco
//
#include "AgenceBancaire.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("AgenceBancaire.Serialisation", "1.1.0");

      Tests::Design("Controle de la persistance", 3);
	
         Tests::Case("Persistance dans le repertoire courant"); {

		   char adresse_1[]= "Imm. Les Magnolias Bat. 2, 8 Bd Napoleon III - NICE (06000)";
		   char adresse_2[]= "Villa Beau Sejour, 115 Av. de la Grande Armee - PARIS (75000)";

		   Titulaire dupuy("DUPUY", "melanie", "1978/04/25", adresse_1);
		   Titulaire durand("Durand", "Paul", "1981/01/03",  adresse_2);
		   Titulaire hulin("HULIN", "Cedric", "1988/04/25", adresse_1);
		   Titulaire boos("BOOS", "Gael", "1989/01/03",  adresse_2);
        
		 AgenceBancaire ag1(adresse_1);
         AgenceBancaire ag2(adresse_2);
		 AgenceBancaire resultat;

            

		 ag1.ouvrirCompte(dupuy);
         ag1.ouvrirCompte(durand, 0.05f);
		 ag1.ouvrirCompte(hulin);
         ag1.ouvrirCompte(boos, 0.05f);

		 ag1.executer(8000001, VERSEMENT, "Cheque 567893", 220.f); 
		 ag1.executer(8000001, VERSEMENT, "Cheque 567893", 220.f);
         ag1.executer(8000002, VERSEMENT, "Guichet 1001",  500.f);
         ag1.executer(4000001, VERSEMENT, "Guichet 1001",  5000.f);
		 ag1.executer(4000001, VERSEMENT, "Guichet 1001",  5000.f);
		 ag1.executer(4000002, VERSEMENT, "Guichet 1001",  5000.f);
		 ag1.executer(4000002, VERSEMENT, "Guichet 1001",  15000.f);
		 ag1.executer(4000002, RETRAIT,   "Facture 2009-29", 400);
		 

		 //ag1.fermerCompte(8000001);

		 
         ag2.ouvrirCompte(durand);

		 
		 _Archives::init();

		 
           
		 
		   ag1.enregistrer("z1.txt"); resultat.restaurer("z1.txt"); resultat.enregistrer("z3.txt"); 
		   Tests::Unit(ag1.toString(), resultat.toString());

		  /* ag2.enregistrer("z2.txt"); resultat.restaurer("z2.txt"); resultat.enregistrer("z4.txt");    		   
           Tests::Unit(ag2.toString(), resultat.toString());*/
     
         }

   Tests::End();
}
