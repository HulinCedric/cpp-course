//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Archives
//
// Classe Archive - Tests unitaires de la surcharge des operateurs
//                  << et >> pour le type char* (Cas nominaux)
//
// Auteur : A. Thuaire
//
#include "Archive.h"
#include "T:\_Tests\Tests\Tests.h"

void main()
{

   Tests::Begin("_Archives.Archive", "1.2.0");

   _Archives::init();

   Tests::Design("Controle des operateurs << et >> (sur type char*)", 3);

   Tests::Case("Cas d'une chaine alphabetique");
   {
      File fOut("f1.txt", _Archives::getModeWrite());
      File fIn("f1.txt", _Archives::getModeRead());
      Archive arS(fOut, _Archives::getModeStore());
      Archive arL(fIn, _Archives::getModeLoad());

      char *pSource = "abcd";
      char *pCible = NULL;

      arS << pSource;
      arS.close();
      arL >> pCible;
      arL.close();

      Tests::Unit(pSource, pCible);
   }

   Tests::Case("Cas d'une chaine numerique");
   {
      File fOut("f2.txt", _Archives::getModeWrite());
      File fIn("f2.txt", _Archives::getModeRead());
      Archive arS(fOut, _Archives::getModeStore());
      Archive arL(fIn, _Archives::getModeLoad());

      char *pSource = "1234";
      char *pCible = NULL;

      arS << pSource;
      arS.close();
      arL >> pCible;
      arL.close();

      Tests::Unit(pSource, pCible);
   }

   Tests::Case("Cas d'une chaine alphanumerique");
   {
      File fOut("f3.txt", _Archives::getModeWrite());
      File fIn("f3.txt", _Archives::getModeRead());
      Archive arS(fOut, _Archives::getModeStore());
      Archive arL(fIn, _Archives::getModeLoad());

      char *pSource = "ab123";
      char *pCible = NULL;

      arS << pSource;
      arS.close();
      arL >> pCible;
      arL.close();

      Tests::Unit(pSource, pCible);
   }

   Tests::Case("Cas d'une chaine avec des espaces");
   {
      File fOut("f4.txt", _Archives::getModeWrite());
      File fIn("f4.txt", _Archives::getModeRead());
      Archive arS(fOut, _Archives::getModeStore());
      Archive arL(fIn, _Archives::getModeLoad());

      char *pSource = "ab 123";
      char *pCible = NULL;

      arS << pSource;
      arS.close();
      arL >> pCible;
      arL.close();

      Tests::Unit(pSource, pCible);
   }

   Tests::Case("Cas d'une chaine avec des tabulations");
   {
      File fOut("f5.txt", _Archives::getModeWrite());
      File fIn("f5.txt", _Archives::getModeRead());
      Archive arS(fOut, _Archives::getModeStore());
      Archive arL(fIn, _Archives::getModeLoad());

      char *pSource = "ab		123";
      char *pCible = NULL;

      arS << pSource;
      arS.close();
      arL >> pCible;
      arL.close();

      Tests::Unit(pSource, pCible);
   }

   Tests::End();
}
