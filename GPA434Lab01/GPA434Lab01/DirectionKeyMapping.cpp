#include "DirectionKeyMapping.h"

DirectionKeyMapping::DirectionKeyMapping(StandardKeyMapping standardkeyMapping)
	 :mLeftKeyMapping{}
	 ,mUpKeyMapping{}
	 ,mRightKeyMapping{}
	 ,mDownKeyMapping{}
{ 
	setKeyMapping(standardkeyMapping);
}

DirectionKeyMapping::~DirectionKeyMapping()
{}

ezgame::Keyboard::Key DirectionKeyMapping::keyMapping(Direction direction) const
{
	switch (direction) 
	{
		case Direction::Left:  return mLeftKeyMapping;
		case Direction::Up:    return mUpKeyMapping;
		case Direction::Right: return mRightKeyMapping;
		case Direction::Down:  return mDownKeyMapping;
	}
}

ezgame::Vect2d DirectionKeyMapping::directionFromKeyboard(ezgame::Keyboard const& keyboard) const
{
	ezgame::Vect2d vecteurVide(0.0f, 0.0f);

	if (keyboard.isKeyPressed(mLeftKeyMapping)) vecteurVide.setX(-1.0f);
	if (keyboard.isKeyPressed(mUpKeyMapping)) vecteurVide.setY(1.0f);
	if (keyboard.isKeyPressed(mRightKeyMapping)) vecteurVide.setX(1.0f);
	if (keyboard.isKeyPressed(mDownKeyMapping)) vecteurVide.setX(-1.0f); 
	if (vecteurVide.length() > 0) vecteurVide.isNormalized();
	ezgame::Vect2d(0.0f, 0.0f);
}

void DirectionKeyMapping::setKeyMapping(Direction direction, ezgame::Keyboard::Key key)
{
	switch (direction)
	{
	case Direction::Left:  mLeftKeyMapping = key; break;
	case Direction::Up:    mUpKeyMapping = key; break;
	case Direction::Right: mRightKeyMapping = key; break;
	case Direction::Down:  mDownKeyMapping = key; break;
	}
}

void DirectionKeyMapping::setKeyMapping(ezgame::Keyboard::Key left,
	ezgame::Keyboard::Key up,
	ezgame::Keyboard::Key right,
	ezgame::Keyboard::Key down)
{
	mLeftKeyMapping = left;
	mUpKeyMapping = up;
	mRightKeyMapping = right;
	mDownKeyMapping = down;
}

void DirectionKeyMapping::setKeyMapping(StandardKeyMapping mapping)
{
	using Key = ezgame::Keyboard::Key;
	switch (mapping)
	{
	case StandardKeyMapping::WASD:    setKeyMapping(Key::A, Key::W, Key::D, Key::S);    break;
	case StandardKeyMapping::IJKL:    setKeyMapping(Key::J, Key::I, Key::L, Key::K);    break;
	case StandardKeyMapping::Arrows:  setKeyMapping(Key::Left, Key::Up, Key::Right, Key::Down); break;
	case StandardKeyMapping::Num8426: setKeyMapping(Key::Num4, Key::Num8, Key::Num6, Key::Num2); break;
	}
}