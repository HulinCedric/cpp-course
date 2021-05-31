//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Librairie STL
//
// Classe list - Tests unitaires des methodes de modification
//               (Cas nominaux)
//
// Auteur : A. Thuaire
//
#pragma warning (disable : 4786)
#include <iostream>
#include <list>
#include <string>
#include <complex>

using namespace std;

#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("STL.list", "?");
   
      Tests::Design("Controle des methodes de modification", 3);
   
         Tests::Case("Insertion dans une liste de nombres entiers"); {
         list <int> L;
         list <int>::iterator i;
         int rang;

            L.push_back(-7);
            L.push_back(3);
            L.push_back(-1);
            L.push_back(8);
            L.push_back(0);
            L.push_back(-7);
            L.push_back(6);
	  
            // Inserer en premiere position
            //
            L.push_front(100);
            i=L.begin(); Tests::Unit(100,*i);

            // Inserer en derniere position
            //
            L.push_back(-100);		 
            i=L.end(); Tests::Unit(-100,*--i);

            // Inserer en 3eme position
            //
            for (rang=1, i=L.begin(); rang<=3; rang++, i++);
            L.insert(i, 1111);
            Tests::Unit(1111,*--i);
         }

         Tests::Case("Remplacement dans une liste de messages"); {
         list <string> L;
         list <string>::iterator i;
         int rang;

            L.push_back(string("rouge"));            // "mauve"
            L.push_back(string("jaune"));
            L.push_back(string("vert"));
            L.push_back(string("bleu"));             // "noir"
            L.push_back(string("blanc"));            // "gris"

            // Remplacer en premiere position
            //	  
            i=L.begin(); L.erase(i);
            L.push_front(string("mauve"));	  
            Tests::Unit("mauve",(char*)L.front().c_str());

            // Remplacer en derniere position
            //	  
            i=L.end(); L.erase(--i);
            L.push_back(string("gris"));	  
            Tests::Unit("gris",(char*)L.back().c_str());

            // Remplacer en 4eme position
            //	
            for (rang=1, i=L.begin(); rang<4; rang++, i++);
            L.erase(i);

            for (rang=1, i=L.begin(); rang<=3; rang++, i++);
            L.insert(i, "noir");
            Tests::Unit("noir", (char*)(*--i).c_str());
         }

         Tests::Case("Suppression positionnelle"); {
         complex <double> z1(3.5, 2), z2(0, -1), z3(1, 1), z4(1.25, 4);
         list < complex <double> > L;
         list <complex <double> >::iterator i;
         int rang;

            L.push_back(z1);
            L.push_back(z2);
            L.push_back(z3);
            L.push_back(z4);
	  
            // Supprimer en 3eme position
            //
            for (rang=1, i=L.begin(); rang<3; rang++, i++);
            L.erase(i);

            for (rang=1, i=L.begin(); rang<3; rang++, i++);
            Tests::Unit(1.25, (*i).real());
            Tests::Unit(4, (int)(*i).imag());

            // Supprimer en premiere position
            //
            L.pop_front();
            i=L.begin(); 
		  
            Tests::Unit(0, (int)(*i).real());
            Tests::Unit(-1, (int)(*i).imag());

            // Supprimer en derniere position
            //
            L.pop_back();
            i=L.end(); i--; 
		  
            Tests::Unit(0, (int)(*i).real());
            Tests::Unit(-1, (int)(*i).imag());
        }

        Tests::Case("Suppression avec adressage par le contenu"); {
        list <int> L;

           L.push_back(-7);
           L.push_back(3);
           L.push_back(-1);
           L.push_back(8);
           L.push_back(3);
           L.push_back(-7);
           L.push_back(3);

           // Supprimer une valeur cible unique
           //
           L.remove(-1);
           Tests::Unit(6, L.size());

           // Supprimer une valeur cible avec plusieurs occurrences
           //
           L.remove(3);
           Tests::Unit(3, L.size());
        }

   Tests::End();
}

