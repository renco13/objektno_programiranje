#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <string>
#include <ctime>
using namespace std;

class Hand {
public:
	int card_num;
	string suit;
};
class Deck {
public:
	vector<Hand> cards;
	Hand new_card;
	void create_deck() {
		string suit[4] = { "SPADI","DINARI","KUPE","BASTONI" };
		for (int i = 0; i < 4; i++) {
			for (int j = 1; j < 14; j++) {
				if (j == 8 || j == 9 || j == 10)
					continue;
				else {
					new_card.card_num = j;
					new_card.suit = suit[i];
					cards.push_back(new_card);
				}
			}
		}
	}
	void shuffle() {
		srand(static_cast<int>(time(0)));
		random_shuffle(cards.begin(), cards.end());
	}
};
class Player {
public:
	string name;
	vector <Hand> hand;
	int points = 0;
	int akuz() {
		int br1 = 0, br2 = 0, br3 = 0, brS = 0, brD = 0, brK = 0, brB = 0;
		int akuz_points = 0;
		for (int i = 0; i < hand.size(); i++) {
			if (hand[i].card_num == 1) {
				br1++;
				if (hand[i].suit == "SPADI")
					brS++;
				if (hand[i].suit == "DINARI")
					brD++;
				if (hand[i].suit == "KUPE")
					brK++;
				if (hand[i].suit == "BASTONI")
					brB++;
			}
			if (hand[i].card_num == 2) {
				br2++;
				if (hand[i].suit == "SPADI")
					brS++;
				if (hand[i].suit == "DINARI")
					brD++;
				if (hand[i].suit == "KUPE")
					brK++;
				if (hand[i].suit == "BASTONI")
					brB++;
			}
			if (hand[i].card_num == 3) {
				br3++;
				if (hand[i].suit == "SPADI")
					brS++;
				if (hand[i].suit == "DINARI")
					brD++;
				if (hand[i].suit == "KUPE")
					brK++;
				if (hand[i].suit == "BASTONI")
					brB++;
			}
		}
		if (br1 >= 1 && br2 >= 1 && br3 >= 1 && (brS >= 3 && brD >= 3 && brK >= 3 && brB >= 3))
			points += 3;
		if (br1 >= 3)
			points += 3;
		if (br2 >= 3)
			points += 3;
		if (br3 >= 3)
			points += 3;
		if (br1 >= 4 || br2 >= 4 || br3 >= 4)
			points += 1;
		return points;
	}
};
void deal_cards(Deck& deck, vector<Player>& player) {
	for (int i = 0; i < player.size(); i++) {
		for (int j = 0; j < 10; j++) {
			player[i].hand.push_back(deck.cards.back());
			deck.cards.pop_back();
		}
	}
}
int main() {
	int num_players;
	cout << "Unesite broj igraca: \n";
	cin >> num_players;
	while (num_players != 2 && num_players != 4) {
		cout << "Molimo unestie tocan broj igraca: \n";
		cin >> num_players;
	}
	vector<Player> players;
	players.resize(num_players);
	for (int i = 0; i < num_players; i++) {
		cout << "Unesite ime: \n";
		cin >> players[i].name;
	}
	Deck deck;
	deck.create_deck();
	deck.shuffle();
	deal_cards(deck, players);
	for (int i = 0; i < num_players; i++) {
		players[i].akuz();
		cout << endl;
		cout << "Igrac " << players[i].name << " ima ";
		for (auto& card : players[i].hand) {
			cout << card.card_num << "-" << card.suit << " ";
		}
		cout << endl;
		cout << "Ima "<< players[i].points << " punti.\n";
	}
}
