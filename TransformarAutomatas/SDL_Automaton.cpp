
#include "SDL_Automaton.h"
#include "SDL_Draw.h"

SDL_Automaton::SDL_Automaton(Automaton automaton) {
	this->automaton = automaton;

	TTF_Init();
	font = TTF_OpenFont("./Fonts/PressStart2P-Regular.ttf", 16);
	TTF_RenderText_Solid(font, "asd", { 255, 255, 255, 255 });

	for (int i = 0; i < GRID_WIDTH; i++) {
		for (int j = 0; j < GRID_HEIGHT; j++) {
			grid[i][j].x = i * grid[i][j].size;
			grid[i][j].y = j * grid[i][j].size;
			grid[i][j].center = { grid[i][j].x + RADIUS, grid[i][j].y + RADIUS };
		}
	}
}

SDL_Automaton::~SDL_Automaton() {
	font = NULL;
	delete font;
}

void SDL_Automaton::draw(SDL_Renderer &renderer) {
	showGrid(renderer);

	SDL_SetRenderDrawColor(&renderer, 255, 255, 255, 255);
	drawRecursive(renderer, &automaton.getStates().at(0), {1, 1}, {-1, -1});
}

void SDL_Automaton::drawRecursive(SDL_Renderer& renderer, State* state, SDL_Point position, SDL_Point lastPosition) {

	if (state->isFinalState()) {
		SDL_DrawCircle(&renderer, grid[position.x][position.y].center.x, grid[position.x][position.y].center.y, RADIUS - 10);
	}
	SDL_DrawCircle(&renderer, grid[position.x][position.y].center.x, grid[position.x][position.y].center.y, RADIUS);
	grid[position.x][position.y].occupied = true;

	lastPosition = position; // Save the position of the last circle drawn.
	position.x++;

	for (std::pair<State*, char> transition : state->getTransitions()) {

		if (state->getName() != transition.first->getName()) {
			drawTransition(renderer, lastPosition, { position.x + 1, position.y });

			if (transition.first != NULL)
				drawRecursive(renderer, transition.first, { position.x + 2, position.y }, lastPosition);

			position.y += 2;
		}
		else {
			drawSelfTransition(renderer, { lastPosition.x, lastPosition.y-1 });
		}
	}

}

void SDL_Automaton::drawTransition(SDL_Renderer &renderer, SDL_Point &statePosition, SDL_Point nextStatePosition) {
	
	SDL_RenderDrawLine(&renderer, 
		grid[statePosition.x+1][statePosition.y].x,
		grid[statePosition.x+1][statePosition.y].y + RADIUS,
		grid[nextStatePosition.x][nextStatePosition.y].x + grid[nextStatePosition.x][nextStatePosition.y].size,
		grid[nextStatePosition.x + 1][nextStatePosition.y].y + RADIUS);
}

void SDL_Automaton::drawSelfTransition(SDL_Renderer &renderer, SDL_Point statePosition) {

	// Lines

	int lineLength{ 30 };

	SDL_RenderDrawLine(&renderer, 
		grid[statePosition.x][statePosition.y].x + RADIUS,
		grid[statePosition.x][statePosition.y].y + grid[statePosition.x][statePosition.y].size,
		grid[statePosition.x][statePosition.y].x + RADIUS,
		grid[statePosition.x][statePosition.y].y + grid[statePosition.x][statePosition.y].size - lineLength);
	SDL_RenderDrawLine(&renderer, 
		grid[statePosition.x][statePosition.y].x + RADIUS,
		grid[statePosition.x][statePosition.y].y  + grid[statePosition.x][statePosition.y].size - lineLength,
		grid[statePosition.x][statePosition.y].x + RADIUS + lineLength, 
		grid[statePosition.x][statePosition.y].y + grid[statePosition.x][statePosition.y].size - lineLength);
	SDL_RenderDrawLine(&renderer, 
		grid[statePosition.x][statePosition.y].x + RADIUS + lineLength, 
		grid[statePosition.x][statePosition.y].y + grid[statePosition.x][statePosition.y].size - lineLength,
		grid[statePosition.x][statePosition.y].x + RADIUS + lineLength, 
		grid[statePosition.x][statePosition.y].y + grid[statePosition.x][statePosition.y].size);

	// Arrowhead
	int arrowSize = 10;

	SDL_RenderDrawLine(&renderer, 
		grid[statePosition.x][statePosition.y].x + RADIUS + lineLength, 
		grid[statePosition.x][statePosition.y].y + grid[statePosition.x][statePosition.y].size,
		grid[statePosition.x][statePosition.y].x + RADIUS + lineLength - arrowSize, 
		grid[statePosition.x][statePosition.y].y + grid[statePosition.x][statePosition.y].size - arrowSize );
	SDL_RenderDrawLine(&renderer, 
		grid[statePosition.x][statePosition.y].x + RADIUS + lineLength, 
		grid[statePosition.x][statePosition.y].y + grid[statePosition.x][statePosition.y].size,
		grid[statePosition.x][statePosition.y].x + RADIUS + lineLength + arrowSize, 
		grid[statePosition.x][statePosition.y].y + grid[statePosition.x][statePosition.y].size - arrowSize);

	grid[statePosition.x][statePosition.y].occupied = true;
}

void SDL_Automaton::showGrid(SDL_Renderer &renderer) {
	
	SDL_SetRenderDrawColor(&renderer, 50, 50, 50, 255);

	for(int i = 0; i < GRID_WIDTH; i++){
		SDL_RenderDrawLine(&renderer, i * RADIUS * 2, 0, i * RADIUS * 2, SCREEN_HEIGHT);
	}

	for (int j = 0; j < GRID_HEIGHT; j++) {
		SDL_RenderDrawLine(&renderer, 0, j * RADIUS * 2, SCREEN_WIDTH, j * RADIUS * 2);
	}


	SDL_SetRenderDrawColor(&renderer, 255, 0, 0, 255);
	for (int i = 0; i < GRID_WIDTH; i++) {
		for (int j = 0; j < GRID_HEIGHT; j++) {
			if (grid[i][j].occupied) {
				
				SDL_RenderDrawLine(&renderer,
					grid[i][j].x,
					grid[i][j].y,
					grid[i][j].x + grid[i][j].size,
					grid[i][j].y + grid[i][j].size);

			}
		}
	}




}