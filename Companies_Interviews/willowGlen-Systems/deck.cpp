#include <string>
#include <iostream>
#include "deck.h"

/*******************************************************************************/
/*                                                                             */
/* Purpose:                                                                    */
/*  Constructor, creates 56 card objects and assigns to *card                  */
/*                                                                             */
/* Parameters:  					                       */
/*                                                                             */
/* Returns: NONE.                                                              */
/*                                                                             */
/* Notes:                                                                      */
/*                                                                             */
/*******************************************************************************/
Deck::Deck()
{
	card = new Card[ TOTAL_CARDS ];

	for(int i=0; i<TOTAL_CARDS; i++)
	{

		//set_value(int value,int suit)
		card[i].set_value (i % CARDS_PER_SUITE,
				   i / CARDS_PER_SUITE);

	}

}
 
/*******************************************************************************/
/*                                                                             */
/* Purpose:                                                                    */
/*  Destructor, deletes all 56 card objects once deck goes out of scope        */
/*                                                                             */
/* Parameters:                                                                 */
/*                                                                             */
/* Returns: NONE.                                                              */
/*                                                                             */
/* Notes:                                                                      */
/*                                                                             */
/*******************************************************************************/
Deck::~Deck()
{
	delete[] card;	
}

/*******************************************************************************/
/*                                                                             */
/* Purpose: 								       */
/*  Print N sets of M cards. 						       */
/*  Two consecutive 'deals' should produce the same result.		       */
/*  The deck must be shuffled in order to produce a different 'deal'.          */
/*                                                                             */
/* Parameters: int sets - Number of sets to be printed                         */
/*             int cards- Number of cards in each set                          */
/*                                                                             */
/* Returns: NONE.                                                              */
/*                                                                             */
/* Notes:                                                                      */
/*                                                                             */
/*******************************************************************************/
void Deck::deal_hand(int sets, int cards)
{
        if( sets*cards > TOTAL_CARDS )
	{
                cout<<"Invalid deal\n";
                return;
        }

	for (int i = 0; i < sets*cards; i++)
	{
		card[i].print();

		if ( i%5 == 4)
			cout<<endl;
	}
	cout<<endl;

	
}
 
/*******************************************************************************/
/*                                                                             */
/* Purpose: 								       */
/*  Prints the entire deck to standard out.				       */
/*  Prints 4 rows of 13 cards each                                    	       */
/*                                                                             */
/* Parameters: None				                               */
/*                                                                             */
/* Returns: NONE.                                                              */
/*                                                                             */
/* Notes:                                                                      */
/*                                                                             */
/*******************************************************************************/
void Deck::print_deck()
{
	for(int i=0; i<TOTAL_CARDS; i++)
	{
		this->card[i].print();

		if ( i % CARDS_PER_SUITE == CARDS_PER_SUITE-1)
			cout<<endl;
	}
	cout<<endl;
}

/*******************************************************************************/
/*                                                                             */
/* Purpose:                                                                    */
/*  all 52 cards should be randomly permuted.                                  */
/*  This uses a seedable random number generator			       */
/*                                                                             */
/* Parameters: None                                                            */
/*                                                                             */
/* Returns: NONE.                                                              */
/*                                                                             */
/* Notes:                                                                      */
/*                                                                             */
/*******************************************************************************/
void Deck::shuffle(int seed)
{
        srand ( seed );
        int shuffl = rand() % TOTAL_CARDS;
        int i = 0;

	Card temp = card[0], temp1;
        card[0] = card[ shuffl ];

        while ( i < shuffl )
	{
                temp1 = card[ i+1 ];
                card[ i+1 ] = temp;
                temp = temp1;
                i++;
        }
}

/*******************************************************************************/
/*                                                                             */
/* Purpose: 								       */
/*  Sorts the deck from lowest to highest by suit then by card face value      */
/*                                                                             */
/* Parameters: None                                                            */
/*                                                                             */
/* Returns: NONE.                                                              */
/*                                                                             */
/* Notes:                                                                      */
/*                                                                             */
/*******************************************************************************/
void Deck::sort()
{
	int suit = 0, value = 0;

	for(int i=0; i<TOTAL_CARDS; i++)
	{
                suit = card[i].get_suit();
                value = card[i].get_value();

		if (value != i % CARDS_PER_SUITE ||
 		    suit != i / CARDS_PER_SUITE)
		{
			card[i].set_value(i % CARDS_PER_SUITE,
                                   i / CARDS_PER_SUITE);
		}
    	}
}
