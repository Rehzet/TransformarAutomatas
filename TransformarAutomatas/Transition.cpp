#include "Transition.h"

Transition::Transition(State* nextState, char value) {
	this->nextState = nextState;
	this->value = value;
}

Transition::~Transition() {

}

State* Transition::getNextState() {
	return nextState;
}

char Transition::getValue() {
	return value;
}