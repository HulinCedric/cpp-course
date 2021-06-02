#include <iostream>

using namespace std;

struct personne
{
	int *age;
	char *pseudo;
};

int main ()
{
	personne p;
	
	p.pseudo = new char[20];
	cout << "Entrer votre nom : " ; cin >> p.pseudo ;
	
	p.age = new int;
	cout << "Entrer votre age : " ; cin >> *p.age ; cout << endl ;
	
	cout << "Salut," << endl << "\tj'ai " << *p.age << " ans" << endl << "et" << endl << "\tje m'appelle " << p.pseudo << endl;
   
	delete[] p.pseudo;
	
	bool majeur;
	
	if (*p.age>=18)
	{
		majeur = true;
	}
	else
	{
		majeur = false;
	}
	
	delete p.age;
	
	if (majeur)
	{
		cout << endl << "Vous etes majeur";
	}
	else
	{
		cout << endl << "Vous etes mineur";
	}
	
	return 0;
}
