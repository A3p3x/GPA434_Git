#pragma once
#ifndef _PLAYER_H
#define _PLAYER_H
#include <ezgame>
#include <string> 
#include "Arena.h"
#include "Dome.h"
#include "DirectionKeyMapping.h"



class Player
{

public:
	// enum class
	enum class Role { Defender, Contender };
	enum class BorderManagement { Restrict, Warping };

	// Acceseurs
	Role role() const;
	std::string name() const;
	ezgame::Color color() const;
	float speed() const;
	size_t hitScore() const;
	float timeAsDefender() const;
	float timeAsContender() const;
	BorderManagement borderManagement() const;
	bool isColliding(ezgame::Circle const& otherCircle) const;
	bool isColliding(Player const& player) const;
	bool isColliding(Dome const& dome) const;
	void tic(ezgame::Keyboard const& keyboard, float elapsedTime, Arena const& arena);
	void draw(ezgame::Screen& screen);
	void newMatch(bool hit, bool swap, Arena const& arena, Dome const& dome);
	void newGame(Role role, Arena const& arena, Dome const& dome);
	void addHit();
	void removeHit();
	void ajustSize(float relativeSize);
	void ajustSpeed(float relativeSpeed);
	void setBorderManagement(BorderManagement borderManagement);


	// Constructeur
	Player(Role role, std::string const& name, ezgame::Color const& color, 
		   DirectionKeyMapping const& directionKeyMapping);

	// Destructeur
	~Player();

private:
	const float mDefaultPlayerRadius = 25.0f;
	const float mDefaultPlayerSpeed = 250.f;
	const float mDefaultBorderManagementRadius = 5.0f;
	Role mRole;
	std::string mName;
	float mSpeed;
	ezgame::Circle mPlayerShape;
	ezgame::Circle mBorderManagementShape;
	size_t mHitScore;
	float mTimeAsDefender;
	float mTimeAsContender;
	BorderManagement mBorderManagement;
	DirectionKeyMapping mDirectionKeyMapping;
	
};
#endif // _PLAYER_H