//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe CompteBancaire - Tests unitaires des cas d'anomalies
//
// Auteur : A. Thuaire
//
#include "AgenceBancaire.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Banque.AgenceBancaire", "1.4.0");

   char adresse_1[]= "Imm. Les Magnolias Bat. 2, 8 Bd Napoleon III - NICE (06000)";
   char adresse_2[]= "Villa Beau Sejour, 115 Av. de la Grande Armee - PARIS (75000)";

   Titulaire dupuy("DUPUY", "melanie", "1978/04/25", adresse_1);
   Titulaire durand("Durand", "Paul", "1981/01/03",  adresse_2);

      Tests::Design("Controle des anomalies de la methode executer", 3);
      int compteur= 0;
  

         Tests::Case("Controle validite premier parametre"); {
         AgenceBancaire ag2(adresse_2);

            try {ag2.executer(1000000, 'X',"xxx", 100.f);}
            catch (double e) {  
               Tests::Unit(-2.1, e); compteur++;
            }
         }

		 Tests::Case("Controle validite troisieme parametre"); {
         AgenceBancaire ag2(adresse_2);

            try {ag2.executer(4000002, 'C', NULL, 100.f);}
            catch (double e) {  
               Tests::Unit(-2.3, e); compteur++;
            }
         }

		 Tests::Case("Controle validite quatrieme parametre"); {
         AgenceBancaire ag2(adresse_2);

            try {ag2.executer(4000002, 'C', "xxx", -100.f);}
            catch (double e) {  
               Tests::Unit(-2.4, e); compteur++;
            }
         }

		 Tests::Case("Controle validite obtention compte"); {
         AgenceBancaire ag2(adresse_2);

		 ag2.ouvrirCompte(dupuy);
         ag2.ouvrirCompte(dupuy, 0.06f);

            try {ag2.executer(5000001, 'C', "xxx", 100.f);}
            catch (double e) {  
               Tests::Unit(-3.5, e); compteur++;
            }
         }

		 Tests::Case("Controle validite second parametre"); {
         AgenceBancaire ag2(adresse_2);

		 ag2.ouvrirCompte(dupuy);
         ag2.ouvrirCompte(dupuy, 0.06f);

            try {ag2.executer(8000002, 'C', "xxx", 100.f);}
            catch (double e) {  
               Tests::Unit(-2.2, e); compteur++;
            }
         }

         Tests::Case("Synthese des controles d'anomalies"); {

            Tests::Unit(5, compteur);
         }

   Tests::End();
}

