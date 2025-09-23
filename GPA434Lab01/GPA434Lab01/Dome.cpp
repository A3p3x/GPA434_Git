#include "Dome.h"

// Constructeur
Dome::Dome(Arena const& Arena)
// LIM
	: mEdgeColorLighterRatio{}
	, mEdgeSize{}
	, mShape{
			Arena.smallerSize() * 0.25f,
			Arena.center(),
			ezgame::Color::White,
			ezgame::Color::Black,
			mEdgeSize,
			ezgame::Alignment::CenterCenter
			}
{}

Dome::~Dome()
{}

float Dome::radius()
{
	return mShape.radius();
}

ezgame::Vect2d Dome::position() 
{
	return mShape.position();
}

ezgame::Circle Dome::circle()
{
	return mShape;
}

ezgame::Color Dome::color()
{
	return mShape.fillColor();
}

void Dome::setColor(ezgame::Color color)
{
	return mShape.setColors(color, color.lighter(mEdgeColorLighterRatio));
}

void tic(ezgame::Timer &elapsedTime)
{
}

void Dome::draw(ezgame::Screen &screen)
{
	return screen.draw(mShape);
}