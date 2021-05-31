//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2007_2008 - Package _Maths
//
// Classe LigneBrisee - Tests unitaires de la persistance
//                      (Cas nominaux)
//
// Auteurs : N. Agostini,  C. Anfossi,    R. Brzokewicz,
//           R. Cochonot,  T. De Freyman, M. Ferrante,
//           O. Giammetta, J. Jot,        C. Loaec,
//           I. Mahjoub,   P. Saramito,   J. Scoffier.
//
#include "LigneBrisee.h"
#include "T:\_Tests\Tests.h"

void main() {
	
	Tests::Begin("_Maths.LigneBrisee", "1.0.0");
	
		Tests::Design("Controle de la persistance", 3);
		
			Tests::Case("Persistance dans le repertoire courant"); {

				Point A(4, -3.8), B(0, 1), C(-2, 5.5), D(4.5, -9);
				LigneBrisee L1(A, B), L2(C, D), LResultat;
				
				_Archives::init();
				
				L1.enregistrer("L1.dat"); LResultat.restaurer("L1.dat");
				Tests::Unit(L1.toString(), LResultat.toString());
				
				L2.enregistrer("L2.dat"); LResultat.restaurer("L2.dat");
				Tests::Unit(L2.toString(), LResultat.toString());
			}
			
	Tests::End();
}
