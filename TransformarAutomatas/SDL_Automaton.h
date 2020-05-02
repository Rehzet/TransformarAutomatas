#pragma once

#include <SDL.h>
#include <SDL_ttf.h>


#include "Automaton.h"
#include "Constants.h"

/**
* This class draws automatons using SDL.
*/
class SDL_Automaton {

public:
	/* Recieves the automaton that will be drawn. */
	SDL_Automaton(Automaton automaton);
	~SDL_Automaton();

	/* Draws the automaton using circles as states, and lines as transitions.*/
	void draw(SDL_Renderer& renderer);

private:

	// Data structure that represents a square in a grid.
	struct gridSquare {
		int x; // X coordinate
		int y; // Y coordinate
		int size = RADIUS * 2; // Size of the square.
		SDL_Point center = {x + RADIUS, y + RADIUS}; // Center of the square.
		bool occupied = false; // Is the square occupied by any state or not?
	};
	
	static const int RADIUS = 40; // Cicles radius.

	static const int GRID_WIDTH = SCREEN_WIDTH / (RADIUS * 2); // Grid width.
	static const int GRID_HEIGHT = SCREEN_HEIGHT / (RADIUS * 2); // Grid height.

	/* This function draws the automaton recursively, checking all the transitions for each state. */
	void drawRecursive(SDL_Renderer& renderer, State *state, SDL_Point position, SDL_Point lastPosition);

	/* Draw a line from one state to anothe state. */
	void drawTransition(SDL_Renderer &renderer, SDL_Point &statePosition, SDL_Point nextStatePosition);

	/* Draw a line from one state to the same state, with an arrow head at the end. */
	void drawSelfTransition(SDL_Renderer &renderer, SDL_Point statePosition);

	/* Function useful for debugging. Draws the grid squares and indicates which ones are occupied. */
	void showGrid(SDL_Renderer &renderer);

	Automaton automaton;

	TTF_Font* font = NULL;

	gridSquare grid[GRID_WIDTH][GRID_HEIGHT]; // Grid made of gridSquares. Each gridSquare can contain only one state.
};

