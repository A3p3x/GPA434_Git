#pragma once
#ifndef _ARENA_H
#define _ARENA_H
#include <ezgame>

class Arena
{
public:
	// Accesseurs
	float width() const;
	float height() const;
	ezgame::Vect2d center() const;
	float smallerSize() const;
	float largerSize() const;

	// Constructeurs
	Arena(float width, float height);

	// Destructeur 
	~Arena();

	// Fonction utilitaires
	ezgame::Vect2d restrictedPosition(ezgame::Vect2d const& position);
	ezgame::Vect2d warpedPosition(ezgame::Vect2d const& position);
	void tic(ezgame::Timer& elapsedTime);

	// Fonction de dessin:
	void draw(ezgame::Screen& screen);

private:
	float mMinimumSize;
	float mMaximumSize;
	float mWidth;
	float mHeight;
	

public:
	// Accesseurs
	float width() const;
	float height() const;
	ezgame::Vect2d center() const;
	float smallerSize() const;
	float largerSize() const;

	// Constructeurs
	Arena(float width, float height);

	// Destructeur 
	~Arena();

	// Fonction utilitaires
	ezgame::Vect2d restrictedPosition(ezgame::Vect2d const& position) const;
	ezgame::Vect2d warpedPosition(ezgame::Vect2d const& position) const;
	void tic(ezgame::Timer &elapsedTime);
		
	// Fonction de dessin:
	void draw(ezgame::Screen &screen);
};
#endif // _ARENA_H

