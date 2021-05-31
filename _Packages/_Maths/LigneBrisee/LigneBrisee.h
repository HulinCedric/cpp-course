//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe LigneBrisee : Ensemble de points du plan euclidien
//
// Edition A : Specifications techniques par A. Thuaire
//    + Version 1.0.0 : Version initiale
//
// Auteurs : C.Fouco
//


#ifndef _Segment_
#include "../Segment/Segment.h"
#endif

#include <string.h>

#define _LigneBrisee_

class LigneBrisee //: public Object
{
	
	private :

		Point** m_pSommets;

	public :
	
		LigneBrisee();
		LigneBrisee(const Point&, const Point&);
		LigneBrisee(Point*, Point*);
		LigneBrisee(Point[], int);
		LigneBrisee(Point**);
		LigneBrisee(const Segment&);
		LigneBrisee(const LigneBrisee&);
		~LigneBrisee();

		int		cardinal()		const;
		Point*	premierSommet()	const;
		Point*	dernierSommet()	const;
		double	longueur()		const;		
	
		LigneBrisee& operator =(const LigneBrisee&);
	
		bool operator ==(const LigneBrisee&);
		bool operator !=(const LigneBrisee&);

		LigneBrisee* operator +=(const LigneBrisee&);
		LigneBrisee* operator +=(const Point&);
		LigneBrisee* operator +=(const Point*); // A CODER
		
	
		LigneBrisee* operator -=(const LigneBrisee&);
		LigneBrisee* operator -=(const Point&);

	
		Point* operator [](int);
		LigneBrisee* operator ()(int,int);	// A CODER
	

	
		//SERVICE
		bool appartient(const Point&) const;
		bool inclus (const LigneBrisee&) const;		// FAIT
	
		//void serialize(Archive&);
	
		char* toString();
};
