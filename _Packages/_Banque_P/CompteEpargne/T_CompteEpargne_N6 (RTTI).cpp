//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe CompteEpargne - Tests unitaires du mecanisme RTTI
//                        (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "CompteEpargne.h"
#include "..\CompteCourant\CompteCourant.h"
#include "T:\_Tests\Tests\Tests.h"
#include <iostream>

void main () {

   Tests::Begin("_Banque.CompteEpargne", "1.2.0");
   char adresse[]= "Villa Beau Sejour, 115 Av. de la Grande Armee - PARIS (75000)";
   Titulaire durand("Durand", "Paul", "1981/01/03",  adresse);
 
      Tests::Design("Controle du mecanisme RTTI", 3);
			
         Tests::Case("Cas natif (aucun transtypage)"); {     
         CompteEpargne* pCompte= new CompteEpargne(durand, 0.05f);
           
            Tests::Unit("class CompteEpargne", (char*)typeid(*pCompte).name());
            Tests::Unit(4000001, pCompte->numeroCompte());
         }
		 
         Tests::Case("Cas avec transtypage dans la classe mere"); {     
         CompteBancaire* pCompte= new CompteEpargne(durand, 0.05f);
           
            Tests::Unit("class CompteEpargne", (char*)typeid(*pCompte).name());
            Tests::Unit(4000002, ((CompteEpargne*)pCompte)->numeroCompte());
         } 

         Tests::Case("Cas avec transtypage dans un pointeur banalise"); {     
         void* pCompte= (void*)new CompteEpargne(durand, 0.05f);
           
            Tests::Unit("class CompteEpargne", (char*)typeid(*(CompteEpargne*)pCompte).name());
            Tests::Unit(4000003, ((CompteEpargne*)pCompte)->numeroCompte());
         } 

      Tests::Design("Controle de validite des transtypages", 3);

         Tests::Case("Cas avec une classe soeur"); {     
         CompteEpargne*  pCpt1= new CompteEpargne(durand, 0.05f);
         CompteBancaire* pCpt2= new CompteBancaire(durand);
         CompteCourant*  pCpt3= new CompteCourant(durand);

            Tests::Unit(true,  dynamic_cast<CompteBancaire*>(pCpt1)!=NULL);
            Tests::Unit(false, dynamic_cast<CompteEpargne*>(pCpt2)!=NULL);
            Tests::Unit(false, dynamic_cast<CompteEpargne*>(pCpt3)!=NULL);
            Tests::Unit(4000004, pCpt1->numeroCompte());
         } 

         Tests::Case("Controle du transtypage dans une classe soeur !!!"); {     
         void* pCompte= new CompteEpargne(durand, 0.05f);
         CompteCourant* pW;
           
            pW= (CompteCourant*)pCompte;
            Tests::Unit("class CompteEpargne", (char*)typeid(*(CompteEpargne*)pW).name());
            Tests::Unit(4000005, ((CompteEpargne*)pW)->numeroCompte());
         } 

   Tests::End();
}

