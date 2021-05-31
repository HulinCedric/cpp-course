//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe _Banque - Tests unitaires des methodes validiteId et validiteDate
//                  (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "_Banque.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Banque", "1.5.0");
   
      Tests::Design("Controle des methodes de servitude (lot 2)", 3);
   
         Tests::Case("Methode validiteId"); {
	  
            Tests::Unit(true,  _Banque::validiteId("dupond"));
            Tests::Unit(true,  _Banque::validiteId("Durand"));
            Tests::Unit(true,  _Banque::validiteId("De margerie"));
            Tests::Unit(true,  _Banque::validiteId("L'huillier"));
            Tests::Unit(false, _Banque::validiteId("A,B"));
            Tests::Unit(false, _Banque::validiteId(""));
         } 

         Tests::Case("Methode validiteDate / Annee invalide"); {
	  
            Tests::Unit(false, _Banque::validiteDate("-9/03/11"));
            Tests::Unit(false, _Banque::validiteDate("1500/11/30"));
            Tests::Unit(false, _Banque::validiteDate("1850/05/01"));
            Tests::Unit(false, _Banque::validiteDate("18500/05/01"));
         } 

         Tests::Case("Methode validiteDate / Mois invalide"); {
	  
            Tests::Unit(false, _Banque::validiteDate("2009/3/11"));
            Tests::Unit(false, _Banque::validiteDate("2009/0/30"));
            Tests::Unit(false, _Banque::validiteDate("2009/13/01"));
         } 

         Tests::Case("Methode validiteDate / Jour invalide"); {
	  
            Tests::Unit(false, _Banque::validiteDate("2009/03/32"));
            Tests::Unit(false, _Banque::validiteDate("2009/10/0"));
            Tests::Unit(false, _Banque::validiteDate("2009/11/31"));
            Tests::Unit(false, _Banque::validiteDate("2009/02/29"));
            Tests::Unit(false, _Banque::validiteDate("1900/02/29"));
            Tests::Unit(false, _Banque::validiteDate("2000/02/30"));
         }

         Tests::Case("Methode validiteDate / Cas d'une annee bissextile"); {
	  
            Tests::Unit(true,  _Banque::validiteDate("2000/02/29"));
            Tests::Unit(true,  _Banque::validiteDate("2004/02/29"));
            Tests::Unit(true,  _Banque::validiteDate("1940/02/29"));
         } 

   Tests::End();
}

