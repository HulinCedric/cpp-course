//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe CompteCourant - Tests unitaires des predicats standards
//                         (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "CompteCourant.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Banque.CompteCourant", "1.1.0");

      Tests::Design("Controle des predicats standards", 3);

         Tests::Case("Controle du predicat neutre"); {
         CompteCourant cpt;
      
            Tests::Unit(true,  cpt.neutre());     
         }

         Tests::Case("Controle du predicat ok"); {
         CompteCourant cpt;
      
            Tests::Unit(true,  cpt.ok());     
         }

         Tests::Case("Controle du predicat nok"); {
         CompteCourant cpt;
      
            Tests::Unit(false,  cpt.nok());     
         }

   Tests::End();
}

