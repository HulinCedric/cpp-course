// Auteurs : De Freyman et Giammetta
//
#ifndef _Object_
#include "T:\_Archives\Object\Object.h"
#endif

#ifndef _Point_
#include "T:\_Maths\Point\Point.h"
#endif

#ifndef _Triangle_
#include "T:\_Maths\Triangle\Triangle.h"
#endif

#ifndef _Segment_
#include "T:\_Maths\Segment\Segment.h"
#endif

#ifndef _Demi_Droite_
#include "..\DemiDroite\DemiDroite.h"
#endif

#define _Polygone_

#include <list>
using namespace std;

class Polygone : public Object {

	list <Point> m_Sommets;

public :
	Polygone();
	Polygone(const Point&, const Point&, const Point&);
	Polygone(const Triangle&);
	Polygone(const Polygone&);

	Polygone& operator +=(const Point&);

	bool appartient(const Point&);

	double distance(const Point&);

	char* toString();
	void serialize(Archive&) { }
};