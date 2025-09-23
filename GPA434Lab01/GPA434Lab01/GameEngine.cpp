#include "GameEngine.h"

GameEngine::GameEngine()
    : mArena(800.0f, 600.0f)
    , mDome(mArena)
	, mText("EzGame", 36.0f, ezgame::Vect2d(400.0f, 100.0f), ezgame::Color(0.15f, 0.25f, 1.0f),
		     ezgame::Alignment::CenterCenter)
	, mCircle(50.0f, ezgame::Vect2d(400.0f, 300.0f), ezgame::Color::Yellow, ezgame::Color::Red,
		      5.0f)
{}

GameEngine::~GameEngine()
{}


float GameEngine::width() const { return mArena.width(); }
float GameEngine::height() const { return mArena.height();}
std::string GameEngine::title() const { return "EzGame Test"; }                                 
std::string GameEngine::iconFileName() const { return "Phil's Game"; }

bool GameEngine::processEvents(ezgame::Keyboard const& keyboard, ezgame::Timer const& timer) {
    /*if (keyboard.isKeyPressed(ezgame::Keyboard::Key::Space)) {
        mCircle.move(ezgame::Vect2d::fromRandomized() * 2.5f);                        
    }      */                                                                         
    return !keyboard.isKeyPressed(ezgame::Keyboard::Key::Escape);                    
}

void GameEngine::processDisplay(ezgame::Screen& screen) {
    
    screen.clear();
    mArena.draw(screen);
    mDome.draw(screen);  
    screen.draw(mText);                                                              
    screen.draw(mCircle);                                                            
}