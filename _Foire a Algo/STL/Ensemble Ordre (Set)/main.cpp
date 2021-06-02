#include <set>
#include <iostream>
#include <stdlib.h>
using namespace std;
#pragma warning (disable : 4786)

// Visualiser un dictionnaire
//
void visualiser(char* titre, set<char*>& cible)
{
	int taille= cible.size();
	cout << titre << endl << "{" << endl;
	if (taille==0) {cout << "}"; return;}
	set<char*>::iterator k= cible.begin();
	while (taille >1)
	{
		printf("\t");
		cout <<"<" << *k << ">" << endl; 
	    k++;
	    taille--;
	}
	printf("\t");
	cout <<"<" << *k<< ">";
	cout << endl << "}" << endl;
}

// Main
//
int main()
{
	set <char*>  couleurs, palette;	
	
	couleurs.insert("Jaune");
	couleurs.insert("Vert");
	couleurs.insert("Bleu");
	
	// Visualiser un ensemble
	//
	visualiser("Ma palette", couleurs);
	cout << endl;
	
	// Dupliquer un ensemble
	//
	palette= couleurs;
	
	// Comparer deux ensemble entre eux
	//
	cout  <<  "A == B : " <<  (palette==couleurs) << endl;
	
	// Transférer le contenu d’un ensemble
	//
	couleurs.swap(palette);
	
	return 0;
}
