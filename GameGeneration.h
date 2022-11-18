#ifndef POKERVS_GAMEGENERATION_H
#define POKERVS_GAMEGENERATION_H
#include <vector>
#include <iostream>
#include "Card.h"
class GameGeneration
{

public:
    //construteur et destructeur obligatoire
    GameGeneration();
    ~GameGeneration();
    //ints pour modifier les parametres du jeu (ca marche pas dans le protected)
    int m_handSize = 5;
    int m_nbPlayer = 10;


    
    //deck de 52 cartes
    std::vector<Card> deck;

    //hands contient toutes les mains des joueurs
    std::vector< std::vector<Card>> hands;

    //j ai mis des refs au cas ou
    std::vector<Card> &r_deck = deck;
    std::vector< std::vector<Card>> &r_hands = hands;
        
        
    //genere une main qui sera incluse dans hands
    std::vector<Card> generateHand(int nbPick);
    
    //genere un nouveau deck
    std::vector<Card> generateDeck();
       
        
    protected:
        

    private:
        
       
};

#endif

