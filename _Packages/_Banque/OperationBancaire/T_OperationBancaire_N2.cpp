//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe OperationBancaire - Tests unitaires des accesseurs
//                            (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "OperationBancaire.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Banque.OperationBancaire", "1.1.0");
   
      Tests::Design("Controle des accesseurs de consultation", 3);
      OperationBancaire op1(VERSEMENT,   "Cheque 8002179", 2500);
      OperationBancaire op2(RETRAIT,     "Guichet 6549", 250.75f); 
      OperationBancaire op3(REMUNERATION,"2009/03", 50.25f); 

         Tests::Case("Methode numeroOperation"); {
      	  
            Tests::Unit(1000001, op1.numeroOperation());
            Tests::Unit(1000002, op2.numeroOperation());
            Tests::Unit(1000003, op3.numeroOperation());
         }

         Tests::Case("Methode typeOperation"); { 	  

            Tests::Unit('V',  op1.typeOperation());
            Tests::Unit('R',  op2.typeOperation());
            Tests::Unit('I',  op3.typeOperation());
         }

         Tests::Case("Methode intituleOperation"); { 	  

           Tests::Unit("Cheque 8002179", op1.intituleOperation());
           Tests::Unit("Guichet 6549",   op2.intituleOperation());
           Tests::Unit("2009/03",        op3.intituleOperation());
         }

         Tests::Case("Methode dateOperation"); {

			Tests::Unit(_Banque::dateCourante(), op1.dateOperation());
            Tests::Unit(_Banque::dateCourante(), op2.dateOperation());
            Tests::Unit(_Banque::dateCourante(), op3.dateOperation());
         }

         Tests::Case("Methode montantOperation"); { 	  

            Tests::Unit(2500.0f,  op1.montantOperation());
            Tests::Unit(250.75f,  op2.montantOperation());
            Tests::Unit(50.25f,   op3.montantOperation());
         }

   Tests::End();
}

