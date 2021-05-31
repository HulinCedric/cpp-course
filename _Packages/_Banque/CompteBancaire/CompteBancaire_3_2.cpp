//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe CompteBancaire - Methode executer
//
// Auteur : A. Thuaire
//
#include "CompteBancaire.h"

// --- Execution d'une operation bancaire
//
float CompteBancaire::executer (char type, char* pLibelle, float montant) {

   // Controler la validite de l'objet support
   //
   if (nok()) throw -2.0;

   // Controler la validite du premier parametre
   //
   if(!_Banque::operationValide(this, type)) throw -2.1;

   // Controler la validite du second parametre
   //
   if(pLibelle==NULL) throw -2.2;

   // Controler la validite du troisieme parametre
   //
   if(montant < 0) throw -2.3;

   // Creer l'operation cible
   //
   OperationBancaire* pOp= new OperationBancaire(type, pLibelle, montant);
   if (pOp == NULL) throw -1.0;

   // Historiser l'operation cible
   //
   historiserOp(pOp);

   // Executer un versement
   //
   if (type==VERSEMENT) *this+=montant;

   // Executer un retrait
   //
   if (type==RETRAIT) *this-=montant;

   // Restituer le resultat
   //
   return soldeCompte();
}










