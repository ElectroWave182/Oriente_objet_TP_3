/*	
 *	1)
 *	
 *	Calcul a)
 *	---------
 *	→ empiler 3
 *	→ empiler /
 *	→ empiler 10
 *	→ empiler -
 *	→ empiler 23
 *	→ appliquer l'opérateur -
 *		→ dépiler 3 fois
 *		→ empiler 13
 *	→ appliquer l'opérateur /
 *		→ dépiler 3 fois
 *		→ empiler 4
 *	
 *	Calcul b)
 *	---------
 *	→ empiler 9
 *	→ empiler *
 *	→ empiler 78
 *	→ appliquer l'opérateur *
 *		→ dépiler 3 fois
 *		→ empiler 702
 *	→ empiler /
 *	→ empiler 32
 *	→ empiler +
 *	→ empiler 2
 *	→ empiler *
 *	→ empiler 233
 *	→ appliquer l'opérateur *
 *		→ dépiler 3 fois
 *		→ empiler 446
 *	→ appliquer l'opérateur +
 *		→ dépiler 3 fois
 *		→ empiler 478
 *	→ appliquer l'opérateur /
 *		→ dépiler 3 fois
 *		→ empiler 0
 *	
 *	Calcul c)
 *	---------
 *	→ empiler y
 *	→ empiler *
 *	→ empiler 30
 *	→ appliquer l'opérateur *
 *		→ dépiler 3 fois
 *		→ empiler 30y
 *	→ empiler /
 *	→ empiler 23
 *	→ empiler *
 *	→ empiler x
 *	→ empiler -
 *	→ empiler 42
 *	→ appliquer l'opérateur -
 *		→ dépiler 3 fois
 *		→ empiler 42 - x
 *	→ appliquer l'opérateur *
 *		→ dépiler 3 fois
 *		→ empiler 966 - 23x
 *	→ appliquer l'opérateur /
 *		→ dépiler 3 fois
 *		→ empiler (966 - 23x) / 30y
 */	


# include <iostream>
# include <vector>
# include <string>
using namespace std;


// 2, 3 et 4)

void displayStack
(const vector <double> & vect)
{
	
	string
		border = "\033[1;47m \033[0m",
		line = "\033[1;47m					\033[0m"
	;
	cout
		<< line
		<< "\n"
	;

	for
	(
		int i = 0;
		i < 5;
		i ++
	)
	{
		cout
			<< border
			<< 4 - i
			<< ":"
		;
		cout.width (18);
		
		if
		(
			i < 5 &&
			vect.size () + i - 5 >= 0
		)
		{
			cout
				<< vect [vect.size () + i - 5]
				<< border
				<< "\n"
			;
		}
		else
		{
			cout
				<< "--"
				<< border
				<< "\n"
			;
		}
	}
	
	cout
		<< line
		<< "\n"
	;
	
}


// 7)

void empiler
(
	vector <double> & pile,
	auto ajout
)
{
	pile.push_back (stod (to_string (ajout)));
}


// 8)

bool estOperateur
(
	string objet
)
{
	return
		objet == "+" ||
		objet == "-" ||
		objet == "*" ||
		objet == "/"
	;
}


// 9)

bool applyOperator
(
	vector <double> & pile,
	string operateur
)
{

	if (! estOperateur (operateur))
	{
		return 1;
	}
	
	double droite = pile.back ();
	pile.pop_back ();
	double gauche = pile.back ();
	pile.pop_back ();
	double resultat;
	
	cout << "gauche : " << gauche << "\ndroite : " << droite << "\n";
	switch (operateur.at (0))
	{
		
		case '+':
			resultat = gauche + droite;
			break;

		case '-':
			resultat = gauche - droite;
			break;
			
		case '*':
			resultat = gauche * droite;
			break;
			
		case '/':
			resultat = gauche / droite;
			break;
		
	}
	
	empiler (pile, resultat);
	cout
		<< gauche
		<< " "
		<< operateur
		<< " "
		<< droite
		<< " = "
		<< resultat
		<< "\n"
	;
	
	return 0;
	
}


int main ()
{

	// 5)
	
	vector <double> maPile =
	{
		69.,
		-42.,
		34.51
	};
	
	displayStack (maPile);
	
	
	// 6) Il y a pas d'erreur en fait, bouffon.
	
	// 7)
	
	empiler (maPile, 33);
	empiler (maPile, 12);
	empiler (maPile, 49);
	
	displayStack (maPile);
	
	
	// 8)
	
	cout << estOperateur ("/") << "\n";
	cout << estOperateur ("8") << "\n";
	
	
	// 10)
	
	string entree;
	while (true)
	{
		cin >> entree;
		applyOperator (maPile, entree);
	}


	return 0;
	
}
