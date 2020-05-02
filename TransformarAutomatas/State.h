#pragma once

#include <vector>
#include <string>


class State {

public:

	/* Creates a state.
	finalState: variable that determines if the state will be a final state or not. 
	name: just the name of the state. */
	State(bool finalState, std::string name);
	
	/* Creates a transition and adds it to the transitions vector. */
	void addTransition(State *nextState, char value);

	/* Returns the transitions vector. */
	std::vector<std::pair<State*, char>> getTransitions();

	/* Checks if the transitions vector is empty. */
	bool hasTransitions();

	std::string toString();

	/* Returns the name of the state. */
	std::string getName();

	/* Checks if the state is a final state. */
	bool isFinalState();

	~State();

private:
	
	bool finalState = false;
	std::string name = "";

	std::vector<std::pair<State*, char>> transitions;

};

