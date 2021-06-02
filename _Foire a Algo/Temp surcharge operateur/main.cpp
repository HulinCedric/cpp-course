#include <iostream>
#include "Duree.h"

using namespace std;

ostream &operator<<( ostream &out, Duree &duree )
{
    duree.afficher(out) ;
    return out;
}

int main()
{
    Duree duree1(1, 45, 50), duree2(1, 15, 50), duree3 (0, 8, 20);
    Duree resultat;

    
    cout <<  duree1 << endl << "+" << endl << duree2 << endl << "+" << endl << duree3 << endl;

    resultat = duree1 + duree2 + duree3;

    cout << "=" << endl << resultat<< endl << endl;

	
    return 0;
}



