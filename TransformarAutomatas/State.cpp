#include "State.h"


// ### CONSTRUCTORS AND DESTRUCTOR ###


/** 
* \brief Create a state and decide if it's final state or not.
*
* \param finalState Specifies if the state will have transitions or not.
*/
State::State(bool finalState) {
	this->finalState = finalState;

	if (finalState) 
		transitions.reserve(0);
	
}

State::~State() {

}

// ### FUNCTIONS ###

void State::addTransition(Transition transition) {
	transitions.push_back(transition);
}

// ### GETTERS AND SETTERS ###

bool State::isFinalState() {
	return finalState;
}
