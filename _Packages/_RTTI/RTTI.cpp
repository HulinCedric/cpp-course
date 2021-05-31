//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Mecanisme RTTI
//
// RTTI - Exemple de mise en oeuvre du mecanisme
//        La mise en oeuvre du RTTI necessite de compiler le projet C++ 
//        avec l'option "Enable RTTI"
// 
//        -> Menu Project -> Item Setting -> Onglet C/C++
//           Selectionner : Categorie / "C++ langage"
//           Cocher "Enable RTTI"
//
// Auteur : A. Thuaire
//
#include <iostream>
//#include <typeinfo>

class Mere {
public:
    virtual ~Mere() {return;}   // Il faut au moins une methode virtuelle
};

class Fille : public Mere {
public:
    virtual ~Fille() {return;}
};

int main() {
Fille* pF = new Fille;
    
    // Transtypage dynamique implicite ascendant
    //
    Mere* pM1 = pF;
    printf("Type natif= %s\n", typeid(*pM1).name()) ;

    // Transtypage par pointeur banalise puis transtypage ascendant
    //
    void* pW  = pF;
    Mere* pM2 = (Mere*)pW;
    printf("Type natif= %s\n", typeid(*pM2).name()) ;

    // Transtypage par pointeur banalise puis affectation a un 
    // pointeur sur type predefini
    //
    void* pZ  = pF;
    char* pC = (char*)pZ;
    printf("Type natif= %s\n", typeid(*pC).name()) ;
}
