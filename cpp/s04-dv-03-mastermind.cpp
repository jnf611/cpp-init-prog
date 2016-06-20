/* s04e03 mastermind

Le jeu sera constitué d'une combinaison de 4 couleurs (de type char) choisies
parmi 7 : 'R', 'G', 'B', 'C', 'Y', 'M' et '.' pour le trou (pas de couleur), qui
peut ici être utilisé pour faire une combinaison, donc par exemple :
« M C . G ».

Comme au niveau de ce devoir vous n'êtes pas encore sensés maîtriser les
tableaux en C++, nous manipulerons explicitement les couleurs séparément une à
une.


3.3 Code à fournir

On vous demande dans cet exercice de fournir 6 fonctions, dont certaines très
simples (1 ligne). Certains prototypes sont déjà fournis, d'autres sont à
écrire.
*/

#include <iostream>
#include <ctime>

// pour les nombres aléatoires
#include <random>
#include <cstring> // strlen

using namespace std;

// ======================================================================
// Couleur au hasard
//- tirer_couleur : cette fonction tire une couleur au hasard parmi les couleurs
//autorisées;
std::uniform_int_distribution<int> distribution;
std::default_random_engine generateur(time(NULL)); /* NOT using std::random_device since not
                                                    * all compilers seems to support it :-( */

char tirer_couleur()
{
  static const char* const couleurs = ".RGBCYM";
  static const int nb = strlen(couleurs) - 1;

  return couleurs[distribution(generateur,
                               std::uniform_int_distribution<int>::param_type {0, nb})];
}

/* ======================================================================
- poser_question : c'est une « fonction outil » que vous n'aurez pas à utiliser
directement mais qui est utilisée par lire_couleur; elle est ici pour illustrer
l'aspect « modularisation du code »; */
char poser_question()
{
  char lu(' ');
  cout << "Entrez une couleur : ";
  cin >> lu;
  return lu;
}

// ---- prototype -------------------------------------------------------
bool couleur_valide(char c);

/* ======================================================================
- lire_couleur : demande à l'utilisateur d'entrer une couleur, dont elle vérifie
la validité grâce à une fonction couleur_valide que vous aurez à définir plus
bas; */
char lire_couleur()
{
  char lu(poser_question());
  while (not couleur_valide(lu)) {
    cout << "'" << lu << "' n'est pas une couleur valide." << endl;
    cout << "Les couleurs possibles sont : ., R, G, B, C, Y ou M." << endl;
    lu = poser_question();
  }
  return lu;
}

/* ======================================================================
- afficher_couleurs : c'est à nouveau une « fonction outil » que vous n'aurez
pas à utiliser directement; elle affiche les 4 couleurs du jeu ou d'une
proposition du joueur; */
void afficher_couleurs(char c1, char c2, char c3, char c4)
{
  cout << ' ' << c1 << ' ' << c2 << ' ' << c3 << ' ' << c4;
}

/* ======================================================================
- afficher : cette fonction permet d'afficher nb fois le caractère c; vous
devrez l'utiliser pour afficher les réponses à donner au joueur; en effet, vous
n'avez pas le droit de faire appel directement à cout dans votre code; */
void afficher(int nb, char c)
{
  while (nb-- > 0) {
    cout << c;
  }
}

// ---- prototype -------------------------------------------------------
void afficher_reponses(char c1, char c2, char c3, char c4,
                       char r1, char r2, char r3, char r4);

/* ======================================================================
- afficher_coup : affiche un coup du jeu en affichant les 4 couleurs proposées
par le joueur et la réponse correspondante; vous devrez utiliser cette fonction
dans la fonction principale qui gère le jeu (fonction jouer, voir plus bas); la
fonction afficher_coup reçoit 4 couleurs en arguments, les 4 couleurs proposées
par le joueur, et 4 caractères pour représenter la réponse; ce dernier point
sera expliqué plus bas;*/
void afficher_coup(char c1, char c2, char c3, char c4,
                   char r1, char r2, char r3, char r4)
{
  afficher_couleurs(c1, c2, c3, c4);
  cout << " : ";
  afficher_reponses(c1, c2, c3, c4,
                    r1, r2, r3, r4);
  cout << endl;
}

/* ======================================================================
- message_gagne : affiche le message à donner au joueur lorsqu'il a gagné; vous
devrez utiliser cette fonction dans la fonction principale qui gère le jeu;
cette fonction reçoit le nombre de coups joués;*/
void message_gagne(int nb_coups)
{
  cout << "Bravo ! Vous avez trouvé en " << nb_coups << " coups." << endl;
}

/* ======================================================================
- message_perdu : affiche le message à donner au joueur lorsqu'il a perdu; vous
devrez utiliser cette fonction dans la fonction principale qui gère le jeu car,
nous répétons, vous n'avez pas le droit de faire appel directement à cout dans
votre code; cette fonction reçoit les 4 couleurs du jeu
(celles qu'il fallait trouver, donc).*/
void message_perdu(char c1, char c2, char c3, char c4)
{
  cout << "Perdu :-(" << endl;
  cout << "La bonne combinaison était : ";
  afficher_couleurs(c1, c2, c3, c4);
  cout << endl;
}

/*****************************************************
 * Compléter le code à partir d'ici
 *****************************************************/

/* ======================================================================
- couleur_valide : détermine si le caractère reçu en paramètre est une couleur,
c.-à-d. s'il est soit '.', 'R', 'G', 'B', 'C', 'Y' ou  'M';*/
bool couleur_valide(char c)
{
	static const char* const couleurs = ".RGBCYM"; // this could be outside ?
	static const int nb = strlen(couleurs) - 1;

	// or a big switch with a default false ?
	for (int i = 0; i < nb; ++i)
	{
		if (c == couleurs[i])
			return true;
	}

	return false;
}

/* ======================================================================
 *  Unittest for couleur valid
 * return 1 in case of one or more errors*/
int unittest_couleur_valide()
{
	int ret = 0;
	const char input[] = "ab.RCABrc?";
	const bool expected_output[] = {false, false, true, true, true, false, true, false, false, false};
	int nb_test = sizeof(expected_output)/sizeof(expected_output[0]);

	for (int i = 0; i < nb_test; ++i)
	{
		bool res = couleur_valide(input[i]);
		if (res != expected_output[i])
		{
			cout << "couleur_valid(" << input[i] << ") = " << res
				<< " while expecting " << expected_output[i] << endl;
			ret = 1;
		}
	}

	return ret;
}

/* ======================================================================
- verifier : vérifie si la couleur reçue (type char) en premier paramètre
correspond à celle donnée en second paramètre, et si c'est le cas cette fonction
augmente de 1 le score reçu en troisième paramètre;
vous devez également faire en sorte que le second paramètre soit modifié en
quelque chose qui n'est pas une couleur (par exemple 'x') de sorte que lorsque
l'on utilise cette fonction, l'on sache que la couleur testée (ce second
paramètre, justement) a déjà été traitée positivement; on ne peut en effet pas
avoir plusieurs réponses (« bonne couleur » ou « bonne couleur bien placée »)
pour une même couleur de référence (couleur à deviner); lors du calcul de la
réponse, il faut donc marquer toute couleur de référence déjà traitée;
enfin, la fonction verifier retourne « true » si la couleur reçue en premier
paramètre correspond à celle donnée en second paramètre, et « false » dans le
cas contraire;*/
bool verifier(char c, char* r, int* score)
{
	bool ret = false;

	if (c == *r)
	{
		ret = true;
		*score++;
	}
	else
	{
		*r = 'x';
	}

	return ret;
}

/* ======================================================================
- apparier : cette fonction sert à tester une couleur proposée par rapport aux
trois couleurs de référence situées dans des autres colonnes (couleur proposée
mal placée); cette fonction doit recevoir :
    - une couleur à tester (couleur proposée);
    - trois couleurs candidates à tester (couleurs de référence); ces trois
    couleurs doivent pouvoir être modifiées par la fonction;
    - un nombre, à modifier, qui sera augmenté de 1 si la couleur proposée à
    tester correspond à l'une des trois couleurs de référence;
cette fonction doit simplement appeler verifier avec la couleur proposée à
tester et, tour à tour, chacune des trois couleurs de référence; notez
cependant bien que l'on ne teste la seconde couleur de référence que si la
couleur proposée à tester ne correspondait pas à la première couleur de
référence, et l'on ne teste la troisième couleur de référence que si aucune des
deux premières ne correspondait à la couleur proposée à tester;*/
void apparier(char c, char* r1, char* r2, char* r3, int* score)
{
	if (!verifier(c, r1, score))
	{
		if(!verifier(c, r2, score))
		{
			verifier(c, r3, score)
		}
	}
}

/* ======================================================================
- afficher_reponses : cette fonction est peut-être la plus complexe; elle
construit la réponse à apporter au joueur lorsqu'il a proposé 4 couleurs; elle
reçoit en paramètres (dans cet ordre) : les 4 couleurs proposées à tester et les
4 couleurs de référence (dans le même ordre de colonnes que celles à tester);
    - en utilisant la fonction afficher, la fonction afficher_reponses doit
    afficher autant de '#' que de couleurs proposées correctes bien placées
    (cela correspond aux petits pions noirs ou rouges dans les versions
    classiques du Mastermind), puis autant de '+' que de couleurs proposées
    présentes dans la combinaison du jeu mais mal placées (cela correspond aux
    petits pions blancs ou jaunes dans les versions classiques du Mastermind) et
    enfin autant de '-' que de couleurs proposées fausses;
    - par exemple, si le jeu est « M..R », et que le joueur propose « CYM. », il
    faudra répondre « ++-- » (le 'M' et un des trous ('.') sont effectivement
    dans le jeu, mais mal placés dans la proposition du joueur); et si le jeu
    est « RRGG », et que le joueur propose « YGGR », il faudra répondre « #++- »
    (la troisième couleur proposée, 'G', est bien placée, et il y a deux autres
    couleurs proposées qui sont justes, mais mal placées, le 'R' et l'autre
    'G');
    - pour construire la réponse, procéder comme suit :
        - tester une à une chacune des couleurs pour voir si elle est bien
        placée;
        - ensuite, une fois ces 4 tests effectués, pour chacune des couleurs
        proposées qui n'étaient pas bien placées, chercher, à l'aide de la
        fonction apparier, si elle s'apparie avec une des trois autres couleurs
        de référence (que celle à la même position);
        - afficher enfin le reste de '-' pour toutes les mauvaises couleurs;*/
void afficher_reponses(char c1, char c2, char c3, char c4,
                       char r1, char r2, char r3, char r4)
{
}

/* ======================================================================
- gagne : cette fonction très simple retourne simplement « true » si la
combinaison de couleurs proposées, donnée par ses 4 premiers arguments,
correspond exactement à celle recherchée, indiquée par ses 4 derniers arguments;
et sinon, elle retourne « false »;*/
bool gagne(char c1, char c2, char c3, char c4,
           char r1, char r2, char r3, char r4)
{
	bool gagne = false;

	if ((c1 == r1) && (c1 == r1) && (c1 == r1) && (c1 == r1))
	{
		gagne = true;
	}

	return gagne;
}

/* ======================================================================
- jouer : le cœur du jeu, combinant les autres fonctions écrites;
cette fonction devra recevoir un paramètre optionnel indiquant le nombre de
coups maximum autorisés pour le joueur; par défaut, le nombre maximum de coups
sera 8;
le déroulement de la fonction jouer est le suivant :
    - commencer par tirer 4 couleurs au hasard (à l'aide de tirer_couleur);
    cela constitue la combinaison de référence, à deviner;
    - ensuite, tant que le joueur n'a pas gagné (fonction gagne) et que le
    nombre de coups est inférieur ou égal au nombre maximum de coups :
    - demander 4 fois une couleur (fonction lire_couleur);
    - puis afficher le coup et sa réponse (fonction afficher_coup);
    - à la fin afficher le message adéquat : celui de message_gagne si le joueur
    a trouvé, et sinon, celui de message_perdu.*/
void jouer(// A remplir
          )
{
}

/* Unittest suite for all implemented functions
 * return 1 in case of one or more errors*/

int unittest()
{
	int ret = 0;

	if (unittest_couleur_valide())
	{
		cout << "ERROR unittest_couleur_valide() failed" << endl;
		ret = 1;
	}

	return ret;
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
	if (unittest())
		return 1;
	jouer();
	return 0;
}
