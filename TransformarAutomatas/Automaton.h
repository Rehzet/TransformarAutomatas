#pragma once
#include <vector>
#include <string>

#include "State.h"

class Automaton {


public:
	Automaton();

	/* Adds a state to the automaton's states vector. */
	void addState(State state);

	/* This function checks if the word is accepted by the automaton.
	A word is accepted by the automaton if the last processed letter of the word ends in a final state. */
	bool checkWord(std::string word);

	/* Returns true if the automaton is deterministic.
	An automaton is deterministic when the symbols of the transitions of every state are not repeated. */
	bool isDeterministic();

	std::string toString();

	~Automaton();

private:

	/* Vector that contains all the automaton's states. */
	std::vector<State> states;

	/* Recursive function that checks if the word passed is accepted by the automaton. */
	bool checkWordRecursive(State state, std::string word);

};

