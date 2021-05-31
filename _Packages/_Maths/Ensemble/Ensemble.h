//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Ensemble : collection d'elements, munie d'une relation d'appartenance
//
// Edition A    : TP_9  
//    + Version 1.0.0  : version initiale
//    
// Auteur : A. Thuaire
//
#ifndef _Collection_
#include "..\Collection\Collection.h"
#endif

#define _Ensemble_

typedef bool  fEquals(void* const, void* const);
typedef void* fNew   (void* const);

class Ensemble : public Collection {
private :
       
fEquals*  m_pfEquals;       // Relation d'appartenance
fNew*     m_pfNew;          // Fonction de duplication d'un element

public :

// ------ Constructeurs
//
Ensemble ();
Ensemble (fEquals*);
Ensemble (fEquals*, fNew*);
Ensemble (const Ensemble&);

// ------ Surcharges de predicats predefinis
//
inline bool ok()  const {if (neutre()) return true; 
                         return m_pfEquals != NULL;}

inline bool nok() const {return !ok();} 

// ------ Accesseurs de consultation
//
inline bool vide () const {return neutre();}

int appartient (void* const) const;

// ------ Accesseurs de modification
//
inline void setfEquals  (fEquals* pfEquals) {m_pfEquals = pfEquals;}
inline void setfNew     (fNew*    pfNew)    {m_pfNew    = pfNew;}

// ------ Surcharges d'operateurs
//
Ensemble&   operator +=  (void* const);
Ensemble&   operator -=  (void* const);

Ensemble&   operator =  (const Ensemble&);
bool        operator == (const Ensemble&);
inline bool operator != (const Ensemble& E) {return !(*this==E);}

Ensemble*   operator +  (void* const)     const;
Ensemble*   operator +  (const Ensemble&) const;   // Union de deux ensembles
Ensemble*   operator -  (void* const)     const;
Ensemble*   operator -  (const Ensemble&) const;

// ------ Services
//
bool        inclus       (const Ensemble&) const;
Ensemble*   intersection (const Ensemble&) const;

inline bool contient (const Ensemble& E) const {return !(E.inclus(*this));}

};



