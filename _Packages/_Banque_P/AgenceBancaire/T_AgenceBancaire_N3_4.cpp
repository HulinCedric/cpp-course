//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe AgenceBancaire - Tests unitaires de l'operateur -=
//                         (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "AgenceBancaire.h"
#include "../../_Tests/Tests/Tests.h"

void main () {

   Tests::Begin("_Banque.AgenceBancaire", "1.4.0");

   char adresse_1[]= "Imm. Les Magnolias Bat. 2, 8 Bd Napoleon III - NICE (06000)";
   char adresse_2[]= "Villa Beau Sejour, 115 Av. de la Grande Armee - PARIS (75000)";
   char adresse_3[]= "Agence des bosquets 8, avenue Clemenceau - Toulon (83000)";

   Titulaire dupuy("DUPUY", "melanie", "1978/04/25", adresse_1);
   Titulaire durand("Durand", "Paul", "1981/01/03",  adresse_2);
   
      Tests::Design("Controle de l'operateur -=", 3);
      AgenceBancaire ag1(adresse_3);
	AgenceBancaire ag2;


	     ag1.ouvrirCompte(dupuy);
         ag1.ouvrirCompte(dupuy, 0.05f);

         ag1.ouvrirCompte(durand);
         ag1.ouvrirCompte(durand, 0.04f);

         Tests::Case("Mise en place du dictionnaire des clients"); {

            ag2 += ag1[8000001]; ag2 += ag1[4000001];
            Tests::Unit(1, ag2.nombreClients());

            ag2 += ag1[8000002]; ag2 += ag1[4000002];
            Tests::Unit(2, ag2.nombreClients());
         }

         Tests::Case("Suppression d'un premier compte"); {

            ag2 -= ag1[8000001];
           
            Tests::Unit(2, ag2.nombreClients());
            // Tests::Unit(1, ag1.nombreComptes(dupuy));        
         }

         Tests::Case("Suppression du premier client"); {

            ag2 -= ag1[4000001];
           
            Tests::Unit(1, ag2.nombreClients());
            // Tests::Unit(0, ag1.nombreComptes(dupuy));       
         }

         Tests::Case("Suppression du second client"); {

            ag2 -= ag1[8000002];
            ag2 -= ag1[4000002];
           
            Tests::Unit(0, ag2.nombreClients());
            // Tests::Unit(0, ag1.nombreComptes(durand));       
         }

   Tests::End();
}

