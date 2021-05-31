//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe CompteEpargne - Tests unitaires des constructeurs
//                        (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "CompteEpargne.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Banque.CompteEpargne", "1.2.0");

   char adresse_1[]= "Imm. Les Magnolias Bat. 2, 8 Bd Napoleon III - NICE (06000)";
   char adresse_2[]= "Villa Beau Sejour, 115 Av. de la Grande Armee - PARIS (75000)";

   Titulaire dupuy("DUPUY", "melanie", "1978/04/25", adresse_1);
   Titulaire durand("Durand", "Paul", "1981/01/03",  adresse_2);

   char titulaire_1[]= "DUPUY Melanie (1978/04/25) - Imm. Les Magnolias Bat. 2, 8 Bd Napoleon III - NICE (06000)";
   char titulaire_2[]= "DURAND Paul (1981/01/03) - Villa Beau Sejour, 115 Av. de la Grande Armee - PARIS (75000)";
   
      Tests::Design("Controle de la construction", 3);
   
         Tests::Case("Construction de l'element neutre"); {
         CompteEpargne neutre;
	  
            Tests::Unit("---", neutre.toString());
         }

         Tests::Case("Constructeur normal"); {
         char attendu_1[200], attendu_2[200];
         CompteEpargne cpt_1(dupuy, 0.005f), cpt_2(durand, 0.003f);

            sprintf(attendu_1, "\n%s\n%d - %7.2f", titulaire_1, 1, 0.0f);
            sprintf(attendu_2, "\n%s\n%d - %7.2f", titulaire_2, 2, 0.0f);

            Tests::Unit(attendu_1, cpt_1.toString());
            Tests::Unit(attendu_2, cpt_2.toString());
         }

   Tests::End();
}

