//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe CompteCourant - Tests unitaires du mecanisme RTTI
//                        (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "CompteCourant.h"
#include "T:\_Tests\Tests\Tests.h"
#include <iostream>

void main () {

   Tests::Begin("_Banque.CompteCourant", "1.1.0");
   char adresse[]= "Villa Beau Sejour, 115 Av. de la Grande Armee - PARIS (75000)";
   Titulaire durand("Durand", "Paul", "1981/01/03",  adresse);
 
      Tests::Design("Controle du mecanisme RTTI", 3);
			
         Tests::Case("Cas natif sans transtypage"); {     
         CompteCourant* pCompte= new CompteCourant(durand);
           
            Tests::Unit("class CompteCourant", (char*)typeid(*pCompte).name());
            Tests::Unit(8000001, pCompte->numeroCompte());
         }
		 
         Tests::Case("Cas avec transtypage dans la classe mere"); {     
         CompteBancaire* pCompte= new CompteCourant(durand);
           
            Tests::Unit("class CompteCourant", (char*)typeid(*pCompte).name());
            Tests::Unit(8000002, ((CompteCourant*)pCompte)->numeroCompte());
         } 

         Tests::Case("Cas avec transtypage dans un pointeur banalise"); {     
         void* pCompte= (void*)new CompteCourant(durand);
           
            Tests::Unit("class CompteCourant", (char*)typeid(*(CompteBancaire*)pCompte).name());
            Tests::Unit(8000003, ((CompteCourant*)pCompte)->numeroCompte());
         } 

         Tests::Case("Controle de validite d'un transtypage"); {     
         CompteCourant*  pCpt1= new CompteCourant(durand);
         CompteBancaire* pCpt2= new CompteBancaire(durand);

            Tests::Unit(true,  dynamic_cast<CompteBancaire*>(pCpt1)!=NULL);
            Tests::Unit(false, dynamic_cast<CompteCourant*>(pCpt2)!=NULL);
         } 
	  
   Tests::End();
}

