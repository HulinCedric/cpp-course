//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe OperationBancaire - Tests unitaires des constructeurs
//                            (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "OperationBancaire.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Banque.OperationBancaire", "1.1.0");
   
      Tests::Design("Controle de la construction", 3);
   
         Tests::Case("Controle de la construction de l'element neutre"); {
         OperationBancaire neutre;
	  
            Tests::Unit("---", neutre.toString());
         }

         Tests::Case("Controle du constructeur normal"); {
         OperationBancaire op1(VERSEMENT, "Cheque 8002179", 2500);
         OperationBancaire op2(RETRAIT,   "Guichet 6549", 250.75f); 
         OperationBancaire op3(REMUNERATION, "2009/03", 50.25f); 	  
     
         char intitule_1[]= "Cheque 8002179";
         char intitule_2[]= "Guichet 6549";
         char intitule_3[]= "2009/03";
         char format[]= "%ld - %s - %s : %7.2f";
         char attendu_1[80], attendu_2[80], attendu_3[80];

            sprintf(attendu_1, format, 1000000L +1, "VERSEMENT",    intitule_1, 2500.);
            sprintf(attendu_2, format, 1000000L +2, "RETRAIT",      intitule_2, 250.75f);
            sprintf(attendu_3, format, 1000000L +3, "REMUNERATION", intitule_3, 50.25f);

            Tests::Unit(attendu_1, op1.toString());
            Tests::Unit(attendu_2, op2.toString());
            Tests::Unit(attendu_3, op3.toString());
         }

   Tests::End();
}

