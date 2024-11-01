# include <iostream>
# include <vector>
# include <chrono> 
using namespace std;


string repeat
(
	string chaine,
	int nbRepetitions
)
{

	string total = "";
	for (int _ = 0; _ < nbRepetitions; _ ++)
	{
		total += chaine;
	}
	
	return total;
	
}


int largeurMax
(vector <auto> & chaines)
{
	
	int maxi = 0;
	int taille;
	
	for (auto chaine: chaines)
	{
		taille = to_string (chaine).length ();
		
		if (taille > maxi)
		{
			maxi = taille;
		}
	}
	
	return maxi;
	
}


void afficheVecteur
(vector <auto> & vecteurTexte)
{

	int
		tailleVecteur = vecteurTexte.size (),
		maxChaine = largeurMax (vecteurTexte),
		tailleChaine
	;
	string
		element,
		affichage
	;

	cout
		<< repeat ("-", maxChaine + 4)
		<< "\n"
	;
	
	for (int indice = 0; indice < tailleVecteur; indice ++)
	{
		element = to_string (vecteurTexte[indice]);
		tailleChaine = element.length ();
		affichage =
			"| "
			+ element
			+ repeat (" ", maxChaine - tailleChaine)
			+ " |"
		;
		
		cout
			<< affichage
			<< "\n"
		;
	}
	
	cout
		<< repeat ("-", maxChaine + 4)
		<< "\n\n"
	;

}


// 1)

void testParam
(int & i)
{
	i = 42;
}


// 2)

void testParamCopie
(int i)
{
	i = 42;
}


// 3)

void testVecteur
(
	vector <int> & reference,
	vector <int> copie
)
{
	reference.push_back (215600);
	copie.push_back (215600);
}


int main ()
{
	
	// 1)
	
	int x = 3;
	
	cout
		<< "valeur de x avant : "
		<< x
		<< "\n"
	;
	
	testParam (x);
	
	cout
		<< "valeur de x après : "
		<< x
		<< "\n\n"
	;


	// 2)
	
	x = 3;
	
	cout
		<< "valeur de x avant : "
		<< x
		<< "\n"
	;
	
	testParamCopie (x);
	
	cout
		<< "valeur de x après : "
		<< x
		<< "\n\n"
	;
	
	
	// 3)
	
	vector <int> v1 = {34, 69};
	vector <int> v2 = {34, 69};
	
	testVecteur (v1, v2);
	
	afficheVecteur (v1);
	afficheVecteur (v2);
	
	
	// 4)
	
	vector <int> grosVecteur = {};
	for (int compteur = 0; compteur < 100 * 1000; compteur ++)
	{
		grosVecteur.push_back (compteur);
	}
	
	cout << "Passage par copie...\n";
	auto start = chrono:: high_resolution_clock:: now ();
	testVecteur (v1, grosVecteur);
	auto stop = chrono:: high_resolution_clock:: now ();
	auto tempsEcoule = stop - start;
	
	cout << "Passage par reference...\n\n";
	start = chrono:: high_resolution_clock:: now ();
	testVecteur (grosVecteur, v1);
	stop = chrono:: high_resolution_clock:: now ();
	tempsEcoule = stop - start;


	return 0;
	
}
