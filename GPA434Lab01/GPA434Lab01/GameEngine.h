#pragma once
#ifndef _GAMEENGINE_H
#define _GAMEENGINE_H
#include <EzGame>
#include "Arena.h"
#include "Dome.h"

class GameEngine
{
public:
	// Accesseurs
	float width() const;
	float height() const;
	std::string title() const;
	std::string iconFileName() const;

	// Constructeur
	GameEngine();

	// Destructeur
	~GameEngine();

	// Fonction utilitaires
	bool processEvents(ezgame::Keyboard const& keyboard, ezgame::Timer const& timer);
	void processDisplay(ezgame::Screen& screen);

private:
	ezgame::Text mText;
	ezgame::Circle mCircle;
	Arena mArena;
	Dome mDome;



};
#endif // _GAMEENGINE_H

