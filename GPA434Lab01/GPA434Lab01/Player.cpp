#include "Player.h"

Player::Player(Role role, std::string const& name, ezgame::Color const& color, DirectionKeyMapping const& directionKeyMapping)
	: mRole(role),
	mName(name),
	mSpeed(mDefaultPlayerSpeed),
	mPlayerShape(mDefaultPlayerRadius, ezgame::Vect2d(0.0f, 0.0f), color),
	mBorderManagementShape(mDefaultBorderManagementRadius, ezgame::Vect2d(0.0f, 0.0f)),
	mHitScore(0),
	mTimeAsDefender(0.0f),
	mTimeAsContender(0.0f),
	mBorderManagement(BorderManagement::Restrict),
	mDirectionKeyMapping(directionKeyMapping)
{}

Player::~Player()
{}

Player::Role Player::role() const
{
	return ezgame::Random::enumerator (Player::Role::Defender,Player::Role::Contender);
}

std::string Player::name() const
{
	return mName;
}

ezgame::Color Player::color() const
{
	return mPlayerShape.fillColor();
}

float Player::speed() const
{
	return mSpeed;
}

size_t Player::hitScore() const
{
	return mHitScore;
}

float Player::timeAsDefender() const
{
	if (mRole == Player::Role::Defender) return mTimeAsDefender;
}

float Player::timeAsContender() const
{
	if (mRole == Player::Role::Contender) return mTimeAsContender;
}

Player::BorderManagement Player::borderManagement() const
{
	return mBorderManagement;
}

bool Player::isColliding(ezgame::Circle const otherCircle) const
{
	return mPlayerShape.isColliding(otherCircle);
}

bool Player::isColliding(Player const& player) const
{
	//return isColliding(mPlayerShape);
	return mPlayerShape.isColliding(player.mPlayerShape);
}

bool Player::isColliding(Dome& const dome) const
{
	return mPlayerShape.isColliding(dome.circle());
}

void Player::tic(ezgame::Keyboard const& keyboard, float elapsedTime, Arena const& arena)
{
	ezgame::Vect2d vecteurVitesse(0.0,0.0);
	
	if (mRole == Player::Role::Defender) {
		mTimeAsDefender += elapsedTime;
		Player::mSpeed = DirectionKeyMapping::directionFromKeyboard(keyboard) * mDefaultPlayerSpeed;
		
	}
	else if (mRole == Player::Role::Contender) {
		mTimeAsContender += elapsedTime;
		// a continuer
	}
}

void Player::draw(ezgame::Screen& screen)
{
	screen.draw(mPlayerShape);
	screen.draw(mBorderManagementShape);
}

void Player::newMatch(bool hit, bool swap, Arena const& arena, Dome const& dome)
{

}

void Player::newGame(Role role, Arena const& arena, Dome const& dome)
{

}

void Player::addHit()
{
	mHitScore ++;
}

void Player::removeHit()
{
	mHitScore --;
}

void Player::ajustSize(float relativeSize)
{
	mPlayerShape.adjustSize(relativeSize);
}

void Player::ajustSpeed(float relativeSpeed)
{
	mSpeed *= relativeSpeed;
}

void Player::setBorderManagement(BorderManagement borderManagement)
{
	mBorderManagement = borderManagement;
}