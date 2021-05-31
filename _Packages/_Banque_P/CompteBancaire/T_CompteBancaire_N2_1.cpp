//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe CompteBancaire - Tests unitaires des predicats standards
//                         (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "CompteBancaire.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Banque.CompteBancaire", "1.2.0");

      Tests::Design("Controle des predicats standards", 3);

         Tests::Case("Controle du predicat neutre"); {
         CompteBancaire cpt;
      
            Tests::Unit(true,  cpt.neutre());     
         }

         Tests::Case("Controle du predicat ok"); {
         CompteBancaire cpt;
      
            Tests::Unit(true,  cpt.ok());     
         }

   Tests::End();
}

