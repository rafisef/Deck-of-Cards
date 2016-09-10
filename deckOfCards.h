#ifndef H_deckOfCards
#define H_deckOfCards
#include "card.h"
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

const int CARDS_PER_DECK = 52; // keeps the total number of cards constant

class deckOfCards
{
public:
    deckOfCards();
    void shuffle();
    void sortDeck();
    void drawToHand();
    void placeInDeck();
    void dealHand();
    void printDeck() const;
private:
    card *deck;
    int currentCard;
    card *cardDraw;
};

void deckOfCards::printDeck() const // prints the deck in order beginning of the array to the end of it. Current card controls where the array starts.
{
    cout << left;
    for(int i=currentCard; i<CARDS_PER_DECK; i++)
    {
        cout << setw(19)<<deck[i].print();
        if((i+1) % 4 == 0)
            cout<<endl;
    }
}

deckOfCards::deckOfCards() // creates an initial deck of 52 cards in numerical order.
{
    string faces[] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven",
            "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    string suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    deck = new card[CARDS_PER_DECK];
    cardDraw = new card[CARDS_PER_DECK];
    currentCard = 0;
    for(int j = 0; j < CARDS_PER_DECK; j++)
        deck[j] = card(faces[j % 13], suits[j / 13]);
}

void deckOfCards::shuffle() // shuffles the cards in the deck.
{
    //currentCard = 0; dont need this
    for(int first = currentCard; first < CARDS_PER_DECK; first++)
    {
        int second = (rand() + time(0)) % (CARDS_PER_DECK-currentCard) + currentCard;
        card temp = deck[first];
        deck[first] = deck[second];
        deck[second] = temp;
    }
}

void deckOfCards::sortDeck() // Uses bubble sort to sort the deck after shuffling it.
{
    string faces[] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven",
            "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    string suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    for(int j = currentCard; j < CARDS_PER_DECK; j++)
        deck[j] = card(faces[j % 13], suits[j / 13]);
}

void deckOfCards:: placeInDeck() // places the last card you drew to your hand back into the deck.
{
    if(currentCard==0)
    {
        cout << "no cards in hand" << endl;
    }
    else
    {
        currentCard--;
    }

}

void deckOfCards::drawToHand() // draws the a card from the deck to your hand
{
    cardDraw[currentCard] = deck[currentCard];
    currentCard++;

}

void deckOfCards:: dealHand() // shows the cards you currently have in your hands.
{
    if(currentCard>0)
    {
        cout << "these are the cards in your hand" << endl;
        for(int i=0; i<currentCard;i++)
        {
            cout << cardDraw[i].print() << endl;
        }
    }


}

#endif // H_deckOfCards
