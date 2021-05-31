//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe OperationBancaire - Tests unitaires de la persistance
//                            (Cas nominaux)
// 
// Auteur : C. Fouco
//
#include "OperationBancaire.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("OperationBancaire.Serialisation", "1.1.0");

      Tests::Design("Controle de la persistance", 3);
	
         Tests::Case("Persistance dans le repertoire courant"); {
        

		 OperationBancaire op1(VERSEMENT,   "Cheque 8002179", 2500);
		 OperationBancaire op2(RETRAIT,     "Guichet 6549", 250.75f); 
		 OperationBancaire op3(REMUNERATION,"2009/03", 50.25f); 
		 OperationBancaire resultat;

		 
		 _Archives::init();

		 
           op1.enregistrer("z1.txt"); resultat.restaurer("z1.txt");
		   Tests::Unit(op1.toString(), resultat.toString());

		   op2.enregistrer("z2.txt"); resultat.restaurer("z2.txt");    		   
           Tests::Unit(op2.toString(), resultat.toString());

		   op3.enregistrer("z3.txt"); resultat.restaurer("z3.txt");    		   
           Tests::Unit(op3.toString(), resultat.toString());
            
         }

   Tests::End();
}
