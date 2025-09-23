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
	float radius();
	ezgame::Vect2d position();
	ezgame::Circle circle();
	ezgame::Color color();
	void setColor(ezgame::Color color);
	// Est-ce que je peut avoir deux fct puclic avec le meme nom Arena/Dome
	void tic(ezgame::Timer& elapsedTime);
	void draw(ezgame::Screen& screen);

private:
	float mEdgeColorLighterRatio = 0.75f;
	float mEdgeSize = 1.5f;
	ezgame::Circle mShape;
};
#endif // _DOME_H