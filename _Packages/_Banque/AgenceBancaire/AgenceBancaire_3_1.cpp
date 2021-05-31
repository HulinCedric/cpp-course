//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe AgenceBancaire - Surcharge de l'operateur [] (premiere forme)
//
// Auteur : A. Thuaire
//
#include "AgenceBancaire.h"

// --- Obtenir une vue sur un compte cible
//
CompteBancaire* AgenceBancaire::operator [] (long int numeroCible) {

   // Controler la validite de l'objet support
   //
   if(nok()) throw -2.0;

   // Controler la validite du parametre
   //
   if(numeroCible < 4000001) throw -2.1;

   // Traiter le numero cible par rapport a la fourchette de valeurs
   // possibles des numeros de compte
   //
   CompteBancaire* pCompte;
   if (numeroCible > 8000000) {

      // Traiter le cas d'un compte courant
      //
	  pCompte =  m_comptesCourant[numeroCible];
   }
   else {

      // Traiter le cas d'un compte epargne
      //
      pCompte =  m_comptesEpargne[numeroCible];
   }

   // Controler que le compte cible n'est pas ferme
   //
   map <long int, CompteBancaire*>::iterator i= m_comptesFermes.begin();
   while (i != m_comptesFermes.end()) {

      // Obtenir le compte designe par l'iterateur
      //
	  long int numeroCompte = i->first;

      // Controler le numero de ce compte
      //
      if (numeroCompte == numeroCible)
		  throw -3.4;

      // Passer a la cle suivante
      //
      i++;
   }

   // Restituer le resultat dans le cas d'une recherche infructeuse
   //
   return pCompte; 
}









