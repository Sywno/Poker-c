#pragma once
#include "Card.h"
#include <string>
#include "GameGeneration.h"


class GameComparaison : public GameGeneration
{

public:
	GameComparaison();
	~GameComparaison();

	//force de la main composé de 4 chiffres pour chaque joueur
	//"Premier chiffre : Force de la combinaison (2 pour double paire et 8 pour Quinte Flush, etc. Deuxieme chiffre : Force de la carte paire/brelan. 
	//Troisieme chiffre : Force de la carte s'il y a une autre paire. Quatrieme chiffre : Force de la carte la plus haute.
	std::vector<std::vector<int>> strenghtPlayerHand;
	std::vector<std::vector<int>>& r_strenghtPlayerHand = strenghtPlayerHand;


	//les noms sont en fonction de l appelation de yves

	//A chaque fois on prend toutes les main le "hands du generation" on va au bonne index player num, et forceofthehand c est la liste strenghtplayerhand que l on va modifier
	int SuiteFinder(std::vector<std::vector<Card>>& completeHand, int playernum, std::vector< std::vector<int>>& forceOfTheHand);
	int ColorFinder(std::vector<std::vector<Card>>& completeHand, int playernum, std::vector< std::vector<int>>& forceOfTheHand);
	int QuinteFlushFinder(std::vector<std::vector<Card>>& completeHand, int playernum, std::vector< std::vector<int>>& forceOfTheHand);

	int CarreFinder(std::vector<std::vector<Card>>& completeHand, int playernum, std::vector< std::vector<int>>& forceOfTheHand);
	int BrelanFinder(std::vector<std::vector<Card>>& completeHand, int playernum, std::vector< std::vector<int>>& forceOfTheHand);
	//retourne la carte forte, une paire ou deux
	int PairFinder(std::vector<std::vector<Card>>& completeHand, int playernum, std::vector< std::vector<int>>& forceOfTheHand);
	int FullFinder(std::vector<std::vector<Card>>& completeHand, int playernum, std::vector< std::vector<int>>& forceOfTheHand);

	//pour trouver la meilleur carte
	int bestCardFinder(std::vector<std::vector<Card>>& completeHand, int playernum);


	//juste pour que ca soit claire dans la console
	const char *combinationType[10] = { "une carte forte de ", "une paire de ", "une double paire ", "un brelan de ", "une suite de ","une couleur ","un full de ", "un carre de ","une quinte flush ", "une quinte flush royale " };
	
	//retourne le meilleur joueur et indique une égalité entre deux, comparaison inter donc la liste strength suffit
	int BestPlayer(std::vector< std::vector<int>>& forceOfTheHand);
};

