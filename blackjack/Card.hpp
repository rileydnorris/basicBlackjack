//
//  Card.hpp
//  blackjack
//
//  Created by Riley Norris on 11/22/18.
//  Copyright © 2018 Riley Norris. All rights reserved.
//

#ifndef Card_hpp
#define Card_hpp

#include <stdio.h>
#include <iostream>

// MARK: - Card Class

// Manages individual cards
class Card {
    
private:
    
public:
    
    std::string name;
    int value;
    
    // Constructor for the Card class
    Card() {
        
        // Pick a random number and suit
        value = rand() % 10 + 2;
        int suit = rand() % 4 + 1;
        
        // Pick a face value if 10 was generated
        if (value == 10) {
            int face = rand() % 4 + 1;
            
            switch (face) {
                case 1:
                    name = "10";
                    break;
                    
                case 2:
                    name = "Jack";
                    break;
                    
                case 3:
                    name = "Queen";
                    break;
                    
                case 4:
                    name = "King";
                    break;
                    
                default:
                    break;
            }
        } else if (value == 11) {
            name = "Ace";
        } else {
            name = std::to_string(value);
        }
        
        // Append the suit to the name string
        switch (suit) {
            case 1:
                name += " of Spades";
                break;
                
            case 2:
                name += " of Clubs";
                break;
                
            case 3:
                name += " of Hearts";
                break;
                
            case 4:
                name += " of Diamonds";
                break;
                
            default:
                break;
        }
    }
};

#endif /* Card_hpp */
