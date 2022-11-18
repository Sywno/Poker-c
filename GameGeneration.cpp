
#include "GameGeneration.h"
#include <iostream>
#include <random>
#include <algorithm>

using namespace std;
GameGeneration::GameGeneration() {
    //std::cout <<this << std::endl;
    //A DECOMMENTER POUR VOIR LES MAINS DES JOUEURS
    deck = generateDeck();
    
    std::cout << "taille du deck " << deck.size() << ", nombre de joueur " << m_nbPlayer<<", nombre de carte par joueur "<< m_handSize<<std::endl;
    for (int i = 0; i < deck.size(); i++)
    {
        //std::cout <<deck[i] << std::endl;
    }
    
    //oui ca commence à 1 c'est fait expres
    for (int i = 1; i < m_nbPlayer+1; i++)
    {
        //on appelle la generation d'une main
        vector<Card> newhand =  generateHand(i);

        //print console
        cout<< "Main du joueur " << i << endl;
        for (int j = 0; j < newhand.size(); j++)
        {
            cout << newhand[j].Getm_str() << " | ";
        }
        cout<< endl;
        //on ajoute la main dans les mains
        hands.push_back(newhand);
    }
    
    //A INVERSER pour pouvoir forcer les combinaisons
    
    //high card
    /*
    std::vector<Card> hand0;
    hand0.push_back(Card('C', 8));
    hand0.push_back(Card('K', AS));
    hand0.push_back(Card('T', 12));
    hand0.push_back(Card('T', 7));
    hand0.push_back(Card('P', 2));

    //pair
    std::vector<Card> hand1;
    hand1.push_back(Card('C', AS));
    hand1.push_back(Card('T', 3));
    hand1.push_back(Card('T', 7));
    hand1.push_back(Card('P', 7));
    hand1.push_back(Card('K', VALET));

    //two pairs
    std::vector<Card> hand2;
    hand2.push_back(Card('T', 4));
    hand2.push_back(Card('K', 11));
    hand2.push_back(Card('C', 11));
    hand2.push_back(Card('C', 2));
    hand2.push_back(Card('C', 4));

    //three of a kind
    std::vector<Card> hand3;
    hand3.push_back(Card('C', 6));
    hand3.push_back(Card('T', 6));
    hand3.push_back(Card('K', 6));
    hand3.push_back(Card('P', 10));
    hand3.push_back(Card('T', 3));

    //straight
    std::vector<Card> hand4;
    hand4.push_back(Card('P', 5));
    hand4.push_back(Card('T', 4));
    hand4.push_back(Card('T', 6));
    hand4.push_back(Card('K', 7));
    hand4.push_back(Card('C', 3));

    //flush
    std::vector<Card> hand5;
    hand5.push_back(Card('P', 6));
    hand5.push_back(Card('P', ROI));
    hand5.push_back(Card('P', VALET));
    hand5.push_back(Card('P', 4));
    hand5.push_back(Card('P', 7));

    //full
    std::vector<Card> hand6;
    hand6.push_back(Card('C', 8));
    hand6.push_back(Card('K', 13));
    hand6.push_back(Card('P', 8));
    hand6.push_back(Card('P', 13));
    hand6.push_back(Card('T', 13));

    //four of a kind
    std::vector<Card> hand7;
    hand7.push_back(Card('T', 8));
    hand7.push_back(Card('P', 8));
    hand7.push_back(Card('C', 8));
    hand7.push_back(Card('K', 8));
    hand7.push_back(Card('K', AS));

    //straight flush
    std::vector<Card> hand8;
    hand8.push_back(Card('C', 11));
    hand8.push_back(Card('C', 13));
    hand8.push_back(Card('C', 10));
    hand8.push_back(Card('C', 14));
    hand8.push_back(Card('C', 12));

    //straight with ace
    std::vector<Card> hand9;
    hand9.push_back(Card('C', AS));
    hand9.push_back(Card('K', 2));
    hand9.push_back(Card('P', 3));
    hand9.push_back(Card('T', 4));
    hand9.push_back(Card('C', 5));

    //All hands vectors into one vector (everyHand vector)
    hands.push_back(hand8);
    hands.push_back(hand1);
    hands.push_back(hand2);
    hands.push_back(hand3);
    hands.push_back(hand4);
    hands.push_back(hand5);
    hands.push_back(hand6);
    hands.push_back(hand7);
    hands.push_back(hand0);
    hands.push_back(hand9);*/
    r_deck = deck;
    r_hands = hands;
    
}


GameGeneration::~GameGeneration() {
    //dtor
}



std::vector<Card> GameGeneration::generateDeck() {
    std::vector<Card> deck;

    for (int c = 0; c < 4; c++) {
        int coulour;
        if (c == 0) coulour = 67;
        if (c == 1) coulour = 75;
        if (c == 2) coulour = 80;
        if (c == 3) coulour = 84;

        for (int n = 2; n < 15; n++)
        {
            deck.push_back(Card(coulour, n));

        }
    }
    //les cartes sont triés dans l ordre mais avec le shuffle ca devient aléatoire
    std::shuffle(deck.begin(), deck.end(), std::mt19937 (std::random_device()()));
    return deck;
}
std::vector<Card> GameGeneration::generateHand(int nbpick) {
    std::vector<Card> hand;
    
    //petite magie noire mathématiques pour ne pas faire de condition
    for (int i = (nbpick-1)*m_handSize; i < m_handSize*nbpick; i++) {
        //on pioche dans l ordre du deck generé prcq le deck est deja mélangé
        hand.push_back(deck[i]);
       
    }

    return hand;
}