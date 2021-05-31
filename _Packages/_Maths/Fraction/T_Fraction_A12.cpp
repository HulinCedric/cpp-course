//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Fraction - Tests unitaires de l'operateur /= 
//                   (cas d'anomalies)
//
// Auteur : C.Fouco
//
#include "Fraction.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.Fraction", "2.3.0");

   Tests::Design("Controle d'anomalies de l'operateur /=", 2);
	
      Tests::Case("Division par une fraction nulle"); { 
      Fraction f1(2,3), f2(0);
    
          try {f1/=f2;}
          catch(double e) {Tests::Unit(-3.0, e);}
      }

   Tests::End();
}
