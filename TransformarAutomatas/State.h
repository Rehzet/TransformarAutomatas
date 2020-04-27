#pragma once

#include <vector>
#include <string>

#include "Transition.h"

class State {

public:

	/* Creates a state.
	finalState: variable that determines if the state will be a final state or not. 
	name: just the name of the state. */
	State(bool finalState, std::string name);
	
	/* Adds a transition to the transitions vector. */
	void addTransition(Transition transition);

	/* Creates a transition and adds it to the transitions vector. */
	void addTransition(State* state, char value);

	/* Returns the transitions vector. */
	std::vector<Transition> getTransitions();

	/* Checks if the transitions vector is empty. */
	bool hasTransitions();

	std::string toString();

	/* Returns the name of the state. */
	std::string getName();

	/* Checks if the state is a final state. */
	bool isFinalState();

	~State();

private:
	
	bool finalState;
	std::string name;

	std::vector<Transition> transitions;

};

