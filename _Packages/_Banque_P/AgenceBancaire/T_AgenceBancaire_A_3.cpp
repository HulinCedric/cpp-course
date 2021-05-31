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

      Tests::Design("Controle des anomalies des operators", 3);
      int compteur= 0;

	  AgenceBancaire ag1(adresse_2);

	  ag1.ouvrirCompte(dupuy);
      ag1.ouvrirCompte(durand);
      ag1.ouvrirCompte(durand, 0.05f);

	  CompteBancaire* pC;
  
         Tests::Case("Controle validite premier parametre []"); {


            try {pC= ag1[2000001];}
            catch (double e) {  
               Tests::Unit(-2.1, e); compteur++;
            }
         }

		 Tests::Case("Controle validite compte ferme parametre []"); {

		 ag1.fermerCompte(8000002);

            try {pC= ag1[8000002];}
            catch (double e) {  
               Tests::Unit(-3.4, e); compteur++;
            }
         }

		 Tests::Case("Controle validite second parametre parametre ()"); {
		 AgenceBancaire ag2;
		 list <CompteBancaire*>* pL;

            try {pL= ag2(dupuy, 'X');}
            catch (double e) {  
               Tests::Unit(-2.2, e); compteur++;
            }
         }
		 
 
		 /*Tests::Case("Controle validite premier parametre +="); {
			 
			 try {ag1+= pC;}
			 catch (double e) {  
				 Tests::Unit(-2.1, e); compteur++;
			 }
			 
         }

		 Tests::Case("Controle validite premier parametre -="); {
			 
			 try {ag1-= pC;}
			 catch (double e) {  
				 Tests::Unit(-2.1, e); compteur++;
			 }
			 
         }

		 Tests::Case("Controle validite premier parametre -="); {
	     AgenceBancaire ag2;
		ag2 += ag1[8000001];
		ag2 += ag1[4000001];
		

			try {ag2 -= ag1[9000001];}
			 catch (double e) {  
				 Tests::Unit(-3.5, e); compteur++;
			 }
			 
         }*/

		 

         Tests::Case("Synthese des controles d'anomalies"); {

            Tests::Unit(3, compteur);
         }

   Tests::End();
}

