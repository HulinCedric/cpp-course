//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2007_2008 - Package _Maths
//
// Classe LigneBrisee - Surcharge de la m�thode serialize
//
// Auteurs : N. Agostini,  C. Anfossi,    R. Brzokewicz,
//           R. Cochonot,  T. De Freyman, M. Ferrante,
//           O. Giammetta, J. Jot,        C. Loaec,
//           I. Mahjoub,   P. Saramito,   J. Scoffier.
//
#include "LigneBrisee.h"

// Serialisation des instances
//
void LigneBrisee:: serialize(Archive& ar) {
	
	if(ar.isStoring()) {

		// Enregistrer le cardinal
		//
		ar << cardinal();

		for(int i=0; i<cardinal(); i++) {

			// Enregistrer l'abscisse et l'ordonn�e de chaque point
			//
			ar << m_pSommets[i]->abscisse();
			ar << m_pSommets[i]->ordonnee();
		}
	}

	else {

		// D�clarer la variable cardinal et restaurer celui-ci
		//
		int cardinal;
		ar >> cardinal;

		// Allouer le tableau de points
		//
		Point* pT = new Point[cardinal];
		if(pT == NULL) throw -1.0;

		// D�clarer la variable abscisse et ordonnee
		//
		double abscisse, ordonnee;

		for(int i=0; i<cardinal; i++) {

			// Restaurer la valeur de l'abcisse et de l'ordonn�e de chaque point
			//
			ar >> abscisse;
			ar >> ordonnee;

			// Ajouter au tableau de points le point que l'on vient de restaurer
			//
			pT[i] = Point(abscisse, ordonnee);
		}

		// D�clarer et initialiser une ligne bris�e avec le tableau de points
		//
		LigneBrisee LResultat(pT, cardinal);

		// Utiliser de l'op�rateur = pour transf�rer la ligne bris�e dans l'objet support
		//
		*this = LResultat;

		// Lib�rer la m�moire allou�e pour le tableau de points
		//
		delete[] pT;
	} 
}