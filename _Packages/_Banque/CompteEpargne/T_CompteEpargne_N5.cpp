//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe CompteEpargne - Tests unitaires de la methode remunerer
//                         (Cas nominaux)
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
 
      Tests::Design("Controle du service remunerer", 3);

         Tests::Case("Cas de l'absence d'operations anterieures"); { 
         CompteEpargne cpt(dupuy, 0.05f);

            cpt.remunerer(_Banque::dateCourante());

            Tests::Unit(0.f,  cpt.soldeCompte());
            Tests::Unit(0,    cpt.nombreOperations());
         }

         Tests::Case("Cas du jour courant"); { 
         CompteEpargne cpt(dupuy, 0.05f);

            cpt.executer(VERSEMENT, "Guichet 322455", 1100);  

            cpt.remunerer(_Banque::dateCourante());

            Tests::Unit(1100.f,  cpt.soldeCompte());
            Tests::Unit(1,       cpt.nombreOperations());
         }

         Tests::Case("Cas du lendemain en milieu de mois"); {
         CompteEpargne cpt(dupuy, 0.05f);

            cpt.executer(VERSEMENT, "Guichet 322455", 1000); 
            
            cpt.remunerer(_Banque::demain());

            Tests::Unit(1000.f,  cpt.soldeCompte());
            Tests::Unit(1,       cpt.nombreOperations());
         }

         Tests::Case("Cas du lendemain hors fin de mois"); {
         CompteEpargne cpt(dupuy, 0.05f);
          
            cpt.executer(VERSEMENT, "Guichet 322455", 1000);

            cpt.remunerer("2009/06/20");

            Tests::Unit(1004.166687f, cpt.soldeCompte());
            Tests::Unit(2,            cpt.nombreOperations());
         }

         Tests::Case("Cas du mois suivant"); {
         CompteEpargne cpt(dupuy, 0.05f);

             cpt.executer(VERSEMENT, "Guichet 322455", 1000);
            
             cpt.remunerer(_Banque::debutMoisSuivant(_Banque::dateCourante()));

            Tests::Unit(1004.166687f, cpt.soldeCompte());
            Tests::Unit(2,            cpt.nombreOperations());
         } 

         Tests::Case("Cas du debut de l'annee suivante"); {
         CompteEpargne cpt(dupuy, 0.05f);

            cpt.executer(VERSEMENT, "Guichet 322455", 10000);
            
            cpt.remunerer(_Banque::debutAnneeSuivante(_Banque::dateCourante()));

            Tests::Unit(10381.311523f,  cpt.soldeCompte());
            Tests::Unit(10,             cpt.nombreOperations());
         } 

   Tests::End();
}

