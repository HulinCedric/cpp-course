//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Ensemble - Tests unitaires de l'operateur ==
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

      Tests::Design("Controle de l'operateur ==", 3); 

         Tests::Case("Cas de deux ensembles vides"); {
         Ensemble E1, E;

            Tests::Unit(true, E==E1);
         }

         Tests::Case("Cas d'un support vide et d'un singleton"); {
         Ensemble E1(&fEntierEquals, &fEntierNew), E;

            E1 += new int(2);

            Tests::Unit(false, E==E1);
         }

         Tests::Case("Cas d'un support vide et d'une cible quelconque"); {
         Ensemble E1(&fEntierEquals, &fEntierNew), E;

            E1 += new int(2);
            E1 += new int(4);
            E1 += new int(6);

            Tests::Unit(false, E==E1);
         }

         Tests::Case("Cas d'un support quelconque et d'une cible vide"); {
         Ensemble E1, E(&fEntierEquals, &fEntierNew);

            E += new int(-2);
            E += new int(-4);
            E += new int(-6);

            Tests::Unit(false, E==E1);
         }

         Tests::Case("Cas de deux ensembles quelconques differents"); {
         Ensemble E1(&fEntierEquals, &fEntierNew);
         Ensemble E (&fEntierEquals, &fEntierNew);

            E += new int(-2);
            E += new int(-4);
            E += new int(-6);

            E1 += new int(2);
            E1 += new int(4);
            E1 += new int(6);

            Tests::Unit(false, E==E1);
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
