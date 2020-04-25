#include "Automaton.h"

Automaton::Automaton() {
}

void Automaton::addState(State state) {
	states.push_back(new State(false));
}

std::string Automaton::toString() {
	std::string str = "Automaton: {\n";


	str += "}";

	return str;
}


Automaton::~Automaton() {
	
}
