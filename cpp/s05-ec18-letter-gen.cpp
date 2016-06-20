/*Exercice 18 : Générateur automatique de lettres (fonctions et chaînes de caractères, niveau 1)
Cet exercice correspond à l'exercice n°16 (pages 54 et 217) de l'ouvrage C++ par la pratique (3e édition, PPUR).

Le but de cet exercice est d'écrire un programme nommé lettre.cc, qui constituera un générateur automatique (très simpliste) de lettres.

    Écrivez tout d'abord une fonction genereLettre (sans argument, et sans valeur de retour). Cette fonction devra simplement produire la sortie suivante à l'écran :
    (ne vous occupez pas de la mise en évidence)

    Bonjour chère Mireille,
    Je vous écris à propos de votre cours.
    Il faudrait que nous nous voyons le 18/12 pour en discuter.
    Donnez-moi vite de vos nouvelles !
    Amicalement, John.

    Invoquez (appelez) simplement la fonction genereLettre depuis la fonction principale main, compilez votre programme et assurez vous de son fonctionnement correct.
    Modifiez maintenant la fonction genereLettre, de manière à rendre paramétrables les parties mises en évidence dans le texte précédant. Il vous faudra pour cela passer
    un certain nombre d'arguments à la fonction, de manière à spécifier :
        La formulation adaptée pour l'entrée en matière ( chère pour un destinataire féminin, et cher pour un destinataire masculin). Ce choix devra être fait en fonction
    de la valeur d'un argument booléen (masculin ou feminin) ou énuméré (sexe).
        Le nom du destinataire, nommé par exemple destinataire
        Le sujet de la lettre (paramètre nommé sujet)
        La date du rendez-vous sous forme de deux paramètres entiers, l'un pour le jour et l'autre pour le mois
        La formule de politesse (paramètre politesse)
        et le nom de l'auteur (auteur).
    La fonction aura donc 7 paramètres.

    Invoquez la fonction au moins deux fois de suite depuis le main, en paramétrant les appels de sorte à produire la lettre précédente, et la réponse ci-dessous :

    Bonjour cher John,
    Je vous écris à propos de votre demande de rendez-vous.
    Il faudrait que nous nous voyons le 16/12 pour en discuter.
    Donnez-moi vite de vos nouvelles !
    Sincèrement, Mireille.

Note : On ne vous demande pas de faire saisir les différents arguments au clavier par l'utilisateur, juste d'appeler deux fois la fonction avec les bons arguments dans le main.
*/
#include <iostream>
#include <string>
using namespace std;

string toName(const string& name)
{
	string ret(name);

	if ((ret[0] >= 'a') && (ret[0] <= 'z'))
		ret[0] += 'A' - 'a';

	return ret;
}

string toDate(int date)
{
	string ret(to_string(date));

	if (date < 10)
		ret = "0" + ret;

	return ret;
}

void genereLettre(const string& dst,
                  bool homme,
                  const string& objet,
                  int jour,
                  int mois,
                  const string& formule,
                  const string& src)
{
	string lettre = "Bonjour " + string(homme?"cher":"chère") + " "
		+ toName(dst) + ",\n";
	lettre += "Je vous écris à propos de votre " + objet + ".\n";
	lettre += "Il faudrait que nous nous voyons le " + toDate(jour) + "/"
		+ toDate(mois) + " pour en discuter.\n";
	lettre += "Donnez-moi vite de vos nouvelles !\n";
	lettre += toName(formule) + ", " + toName(src) + ".\n";

	cout << lettre << endl;
}

int main()
{
	genereLettre("mireille", false, "cours", 8, 12, "amicalement", "john");
	genereLettre("john", true, "demande de rendez-vous", 16, 12, "sincerement",
		"mireille");

	return 0;
}
