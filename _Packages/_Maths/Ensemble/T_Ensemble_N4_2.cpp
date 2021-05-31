//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Ensemble - Tests unitaires de la methode intersection
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

      Tests::Design("Controle de la methode intersection", 3); 

         Tests::Case("Cas particulier de deux ensembles vides"); {
         Ensemble Op1(&fEntierEquals, &fEntierNew), Op2(&fEntierEquals, &fEntierNew);
         Ensemble* pResultat;

            pResultat= Op1.intersection(Op2);
            Tests::Unit("{}", pResultat->toString(&fEntierToString));

            pResultat= Op2.intersection(Op1);
            Tests::Unit("{}", pResultat->toString(&fEntierToString));
         }

         Tests::Case("Cas particulier d'un ensemble vide"); {
         Ensemble Op1(&fEntierEquals, &fEntierNew), Op2;
         Ensemble* pResultat;

            Op1 += new int(2);
            Op1 += new int(4);
            Op1 += new int(6);

            pResultat= Op1.intersection(Op2);
            Tests::Unit("{}", pResultat->toString(&fEntierToString));

            pResultat= Op2.intersection(Op1);
            Tests::Unit("{}", pResultat->toString(&fEntierToString));
         }

         Tests::Case("Cas particulier de deux ensembles egaux"); {
         Ensemble Op1(&fEntierEquals, &fEntierNew), Op2(&fEntierEquals, &fEntierNew);
         Ensemble* pResultat;

            Op1 += new int(1);
            Op1 += new int(2);

            Op2 += new int(1);
            Op2 += new int(2);
      
            pResultat= Op1.intersection(Op2);
            Tests::Unit("{1, 2}", pResultat->toString(&fEntierToString));
         }

         Tests::Case("Cas general / Intersection vide"); {
         Ensemble Op1(&fEntierEquals, &fEntierNew), Op2(&fEntierEquals, &fEntierNew);
         Ensemble* pResultat;

            Op1 += new int(1);
            Op1 += new int(2);

            Op2 += new int(3);
            Op2 += new int(4);
      
            pResultat= Op1.intersection(Op2);
            Tests::Unit("{}", pResultat->toString(&fEntierToString));
         }

         Tests::Case("Cas general / Intersection non vide"); {
         Ensemble Op1(&fEntierEquals, &fEntierNew), Op2(&fEntierEquals, &fEntierNew);
         Ensemble* pResultat;

            Op1 += new int(1);
            Op1 += new int(2);
            Op1 += new int(4);

            Op2 += new int(2);
            Op2 += new int(1);
      
            pResultat= Op1.intersection(Op2);
            Tests::Unit("{1, 2}", pResultat->toString(&fEntierToString));
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
