#include <list>
#include <iostream>
using namespace std;

// Visualiser une liste de reel
//
void visualiser (char* titre, list<float>& cible) {
	int taille= cible.size();
	cout << titre << "[";
	if (taille==0) {cout << "]"; return;}
	list<float>::iterator k= cible.begin();
	while (taille >1)
	{cout <<  *k++ <<",  "; taille--;} 
	cout  << *k  << "]";
}

// Moyenne d'une liste de reel
//
float moyenne (list<float>& notes)
{
	list<float>::iterator k= notes.begin();
	float somme=0.0f; 
	
	while (k != notes.end()) somme += *k++; 
	return somme/notes.size();
}	

// predicat pour remove_if
//
bool infA10 (const float& value) { return (value<10); }

// Main
//
int main ()
{
	//Créer une liste
	//
	list <float>  exemple, travail, transfert;
	
	//Créer un itterateur
	//
	list <float>::iterator i= exemple.begin();
	
	// Initialiser une Liste
	//
	exemple.insert(i, 17);
	exemple.insert(i, 2, 14);
	exemple.insert(i, 3, 11);
	exemple.insert(i, 22);
	exemple.insert(i, 2);
	
	
	// Visualiser une liste d’entiers
	//
	visualiser("Ma Liste", exemple);
	cout << endl;
	
	// Parcourir une liste de réels
	//
	cout << "Moyenne : " << moyenne(exemple) << endl;

	// Dupliquer une liste
	//
	travail= exemple;
	
	// Comparer deux listes entre elles
	//
	cout  <<  "A == B : " <<  (travail==exemple) << endl;
	
	// Insérer un nouvel élément
	//
	i--;i--;
	exemple.insert(i, -44);
	
	// Supprimer un élément cible
	//
	i--;
	i=exemple.erase(i);
	
	// Supprimer une valeur cible
	//
	exemple.remove(14);
	
	// Supprimer les doublons consécutifs
	//
	exemple.unique();
	
	// Trier une liste (ordre croissant)
	//
	exemple.sort();

	// Inverser une liste
	//
	exemple.reverse();
	
	// Transférer le contenu d’une liste
	//
	transfert.swap(exemple);
	
	// Ajouter en queue
	//
	travail.push_back(12);
	
	// Ajouter en tete
	//
	travail.push_front(12);
	
	// Supprimer queue
	//
	travail.pop_back();
	
	// Supprimer tete
	//
	travail.pop_front();
	
	// Supprimer conditionnel
	//
	travail.remove_if(infA10);
	
	
	// Transfere une liste dans une autre
	// Transfere un element d'une liste dans une autre
	// Transfere en debut ou fin une autre liste dans une liste
	//								   Actuelement
	travail.unique();	
	i=travail.begin();				// transfert= 22, 17, 11, 2	travail= 17, 14, 11, 22

									
	travail.splice(i, transfert);	// met tt les element dans l'autre liste
									// transfert= ø	travail= 22,  17,  11,  2,  17,  14,  11,  22
	
	i=travail.begin(); i++; i++; i++;					
	transfert.splice(transfert.begin(), travail, i);	// met un element dans l'autre liste	
														// transfert= 2	travail= 22,  17,  11,  17,  14,  11,  22
	
	i=travail.begin(); advance(i, 2);							
	travail.splice(travail.begin(), travail, i, travail.end());	// met en queue, la tete
																// transfert= 2	travail= 11,  17,  14,  11,  22,  22,  17

	// Taille de liste
	//
	cout << "Size : " << travail.size() << endl;
	
	// Vide ou pas ?
	//
	cout << "Vide : " << travail.empty() << endl;
	
	// Vide une liste
	//
	travail.clear();
	
	cout << "Vide : " << travail.empty();
	
	return 0;
}