#ifndef CARD_H
#define CARD_H

#include <string>

const int SUIT_MAX(4);
const int RANK_MAX(13);

class Card
{
    friend class Deck; // Deck Class needs to access to Card Class but not vice versa
    friend class Hand;
public:
    explicit Card();
    explicit Card(const int &suit, const int &rank);

    std::string Card2Str() const;

private:
    int generate_suit();
    int generate_rank();
    int get_suit() const;
    int get_rank() const;
    int m_suit;
    int m_rank;
};
#endif