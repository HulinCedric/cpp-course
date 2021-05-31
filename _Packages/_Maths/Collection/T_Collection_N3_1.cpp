//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Collection - Tests unitaires de l'operateur +=
//                     (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "Collection.h"
#include "T:\_Tests\Tests\Tests.h"
#include "..\Point\Point.h"

char* fEntierToString(void*);
char* fPointToString(void*);

void main () {

   Tests::Begin("_Maths.Collection", "1.0.0");

      Tests::Design("Controle de l'operateur +=", 3);

         Tests::Case("Cas du premier element"); {
         Collection C1;

           // C1 += new int(2);
			C1 += new Point(3,2);

            Tests::Unit("{(3, 2)}", C1.toString(&fPointToString));
         }

         Tests::Case("Cas de moins de 10 elements"); {
         Collection C1;

            C1 += new int(2);
            C1 += new int(4);
            C1 += new int(6);

            Tests::Unit("{2, 4, 6}", C1.toString(&fEntierToString));
         }

         Tests::Case("Cas de 10 elements"); {
         Collection C1;

            for (int k=1; k<=10; k++) C1 += new int(k*2);

            Tests::Unit("{2, 4, 6, 8, 10, 12, 14, 16, 18, 20}", C1.toString(&fEntierToString));
         }

         Tests::Case("Cas de plus de 10 elements"); {
         Collection C1;

            for (int k=1; k<=11; k++) C1 += new int(k*2);

            Tests::Unit("{2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22}", C1.toString(&fEntierToString));
         }

   Tests::End();
}

char* fEntierToString(void* const pV) {
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

char* fPointToString(void* const pV) {


   // Controler la validite du parametre
   //
   if (pV==NULL) return NULL;

   // Allouer le buffer resultant
   //
  
   //
   return ((Point*)pV)->toString();
}