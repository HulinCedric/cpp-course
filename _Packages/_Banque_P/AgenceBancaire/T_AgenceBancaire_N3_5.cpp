//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe AgenceBancaire - Tests unitaires de l'operateur ()
//                         (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "AgenceBancaire.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Banque.AgenceBancaire", "1.4.0");

   char adresse_1[]= "Imm. Les Magnolias Bat. 2, 8 Bd Napoleon III - NICE (06000)";
   char adresse_2[]= "Villa Beau Sejour, 115 Av. de la Grande Armee - PARIS (75000)";
   char adresse_3[]= "Agence des bosquets 8, avenue Clemenceau - Toulon (83000)";

   Titulaire dupuy("DUPUY", "melanie", "1978/04/25", adresse_1);
   Titulaire durand("Durand", "Paul", "1981/01/03",  adresse_2);
   Titulaire durand_("Durand", "Francoise", "1983/05/05",  adresse_2);

      Tests::Design("Controle de l'operateur [] (seconde forme)", 3); 
      AgenceBancaire ag1(adresse_3);

         ag1.ouvrirCompte(dupuy);
         ag1.ouvrirCompte(durand);
         ag1.ouvrirCompte(durand, 0.05f);
         ag1.ouvrirCompte(durand, 0.04f);
         
         Tests::Case("Cas de l'absence de comptes du type cible"); {
         AgenceBancaire ag2;
         list <CompteBancaire*>* pL;

            pL= ag2(dupuy, 'E');
            Tests::Unit(0, pL->size());
         }

         Tests::Case("Cas d'un seul compte du type cible"); {
         list <CompteBancaire*>* pL;

            pL= ag1(durand, 'C');
            Tests::Unit(1, pL->size());
         }

         Tests::Case("Cas de plusieurs comptes du type cible"); {
         list <CompteBancaire*>* pL;

            pL= ag1(durand, 'E');
            Tests::Unit(2, pL->size());
         }

         Tests::Case("Cas d'un client inconnu"); {
         list <CompteBancaire*>* pL;

            pL= ag1(durand_, 'C');
            Tests::Unit(0, pL->size());
         }

   Tests::End();
}

