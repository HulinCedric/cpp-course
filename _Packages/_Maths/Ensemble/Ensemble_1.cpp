//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Ensemble - Constructeurs et destructeur
//    
// Auteur : A. Thuaire
//
#include "Ensemble.h"

// --- Surcharge du constructeur par defaut
//
Ensemble::Ensemble() : Collection() {
	
   m_pfEquals     = NULL;
   m_pfNew        = NULL;
}

// --- Premier constructeur normal
//
Ensemble::Ensemble(fEquals* pfEquals) : Collection() {

   // Renseigner le pointeur de fonction
   //
   m_pfEquals     = pfEquals; 
}

// --- Second constructeur normal
//
Ensemble::Ensemble(fEquals* pfEquals, 
                   fNew*    pfNew) : Collection() {

   // Renseigner les pointeurs de fonction
   //
   m_pfEquals     = pfEquals;
   m_pfNew        = pfNew; 
}

// --- Surcharge du constructeur de copie
//
Ensemble::Ensemble(const Ensemble& E) {
void* pElement;
int i;

   // Controler la validite du parametre
   //
   if (E.nok()) throw -2.1;

   // Recopier les attributs scalaires
   //
   m_pfEquals   = E.m_pfEquals;
   m_pfNew      = E.m_pfNew;

   // Traiter le cas particulier d'un ensemble source vide
   //
   int nbElementsSource= E.cardinal();
   if (nbElementsSource == 0) return;

   // Controler la capacite de l'ensemble source a supporter
   // la duplication de tous ses elements
   //
   if (E.m_pfNew == NULL) throw -3.2;

   // Ajouter un duplicata de tous les elements de l'ensemble
   // source
   //    
   for (i=1; i<= nbElementsSource; i++) { 
      pElement= (*E.m_pfNew)(E[i]);
      if (pElement==NULL) throw -1.0;
      *this += pElement;
   }
}





