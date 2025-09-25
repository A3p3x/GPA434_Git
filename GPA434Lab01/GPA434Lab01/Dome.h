#pragma once
#ifndef _DOME_H
#define _DOME_H
#include <ezgame>
#include "Arena.h"

class Dome
{
public:
	// Constructeur, pk pas(Arena::Arena ici??
	Dome(Arena const& Arena);

	// Destructeur
	~Dome();

	// Accesseurs
	const float radius();
	ezgame::Vect2d position() const;
	ezgame::Circle circle() const;
	ezgame::Color color() const;
	void setColor(ezgame::Color& color);
	void tic(ezgame::Timer& elapsedTime);
	void draw(ezgame::Screen& screen);

private:
	const float mEdgeColorLighterRatio = 0.75f;
	const float mEdgeSize = 1.5f;
	ezgame::Circle mShape;
};
#endif // _DOME_H