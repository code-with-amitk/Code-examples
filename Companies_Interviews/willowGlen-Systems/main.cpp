#include <iostream>
#include "deck.h"

using namespace std;

int main() 
{
	Deck deck;
	deck.print_deck();

  	cout << "\n=== Shuffle Deck ==============================\n";
  	deck.shuffle(15);  // use a seed value of 15
  	deck.print_deck();	

  	cout << "\n=== Sorted Deck ==============================\n";
  	deck.sort();
  	deck.print_deck();	

  	cout << "\n=== Shuffled Again ==============================\n";
  	deck.shuffle(34);  // use a seed value of 34
  	deck.print_deck();	

        cout << "\n=== Deal 3 sets of 5 cards ==============================\n";
        deck.deal_hand(3,5);	

        cout << "\n=== Deal again ==============================\n";
  	deck.deal_hand(3,5);	

  	cout << "\n=== Suffle and deal again ==============================\n";
  	deck.shuffle(99);  // use a seed value of 99
  	deck.deal_hand(3,5);	
}
