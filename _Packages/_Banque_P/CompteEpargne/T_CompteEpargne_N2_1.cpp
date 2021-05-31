//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe CompteEpargne - Tests unitaires des predicats standards
//                        (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "CompteEpargne.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Banque.CompteEpargne", "1.2.0");

      Tests::Design("Controle des predicats standards", 3);

         Tests::Case("Controle du predicat neutre"); {
         CompteEpargne cpt;
      
            Tests::Unit(true,  cpt.neutre());     
         }

         Tests::Case("Controle du predicat ok"); {
         CompteEpargne cpt;
      
            Tests::Unit(true,  cpt.ok());     
         }

         Tests::Case("Controle du predicat nok"); {
         CompteEpargne cpt;
      
            Tests::Unit(false,  cpt.nok());     
         }

   Tests::End();
}

