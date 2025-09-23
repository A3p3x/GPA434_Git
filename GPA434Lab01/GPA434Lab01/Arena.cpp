#include "Arena.h"

Arena::Arena(float width, float height)
	: mMinimumSize{ 50 }
	, mMaximumSize{ 2000 }
	,mWidth{ std::clamp(width, mMinimumSize, mMaximumSize) }
	,mHeight{ std::clamp(height, mMinimumSize, mMaximumSize) }
{}

Arena::~Arena() 
{}

float Arena::width() const
{
	return mWidth;
}

float Arena::height() const
{
	return mHeight;
}

ezgame::Vect2d Arena::center() const
{
	return ezgame::Vect2d(mWidth/2.0, mHeight/2.0); 
}

float Arena::smallerSize() const
{
	return std:: min(mWidth,mHeight);
}

float Arena::largerSize() const
{
	return std::max(mWidth, mHeight);
}

ezgame::Vect2d Arena::restrictedPosition(ezgame::Vect2d const& position)
{
	float rpx = position.x();
	float rpy = position.y();

	// borne en X
	if (rpx < mWidth && rpx > 0) rpx = position.x();
	else if (rpx > mWidth) rpx = mWidth;
	else if (rpx < 0) rpx = 0;

	// borne en Y
	if (rpy < mHeight && rpy > 0) rpy = position.y();
	else if (rpy > mHeight) rpy = mHeight;
	else if (rpy < 0) rpy = 0;

	return ezgame::Vect2d(rpx, rpy);
}

ezgame::Vect2d Arena::warpedPosition(ezgame::Vect2d const& position) 
{
	float wpx = position.x();
	float wpy = position.y();

	// borne en X
	if (wpx < mWidth && wpx > 0.0) wpx = position.x();
	else if (wpx > mWidth) wpx = 0.0;
	else if (wpx < 0.0) wpx = mWidth;

	// borne en Y
	if (wpy < mHeight && wpy > 0.0) wpy = position.y();
	else if (wpy > mHeight) wpy = 0.0;
	else if (wpy < 0.0) wpy = mHeight;

	return ezgame::Vect2d(wpx, wpy);
}

void Arena::tic(ezgame::Timer &elapsedTime) 
{
}

void Arena::draw(ezgame::Screen &screen)
{
	screen.clear();
}



