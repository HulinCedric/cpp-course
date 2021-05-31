//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Vecteur : modelisation de l'espace vectoriel RxR
//
// Edition A    : cours_2
//    + Version 1.0.0  : version initiale
//    + Version 1.1.0  : introduction de la surcharge des operateurs
//    + Version 1.2.0  : introduction des packages
//    + Version 1.3.0  : prise en compte du fichier header _Maths et
//                       ajout d'un constructeur normal
//
// Edition B    : travaux simulateur Trafalgar
//    + Version 2.0.0  : version initiale
//
// Edition C    : introduction de la persistance des objets
//    + Version 3.0.0  : version initiale
//   
// Auteur : A. Thuaire
//
#ifndef _Angle_
#include "..\Angle\Angle.h"
#endif

#define _Vecteur_

class Vecteur : public Object {
private :
double m_x;
double m_y;

public :

// ------ Constructeurs
//
Vecteur ();
Vecteur (double, double);
Vecteur (const RxR&, const RxR&);

// ------ Accesseurs
//
inline double abscisse () const {return m_x;}	 
inline double ordonnee () const {return m_y;}
inline double norme    () const {return sqrt(m_x*m_x + m_y*m_y);};
                                
// ------ Operateurs
//
Vecteur& operator =   (const Vecteur&);
bool     operator ==  (const Vecteur&);
bool     operator !=  (const Vecteur&);

Vecteur* operator +   (const Vecteur&);
Vecteur* operator -   (const Vecteur&);
Vecteur* operator -   ();
Vecteur* operator *   (double);
double   operator *   (const Vecteur&);

Vecteur& operator +=  (const Vecteur&);
Vecteur& operator -=  (const Vecteur&);
Vecteur& operator *=  (double);

// ------ Services
//
bool     colineaire (const Vecteur&) const;
bool     orthogonal (const Vecteur&) const;
bool     memeSens   (const Vecteur&) const;
Angle*   angle      (const Vecteur&) const;

char*    toString();

void serialize (Archive&);

};




