#pragma once

#include <SDL.h>
#include <SDL_ttf.h>


#include "Automaton.h"
#include "Constants.h"

class SDL_Automaton {

public:
	SDL_Automaton(Automaton automaton);
	~SDL_Automaton();

	void draw(SDL_Renderer& renderer);

private:
	
	static const int RADIUS = 40;
	static const int DEFAULT_HEIGHT = SCREEN_HEIGHT / 2 - RADIUS / 2;

	static const int GRID_WIDTH = SCREEN_WIDTH / (RADIUS * 2);
	static const int GRID_HEIGHT = SCREEN_HEIGHT / (RADIUS * 2);

	void drawRecursive(State *state, int xIndex, int lastXIndex, int y, SDL_Renderer& renderer);

	void drawTransition(SDL_Renderer &renderer, SDL_Point statePosition, SDL_Point nextStatePosition);
	void drawSelfTransition(SDL_Renderer &renderer, SDL_Point statePosition);

	void showGrid(SDL_Renderer &renderer);

	Automaton automaton;

	TTF_Font* font = NULL;

	bool grid[GRID_WIDTH][GRID_HEIGHT];
};

