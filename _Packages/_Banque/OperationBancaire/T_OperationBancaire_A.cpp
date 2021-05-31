//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe OperationBancaire - Tests unitaires des constructeurs
//                            (Cas d'anomalies)
//
// Auteur : A. Thuaire
//
#include "OperationBancaire.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Banque.OperationBancaire", "1.0.0");
   
      Tests::Design("Controle des anomalies de construction", 3);
      int compteur= 0;
   
         Tests::Case("Controle du type de l'operation"); {
      
            try {OperationBancaire op1('X', "Cheque 8002179", 2500);}
            catch (double e) {  
               Tests::Unit(-2.1, e); compteur++;
            }
         }

         Tests::Case("Controle de l'intitule de l'operation"); {
         char invalide[]= "xxxxxxxxxx xxxxxxxxxx xxxxxxxxxx xxxxxxxxxx";

            try {OperationBancaire op1(RETRAIT, invalide, 2500);}
            catch (double e) {  
               Tests::Unit(-2.2, e); compteur++;
            }
         }

         Tests::Case("Controle du montant de l'operation"); {
            try {OperationBancaire op1(RETRAIT, "Cheque 8002179", -2500);}
            catch (double e) {  
               Tests::Unit(-2.3, e); compteur++;
            }
         }

         Tests::Case("Controle de la duplication"); {

            try { OperationBancaire op1(RETRAIT, "Cheque 8002179", 2500);
                  OperationBancaire op2(op1);
            }
            catch (double e) {  
               Tests::Unit(-3.0, e); compteur++;
            }
         }

         Tests::Case("Synthese des controles d'anomalies"); {

            Tests::Unit(4, compteur);
         }

   Tests::End();
}

