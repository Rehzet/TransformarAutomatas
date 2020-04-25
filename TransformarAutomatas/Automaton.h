#pragma once
#include <vector>
#include <string>

#include "State.h"

class Automaton {


public:
	Automaton();

	void addState(State state);

	std::string toString();

	~Automaton();

private:

	std::vector<State> states;		// States vector. 

};

