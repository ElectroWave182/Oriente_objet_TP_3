# include <iostream>
# include <vector>
using namespace std;


int main ()
{

	// 1)

	vector <int> v;
	
	v.push_back (42);
	v.push_back (34);
	
	cout << v.back () << '\n';
	cout << v[1] << '\n';
	cout << v.size () << '\n';
	
	
	// 2) Non, car le vecteur prend des données de type int.
	
	
	// 3)
	
	vector <string> v2;
	
	v2.push_back ("hello");
	v2.push_back ("world");
	
	
	// 4)
	
	cout << "Affichage par indice :" << '\n';
	for (int indice = 0; indice < v2.size (); indice ++)
	{
		cout << v2[indice] << '\n';
	}
	
	cout << "Affichage par collection :" << '\n';
	for (auto element: v2)
	{
		cout << element << '\n';
	}

	return 0;

}
