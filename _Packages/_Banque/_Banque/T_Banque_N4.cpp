//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe _Banque - Tests unitaires de la methode operationValide 
//                  (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "_Banque.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Banque", "1.5.0");
   
      Tests::Design("Controle des methodes de servitude (lot 6)", 3);

         Tests::Case("Methode operationValide"); {
	  
            Tests::Unit(true,  _Banque::operationValide(NULL, VERSEMENT));
            Tests::Unit(true,  _Banque::operationValide(NULL, RETRAIT));
            Tests::Unit(true,  _Banque::operationValide(NULL, REMUNERATION));
         }

   Tests::End();
}

