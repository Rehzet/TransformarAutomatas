#pragma once

#include <string>
//#include "State.h"
class State;


class Transition {

public:

	Transition(State *nextState, char value);
	~Transition();

	State* getNextState();
	char getValue();


private:
	State* nextState;
	char value;
};

