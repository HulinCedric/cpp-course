//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Ensemble - Tests unitaires des cas d'anomalies
//   
//
// Auteur : A. Thuaire
//
#include "Ensemble.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Ensemble.Collection", "1.0.0");

      Tests::Design("Controle des anomalies", 3);
      int compteur=0;

         Tests::Case("Operateur +="); {
         Ensemble E;

            try {E += NULL;}
            catch (double e) {
               Tests::Unit(-3.1, e); compteur++;
            }        
         }

         Tests::Case("Operateur -="); {
         int* pE1= new int(-7), *pE2= new int(10);
         Ensemble E;

            try {E -= NULL;}
            catch (double e) {
               Tests::Unit(-3.1, e); compteur++;
            } 

            try {E -= pE2;}
            catch (double e) {
               Tests::Unit(-3.1, e); compteur++;
            } 
			
           
			try {E += pE2;}
			catch (double e) {
               Tests::Unit(-3.1, e); compteur++;
			}

            try {E -= pE1;}
            catch (double e) {
               Tests::Unit(-3.1, e); compteur++;
            } 
         }

         Tests::Case("Operateur []"); {
         int* pE1= new int(-7), *pE2= new int(10);
         void* pW;
         Ensemble E;

            try {pW= E[0];}
            catch (double e) {
               Tests::Unit(-2.1, e); compteur++;
            } 

            try {pW= E[4];}
            catch (double e) {
               Tests::Unit(-2.1, e); compteur++;
            } 
         }

         Tests::Case("Synthese du nombre d'anomalies"); {
         
            Tests::Unit(7, compteur);
         }

   Tests::End();
}

