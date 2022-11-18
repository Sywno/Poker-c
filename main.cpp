#include <iostream>
#include <vector>
#include <stdexcept> // invalid_argument
#include <algorithm> // for_each
#include "GameComparaison.h"
//#include "GameGeneration.h"
#include "card.h"
using namespace std;

void show_card(const Card& c) {  // function:
  std::cout << c << ", " ;
}

void test_cards()
{
    cout << "Start of test for Card class" << endl ;
    Card c = Card(COEUR, DIX) ;
    cout << c << endl ;
    try {
        Card d = Card('Q', 100) ;
    }
    catch(const std::invalid_argument& ia) {
	  std::cerr << "Invalid argument: " << ia.what() << std::endl ;
    }

    std::vector<Card> hand ;
    try {
        hand.push_back(Card('T', 10)) ;
        hand.push_back(Card('T', 3)) ;
        hand.push_back(Card('C', VALET)) ;
        hand.push_back(Card('P', ROI)) ;
        hand.push_back(Card('P', DAME)) ;
    }
    catch(const std::invalid_argument& ia) {
	  std::cerr << "Invalid argument: " << ia.what() << std::endl ;
    }
    std::cout << "--------- hand (for const Card&) --------------" << std::endl ;
    for(const Card& c: hand)
        show_card(c) ;
    std::cout << endl ;
    std::cout << "--------- == --------------" << std::endl ;
    std::cout << hand[0] << " == " << hand[1] << " -> " << (hand[0] == hand[1]) << std::endl ;

    // for_each(hand.cbegin(), hand.cend(), show_card) ;
    std::cout << "--------- hand2 (for with auto) --------------" << std::endl ;
    try {
        std::vector<Card> hand2 = { Card('P', 9), Card(TREFLE, 7) } ;
        // for(const Card& c: hand2)
        for(auto c: hand2)

            show_card(c) ;
        std::cout << endl ;

        std::cout << "--------- == --------------" << std::endl ;
        hand2.push_back(hand2[1]) ;
        std::cout << hand2[1] << " == " << hand2[2] << " -> " << (hand2[1] == hand2[2]) << std::endl ;
    }
    catch(const std::invalid_argument& ia) {
	  std::cerr << "Invalid argument: " << ia.what() << std::endl ;
    }
    catch(const std::exception& e) {
	  std::cerr << "Exception: " << e.what() << std::endl ;
    }
    std::cout << "--------- static of Card --------------" << std::endl ;
    cout << Card::StringColors[TREFLE] << std::endl ;
    cout << Card::StringValues[UN] << std::endl ;
    cout << hand[3] << " vs " << hand[3].Getm_str() << std::endl ;
}
int main()
{
    std::cout << "Demarrage" << std::endl;


    int iteration = 1;
    while (true) {

        //syntaxe bizarre mais sur vs il la demande...
        GameComparaison game{};
        std::cout << "iteration n : " <<iteration<< std::endl;
        iteration++;

        //en attente d'une pression d'entrée
        cin.get();
    }
    
    //GameComparaison game{};
    return 0;
}
