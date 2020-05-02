
#include "SDL_Automaton.h"
#include "SDL_Draw.h"

// TODO: Crear cuadrícula para colocar los estados e impedir así que dos o más estados estén en el mismo sitio.

SDL_Automaton::SDL_Automaton(Automaton automaton) {
	this->automaton = automaton;

	TTF_Init();
	font = TTF_OpenFont("./Fonts/PressStart2P-Regular.ttf", 16);
	TTF_RenderText_Solid(font, "asd", { 255, 255, 255, 255 });

	for (int i = 0; i < GRID_WIDTH; i++) {
		for (int j = 0; j < GRID_HEIGHT; j++) {
			grid[i][j] = false;
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
	drawRecursive(&automaton.getStates().at(0), 0, -1, 0, renderer);
}

void SDL_Automaton::drawRecursive(State* state, int xIndex, int lastXIndex, int y, SDL_Renderer& renderer) {

	SDL_Point circlePosition = { xIndex * 300 + 100 , DEFAULT_HEIGHT};
	SDL_Point nextCirclePosition = { (xIndex + 1) * 300 + 100 , DEFAULT_HEIGHT + y};

	if (state->isFinalState()) {
		SDL_DrawCircle(&renderer, circlePosition.x, circlePosition.y + y, RADIUS - 10);
	}
	SDL_DrawCircle(&renderer, circlePosition.x, circlePosition.y + y, RADIUS);

	for (std::pair<State*, char> transition : state->getTransitions()) {
		
		
		if (xIndex != lastXIndex) {
			if (state->getName() != transition.first->getName()) {

				drawTransition(renderer, { circlePosition.x , circlePosition.y}, {nextCirclePosition.x, nextCirclePosition.y});



				if(transition.first != NULL)
					drawRecursive(transition.first, xIndex + 1, xIndex, y, renderer);

				y += 100;
				nextCirclePosition.y += y;
				
			}
			else {
				drawSelfTransition(renderer, {circlePosition.x, circlePosition.y + y});
				drawRecursive(transition.first, xIndex, xIndex, y, renderer);
			}
		}
	}

}

void SDL_Automaton::drawTransition(SDL_Renderer &renderer, SDL_Point statePosition, SDL_Point nextStatePosition) {
	SDL_RenderDrawLine(&renderer, statePosition.x + RADIUS, statePosition.y, nextStatePosition.x - RADIUS, nextStatePosition.y);		
}

void SDL_Automaton::drawSelfTransition(SDL_Renderer &renderer, SDL_Point statePosition) {

	// Lines
	SDL_RenderDrawLine(&renderer, statePosition.x, statePosition.y - RADIUS, statePosition.x, statePosition.y - RADIUS - 30);
	SDL_RenderDrawLine(&renderer, statePosition.x, statePosition.y - RADIUS - 30, statePosition.x + RADIUS / 2, statePosition.y - RADIUS - 30);
	SDL_RenderDrawLine(&renderer, statePosition.x + RADIUS / 2, statePosition.y - RADIUS - 30, statePosition.x + RADIUS / 2, statePosition.y - (RADIUS));

	// Arrowhead
	int arrowSize = 10;

	SDL_RenderDrawLine(&renderer, statePosition.x + RADIUS / 2, statePosition.y - RADIUS, statePosition.x + RADIUS / 2 - arrowSize, statePosition.y - RADIUS - arrowSize );
	SDL_RenderDrawLine(&renderer, statePosition.x + RADIUS / 2, statePosition.y - RADIUS, statePosition.x + RADIUS / 2 + arrowSize, statePosition.y - RADIUS - arrowSize);

}

void SDL_Automaton::showGrid(SDL_Renderer &renderer) {

	SDL_SetRenderDrawColor(&renderer, 50, 50, 50, 255);

	for(int i = 0; i < GRID_WIDTH; i++){
		SDL_RenderDrawLine(&renderer, i * RADIUS * 2, 0, i * RADIUS * 2, SCREEN_HEIGHT);
	}

	for (int j = 0; j < GRID_HEIGHT; j++) {
		SDL_RenderDrawLine(&renderer, 0, j * RADIUS * 2, SCREEN_WIDTH, j * RADIUS * 2);
	}
}