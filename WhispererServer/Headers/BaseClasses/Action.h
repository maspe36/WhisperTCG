#pragma once
#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

class Player;
class Card;
class Creature;

class Action
{
public:
	vector<Card*> CardTargets;
	vector<Player*> PlayerTargets;
	Creature* Attacker;
	Creature* Target;
	Player* PlayerTarget;
	Player* Owner;

	enum _ActionType
	{
		Attack,
		Damage,
		Heal,
		Buff,
		Debuff,
		Draw,
		Discard,
		Summon,
		Destroy,
		TurnStart,
		TurnEnd
	} ActionType;

	// We keep this because in the game loop (Located in GameState->PlayState()) we reuse the same Action object most of the time.
	Action();
	// Generic actions like turnstart and end that don't specifically target
	Action(Player* Owner, _ActionType ActionType);
	// Only card targets
	Action(vector<Card*> CardTargets, Player* Owner, _ActionType ActionType);
	// Only player targets
	Action(vector<Player*> PlayerTargets, Player* Owner, _ActionType ActionType);
	// Attacking and defending creature
	Action(Creature* Attacker, Creature* Target, Player* Owner, _ActionType ActionType);
	// Attacking and defending player
	Action(Creature* Attacker, Player* PlayerTarget, Player* Owner, _ActionType ActionType);
	// Card AND player targets
	Action(vector<Card*> CardTargets, vector<Player*> PlayerTargets, Player* Owner, _ActionType ActionType);
	~Action();
};