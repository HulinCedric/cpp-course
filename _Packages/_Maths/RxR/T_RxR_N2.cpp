//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe RxR - Tests unitaires des accesseurs 
//              (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "RxR.h"
#include "T:\_Tests\Tests\Tests.h"

void main () {

   Tests::Begin("_Maths.RxR", "2.0.0");

   Tests::Design("Controle des accesseurs", 3);

      Tests::Case("Methode abscisse"); {
      RxR z1(4,-7.1), z2(11, 9.81), z3(-1.34, 2.55), z4(-77.12, -22.13);
         
         Tests::Unit(4.0,    z1.abscisse());
         Tests::Unit(11.0,   z2.abscisse());
         Tests::Unit(-1.34,  z3.abscisse());
         Tests::Unit(-77.12, z4.abscisse());
      }

      Tests::Case("Methode ordonnee"); {   
      RxR z1(4,-7.1), z2(11, 9.81), z3(-1.34, 2.55), z4(-77.12, -22.13);
         
         Tests::Unit(-7.1,   z1.ordonnee());
         Tests::Unit(9.81,   z2.ordonnee());
         Tests::Unit(2.55,   z3.ordonnee());
         Tests::Unit(-22.13, z4.ordonnee());
      }
      
      Tests::Case("Methode rho"); {
      RxR z1(1, 0), z2(0, 1), z3(-2, 0), z4(0, -7);
      RxR z5(1, 1), z6(2, 1), z7(-2, 1), z8(-2, -3);
         
         Tests::Unit(1.0, z1.rho());
         Tests::Unit(1.0, z2.rho());
         Tests::Unit(2.0, z3.rho());
         Tests::Unit(7.0, z4.rho());

         Tests::Unit(sqrt(2.0),  z5.rho());
         Tests::Unit(sqrt(5.0),  z6.rho());
         Tests::Unit(sqrt(5.0),  z7.rho());
         Tests::Unit(sqrt(13.0), z8.rho());
      }

      Tests::Case("Methode teta"); {
      RxR z0, z1(0, 1), z2(-1, 0), z3(1, 0), z4(0, -1), z5(1, 1);
      RxR z6(-1, 1), z7(-1, -1), z8(1, -1); 
         
         Tests::Unit(PI/2, z0.teta());	  
         Tests::Unit(PI/2, z1.teta());
         Tests::Unit(PI, z2.teta());
         Tests::Unit(0., z3.teta());

         Tests::Unit(-PI/2,  z4.teta());
         Tests::Unit(PI/4,   z5.teta(), EPSILON);
         Tests::Unit(3*PI/4, z6.teta(), EPSILON);
         Tests::Unit(5*PI/4, z7.teta(), EPSILON);
         Tests::Unit(-PI/4,  z8.teta(), EPSILON);
      }

   Tests::End();
}
