#include "State.h"

// ### CONSTRUCTORS AND DESTRUCTOR ###



/// Creates a state and decide if it's final state or not.
/// param finalState Specifies if the state will have transitions or not.
State::State(bool finalState, std::string name) {
	this->finalState = finalState;
	this->name = name;	
}

State::~State() {

}

// ### FUNCTIONS ###

void State::addTransition(State *nextState, char value) {


	transitions.push_back(std::make_pair(nextState, value));
}

std::vector<std::pair<State*, char>> State::getTransitions() {
	return transitions;
}

bool State::hasTransitions() {
	return !transitions.empty();
}

std::string State::toString() {

	std::string str = getName() + ": \n";

	if (isFinalState()) {
		str += "    #Final state#\n";
	}

	for (std::pair<State*, char> transition : transitions) {
		str += "    "; 
		str += transition.second;
		str += " --> " + transition.first->getName() + "\n";
	}

	return str;
}

// ### GETTERS AND SETTERS ###

std::string State::getName() {
	return name;
}

bool State::isFinalState() {
	return finalState;
}
