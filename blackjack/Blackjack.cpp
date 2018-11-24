//
//  Blackjack.cpp
//  blackjack
//
//  Created by Riley Norris on 11/22/18.
//  Copyright © 2018 Riley Norris. All rights reserved.
//

#include <stdio.h>
#include "Blackjack.h"

// Adds a random card to the current hand
void Blackjack::hit() {
    Card newCard = Card();
    
    Blackjack::list.push_back(newCard);
}

// Lists all the cards in the current hand
void Blackjack::listCards() {
    
    for (int i = 0; i<Blackjack::list.size(); i++) {
        std::cout << list.at(i).name << std::endl;
    }
    
    std::cout << std::endl;
}

// Gets the # value of the current hand
int Blackjack::getValue() {
    int val = 0;
    for (int i = 0; i<Blackjack::list.size(); i++) {
        val += list.at(i).value;
    }
    return val;
}

// Finds out whether the user has busted or not
bool Blackjack::didBust() {
    int value = Blackjack::getValue();
    if (value > 21) {
        return true;
    }
    return false;
}
