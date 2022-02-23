#ifndef HAND_H
#define HAND_H

#include <vector>
#include <iostream>
#include "card.h"

const int HAND_SIZE = 5;

class Hand 
{
public:
    explicit Hand();
    explicit Hand(Card);

    std::vector<Card> cards;
    uint hand; //0 to 10 - corresponds to index of hands array
    const std::string handsInOrder[10] = {"HC","P","TP","ToK"
                                          "S","F","FH","FoK",
                                          "SF","RF"};
    int handsCount[10];
    bool addToHand(Card);
    char getVal(Card);
    bool isPair();
    bool isToK();
    bool isFoK();

    void printHand();
    void resetHand();
    


};

#endif