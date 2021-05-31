//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Collection - Tests unitaires des constructeurs
//                     (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "Collection.h"
#include "T:\_Tests\Tests\Tests.h"

char* fEntierToString(void*);

void main () {

   Tests::Begin("_Maths.Collection", "1.0.0");

      Tests::Design("Controle des constructeurs", 3);

         Tests::Case("Cas du constructeur par defaut"); {
         Collection neutre;

            Tests::Unit("{}", neutre.toString(&fEntierToString));
         }

         Tests::Case("Cas du constructeur de copie"); {
         Collection neutre;
         Collection C1(neutre);

            Tests::Unit("{}", C1.toString(&fEntierToString));
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
