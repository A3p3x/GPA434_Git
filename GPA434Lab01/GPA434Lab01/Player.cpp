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


										// & const ERREUR
bool Player::isColliding(ezgame::Circle const& otherCircle) const
{
	return mPlayerShape.isColliding(otherCircle);
}

bool Player::isColliding(Player const& player) const
{
	// return isColliding(mPlayerShape);
	return mPlayerShape.isColliding(player.mPlayerShape);
}

bool Player::isColliding(Dome const& dome) const
{
	return mPlayerShape.isColliding(dome.circle());
}

void Player::tic(ezgame::Keyboard const& keyboard, float elapsedTime, Arena const& arena)
{
	// Récupérer la direction à partir du clavier
	ezgame::Vect2d direction = mDirectionKeyMapping.directionFromKeyboard(keyboard);
	// Calculer le déplacement
	ezgame::Vect2d delta = direction * mDefaultPlayerSpeed * elapsedTime;
	// Mettre à jour la position du joueur
	ezgame::Vect2d nextPos = mPlayerShape.position() + delta;

	if (mRole == Player::Role::Defender) {
		
		if (mBorderManagement == BorderManagement::Restrict) {
			nextPos = arena.restrictedPosition(nextPos);
		}
		else if (mBorderManagement == BorderManagement::Warping) {
			nextPos = arena.warpedPosition(nextPos);
		}

		// Mettre à jour la position
		mPlayerShape.setPosition(nextPos);
	}
}

void Player::draw(ezgame::Screen& screen)
{
	screen.draw(mPlayerShape);
	screen.draw(mBorderManagementShape);
}

void Player::newMatch(bool hit, bool swap, Arena const& arena, Dome const& dome)
{
	if (hit) {
		addHit();
	}
	if (swap) {
		mRole = Role::Contender;
	else
		mRole = Role::Defender;
	}
	
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