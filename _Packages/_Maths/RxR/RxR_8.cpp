//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe RxR - Calcul des N racines Nième d'un nombre complexe
//
// Auteur : A. Thuaire
//
#include "RxR.h"

// --- Calcul des racines Niemes d'un nombre complexe
//
RxR** RxR::racines (int N) {

   // Controler la validite du parametre
   //
   if (N <= 1) return NULL;

   // Allouer le tableau resultant
   //
   RxR** pResultat= new RxR*[N+1];
   if (pResultat==NULL) return NULL;

   // Calculer le module et l'argument du nombre cible
   //
   double rho= this->rho();
   double teta= this->teta();

   // Calculer le module commun des N racines
   //
   double moduleRacines= pow(rho, 1.0/N);

   // Calculer chaque racine et placer son adresse dans le tableau resultant
   //
   double abscisse, ordonnee;
   RxR* pRacine;

   for (int k=0; k<N; k++) {

      // Calculer la partie reelle de la Kieme racine
      //
      abscisse= moduleRacines*cos(teta/N+ 2*k*PI/N);

      // Calculer la partie reelle de la Kieme racine
      //
      ordonnee= moduleRacines*sin(teta/N+ 2*k*PI/N);

      // Allouer la Kieme racine
      //
      pRacine= new RxR(abscisse, ordonnee);
      if (pRacine == NULL) {
      
         // Detruire le contenu du tableau resultant et le container
         //
         for (int i=0; i<k-1; i++) delete pResultat[i];
         delete[] pResultat;

         return NULL;
      }

      // Placer l'adresse de la Kieme racine dans le tableau resultant
      //
      pResultat[k]= pRacine;
   }

   // Marquer la fin du tableau resultant
   //
   pResultat[N]= NULL;

   return pResultat;
}









