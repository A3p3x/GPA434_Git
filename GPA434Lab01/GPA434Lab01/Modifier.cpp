#include "Modifier.h"

Modifier::Modifier(Arena const& arena, Dome const& dome)
{
	// Appel randomise
}

Modifier::~Modifier() 
{
}

Modifier::Type Modifier::type() 
{
	return mType;
}

Modifier::Effect Modifier::effect()
{
	return mEffect;
}
	

void Modifier::randomize(Arena const& arena, Dome const& dome) 
{

	 ezgame::Vect2d spawnModifcenter = arena.center();
	 const float spawnModifInnerRadius = 0.25f * arena.smallerSize();
	 const float spawnModifOuterRadius = 0.5f * arena.smallerSize();
	
mType = ezgame::Random::enumerator(Modifier::Type::Bonus, Modifier::Type::Malus);

if (mType == Type::Bonus) mTypeShape.setFill(ezgame::Color::Green);

else if (mType == Type::Malus) mTypeShape.setFill(ezgame::Color::Red);

mEffect = ezgame::Random::enumerator(Modifier::Effect::Speed, Modifier::Effect::Size,
									 Modifier::Effect::Warping, Modifier::Effect::Hit);
if (mEffect == Effect::Speed)   mText.setText( Modifier::mTextEffectSpeed);
if (mEffect == Effect::Size)    mText.setText(Modifier::mTextEffectSize);
if (mEffect == Effect::Warping) mText.setText(Modifier::mTextEffectWarping);
if (mEffect == Effect::Hit)     mText.setText(Modifier::mTextEffectHit);

	



mTypeShape.adjustSize(mDefaultTypeShapeSize);





}