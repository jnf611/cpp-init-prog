#include <iostream>
#include <string>
using namespace std;

int main()
{
	int res;
	string answer;
	
	cout << "Pensez à un champignon : amanite tue-mouches, pied bleu, girolle," << endl
	<< "cèpe de Bordeaux, coprin chevelu ou agaric jaunissant." << endl << endl;

	cout << "Est-ce que votre champignon a un chapeau convexe (1 : oui, 0 : non) ? ";
	cin >> res;
	if (res) {
		// agaric jaunissant, l'amanite tue-mouches et le pied bleu
		cout << "Est-ce que votre champignon vit en forêt (1 : oui, 0 : non) ? ";
		cin >> res;
		if (res) {
			cout << "Est-ce que votre champignon a un anneau (1 : oui, 0 : non) ? ";
			cin >> res;
			if (res) {
				answer.assign("l'amanite tue-mouches");
			} else {
				answer.assign("le pied bleu");
			}
		} else {
			answer.assign("l'agaric jaunissant");
		}
	} else {
		//cèpe de Bordeaux, coprin chevelu, girolle
		cout << "Est-ce que votre champignon a des lamelles (1 : oui, 0 : non) ? ";
		cin >> res;
		if (res) {
			cout << "Est-ce que votre champignon vit en forêt (1 : oui, 0 : non) ? ";
			cin >> res;
			if (res) {
				answer.assign("la girolle");
			} else {
				answer.assign("le coprin chevelu");
			}
		} else {
			answer.assign("le cèpe de Bordeaux");
		}		
	}
	
	cout << "==> Le champignon auquel vous pensez est " << answer << endl;
}
