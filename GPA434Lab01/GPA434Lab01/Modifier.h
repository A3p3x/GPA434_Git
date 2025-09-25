#pragma once
#ifndef _MODIFIER_H
#define _MODIFIER_H
#include <ezgame>
#include <string>
#include "Arena.h"
#include "Dome.h"
#include "Player.h"

class Modifier {

public:
	// enum class
	enum class Type { Bonus, Malus };
	enum class Effect { Speed, Size, Warping, Hit };

	// Accesseurs
	Type type();
	Effect effect();
	void randomize(Arena const& arena, Dome const& dome);
	void tic(Player& player0, Player& player1, Arena const& arena, Dome const& dome);
	void draw(ezgame::Screen& screen);
	void applyBonus(Player& player);
	void applyMalus(Player& player);

	// Constructeurs
	Modifier(Arena const& arena, Dome const& dome);

	// Destructeur
	~Modifier();

private:
	const float mDefaultTextSize = 25.0f;
	const ezgame::Color mDefaultTextColor{ 1.0f,1.0f,1.0f,0.5f };
	const float mDefaultShapeSize = 15;
	const ezgame::Color mDefaultShapeColor{ 0.9f,0.9f,0.9f,1.0f };
	const float mDefaultTypeShapeSize = 5.0f;
	const float mPlayerSizeIncrease = 1.15f;
	const float mPlayerSpeedIncrease = 1.15f;
	const float mPlayerSizeDecrease = 1.0f / mPlayerSpeedIncrease;
	const float mPlayerSpeedDecrease = 1.0f / mPlayerSpeedIncrease;
	const ezgame::Color mColorTypeBonus = ezgame::Color::Green;
	const ezgame::Color mColorTypeMalus = ezgame::Color::Red;
	const std::string mTextEffectSpeed = "Speed";
	const std::string mTextEffectSize = "Size";
	const std::string mTextEffectWarping = "Warping";
	const std::string mTextEffectHit = "hit";
	Type mType;
	Effect mEffect;
	ezgame::Text mText;
	ezgame::Circle mShape;
	ezgame::Circle mTypeShape;

};
#endif // _MODIFIER_H

