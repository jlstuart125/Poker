//Modified Implementation file from user CroCo at
//https://codereview.stackexchange.com/questions/41810/card-and-deck-classes

#include <iostream>
#include <random>
#include <algorithm>
#include "deck.h"


Deck::Deck()
{
    for (unsigned int i(0); i < SUIT_MAX; ++i)
    {
        for (unsigned int j(0); j < RANK_MAX; ++j)
        {
            Card card(i, j);
            m_deck.push_back(card);
        }
    }
}


void Deck::print_Deck() const
{
    unsigned int count(1);

    for (unsigned int i(0); i < m_deck.size(); i++)
    {
        std::cout << m_deck[i].Card2Str() << " ";
        if ( count == 13 )
        {
          std::cout << std::endl;
          count = 0;
        }
        ++count;
    }
}

Card Deck::getOneCard()
{   
    Card cd(m_deck.back().get_suit(), m_deck.back().get_rank());
    m_deck.pop_back();
    //std::cout << cd.Card2Str() << std::endl;
    return cd;
}

void Deck::shuffleDeck() {
   std::random_device rd;
   std::default_random_engine rng(rd());
   shuffle(m_deck.begin(),m_deck.end(), rng);
}

void Deck::resetDeck() {
m_deck.clear();
  
  for (unsigned int i(0); i < SUIT_MAX; ++i)
    {
        for (unsigned int j(0); j < RANK_MAX; ++j)
        {
            Card card(i, j);
            m_deck.push_back(card);
        }
    }
  
}