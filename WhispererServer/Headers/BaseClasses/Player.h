#pragma once

#include "stdafx.h"
#include <vector>
#include <iostream>     // std::cout
#include <algorithm>    // std::random_shuffle
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand
#include <memory>
#include "Card.h"

class Soul;

class Player
{
public:
	~Player();
	Player(vector<Card*> NewDeck, string NewUserName);

	int Health = 30;
	int MulligansTaken = 0;
	string UserName;
	bool KeepHand = false;

	int Devotion[6] = {1,1,1,1,1,1};
	vector<Card*> MainDeck;
	vector<Card*> Hand;
	vector<Soul*> SoulsInPlay;
	//vector<Swift*> SwiftsInPlay;
	//vector<Constant*> ConstantsInPlay;
	vector<Card*> Graveyard;

	
	string HandToString();
	string ToString();
	string SoulsInPlayToString();

	bool Compare(Player* OtherPlayer);
	bool IsPlayable(Card* ToPlay);

	void DrawCard();
	void DrawCard(int Amount);
	void ShuffleDeck();
	void HandToDeck();
	void PlayCard(Card* ToPlay, string Detail);

	void PrintDeck();
};
