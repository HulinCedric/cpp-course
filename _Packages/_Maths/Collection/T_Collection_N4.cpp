//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Collection - Tests unitaires des services
//                     (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "Collection.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.Collection", "1.0.0");

      Tests::Design("Controle des services", 3);

         Tests::Case("Methode designe / Cas particulier d'une collection vide"); {
         Collection neutre;

            Tests::Unit(false, neutre.designe(NULL));
         }

         Tests::Case("Methode designe / Cas general"); {
         int *pE1= new int(-2), *pE2= new int(-4);
         int *pE3= new int(-6), *pE4= new int(-6);
         Collection entiers;
         
            entiers += pE1; entiers += pE2; 
            entiers += pE3;

            Tests::Unit(true,  entiers.designe(pE2));
            Tests::Unit(true,  entiers.designe(pE1));
            Tests::Unit(false, entiers.designe(pE4));
         }

         Tests::Case("Methode cardinal / Cas particulier d'une collection vide"); {
         Collection neutre;

            Tests::Unit(0, neutre.cardinal());
         } 

         Tests::Case("Methode cardinal / Cas general"); {
         char *pE1= new char[12], *pE2= new char[12];
         char *pE3= new char[12], *pE4= new char[12];
         Collection couleurs;
         
            strcpy(pE1, "rouge");
            strcpy(pE2, "jaune");
            strcpy(pE3, "vert");
            strcpy(pE4, "magenta");

            couleurs += pE1; couleurs += pE2; 
            couleurs += pE3; couleurs += pE4; 

            Tests::Unit(4, couleurs.cardinal());
         }

         Tests::Case("Methode vider / Cas particulier d'une collection vide"); {
         Collection neutre;

            neutre.vider();
            Tests::Unit(0, neutre.cardinal());
         }  

         Tests::Case("Methode vider / Cas general"); {
         char *pE1= new char[12], *pE2= new char[12];
         char *pE3= new char[12], *pE4= new char[12];
         Collection couleurs;
         
            strcpy(pE1, "rouge");
            strcpy(pE2, "jaune");
            strcpy(pE3, "vert");
            strcpy(pE4, "magenta");

            couleurs += pE1; couleurs += pE2; 
            couleurs += pE3; couleurs += pE4; 

            couleurs.vider();
            Tests::Unit(0, couleurs.cardinal());
         }  

   Tests::End();
}

