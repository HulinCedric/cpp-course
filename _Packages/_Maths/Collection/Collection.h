//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Collection : agregat d'elements, non necessairement uniques
//
// Edition A    : TP_10  
//    + Version 1.0.0  : version initiale
//    
// Auteur : A. Thuaire
//
#include <string.h>
#ifndef _Maths_
#include "..\_Maths\_Maths.h"
#endif

#ifndef _Object_
#include "T:\_Archives\Object\Object.h"
#endif

typedef char* fToString(void*);

#define _Collection_

class Collection: public Object{
private :
	void**    m_pElements;       

public :

	// ------ Constructeurs et destructeur
	//
	Collection ();
	Collection (const Collection&);
	~Collection();

	// ------ Predicats predefinis
	//
	inline bool neutre() const {return m_pElements != NULL && 
									   m_pElements[0]==NULL;} 
	inline bool ok()     const {return m_pElements != NULL;}
	inline bool nok()    const {return !ok();}		

	// ------ Surcharges d'operateurs
	//
	Collection& operator += (void* const);
	Collection& operator -= (void* const);

	void*       operator [] (int) const;

	// ------ Services
	//
	void  vider()                const;
	int   cardinal ()            const;
	bool  designe  (void* const) const;
	char* toString (fToString*);

	void serialize (Archive&);

};



