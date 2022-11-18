#include "GameComparaison.h"


using namespace std;
GameComparaison::GameComparaison() {
	
	cout <<"\n"<<"Premier chiffre : Force de la combinaison (2 pour double paire et 8 pour Quinte Flush, etc. Deuxieme chiffre : Force de la carte paire/brelan. Troisieme chiffre : Force de la carte s'il y a une autre paire. Quatrieme chiffre : Force de la carte la plus haute."<<"\n" << endl;
	
	for (int i = 0; i < this->m_nbPlayer; i++)
	{
	//c'est pas beau comme pierre luc dirait mais ca marche tres bien, si une combinaison n 'existe pas on regarde si la suivante existe	
		if (QuinteFlushFinder(this->r_hands, i, r_strenghtPlayerHand) == 0) {
			if (CarreFinder(this->r_hands, i, r_strenghtPlayerHand) == 0) {
				if (FullFinder(this->r_hands, i, r_strenghtPlayerHand) == 0) {
					if (ColorFinder(this->r_hands, i, r_strenghtPlayerHand) == 0) {
						if (SuiteFinder(this->r_hands, i, r_strenghtPlayerHand) == 0) {
							if (BrelanFinder(this->r_hands, i, r_strenghtPlayerHand) == 0) {
								PairFinder(this->r_hands, i, r_strenghtPlayerHand);
							}
						}
					}
				}
			}
		}
		
		//A DECOMMENTER POUR VOIR LES COMBINAISONS DES JOUEURS

		cout << "Force de la main du joueur " << i +1 << " : " << endl;
		
		for (int j = 0; j < 4; j++)
		{
			cout << this->r_strenghtPlayerHand[i][j]<<" | ";
		}
		cout<< endl;
	}
	//permet l affichage correct
	int bestPlayer = BestPlayer(r_strenghtPlayerHand);
	vector<int> bestCombination = r_strenghtPlayerHand[bestPlayer-1]; 
	
	if (bestCombination[1]>1&& bestCombination[1] > bestCombination[2]) {
		cout << "\n"<<  "Le meilleur joueur est le " << bestPlayer << " avec " << combinationType[bestCombination[0]] << bestCombination[1]   <<" et sa meilleure carte est un " << bestCombination[3] << endl;
	}
	else if (bestCombination[2]!=0) {
		cout << "\n"<<  "Le meilleur joueur est le " << bestPlayer << " avec " << combinationType[bestCombination[0]] << bestCombination[2]<<   " et sa meilleure carte est un " << bestCombination[3] << endl;

	}
	else {
		cout << "\n"<< "Le meilleur joueur est le " << bestPlayer << " avec " << combinationType[bestCombination[0]] << bestCombination[3] << " et sa meilleure carte est un " << bestCombination[3] << endl;

	}
	
}

GameComparaison::~GameComparaison() {

}
int GameComparaison::PairFinder(std::vector<std::vector<Card>>& completeHand, int playernum, std::vector<  std::vector<int>>& forceOfTheHand) {
	int nbPaire = 0;
	int firstCard = 0;
	int secondCard = 0;
	//tempvector sert a rentrer les données dans strengthofthehand pour une comparaison future
	vector<int> tempVector;

	//j aime les for à chaque fois on saute quand l index est le meme :
	for (int i = 0; i < this->m_handSize; i++)
	{
		int valueCard = completeHand[playernum][i].Getm_value();
		for (int j = 0; j < this->m_handSize; j++)
		{	
			//ici par exemple
			if (i != j) {
				int valueSecondCard = completeHand[playernum][j].Getm_value();
				if (valueCard == valueSecondCard) {
					nbPaire++;
					if (firstCard == 0) {
						firstCard = valueCard;
					}
					else if (secondCard == 0 && firstCard != valueCard) {

						secondCard = valueCard;
					}
				}
			}

		}
	}
	
	//int p[3] = { nbPaire / 2, firstCard,secondCard };
	tempVector.push_back( nbPaire / 2);
	tempVector.push_back(firstCard);
	
	tempVector.push_back( secondCard);
	tempVector.push_back(bestCardFinder(completeHand, playernum));
	//cout << tempVector[0] << endl;
	forceOfTheHand.insert(forceOfTheHand.begin()+playernum,tempVector);
	//magie noire car les paires sont doublées nbpaire peut valoir :0,2,4
	return nbPaire/2;

}
int GameComparaison::BrelanFinder(std::vector<std::vector<Card>>& completeHand, int playernum, std::vector< std::vector<int>>& forceOfTheHand) {

	int brelan = 0;
	//3 cartes donc 3 for
	for (int i = 0; i < this->m_handSize; i++)
	{
		int valueCard = completeHand[playernum][i].Getm_value();
		for (int j = 0; j < this->m_handSize; j++)
		{
			if (i != j) {
				int valueSecondCard = completeHand[playernum][j].Getm_value();
				if (valueCard == valueSecondCard) {
					for (int z = 0; z < this->m_handSize; z++)
					{
						if (i != z &&j!=z) {
							int valueThirdCard = completeHand[playernum][z].Getm_value();
							if (valueSecondCard== valueThirdCard) {
								brelan = 1;
								vector<int> tempVector;
								
								tempVector.push_back(3);
								tempVector.push_back(valueThirdCard);
								tempVector.push_back(0);
								tempVector.push_back(bestCardFinder(completeHand, playernum));
								forceOfTheHand.push_back(tempVector);
							}
						}

					}
				}
			}

		}
	}
	
	return brelan;

}
int GameComparaison::CarreFinder(std::vector<std::vector<Card>>& completeHand, int playernum, std::vector< std::vector<int>>& forceOfTheHand) {

	int carre = 0;
	//4 cartes donc 4 for
	for (int i = 0; i < this->m_handSize; i++)
	{
		int valueCard = completeHand[playernum][i].Getm_value();
		for (int j = 0; j < this->m_handSize; j++)
		{
			if (i != j) {
				int valueSecondCard = completeHand[playernum][j].Getm_value();
				if (valueCard == valueSecondCard) {
					for (int z = 0; z < this->m_handSize; z++)
					{
						if (i != z && j != z) {
							int valueThirdCard = completeHand[playernum][z].Getm_value();
							if (valueSecondCard == valueThirdCard) {
								for (int y = 0; y < this->m_handSize; y++)
								{
									if (i != y && j != y &&z != y) {
										int valueFourthCard = completeHand[playernum][y].Getm_value();
										if (valueThirdCard==valueFourthCard) {
											carre = 1;
											vector<int> tempVector;

											tempVector.push_back(7);
											tempVector.push_back(valueThirdCard);
											tempVector.push_back(0);
											tempVector.push_back(bestCardFinder(completeHand, playernum));
											forceOfTheHand.push_back(tempVector);
										}
									}

								}
							}
						}

					}
				}
			}

		}
	}
	return carre;
	

}
int GameComparaison::FullFinder(std::vector<std::vector<Card>>& completeHand, int playernum, std::vector< std::vector<int>>& forceOfTheHand) {

	int brelan = 0;
	int full = 0;
	int brelanCardValue;
	vector<int> tempVector;
	//2 étapes le brelan si oui : recherche de paire
	for (int i = 0; i < this->m_handSize; i++)
	{
		int valueCard = completeHand[playernum][i].Getm_value();
		for (int j = 0; j < this->m_handSize; j++)
		{
			if (i != j) {
				int valueSecondCard = completeHand[playernum][j].Getm_value();
				if (valueCard == valueSecondCard) {
					for (int z = 0; z < this->m_handSize; z++)
					{
						if (i != z && j != z) {
							int valueThirdCard = completeHand[playernum][z].Getm_value();
							if (valueSecondCard == valueThirdCard) {
								brelan = 1;
								brelanCardValue = valueThirdCard;
							}
						}

					}
				}
			}

		}
	}
	if (brelan == 1) {
		int nbPaire = 0;
		for (int i = 0; i < this->m_handSize; i++)
		{
			int valueCard = completeHand[playernum][i].Getm_value();
			if (valueCard != brelanCardValue) {
				for (int j = 0; j < this->m_handSize; j++)
				{
					if (i != j) {
						int valueSecondCard = completeHand[playernum][j].Getm_value();
						if (valueCard == valueSecondCard) {
							nbPaire++;
							tempVector.push_back(6);
							tempVector.push_back(brelanCardValue);
							tempVector.push_back(valueCard);
							tempVector.push_back(bestCardFinder(completeHand, playernum));
						}
					}

				}
			}
			
		}
		if (nbPaire > 0) {
			full = 1;
			

			
			forceOfTheHand.push_back(tempVector);
		}
	}
	
	
	return full;

}
int GameComparaison::SuiteFinder(std::vector<std::vector<Card>>& completeHand, int playernum, std::vector< std::vector<int>>& forceOfTheHand) {
	int suite = 1;
	int valueBestCard = bestCardFinder(completeHand, playernum);
	vector<int> tempVector;
	vector<int> vcards;

	for (int i = 0; i < this->m_handSize ; i++)
	{
		vcards.push_back(completeHand[playernum][i].Getm_value());
	}
	for (int i = valueBestCard - 1; i > valueBestCard - this->m_handSize; i--)
	{
		//count ne compte pas il cherche si un élément existe dans le vector	
		if (count(vcards.begin(), vcards.end(), i)) {
			suite++;
		}
		else {
			suite = 0;
			break;
		}

	}
	//on considere l as comme un 1 si aucune suite n'est trouvée
	if (valueBestCard == 14 && suite == 0) {
		suite = 1;
		for (int i = 2; i < 6; i++)
		{

			if (count(vcards.begin(), vcards.end(), i)) {
				suite++;
			}
			if (suite == 5) {
				valueBestCard = i;
			}
			else {
				suite = 0;
				break;
			}

		}
		
	}
	
	
	if (suite == 5) {
		tempVector.push_back(4);
		tempVector.push_back(valueBestCard);
		tempVector.push_back(0);
		tempVector.push_back(bestCardFinder(completeHand, playernum));
		forceOfTheHand.push_back(tempVector);
	}
	return suite;
}
int GameComparaison::ColorFinder(std::vector<std::vector<Card>>& completeHand, int playernum, std::vector< std::vector<int>>& forceOfTheHand) {
	vector<int> tempVector;
	
	int color = 1;
	//on prend une carte de reference
	int colorFirstCard = completeHand[playernum][0].Getm_color();
	for (int i = 1; i < this->m_handSize; i++) {
		if (colorFirstCard == completeHand[playernum][i].Getm_color()) {
			color++;
		}
		else {
			color = 0;
			break;
		}
	}
	if (color == 5) {
		tempVector.push_back(5);
		tempVector.push_back(1);
		tempVector.push_back(0);
		tempVector.push_back(bestCardFinder(completeHand, playernum));
		forceOfTheHand.push_back(tempVector);
	}
	return color;
}
int GameComparaison::QuinteFlushFinder(std::vector<std::vector<Card>>& completeHand, int playernum, std::vector< std::vector<int>>& forceOfTheHand) {
	int quinteFlush = 0;
	vector<int> tempVector;


	int suite = 1;
	int valueBestCard = bestCardFinder(completeHand, playernum);
	
	vector<int> vcards;
	//j aurai pu appeler le suite finder et le couleurfinder mais a cause du tempvector les index auraient été décalé

	//donc c'est la meme mais sans les vectors
	for (int i = 0; i < this->m_handSize; i++)
	{
		vcards.push_back(completeHand[playernum][i].Getm_value());
	}
	for (int i = valueBestCard - 1; i > valueBestCard - this->m_handSize; i--)
	{

		if (count(vcards.begin(), vcards.end(), i)) {
			suite++;
		}
		else {
			suite = 0;
			break;
		}

	}
	if (valueBestCard == 14&&suite==0) {
		suite = 1;
		for (int i = 2; i < 6; i++)
		{
			if (count(vcards.begin(), vcards.end(), i)) {
				suite++;
			}
			else {
				suite = 0;
				break;
			}

		}
	}
	if (suite == 5) {
		int color = 1;

		int colorFirstCard = completeHand[playernum][0].Getm_color();
		for (int i = 1; i < this->m_handSize; i++) {
			if (colorFirstCard == completeHand[playernum][i].Getm_color()) {
				color++;
			}
			else {
				color = 0;
				break;
			}
		}
		
		if (color == 5) {
			quinteFlush = 8;
			//ca c'est juste pour la royale
			if (bestCardFinder(completeHand, playernum) == 14) {
				vector<int> vcards;
				for (int i = 0; i < this->m_handSize; i++)
				{
					vcards.push_back(completeHand[playernum][i].Getm_value());
				}
				if (count(vcards.begin(), vcards.end(), 13)) {
					//c'est impossible à choper mais si vous forcez les combis ca marche
					quinteFlush = 9;
				}
			}
			tempVector.push_back(quinteFlush);
			tempVector.push_back(1);
			tempVector.push_back(0);
			tempVector.push_back(bestCardFinder(completeHand, playernum));
			
			forceOfTheHand.push_back(tempVector);
		}
	}
	return quinteFlush;
}
int GameComparaison::bestCardFinder(std::vector<std::vector<Card>>& completeHand, int playernum) {
	int valueCard = 0;

	//simple comparaison c'est trivial
	for (int i = 0; i < this->m_handSize; i++)
	{
		int valueActualCard = completeHand[playernum][i].Getm_value();
		if (valueActualCard > valueCard) {
			valueCard = valueActualCard;
		}
	}

	return valueCard;
}
int GameComparaison::BestPlayer(std::vector< std::vector<int>>& forceOfTheHand) {
	//int bestCombination = forceOfTheHand[0][0];
	vector<int> bestCombination = forceOfTheHand[0];
	int bestPlayer = 0;
	for (int i = 1; i < forceOfTheHand.size(); i++)
	{
		vector<int> actualCombination = forceOfTheHand[i];
		//un peu de magie noire ou on check les combinaisons une à une et on fait remonté le meilleur joueur
		if (actualCombination[0] == bestCombination[0]) {
			if (actualCombination[1] == bestCombination[1]&& actualCombination[1]== bestCombination[2]) {
				if (actualCombination[2] == bestCombination[1] && actualCombination[2] == bestCombination[2]) {
					if (actualCombination[3] == bestCombination[3]) {
						cout << "egalite entre le joueur " << bestPlayer + 1 << " et " << i + 1 << endl;
						bestPlayer = i;
						bestCombination = actualCombination;
					}
					else if (actualCombination[3] > bestCombination[3]) {
						bestPlayer = i;
						bestCombination = actualCombination;
					}
				}
				else if (actualCombination[2] > bestCombination[2] && actualCombination[2] > bestCombination[2]) {
					bestPlayer = i;
					bestCombination = actualCombination;
				}
			}
			else if (actualCombination[1] > bestCombination[1] && actualCombination[1] > bestCombination[2]) {
				bestPlayer = i;
				bestCombination = actualCombination;
			}
		}else if (actualCombination[0] > bestCombination[0]) {
			bestPlayer = i;
			bestCombination = actualCombination;
		}
		
	}
	//magie noire pour éviter le joueur 0
	return bestPlayer+1;
}