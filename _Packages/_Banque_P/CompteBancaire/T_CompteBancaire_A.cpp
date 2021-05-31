//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe CompteBancaire - Tests unitaires des cas d'anomalies
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

      Tests::Design("Controle des anomalies de construction", 3);
      int compteur= 0;
   
         Tests::Case("Controle duplication d'un element neutre"); {
         CompteBancaire neutre;

            try {CompteBancaire clone(neutre);}
            catch (double e) {  
               Tests::Unit(-3.1, e); compteur++;
            }
         }

         Tests::Case("Controle duplication d'un element quelconque"); {
         CompteBancaire cpt(durand);

            try {CompteBancaire clone(cpt);}
            catch (double e) {  
               Tests::Unit(-3.1, e); compteur++;
            }
         }

         Tests::Case("Controle validite premier parametre"); {
         CompteBancaire cpt(dupuy);

            try {cpt.executer('X',"xxx", 100.f);}
            catch (double e) {  
               Tests::Unit(-2.1, e); compteur++;
            }
         }

         Tests::Case("Controle validite second parametre"); {
         CompteBancaire cpt(dupuy);

            try {cpt.executer(VERSEMENT,NULL, 100.f);}
            catch (double e) {  
               Tests::Unit(-2.2, e); compteur++;
            }
         }

         Tests::Case("Controle validite troisieme parametre"); {
         CompteBancaire cpt(dupuy);

            try {cpt.executer(VERSEMENT,"xxx", -100.f);}
            catch (double e) {  
               Tests::Unit(-2.3, e); compteur++;
            }
         }

         Tests::Case("Controle validite d'un retrait"); {
         CompteBancaire cpt(dupuy);

            cpt.executer(VERSEMENT, "xxxx", 100.f);

            try {cpt.executer(RETRAIT,"xxx", 200.f);}
            catch (double e) {  
               Tests::Unit(-3.0, e); compteur++;
            }
         }

         Tests::Case("Synthese des controles d'anomalies"); {

            Tests::Unit(6, compteur);
         }

   Tests::End();
}

