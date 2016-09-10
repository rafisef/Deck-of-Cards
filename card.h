#ifndef H_card
#define H_card
#include <string>
#include <iostream>

using namespace std;

class card
{
public:
    card(string cardFace, string cardSuit);
    string print() const;
    card();
private:
    string face;
    string suit;
};

card::card()
{

}

card::card(string cardFace, string cardSuit) // function that takes in a face and suit. Defines the card.
{
    face = cardFace;
    suit = cardSuit;
}

string card::print() const //returns name of the card
{
    return (face + " of " + suit);
}
#endif // H_card
