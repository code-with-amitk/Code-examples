// card.h
//
// @brief A class that represents a playing card
//
// @details
// This class is responsible for storing, printing and comparing a playing card.
//

#include <string>
#include <iostream>
using namespace std;

class Card 
{
public:

  // Suit enumeration
	enum Suit
	{
		DIAMONDS = 0,
		CLUBS = 1,
		HEARTS = 2,
		SPADES = 3
	};
	
	// value enumeration
	enum Value
	{
		//Taken 56 cards. 14 cards per Suit
		JOKER = 0,
		ACE   = 1,
		TWO   = 2,
		THREE = 3,
		FOUR  = 4,
		FIVE  = 5,
		SIX   = 6,
		SEVEN = 7,
		EIGHT = 8,
		NINE  = 9,
		TEN   = 10,
		JACK  = 11,
		QUEEN = 12,
		KING  = 13
	};

	// Constructor
  	Card();
  
	// Destructor
  	~Card();
	
	// Returns the suit of the card.
	//
	// @return	The suit.
	Suit  get_suit()
	{
		return m_suit;
	}

	// Returns the value of the card.
	//
	// @return	The suit enumeration.
	Value get_value()
	{
		return m_value;
	}
  
	// Compares if the card face value of two cards are equal.  
	// Does not take suit into consideration.
	//
	// @param[in]	rhs   The right hand side card.
	// @return	  true if equal.
	bool operator== (const Card& rhs);

	// Compares if the card face value of the left card is less than the right.  
	// Does not take suit into consideration.
	//
	// @param[in]	rhs   The right hand side card.
	// @return	  true if less than.
	bool operator< (const Card& rhs);

	// Compares if the card face value of the left card is less than or equal the right.  
	// Does not take suit into consideration.
	//
	// @param[in]	rhs   The right hand side card.
	// @return	  true if less than or equal.
	bool operator<= (const Card& rhs);

	// Compares if the card face value of the left card is greater than the right.  
	// Does not take suit into consideration.
	//
	// @param[in]	rhs   The right hand side card.
	// @return	  true if greater than.
	bool operator> (const Card& rhs);

	// Compares if the card face value of the left card is greater than or equal the right.  
	// Does not take suit into consideration.
	//
	// @param[in]	rhs   The right hand side card.
	// @return	  true if greater than or equal.
	bool operator>= (const Card& rhs);

	// Prints a single card to std out.
	void  print();	
  
	// Sets the value of the card.
	//
	// @param[in]	value The value of the card.
	// @param[in]	suit  The value of thd card.
	void  set_value(Value value,Suit suit)
	{
	  m_value = value;
	  m_suit = suit;
	}

	void  set_value(int value,int suit)
	{
	  m_value = static_cast<Value>(value);
	  m_suit = static_cast<Suit>(suit);
	}


private:

	Suit  m_suit;   // The suit of the card
	Value m_value;  // The value o the card
};
