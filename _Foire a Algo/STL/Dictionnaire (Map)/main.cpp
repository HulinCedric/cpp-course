#include <map>
#include <iostream>
#include <stdlib.h>
#include <list>
using namespace std;
#pragma warning (disable : 4786)

// Visualiser un dictionnaire
//
void visualiser(char* titre, map<char*, char*>& cible)
{
	int taille= cible.size();
	cout << titre << endl << "\t{" << endl;
	if (taille==0) {cout << "}"; return;}
	map<char*, char*>::iterator k= cible.begin();
	while (taille >1)
	{
		printf("\t\t");
		cout <<"<" << k->first << " : " << k->second << ">" << endl; 
	    k++;
	    taille--;
	}
	printf("\t\t");
	cout <<"<" << k->first << " : " << k->second << ">";
	cout << endl << "\t}";
}

// Visualiser un dictionnaire
//
void visualiser(char* titre, map<int, map<char*, char*> >& cible)
{
	int taille= cible.size();
	cout << titre << endl << "{" << endl;
	if (taille==0) {cout << "}" << endl; return;}
	int i=1;
	while (taille >1)
	{
		printf("\t");
		visualiser("Registre", cible[i]);
		cout << endl;
	    i++;
		taille--;
	}
	printf("\t");
	visualiser("Registre", cible[i]);
	cout << endl << "}" << endl;
}

// Parcourir un dictionnaire
//
float moyenne (map<char*, float>& notes)
{
	map <char*, float>::iterator k= notes.begin();
	float somme=0.0f;
	
	while (k != notes.end()) {
		somme += k->second;
		k++;
	} 
	return somme/notes.size();
}

// Main
//
int main()
{
	map <char*, char*>  annuaire, travail, transfert;
	
	annuaire["Durand "]= "04.93.77.18.00";
	annuaire["Dupuy"]  =  "04.93.66.38.76";
	annuaire["Leroy"]   =  "04.92.94.20.00";
	
	// Visualiser un dictionnaire
	//
	visualiser("Mon Annuaire", annuaire);
	cout << endl;
		
	// Dupliquer un dictionnaire
	//
	travail= annuaire;
	
	// Accéder à un élément cible
	//
	char* dupuy="Dupuy";
	cout << "Numero de Dupuy :  " << annuaire[dupuy] << endl;
	cout << "Numero de Dupuy :  " << annuaire["Dupuy"] << endl;
	
	
	// Comparer deux dictionnaires entre eux
	//
	cout  <<  "A == B : " <<  (annuaire==travail) << endl;
	
	// Supprimer un élément cible
	//
	annuaire.erase(dupuy);
	
	// Transférer le contenu d’un dictionnaire
	//
	transfert.swap(annuaire);
	
	// Connaitre la taille du dicrtionnaire
	//
	cout << "Size : " << transfert.size() << endl;
	
	// Compter les element ayant la clef spécifier
	//
	cout << "Count : " << transfert.count("Leroy") << endl;

	// Dictionnaire de Dictionnaire
	//
	map<int, map<char*, char*> > registre;
	
	registre[1]= transfert;
	registre[2]= travail;
	cout << endl;
 	
	visualiser("Registre",  registre);
	
	map < string, list <int> >  marde;
	list <int> exempele;
	list <int>::iterator e;
	map < string, list <int> >::iterator b;
	
	exempele.insert(e, 17);
	exempele.insert(e, 2, 14);
	
	marde["connard"]= exempele;
	
	b=marde.find("connard");
	
	
	
	return 0;
}
