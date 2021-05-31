//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Ensemble - Tests unitaires de la methode vider
//                   (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "Ensemble.h"
#include "T:\_Tests\Tests\Tests.h"

bool   fEntierEquals (void* const, void* const);
void*  fEntierNew    (void* const);

char*  fEntierToString(void*);

void main () {

   Tests::Begin("_Maths.Ensemble", "1.0.0");

      Tests::Design("Controle de la methode vider", 3); 

         Tests::Case("Cas particulier d'un ensemble vide"); {
         Ensemble E(&fEntierEquals, &fEntierNew);

            E.vider();
            Tests::Unit("{}", E.toString(&fEntierToString));
         }

         Tests::Case("Cas general"); {
         Ensemble E(&fEntierEquals, &fEntierNew);

            E += new int(2);
            E += new int(4);
            E += new int(6);

            E.vider();
            Tests::Unit("{}", E.toString(&fEntierToString));
         }

   Tests::End();
}

// --- Fonction de comparaison entre deux entiers
//
bool fEntierEquals(void* const pV1, void* const pV2) {

   // Controler la validite des deux parametres
   //
   if (pV1==NULL) throw -2.1;
   if (pV2==NULL) throw -2.2;

   // Restituer le resultat
   //
   return *(int*)pV1==*(int*)pV2;
}

// --- Fonction unitaire de duplication
//
void* fEntierNew(void* const pV) {

   // Controler la validite du parametre
   //
   if (pV==NULL) throw -2.1;

   // Restituer le resultat
   //
   return (void*)new double(*(double*)pV);
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
