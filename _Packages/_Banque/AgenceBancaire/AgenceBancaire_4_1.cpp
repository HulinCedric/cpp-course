//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe AgenceBancaire - Service executer
//
// Auteur : A. Thuaire
//
#include "AgenceBancaire.h"

// --- Execution d'une operation bancaire
//
float AgenceBancaire::executer (long int numeroCompte, 
                                char typeOp,
                                char* pLibelleOp, 
                                float montantOp) {

   // Controler la validite de l'objet support
   //
   if(nok()) throw -2.0;

   // Controler la validite du premier parametre
   //
   if (numeroCompte < 4000001) throw -2.1;

   // Controler la validite du troisieme parametre
   //
   if (pLibelleOp == NULL) throw -2.3;

   // Controler la validite du quatrieme parametre
   //
   if (montantOp < 0) throw -2.4;

   // Obtenir le compte cible 
   //
   CompteBancaire* pCompte= (*this)[numeroCompte];
   if (pCompte == NULL) throw -3.5;

   // Controler la validite de l'operation
   //
   if(!_Banque::operationValide(NULL, typeOp)) throw -2.2;
 
   // Traiter le cas d'un compte courant
	//
	if ( dynamic_cast<CompteCourant*>(pCompte) != NULL)	return m_comptesCourant[numeroCompte]->executer(typeOp,pLibelleOp,montantOp);
   
   // Traiter le cas d'un compte epargne
   //
	if ( dynamic_cast<CompteEpargne*>(pCompte) != NULL)	return m_comptesEpargne[numeroCompte]->executer(typeOp,pLibelleOp,montantOp);

   // Traiter le cas d'un type de compte invalide
   //
   throw -3.3;
}







