// Perforce assesment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

class Card
{
private:
    string value;
    string suit;
public:
    Card() = default;
    //constructor
    Card(string _val, string _suit) : value{ _val }, suit{ _suit } { }
    //set suit
    void setSuit(string _suit) { suit = _suit; }
    //set value
    void setValue(string _value) { value = _value; }
    //get suit
    string getSuit() { return suit; }
    //get value
    string getValue() { return value; }
    void showCard() { cout << getValue() << getSuit(); }
};

class Deck
{
private:
    vector<Card> deck;
    const string spades{ " spades "};
    const string clubs{ " clubs" };
    const string hearts{ " hearts" };
    const string diamonds{ " diamonds" };
    const string card_values[13]{ "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
public:

    //constructor
    Deck() { fillDeck(); }

    void fillDeck();
    void showDeck();
    void shuffleDeck();
    Card getCard(int pos);

};

void Deck::fillDeck()
{
    for (int j{}; j < 52; j++)
    {
        if (j <= 12)
        {
            deck.push_back(Card(card_values[j], spades));
        }
        if (j >= 13 && j <= 25)
        {
            deck.push_back(Card(card_values[j - 13], clubs));
        }
        if (j >= 26 && j <= 38)
        {
            deck.push_back(Card(card_values[j - 26], hearts));
        }
        if (j >= 39)
        {
            deck.push_back(Card(card_values[j - 39], diamonds));
        }
    }
}

void Deck::showDeck()
{
    for (int i{}; i < 52; i++)
    {
        Card temp(deck[i]);
        cout << temp.getValue() << temp.getSuit() << " ";
        if (i == 12 || i == 25 || i == 38)
        {
            cout << endl;
        }
    }
}

void Deck::shuffleDeck()
{
    for (int i{}; i < 52; i++)
    {
        int pos_1 = (rand() % 51);
        int pos_2 = (rand() % 51);
        if (pos_1 == pos_2)
        {
            pos_1 = (rand() % 51);
            pos_2 = (rand() % 51);
        }
        swap(deck[pos_1], deck[pos_2]);
    }
}

Card Deck::getCard(int pos)
{
    //Card temp;
    return deck[pos];
    //return temp;
}

int main()
{

    Deck deck;
    deck.fillDeck();
    deck.shuffleDeck();

    int numberOfCards;

    cout << endl;
    cout << "Enter the number of cards you need:\n";
    cin >> numberOfCards;

    for (int i = 0; i < numberOfCards; i++) {
        Card temp(deck.getCard(i));
        cout << temp.getValue() << temp.getSuit() << " " << endl;
    }

    return 0;
}
