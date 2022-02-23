#include "hand.h"
#include <map>

Hand::Hand() {
  
}

Hand::Hand(Card c) {
  cards.push_back(c);
} 

bool Hand::addToHand(Card c) {
  if(cards.size() < HAND_SIZE)
    cards.push_back(c);
  else 
    return false;

  return true;
}

bool Hand::isPair() {
  char searchItem;

  for(int i = 0; i< cards.size();i++) {
    searchItem = getVal(cards[i]);

    for(int j = i + 1; j < cards.size(); j++) {
      if(searchItem == getVal(cards[j]))
        return true;
    }
  }

  return false;
}

bool Hand::isToK() {
  char searchItem;
  int count = 2; //Decrement when a match to the card is found

  for(int i = 0; i< cards.size();i++) {
    searchItem = getVal(cards[i]);

    for(int j = i + 1; j < cards.size(); j++) {
      if(searchItem == getVal(cards[j]))
        count--;
    }
  }

  if(count < 0)  //If there are two matches, it is a ToK
    return true;

  return false; 
}

bool Hand::isFoK() { // Not properly working
/*  char searchItem;   //Will give true for a Full House
  int count = 3; //Decrement when a match to the card is found

  for(int i = 0; i< cards.size();i++) {
    searchItem = getVal(cards[i]);

    for(int j = i + 1; j < cards.size(); j++) {
      if(searchItem == getVal(cards[j]))
        count--;
    }
  }

  if(count < 0)  //If there are three matches, it is a FoK
    return true;

  return false; 
  */

  std::map<char,int> counts;

  for(int i = 0; i < cards.size(); i++) {
    char cardVal = getVal(cards[i]);
    
    if(counts.count(cardVal) < 0)
      counts.at(cardVal) = 1;
    else
      counts.at(cardVal) = counts[cardVal] + 1;
  }

  for (auto it = counts.cbegin(); it != counts.cend(); ++it)
    if((*it).second == 4)
      return true;

  return false;
  
}

void evaluateHand() {
  uint handInd = 0;
  //if (this->isPair() && !isToK() && !isFoK())
    handInd = 1;
  
}

char Hand::getVal(Card c) {
  std::string temp = c.Card2Str();
  return temp[1];
}

void Hand::printHand() {
  for(int i = 0; i < cards.size(); i++)
    std::cout << cards[i].Card2Str() << std::endl;
}

void Hand::resetHand() {
  cards.clear();
}
