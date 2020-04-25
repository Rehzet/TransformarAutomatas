#include "Transition.h"


Transition::Transition(State* nextState, int value) {
	this->nextState = nextState;
	this->value = value;
}

Transition::~Transition() {

}
