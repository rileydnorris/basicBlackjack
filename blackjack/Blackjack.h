//
//  Blackjack.h
//  blackjack
//
//  Created by Riley Norris on 11/22/18.
//  Copyright © 2018 Riley Norris. All rights reserved.
//

#ifndef Blackjack_h
#define Blackjack_h

#include <vector>
#include "Card.hpp"

// MARK: - Blackjack Class

class Blackjack {
    
public:
    
    void hit();         // Adds a random card to the current hand
    void listCards();   // Lists all of a user's cards
    int getValue();     // Returns the current # value of a hand
    bool didBust();     // Checks if the player has busted
    
private:
    
    std::vector<Card> list;
};

#endif


