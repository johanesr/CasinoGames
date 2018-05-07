#ifndef Casino_hpp
#define Casino_hpp

#include <stdio.h>
#include <iostream>
#include <array>
#include <ctime>
#include <string.h>
using namespace std;

int totalMoney=100;

enum Rank
{
    Rank_2,
    Rank_3,
    Rank_4,
    Rank_5,
    Rank_6,
    Rank_7,
    Rank_8,
    Rank_9,
    Rank_10,
    Rank_Jack,
    Rank_Queen,
    Rank_King,
    Rank_Ace,
    Max_Rank
};

enum Suit
{
    Suit_Club,
    Suit_Diamond,
    Suit_Heart,
    Suit_Spade,
    Max_Suit
};

struct card
{
    Rank Rank;
    Suit Suit;
};

class Casino
{
private:
    card deck;
public:
    Casino();
    ~Casino();
    void printCard(card &c);
    void printDeck(card deck[]);
    void swapCard(card &a,card &b);
    void shuffleDeck(card deck[]);
    int getCardValue(card x);
    void playBaccarat(card deck[52]);
    void playBlackJack(card deck[52]);
};

#endif /* Casino_hpp */
