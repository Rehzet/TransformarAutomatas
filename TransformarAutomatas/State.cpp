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

void State::addTransition(Transition transition) {
	transitions.push_back(transition);
}

void State::addTransition(State* state, char value) {
	Transition t(state, value);

	transitions.push_back(t);
}

std::vector<Transition> State::getTransitions() {
	return transitions;
}

bool State::hasTransitions() {
	return !transitions.empty();
}

std::string State::toString() {

	std::string str = getName() + ": {\n";

	if (isFinalState()) {
		str += "    #Final state#\n";
	}

	for (Transition transition : transitions) {
		str += "    "; 
		str += transition.getValue();
		str += " --> " + transition.getNextState()->getName() + "\n";
	}

	str += "}\n";

	return str;
}

// ### GETTERS AND SETTERS ###

std::string State::getName() {
	return name;
}

bool State::isFinalState() {
	return finalState;
}
