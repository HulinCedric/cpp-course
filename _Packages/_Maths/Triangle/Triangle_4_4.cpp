//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Maths
//
// Classe Triangle - Methode Orthocentre et barycentre
//
// Auteur : C.Fouco
//
#include "Triangle.h"

Point* Triangle::orthocentre()
{
	// Cas particulier d'un triangle rectangle
	//
	if (rectangle())
	{
		for(int i=1; i <= 3; i++)
		if (*angle(*sommet(i)) == PI/2)	return sommet(i);
	}

	// Creer les point d'intersections des hauteurs
	//
	Point* pI= NULL;
	Point* pI2= NULL;

	// Creer le segment coorespondant a la premiere hauteur
	//
	Segment* S = (hauteur(1));

	// Creer les points correspondant aux extremitÈes du segment
	//
	Point** pR = (S->extremites());
	if (pR==NULL) throw -1.0;
	
	// CrÈer la droite correspondante
	//
	Droite D1(*pR[0],*pR[1]);

	// Supprimer les points de travail
	//
	delete pR[0];
    delete pR[1];
    delete[] pR;

	// Creer le segment coorespondant a la seconde hauteur
	//
	Segment* S2 = (hauteur(2));

	// Creer les points correspondant aux extremitÈes du segment
	//
	Point** pR2 = (S2->extremites());
	if (pR2==NULL) throw -1.0; 
	
	// CrÈer la droite correspondante
	//
	Droite D2(*pR2[0], *pR2[1]);

	// Supprimer les points de travail
	//
	delete pR2[0];
    delete pR2[1];
    delete[] pR2;

	// Determiner le point d'intersection entre deux lignes
	//
	pI = D1.intersection(D2);

	// Creer le segment coorespondant a la troisieme hauteur
	//
	Segment* S3 = (hauteur(3));

	// Creer les points correspondant aux extremitÈes du segment
	//
	Point** pR3 = (S3->extremites());
	if (pR3==NULL) throw -1.0; 
	
	// CrÈer la droite correspondante
	//
	Droite D3(*pR3[0], *pR3[1]);

	// Supprimer les points de travail
	//
	delete pR3[0];
	delete pR3[1];
	delete[] pR3;	

	// Determiner le point d'intersection entre deux lignes
	//
	pI2 = D1.intersection(D3);

	// Si les deux points d'intersections on retourne le point
	//
	if( pI == pI2) return pI;
	
	return pI;

}

Point*   Triangle::barycentre  ()
{
	// Initialisation des point de construction des	medianes
	//
	Point** pMediane1= mediane(1)->extremites();
	Point** pMediane2= mediane(2)->extremites();
	Point** pMediane3= mediane(3)->extremites();
	
	// Controle de la validiter de l'allocation dynamique des points
	//
	if (pMediane1 == NULL) throw -1.0;
	if (pMediane2 == NULL) {	delete pMediane1[0]; 
								delete pMediane1[1]; 
								delete[] pMediane1; 
								throw -1.0;
							}
	if (pMediane3 == NULL) {	delete pMediane1[0]; 
								delete pMediane1[1]; 
								delete[] pMediane1;
								delete pMediane2[0]; 
								delete pMediane2[1]; 
								delete[] pMediane2; 
								throw -1.0;
							}
	
	// Contruction des droites avec les points des miedianes
	//
	Droite* pDroite1= new Droite(*pMediane1[0], *pMediane1[1]);
	Droite* pDroite2= new Droite(*pMediane2[0], *pMediane2[1]);
	Droite* pDroite3= new Droite(*pMediane3[0], *pMediane3[1]);
	
	// Suppression des point de constructions des medianes
	//
	delete pMediane1[0]; 
	delete pMediane1[1]; 
	delete[] pMediane1;
	delete pMediane2[0]; 
	delete pMediane2[1]; 
	delete[] pMediane2;
	delete pMediane3[0]; 
	delete pMediane3[1]; 
	delete[] pMediane3;

	// Controle de la validiter de l'allocation dynamique des droites
	//
	if (pDroite1 == NULL) throw -1.0;
	if (pDroite2 == NULL) { delete pDroite1; throw -1.0;}
	if (pDroite2 == NULL) { delete pDroite2; delete pDroite3; throw -1.0;}
	
	// Contruction des points d'intersection des medianes
	//
	Point* pPoint1= pDroite1->intersection(*pDroite2);
	Point* pPoint2= pDroite2->intersection(*pDroite3);
	
	// Suppression des droites de construction des medianes
	//
	delete pDroite1;
	delete pDroite2;
	delete pDroite3;
	
	// Controle de la validiter de l'allocation dynamique des points d'intersection
	//
	if (pPoint1 == NULL) throw -1.0;
	if (pPoint1 == NULL) { delete pPoint1; throw -1.0;}
	
	// Controle de la validiter et l'unicit√© du point d'instersection
	//
	if (*pPoint2 == *pPoint1) return pPoint1;
	
	// Suppression des points d'intersection
	//
	delete pPoint1;
	delete pPoint2;
	
	// Restitution du resultat erreur
	//
	return NULL;
}