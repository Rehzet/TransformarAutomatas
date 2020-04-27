#include "Automaton.h"

Automaton::Automaton() {
}


void Automaton::addState(State state) {
	states.push_back(state);
}


bool Automaton::checkWord(std::string word) {
	return checkWordRecursive(states.front(), word);
}

bool Automaton::checkWordRecursive(State state, std::string word) {
	if (word.empty()) {
		return state.isFinalState();
	}
	else {
		for (Transition transition : state.getTransitions()) {
			if (transition.getValue() == word[0])
				return checkWordRecursive(*transition.getNextState(), word.substr(1, word.length()));
		}
		return false;
	}
}



std::string Automaton::toString() {
	std::string str = "Automaton: {\n";

	for (State state : states) {
		str += state.toString();
	}

	str += "}";

	return str;
}


Automaton::~Automaton() {
	
}
