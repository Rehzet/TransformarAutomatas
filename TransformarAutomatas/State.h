#pragma once

#include <vector>

#include "Transition.h"

class State {

public:
	State(bool finalState);

	bool isFinalState();

	void addTransition(Transition transition);

	~State();

private:
	
	bool finalState;

	std::vector<Transition> transitions;

};

