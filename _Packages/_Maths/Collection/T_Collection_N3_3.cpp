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

void main () {

   Tests::Begin("_Maths.Collection", "1.0.0");

      Tests::Design("Controle de l'operateur []", 3);
      
         Tests::Case("Acces en consultation / Collection d'entiers"); {
         int *pE1= new int(-2), *pE2= new int(-4);
         int *pE3= new int(-6), *pE4= new int(-6);
         Collection entiers;
         
            entiers += pE1; entiers += pE2; 
            entiers += pE3; entiers += pE4;

            Tests::Unit(-4, *(int*)entiers[2]);
            Tests::Unit(-6, *(int*)entiers[4]);
            Tests::Unit(-2, *(int*)entiers[1]);
         }

         Tests::Case("Acces en consultation / Collection de messages"); {
         char *pE1= new char[12], *pE2= new char[12];
         char *pE3= new char[12], *pE4= new char[12];
         Collection couleurs;
         
            strcpy(pE1, "rouge");
            strcpy(pE2, "jaune");
            strcpy(pE3, "vert");
            strcpy(pE4, "magenta");

            couleurs += pE1; couleurs += pE2; 
            couleurs += pE3; couleurs += pE4; 

            Tests::Unit("jaune",   (char*)couleurs[2]);
            Tests::Unit("magenta", (char*)couleurs[4]);
            Tests::Unit("rouge",   (char*)couleurs[1]);
            Tests::Unit("vert",    (char*)couleurs[3]);
         }

   Tests::End();
}
