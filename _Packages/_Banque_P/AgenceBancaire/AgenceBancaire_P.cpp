//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe AgenceBancaire - Methode serialize
//
// Auteur : C. Fouco
//
#include "AgenceBancaire.h"

// Serialisation 
//
void AgenceBancaire::serialize(Archive& ar) {

	

   // Traiter le cas des attributs predefinis
   //
   if (ar.isStoring())
   {
	    // Recuperation du char* dans le string pour adresseAgence
	    // -> string : type non defini dans Archive
	    //
	    char* adresseAgence = new char[m_adresseAgence.size()+1]; 
		strcpy(adresseAgence, m_adresseAgence.c_str());
		int tailleAdresse = m_adresseAgence.size();

		

	

		// Sauvegarder les attributs prédéfinis
	    //
	    ar << m_numeroGuichet << tailleAdresse << adresseAgence;

		// Sauvegarder le nombre de chaque compte
		//
		ar << nombreComptesCourant() << nombreComptesEpargne() << nombreComptesFermes();
		ar << nombreClients  () << nombreComptes();

	    // Traiter le cas des relations de composition
	    //
		// Parcourir le dictionnaire des comptes courant
		//
		map <long int, CompteCourant*>::iterator i= m_comptesCourant.begin();
		while (i != m_comptesCourant.end()) {

			// Serialiser le compte courant
			//
			m_comptesCourant[i->first]->serialize(ar);
			i++;
		}

		// Parcourir le dictionnaire des comptes epargne
		//
		map <long int, CompteEpargne*>::iterator k= m_comptesEpargne.begin();
		while (k != m_comptesEpargne.end()) {

			// Serialiser le compte epargne
			//
			m_comptesEpargne[k->first]->serialize(ar);
			k++;
		}

		// Parcourir le dictionnaire des comptes ferme
		//
		map <long int, CompteBancaire*>::iterator j= m_comptesFermes.begin();
		while (j != m_comptesFermes.end()) {

			// Serialiser le compte ferme
			//
			m_comptesFermes[j->first]->serialize(ar);
			j++;
		}

		// Parcourir le dictionnaire des comptes client
		//
		/*map <string, list <CompteBancaire*> >::iterator m= m_clients.begin();
		while (m != m_clients.end())
		{
			//printf("%d",m_clients.size());
			
			list <CompteBancaire*> L = m->second;

			printf("%d",L.size());
			list <CompteBancaire*>::iterator p=L.begin(); 
			while( p != L.end());
			{
			
				CompteBancaire* bC = new CompteBancaire; 

				bC = *p;
				// Serialiser le compte client
				//
				bC->serialize(ar); 				
				p++;
			}			
			m++;						
		}*/

		// Parcourir le dictionnaire des comptes client
		//
		/*map <string, list <CompteBancaire*> >::iterator m= m_clients.begin();
		while (m != m_clients.end())
		{
			// Recuperation du char* dans le string pour client
			// -> string : type non defini dans Archive
			//
			int tailleClient = m->first.size();
			char* nomClient = new char[tailleClient+1]; 
			strcpy(nomClient, m->first.c_str());

			int size = (m->second).size();
					
			// Sauvegarder les attributs prédéfinis
			//
			ar << tailleClient << nomClient << size;
			
			list <CompteBancaire*>* L = new list <CompteBancaire*>;
			L=m->second;
			list <CompteBancaire*>::iterator p=L.begin(); 
			while( p != L.end());
			{
				// Serialiser le compte client
				//
				(*p)->serialize(ar); 				
				p++;
			}			
			m++;
		}*/
   }
   else 
   {

	    // Restaurer les attributs prédéfinis
	    //
		int taille =0;

		int nombreCC;
		int nombreCE;
		int nombreCF;
		int nombreC;
		int nombreCpt;

		int nombreCptClient;
		int tailleClient=0;

		ar >> m_numeroGuichet >> taille;

		char* adresseAgence = new char[taille+1];
		if (adresseAgence == NULL) throw -1.0;

		adresseAgence[taille] = NULL;
		
		ar >> adresseAgence ;

		m_adresseAgence = adresseAgence;
		
		
		// Restaurer le nombre de compte
		//
		ar >> nombreCC >> nombreCE >> nombreCF;
		ar >> nombreC >> nombreCpt;


		// Traiter le cas des relations de composition
	    //
		// Parcourir le dictionnaire des comptes courant
		//
		
		for(int i=0; i < nombreCC; i++) {
			CompteCourant* cc= new CompteCourant;

			// Serialiser le compte courant
			//
			cc->serialize(ar);
			m_comptesCourant[i] = cc;
		}
		
		// Parcourir le dictionnaire des comptes epargne
		//
		
		for(int j=0; j < nombreCE; j++) {
			CompteEpargne* ce= new CompteEpargne;

			// Serialiser le compte epargne
			//
			ce->serialize(ar);
			m_comptesEpargne[j] = ce;
		}

		// Parcourir le dictionnaire des comptes ferme
		//	       
		for(int k=0; k < nombreCF; k++) {
			CompteBancaire* cf = new CompteBancaire;

			// Serialiser le compte ferme
			//
			cf->serialize(ar);
			m_comptesFermes[k] = cf;
		}

		// Parcourir le dictionnaire des comptes client
		//
		/*CompteBancaire* bC = new CompteBancaire; 
		for(int m=0; m < nombreComptesClients; m++)
		{
			for(int n=0; n < nombreComptes; n++)
			{
				// Serialiser le compte client
				//
				bC = m_clients[]; 
				bC->serialize(ar); 								
			}									
		}*/

		// Parcourir le dictionnaire des comptes client
		//
	   /* for(int m=0; m < nombreC ; m++)
		{
			ar >> tailleClient;

			char* nomClient = new char[tailleClient+1];
			if (nomClient == NULL) throw -1.0;

			nomClient[tailleClient] = NULL;

			ar >> nomClient >> nombreCptClient;

			list <CompteBancaire*> L;

			for( int n = 0; n < nombreCptClient; n++)
			{
				CompteBancaire* ccl = new CompteBancaire;

				ccl->serialize(ar);

				L.push_back(ccl);
			}

			m_clients[nomClient]=L;
			L.clear();
		}*/


   }
} 














