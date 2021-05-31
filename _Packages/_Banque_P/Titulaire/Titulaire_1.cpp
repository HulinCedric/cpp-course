//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe Titulaire - Constructeurs et destructeur
//
// Auteur : A. Thuaire
//
#include "Titulaire.h"

// Constructeur par defaut
//
Titulaire::Titulaire () {

   // Allouer et initialiser le nom avec la valeur par defaut
   //
   m_pNom= new char[2];
   if (m_pNom == NULL) throw -1.0;
   strcpy(m_pNom, "-");

   // Allouer et initialiser le prenom avec la valeur par defaut
   //
   m_pPrenom= new char[2];
   if (m_pPrenom == NULL) throw -1.0;
   strcpy(m_pPrenom, "-");

   // Allouer et initialiser la date de naissance avec la valeur par defaut
   //
   m_pDateNaissance= new char[11];
   if (m_pDateNaissance == NULL) throw -1.0;
   strcpy(m_pDateNaissance, "0000/00/00");

   // Allouer et initialiser l'adresse avec la valeur par defaut
   //
   m_pAdresse= new char[2];
   if (m_pAdresse == NULL) throw -1.0;
   strcpy(m_pAdresse, "-");
}
 
// Constructeur normal
//
Titulaire::Titulaire ( char* const pNom, 
                       char* const pPrenom, 
                       char* const pDateNaissance, 
                       char* const pAdresse) {

   // Controler la validite du premier parametre
   //
	if (pNom==NULL || !_Banque::validiteId(pNom)) throw -2.1; 
 
   // Controler la validite du second parametre
   //
	if (pPrenom==NULL || !_Banque::validiteId(pPrenom)) throw -2.2; 

   // Controler la validite du troisieme parametre
   //
	if (pDateNaissance==NULL || !_Banque::validiteDate(pDateNaissance)) throw -2.3;

   // Controler la validite du quatrieme parametre
   //
   if (pAdresse==NULL) throw -2.4;

   // Allouer et initialiser le nom du nouveau titulaire
   //
   m_pNom= new char[strlen(pNom) + 1];
   if (m_pNom == NULL) throw -1.0;
   strcpy(m_pNom, pNom);

   int taille= strlen(m_pNom);
   for (int i=0; i<taille; i++) m_pNom[i]= toupper(m_pNom[i]);

   // Allouer et initialiser le prenom du titulaire
   //
   m_pPrenom= new char[strlen(pPrenom) + 1];
   if (m_pPrenom == NULL) {
      delete[] m_pNom; 
      throw -1.0;
   }
   strcpy(m_pPrenom, pPrenom);

   m_pPrenom[0]= toupper(m_pPrenom[0]);

   // Allouer et initialiser la date de naissance du titulaire
   //
   m_pDateNaissance= new char[strlen(pDateNaissance) + 1];
   if (m_pDateNaissance == NULL) {
      delete[] m_pNom; 
      delete[] m_pPrenom; 
      throw -1.0;
   }
   strcpy(m_pDateNaissance, pDateNaissance);

   // Allouer et initialiser l'adresse du titulaire
   //
   m_pAdresse= new char[strlen(pAdresse) + 1];
   if (m_pAdresse == NULL) {
      delete[] m_pNom; 
      delete[] m_pPrenom; 
      delete[] m_pDateNaissance; 
      throw -1.0;
   }
   strcpy(m_pAdresse, pAdresse);
}

// Surcharge du constructeur de copie
//
Titulaire::Titulaire (const Titulaire& source) {
int taille;

   // Allouer et initialiser le nom de la copie
   //
   taille= strlen(source.m_pNom);
   m_pNom= new char[taille+1];
   if (m_pNom == NULL) throw -1.0;
   strcpy(m_pNom, source.m_pNom);

   // Allouer et initialiser le prenom de la copie
   //
   taille= strlen(source.m_pPrenom);
   m_pPrenom= new char[taille+1];
   if (m_pPrenom == NULL) {
      delete m_pNom;
      throw -1.0;
   }
   strcpy(m_pPrenom, source.m_pPrenom);

   // Allouer et initialiser la date de naissance de la copie
   //
   taille= strlen(source.m_pDateNaissance);
   m_pDateNaissance= new char[taille+1];
   if (m_pDateNaissance == NULL) {
      delete m_pNom;
      delete m_pPrenom;
      throw -1.0;
   }
   strcpy(m_pDateNaissance, source.m_pDateNaissance);

   // Allouer et initialiser l'adresse de la copie
   //
   taille= strlen(source.m_pAdresse);
   m_pAdresse= new char[taille+1];
   if (m_pAdresse == NULL) {
      delete m_pNom;
      delete m_pPrenom;
      delete m_pDateNaissance;
      throw -1.0;
   }
   strcpy(m_pAdresse, source.m_pAdresse);
}

// Surcharge du destructeur
//
Titulaire::~Titulaire() {

   // Controler la validite de l'objet support
   //
   if (nok()) return;

   // Liberer chacun des champs dynmaiques
   //
   delete[] m_pNom;
   delete[] m_pPrenom;
   delete[] m_pDateNaissance;
   delete[] m_pAdresse;
}

// Servitude pour les tests unitaires
//
char* Titulaire::toString() {
char* pBuffer;

   // Allouer le buffer resultant
   //
   pBuffer= new char[200];
   if (pBuffer==NULL) return NULL;

   // Traiter le cas particulier de l'element neutre
   //
   if (neutre()) {strcpy(pBuffer, "---"); return pBuffer;} 

   // Traiter le cas general
   //
   sprintf(pBuffer, "%s %s (%s) - %s", m_pNom, m_pPrenom, m_pDateNaissance, m_pAdresse);

   return pBuffer;
}