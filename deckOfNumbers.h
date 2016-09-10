#ifndef H_deckOfNumbers
#define H_deckOfNumbers
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

const int TOTAL_CARDS = 60; // keeps the amount of cards in the deck to 60.

class deckOfNumbers
{
public:
    deckOfNumbers();
    void shuffle();
    int dealHand();
    void printDeck() const;
    void newDeck();
    void drawToHand();
    void placeInDeck();
    void sortDeck();
private:
    int* value;
    int cardInHand;
    int* cardDraw;
    int* deck;

};
void deckOfNumbers:: printDeck() const // prints the deck
{
    cout << left;
    for(int i=cardInHand; i<TOTAL_CARDS; i++)
    {
        deck[i] = value[i];
        cout << deck[i] << " ";
        if ((i+1) % 10 == 0)
        cout << endl;

    }
}

void deckOfNumbers:: drawToHand() // draws card from the deck to the hand
{

    cardDraw[cardInHand] = value[cardInHand];
    cardInHand++;
    }

void deckOfNumbers:: placeInDeck() // places the card in your hand back into the deck
{
    if(cardInHand == 0)
    {
        cout << "You have no more cards in your hand" << endl<< endl;
    }
    else
    {
        cardInHand--;
    }
}

deckOfNumbers:: deckOfNumbers() // initializes the deck containing cards 0-59 numerically
{
    value = new int [TOTAL_CARDS];
    cardDraw = new int[TOTAL_CARDS];
    deck = new int[TOTAL_CARDS];
    for(int i=0; i<TOTAL_CARDS; i++)
    {
        value[i] = i;
    }

}

void deckOfNumbers:: newDeck() // creates a new deck with cards from 0-59. Redundant function since the previous function accomplishes this task.
{
    cardInHand = 0;
    for(int i=0; i<TOTAL_CARDS; i++)
    {
        value[i] = i;
    }

}

void deckOfNumbers:: shuffle() // shuffles the deck
{
    int random;
    int temp;
    srand(time(NULL));
    for(int i=cardInHand; i<TOTAL_CARDS; i++)
        {
        random = rand() % (TOTAL_CARDS-cardInHand) + cardInHand; // sets random number for random between cardInHand-59
        temp = value[i];
        value[i] = value[random]; //creates a random order deck
        //cout << endl<< simple_deck[i]<< endl;
        value[random] = temp;
        }

}

void deckOfNumbers:: sortDeck() // sorts the deck with a bubble sort.
{
    int temp;
    int flag = 1;
    for(int i=cardInHand; i<TOTAL_CARDS && flag == 1;i++)
    {
        flag = 0;
        for(int j=cardInHand; j<TOTAL_CARDS-1; j++)
        {
            if(value[j+1] < value[j] )
            {
                temp = value[j];
                value[j] = value[j+1];
                value[j+1] = temp;
                flag = 1;
            }
        }
    }
}

int deckOfNumbers:: dealHand() // prints the cards that are in your hand.
{
    if(cardInHand > 0)
    {
    cout << endl << "These are the cards in your hand:" << endl;
    for(int i=0; i<cardInHand; i++)
        {
            cout << cardDraw[i] << endl;
        }
    }
    else
    return 0;
}

#endif // H_deckOfNumbers
