//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Banque
//
// Classe Titulaire : description du titulaire d'un compte bancaire
//
// Edition  A   : TP_4
//    + Version 1.0.0  : version initiale
//    + Version 1.1.0  : introduction de la classe _Banque
//
// Auteur : A. Thuaire
//
# include "..\_Banque\_Banque.h"

#define _Titulaire_

class Titulaire: public Object{
private :

char* m_pNom;
char* m_pPrenom;
char* m_pDateNaissance;
char* m_pAdresse;

public :
Titulaire();
Titulaire(char* const, char* const, char* const, char* const);
Titulaire(const Titulaire&);
~Titulaire();

inline bool neutre() const {return strlen(m_pNom)==1;}
inline bool ok()     const {return m_pNom != NULL;}
inline bool nok()    const {return !ok();}

char* nom()           const;
char* prenom()        const;
char* dateNaissance() const;
char* adresse()       const;

void  modifierAdresse(char* const);

Titulaire& operator =(const Titulaire&);

bool  operator ==(const Titulaire&);
bool  operator !=(const Titulaire&);

char*  toString();

void serialize (Archive&);

};


