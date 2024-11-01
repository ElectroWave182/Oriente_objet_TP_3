# include <iostream>
# include <vector>
using namespace std;


// 2) et 3)

void afficheVecteur (vector<string> vecteurTexte, bool affIndice = true)
{

	int taille = vecteurTexte.size ();
	for (int indice = 0; indice < taille; indice ++)
	{
		if (affIndice)
		{
			cout
				<< "Indice : "
				<< indice
				<< ", "
			;
		}
		
		cout
			<< "Element : "
			<< vecteurTexte[indice]
			<< '\n'
		;
	}

}


int main ()
{

	// 1)

	vector <string> quelconque = {"hello", "world", "j'ai", "pas", "d'idée"};
	vector <string> monoElement = {"good bye"};
	vector <string> vide = {};
	
	
	// 4)
	
	afficheVecteur (quelconque);
	afficheVecteur (monoElement, false);
	afficheVecteur (vide, true);
	
	
	return 0;
	
}
