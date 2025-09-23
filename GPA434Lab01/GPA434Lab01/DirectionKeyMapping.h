#pragma once
#ifndef _DIECTIONKEYMAPPING_H
#define _DIECTIONKEYMAPPING_H
#include <ezgame>



class DirectionKeyMapping
{
public:

	// Enum class
	enum class Direction { Left, Up, Right, Down };
	enum class StandardKeyMapping { WASD, IJKL, Arrows, Num8426 };

	// Constructeur
	DirectionKeyMapping(StandardKeyMapping = StandardKeyMapping::WASD);

	// Destructeur
	~DirectionKeyMapping();


	// Acccesseur
	ezgame::Keyboard::Key keyMapping(Direction direction) const;


	// Utilitaire
	ezgame::Vect2d directionFromKeyboard(ezgame::Keyboard const& keyboard) const;

	// Mutateurs
	void setKeyMapping(Direction direction, ezgame::Keyboard::Key key);
	void setKeyMapping(ezgame::Keyboard::Key left,
		ezgame::Keyboard::Key up,
		ezgame::Keyboard::Key right,
		ezgame::Keyboard::Key down);
	void setKeyMapping(StandardKeyMapping mapping);

private:
	ezgame::Keyboard::Key mLeftKeyMapping;
	ezgame::Keyboard::Key mUpKeyMapping;
	ezgame::Keyboard::Key mRightKeyMapping;
	ezgame::Keyboard::Key mDownKeyMapping;
};
#endif // _DIECTIONKEYMAPPING_H