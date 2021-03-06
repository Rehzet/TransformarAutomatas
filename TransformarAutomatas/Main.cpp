
#include <SDL.h>
#include "SDL_Draw.h"

#include <iostream>
#include <cmath>

#include "SDL_Automaton.h"
#include "Constants.h"




const char* WINDOW_TITLE = "Automaton";

// FORWARD DECLARATIONS
bool init();
bool loadMedia();

void gameLoop();
void events();
void close();

void SDL_DrawEllipse(SDL_Renderer* r, int x0, int y0, int radiusX, int radiusY);

// VARIABLES

bool quit;
bool pause;

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

Automaton* a = NULL;
SDL_Automaton* sdla = NULL;

State q0(false, "q0");
State q1(false, "q1");
State q2(true, "q2");
State q3(true, "q3");

bool init() {

    quit = false;
    pause = true;

    bool success = true;


    // SDL INIT
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("ERROR %s\n", SDL_GetError());
        success = false;
    }
    else {
        window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH + 1, SCREEN_HEIGHT + 1, SDL_WINDOW_SHOWN);

        if (window == NULL) {
            printf("Window error %s\n", SDL_GetError());
            success = false;
        }
        else {
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
            if (renderer == NULL) {
                success = false;
            }
        }

    }



    // AUTOMATON INIT
   /* Automaton a;

    State q0(false, "q0");
    State q1(true, "q1");

    //Transition t1(&q1, "a");

    q0.addTransition(&q1, "a");

    a.addState(q0);
    a.addState(q1);

    std::cout << a.toString() << std::endl;
    */
    
      



    q0.addTransition(&q1, 'a');

    q1.addTransition(&q1, 'b');
    q1.addTransition(&q2, 'a');
    q1.addTransition(&q3, 'a');

    a = new Automaton();

    a->addState(q0);
    a->addState(q1);
    a->addState(q2);
    a->addState(q3);

    sdla = new SDL_Automaton(*a);

    std::cout << a->toString() << "\n";

    std::cout << a->checkWord("abba") << "\n";
    std::cout << a->checkWord("abab") << "\n";
    std::cout << a->checkWord("a") << "\n";

    

   /*
    Automaton a;

    State q0(false, "q0");
    State q1(false, "q1");
    State q2(true, "q2");
    State q3(true, "q3");

    Transition tq0_1(&q1, 'a');
    q0.addTransition(tq0_1);


    Transition tq1_2(&q2, 'b');
    Transition tq1_1(&q1, 'b');
    Transition tq1_3(&q3, 'a');
    q1.addTransition(tq1_1);
    q1.addTransition(tq1_2);
    q1.addTransition(tq1_3);

    Transition tq2_1(&q2, 'b');
    q2.addTransition(tq2_1);

    a.addState(q0);
    a.addState(q1);
    a.addState(q2);
    a.addState(q3);

    std::cout << a.toString() << "\n";

    std::cout << a.checkWord("abba") << "\n";
    std::cout << a.checkWord("abab") << "\n";
    std::cout << a.checkWord("a") << "\n";

    */
    
    std::cout << "Deterministic? ";
    if (a->isDeterministic())
        std::cout << "True\n";
    else
        std::cout << "False\n";

    return success;
}

bool loadMedia() {
    bool success = true;

    return success;
}

void close() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    window = NULL;
    renderer = NULL;
    sdla = NULL;
    a = NULL;

    SDL_Quit();
}


void events() {
    SDL_Event event;

    while (SDL_PollEvent(&event) != 0) {

        switch (event.type) {
        case SDL_QUIT:
            quit = true;
            break;

        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
                case SDLK_ESCAPE:
                    quit = true;
                    break;

                default:
                    break;
            }
            break;
        }
    }

}

void gameLoop() {
    
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

    
    sdla->draw(*renderer);

    /*
    SDL_DrawEllipse(renderer, 300, 300, 200, 300);
    SDL_DrawCircle(renderer, 100, 190, 143);
    */


}

int main(int argc, char* args[]) {

    if (!init()) {
        printf("Failed to initialize.\n");
    }
    else {
        if (!loadMedia()) {
            printf("Failed to load media\n");
        }
        else {
            
            while (!quit) {

                events();

                // Clear screen
                SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
                SDL_RenderClear(renderer);

                // Functions here

                gameLoop();

                // Update screen
                SDL_RenderPresent(renderer);
            }
        }
    }


    close();
    return 0;
}