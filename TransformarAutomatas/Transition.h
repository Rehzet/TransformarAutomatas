#pragma once

#include "State.h"

class Transition {

public:
	Transition(State* nextState, int value);
	~Transition();

	const int EMPTY_WORD = -1;

private:
	State* nextState;
	int value;
};

