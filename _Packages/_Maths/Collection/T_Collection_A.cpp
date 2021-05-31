//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Collection - Tests unitaires des cas d'anomalies
//   
//
// Auteur : A. Thuaire
//
#include "Collection.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.Collection", "1.0.0");

      Tests::Design("Controle des anomalies", 3);
      int compteur=0;

         Tests::Case("Operateur +="); {
         Collection C1;

            try {C1 += NULL;}
            catch (double e) {
               Tests::Unit(-2.1, e); compteur++;
            }        
         }

         Tests::Case("Operateur -="); {
         int* pE1= new int(-7), *pE2= new int(10);
         Collection C1;

            try {C1 -= NULL;}
            catch (double e) {
               Tests::Unit(-2.1, e); compteur++;
            } 

            try {C1 -= pE2;}
            catch (double e) {
               Tests::Unit(-3.0, e); compteur++;
            } 
			
            C1 += pE2;

            try {C1 -= pE1;}
            catch (double e) {
               Tests::Unit(-3.0, e); compteur++;
            } 
         }

         Tests::Case("Constructeur de copie"); {
         int* pE1= new int(-7), *pE2= new int(10);
         Collection C1;
			
            C1 += pE2;

            try {Collection C2(C1);}
            catch (double e) {
               Tests::Unit(-2.1, e); compteur++;
            } 
         }

         Tests::Case("Operateur []"); {
         int* pE1= new int(-7), *pE2= new int(10);
         void* pW;
         Collection C1;

            try {pW= C1[0];}
            catch (double e) {
               Tests::Unit(-2.1, e); compteur++;
            } 

            try {pW= C1[4];}
            catch (double e) {
               Tests::Unit(-2.1, e); compteur++;
            } 
         }

         Tests::Case("Controle du nombre d'anomalies"); {
         
            Tests::Unit(7, compteur);
         }

   Tests::End();
}

