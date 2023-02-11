#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "StandardIncludes.h"

class GameController : public Singleton<GameController>
{
public:
	//Contructors/Destructors
	GameController();
	virtual ~GameController();

	//Methods
	void RunGame();

private:
	//Members
	SDL_Event m_sdlEvent;
};

#endif // !GAME_CONTROLLER_H


