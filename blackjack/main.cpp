//
//  main.cpp
//  blackjack
//
//  Created by Riley Norris on 11/22/18.
//  Copyright © 2018 Riley Norris. All rights reserved.
//

#include <iostream>
#include "Blackjack.h"

// MARK: - Inputs

// Receives input from the user and processes request
bool receiveInput(Blackjack &player) {
    std::cout << "Please enter what you would like to do:" << std::endl;
    std::cout << "(1) Hit" << std::endl;
    std::cout << "(2) Stay" << std::endl;
    std::cout << std::endl << "Action: ";
    
    std::string input;
    std::cin >> input;
    
    if ((input.compare("Hit") == 0) || (input.compare("1")) == 0) {
        player.hit();
        
        if (player.didBust()) {
            std::cout << std::endl << "You busted! Sorry!" << std::endl << std::endl;
            return false;
        }
        
    } else if ((input.compare("Stay") == 0) || (input.compare("2")) == 0) {
        return false;
        
    } else {
        std::cout << std::endl << "Please enter one of the options below." << std::endl;
    }
    
    return true;
}

// Manages the AI, checks if bust
bool processAI(Blackjack &ai) {
    while (ai.getValue() < 15) {
        ai.hit();
    }
    
    if (ai.didBust()) {
        std::cout << std::endl << "The AI busted! You win!" << std::endl << std::endl;
        return false;
    }
    return true;
}

// Checks the winner of the game
void checkWinner(Blackjack player, Blackjack ai) {
    
    // Check if any player has busted
    if (player.didBust() || ai.didBust()) {
        return;
    } else {
        if (player.getValue() > ai.getValue()) {
            std::cout << std::endl << "You win!" << std::endl << std::endl;
        } else if (ai.getValue() > player.getValue()) {
            std::cout << std::endl << "You lose!" << std::endl << std::endl;
        } else {
            std::cout << std::endl << "It was a tie!" << std::endl << std::endl;
        }
    }
}

// MARK: - MAIN

// Main Function
int main(int argc, const char * argv[]) {
    
    Blackjack player = Blackjack();
    Blackjack ai = Blackjack();
    
    // Pick new seed for random functions
    srand(time(NULL));
    
    // Set up player & AI hands
    player.hit();
    player.hit();
    bool doContinue = processAI(ai);
    
    // Loop through user input until the decide to stay
    if (doContinue) {
        bool doLoop = true;
        while(doLoop) {
            std::cout << std::endl << std::endl << std::endl << std::endl << std::endl;
            std::cout << std::endl << "Your cards:" << std::endl;
            std::cout << "-----------------------------" << std::endl;
            player.listCards();
            
            std::cout << "AI's cards:" << std::endl;
            std::cout << "-----------------------------" << std::endl;
            ai.listCards();
            doLoop = receiveInput(player);
        }
    }
    
    // Check who the winner is
    checkWinner(player, ai);
    
    return 0;
}
