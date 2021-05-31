//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Collection - Tests unitaires de l'operateur -=
//                     (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "Collection.h"
#include "T:\_Tests\Tests\Tests.h"

char* fEntierToString(void*);

void main () {

   Tests::Begin("_Maths.Collection", "1.0.0");

      Tests::Design("Controle de l'operateur -=", 3);
      int *pE1= new int(1), *pE2= new int(2), *pE3= new int(3), *pE4= new int(4);
      int *pE5= new int(5), *pE6= new int(6), *pE7= new int(7), *pE8= new int(8);
      int *pE9= new int(9), *pE10= new int(10), *pE11= new int(11);

         Tests::Case("Cas d'un singleton"); {
         Collection C1;

            C1 += pE1; 
            C1 -= pE1; 

            Tests::Unit("{}", C1.toString(&fEntierToString));
         }

         Tests::Case("Cas de deux elements / Suppression du premier"); {
         Collection C1;
         
            C1 += pE1; C1 += pE2;
            C1 -= pE1; 

            Tests::Unit("{2}", C1.toString(&fEntierToString));
         }

         Tests::Case("Cas de deux elements / Suppression du dernier"); {
         Collection C1;
         
            C1 += pE1; C1 += pE2;
            C1 -= pE2;
 
           Tests::Unit("{1}", C1.toString(&fEntierToString));
         }

         Tests::Case("Cas general / Collection de moins de 10 elements"); {
         Collection C1;
         
            C1 += pE1; C1 += pE2; C1 += pE3;
            C1 -= pE2; 

            Tests::Unit("{1, 3}", C1.toString(&fEntierToString));
         }

         Tests::Case("Cas general / Collection de 10 elements"); {
         Collection C1;
         
            C1 += pE1; C1 += pE2; C1 += pE3; C1 += pE4;
            C1 += pE5; C1 += pE6; C1 += pE7; C1 += pE8;
            C1 += pE9; C1 += pE10;

            Tests::Unit("{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}", C1.toString(&fEntierToString));
            
            C1 -= pE5; 
            Tests::Unit("{1, 2, 3, 4, 6, 7, 8, 9, 10}", C1.toString(&fEntierToString));

            C1 -= pE1; 
            Tests::Unit("{2, 3, 4, 6, 7, 8, 9, 10}", C1.toString(&fEntierToString));

            C1 -= pE10; 
            Tests::Unit("{2, 3, 4, 6, 7, 8, 9}", C1.toString(&fEntierToString));

            C1 -= pE3; 
            Tests::Unit("{2, 4, 6, 7, 8, 9}", C1.toString(&fEntierToString));

            C1 -= pE8; 
            Tests::Unit("{2, 4, 6, 7, 9}", C1.toString(&fEntierToString));

            C1 -= pE9; 
            Tests::Unit("{2, 4, 6, 7}", C1.toString(&fEntierToString));

            C1 -= pE2; 
            Tests::Unit("{4, 6, 7}", C1.toString(&fEntierToString));
         }

         Tests::Case("Cas general / Collection de plus de 10 elements"); {
         Collection C1;
         
            C1 += pE1; C1 += pE2; C1 += pE3; C1 += pE4;
            C1 += pE5; C1 += pE6; C1 += pE7; C1 += pE8;
            C1 += pE9; C1 += pE10; C1 += pE11;

            Tests::Unit("{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}", C1.toString(&fEntierToString));

            C1 -= pE5; 
            Tests::Unit("{1, 2, 3, 4, 6, 7, 8, 9, 10, 11}", C1.toString(&fEntierToString));

            C1 -= pE1; 
            Tests::Unit("{2, 3, 4, 6, 7, 8, 9, 10, 11}", C1.toString(&fEntierToString));

            C1 -= pE11; 
            Tests::Unit("{2, 3, 4, 6, 7, 8, 9, 10}", C1.toString(&fEntierToString));
         }

   Tests::End();
}

char* fEntierToString(void* pV) {
char* pBuffer;

   // Controler la validite du parametre
   //
   if (pV==NULL) return NULL;

   // Allouer le buffer resultant
   //
   pBuffer= new char[10];
   if (pBuffer==NULL) return NULL;

   sprintf(pBuffer, "%d", *(int*)pV);

   // Restituer le resultat
   //
   return pBuffer;
}