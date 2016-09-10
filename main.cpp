//C++ Deck of cards Program
#include "deckOfCards.h"
#include "deckOfNumbers.h"
#include <iostream>

using namespace std;

int main()
{

    deckOfNumbers numDeck;
    numDeck.newDeck();
    deckOfCards deck;
    card currentCard; // creates both decks
    cout << "Please choose a deck" << endl << "1. Traditional Deck"
         << endl << "2. Number Deck" << endl;
    int input;
    char ans;
    cin >> input;
    switch(input)
    {
    case 1:
        do {


        cout << "Please choose what you'd like to do." << endl << "1. Draw a card"
             << endl << "2. Place a card on the top of the deck" << endl
             << "3. Shuffle" << endl << "4. Sort" << endl << "5. Print cards in your hand" << endl;
             int secondInput;
             cin >> secondInput;
             switch(secondInput)
             {
             case 1:
                deck.drawToHand();
                deck.printDeck();
                break;
             case 2:
                 deck.placeInDeck();
                 deck.printDeck();
                break;
             case 3:
                 deck.shuffle();
                 deck.printDeck();
                break;
             case 4:
                 deck.sortDeck();
                 deck.printDeck();
                break;
             case 5:
                 deck.dealHand();
                break;
             default:
                 cout << "Invalid entry, please try again." << endl;
                break;
             }
             cout << endl << "Do you want to make another choice? Y or N" << endl;
             cin >> ans;
        } while(ans == 'Y');
        break;
    case 2:
        do{


        cout << "Please choose what you'd like to do." << endl << "1. Draw a card"
             << endl << "2. Place a card on the top of the deck" << endl
             << "3. Shuffle" << endl << "4. Sort" << endl << "5. Print cards in your hand" << endl;
        int thirdInput;
        cin >> thirdInput;
        switch(thirdInput)
        {
        case 1:
            numDeck.drawToHand();
            cout << endl << "You have placed a card in your hand" << endl;
            numDeck.printDeck();
            break;
        case 2:
            numDeck.placeInDeck();
            cout << endl << "You have placed a card in the top of the deck" << endl;
            numDeck.printDeck();
            break;
        case 3:
            cout << endl << "Here are the shuffled cards" << endl << endl;
            numDeck.shuffle();
            numDeck.printDeck();
            break;
        case 4:
            cout << endl << "Here are the sorted cards" << endl;
            numDeck.sortDeck();
            numDeck.printDeck();
            break;
        case 5:
            numDeck.dealHand();
            break;
        default:
            cout << "Invalid entry, please try again." << endl;
            break;
        }
        cout << endl << "Do you want to make another choice? Y or N" << endl;
        cin >> ans;
        }while(ans == 'Y');
        break;
    default:
        cout << "Invalid entry, please try again." << endl;
        break;

    }


    system("PAUSE");
    return 0;
}
