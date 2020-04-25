#include "Automaton.h"

Automaton::Automaton() {

}

Automaton::Automaton(int states, int elements) {
	statesVector.reserve(states);

	for (int i = 0; i < statesVector.size(); i++) {
		statesVector.at(i).reserve(elements);
	}
}

std::string Automaton::toString() {
	std::string str = "Automaton: {\n";


	str += "}";

	return str;
}


Automaton::~Automaton() {
	
}
