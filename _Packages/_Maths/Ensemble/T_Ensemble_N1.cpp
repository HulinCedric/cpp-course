//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Ensemble - Tests unitaires des constructeurs
//                   (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "Ensemble.h"
#include "T:\_Tests\Tests\Tests.h"

bool   fDoubleEquals (void* const,void* const);
void*  fDoubleNew    (void* const);
void   fDoubleDelete (void* const); 

char*  fDoubleToString(void*);

void main () {

   Tests::Begin("_Maths.Ensemble", "1.0.0");

      Tests::Design("Controle des constructeurs", 3); 

         Tests::Case("Constructeur par defaut"); {
         Ensemble vide;

            Tests::Unit("{}",  vide.toString(&fDoubleToString));
         }

         Tests::Case("Premier constructeur normal"); {
         Ensemble vide (fDoubleEquals);

            Tests::Unit("{}",  vide.toString(&fDoubleToString));
         }

         Tests::Case("Second constructeur normal"); {
         Ensemble vide (fDoubleEquals, fDoubleNew);

            Tests::Unit("{}",  vide.toString(&fDoubleToString));
         }

         Tests::Case("Constructeur de copie"); {
         Ensemble vide, E(vide);

            Tests::Unit("{}",  E.toString(&fDoubleToString));
         }

   Tests::End();
}

// --- Relation d'appartenance a un ensemble de double
//
bool fDoubleEquals(void* pV1, void* pV2) {

   // Controler la validite des deux parametres
   //
   if (pV1==NULL) throw -2.1;
   if (pV2==NULL) throw -2.2;

   // Restituer le resultat
   //
   return *(double*)pV1==*(double*)pV2;
}

// --- Fonction unitaire de duplication
//
void* fDoubleNew(void* pV) {

   // Controler la validite du parametre
   //
   if (pV==NULL) throw -2.1;

   // Restituer le resultat
   //
   return (void*)new double(*(double*)pV);
}

char* fDoubleToString(void* pV) {
char* pBuffer;

   // Controler la validite du parametre
   //
   if (pV==NULL) return NULL;

   // Allouer le buffer resultant
   //
   pBuffer= new char[10];
   if (pBuffer==NULL) return NULL;

   sprintf(pBuffer, "%lg", *(double*)pV);

   // Restituer le resultat
   //
   return pBuffer;
}
