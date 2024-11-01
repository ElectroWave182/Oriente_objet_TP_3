# include <iostream>
# include <vector>
using namespace std;


// 1)

int largeurMax (vector <string> chaines)
{
	
	int maxi = 0;
	int taille;
	
	for (string chaine: chaines)
	{
		taille = chaine.length ();
		
		if (taille > maxi)
		{
			maxi = taille;
		}
	}
	
	return maxi;
	
}


string repeat (string chaine, int nbRepetitions)
{

	string total = "";
	for (int _ = 0; _ < nbRepetitions; _ ++)
	{
		total += chaine;
	}
	
	return total;
	
}


void afficheVecteur (vector<string> vecteurTexte, bool affIndice = true)
{
	
	// 3)

	int chaineMax = largeurMax (vecteurTexte);
	int tailleVecteur = vecteurTexte.size ();
	int taille;
	string affichage;
	
	if (! affIndice)
	{
		cout
			<< repeat ("-", chaineMax + 4)
			<< '\n'
		;
	}
	
	for (int indice = 0; indice < tailleVecteur; indice ++)
	{
		taille = vecteurTexte[indice].length ();
		affichage = vecteurTexte[indice];
		
		if (affIndice)
		{
			affichage =
				"Indice : "
				+ to_string (indice)
				+ ", "
				+ affichage
			;
		}
		else
		{
			affichage =
				"| "
				+ affichage
				+ repeat (" ", chaineMax - taille)
				+ " |"
			;
		}
		
		cout
			<< affichage
			<< '\n'
		;
	}
	
	if (! affIndice)
	{
		cout
			<< repeat ("-", chaineMax + 4)
			<< "\n\n"
		;
	}

}


int main ()
{

	vector <string> quelconque = {"hello", "world", "j'ai", "pas", "d'idée"};
	vector <string> monoElement = {"good bye"};
	vector <string> vide = {};
	
	afficheVecteur (quelconque);
	afficheVecteur (monoElement, false);
	afficheVecteur (vide, true);
	
	
	// 2)
	
	cout
		<< "Largeur maximale : "
		<< largeurMax (quelconque)
		<< "\n\n"
	;
	
	afficheVecteur (quelconque, false);
	quelconque.push_back ("anticonstitutionnellement");
	afficheVecteur (quelconque, false);
	
	
	return 0;
	
}
