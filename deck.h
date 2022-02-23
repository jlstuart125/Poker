////Modified Header file from user CroCo at
//https://codereview.stackexchange.com/questions/41810/card-and-deck-classes
#ifndef DECK_H
#define DECK_H

#include <vector>
#include <iostream>
#include <fstream>
#include "card.h"

using namespace std;

class Deck
{ 
public:
      explicit Deck();
      void print_Deck() const;

      Card getOneCard();
      void shuffleDeck();
      void resetDeck();

private:
    std::vector<Card> m_deck;

};

#endif