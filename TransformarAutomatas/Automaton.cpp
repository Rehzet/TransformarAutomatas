#include <set>
#include <sstream>

#include "Automaton.h"
#include "Constants.h"

Automaton::Automaton() {

}


void Automaton::addState(State state) {
	states.push_back(state);
}

std::vector<State> Automaton::getStates() {
	return states;
}

bool Automaton::checkWord(std::string word) {
	return checkWordRecursive(states.front(), word);
}

bool Automaton::checkWordRecursive(State state, std::string word) {
	if (word.empty()) {
		return state.isFinalState();
	}
	else {
		for (std::pair<State*, char> transition : state.getTransitions()) {
			if (transition.second == word[0])
				return checkWordRecursive(*transition.first, word.substr(1, word.length()));
		}
		return false;
	}
}

bool Automaton::isDeterministic() {

	for (State state : states) {

		std::set<char> valueRepeatedChecker;
		for (std::pair<State*, char> transition : state.getTransitions()) {
			if (transition.second == EMPTY_WORD)
				return false;
			else {
				if (!valueRepeatedChecker.insert(transition.second).second)
					return false;
			}
		}
	}

	return true;
}


std::string Automaton::toString() {


	std::string str = "Automaton: {\n";

	for (State state : states) {
		//str += state.toString();
		std::istringstream iss(state.toString());

		for (std::string line; std::getline(iss, line);) {
			str += "\t" + line + "\n";
		}

		str += "\n";
	}

	str += "}";

	return str;
}


Automaton::~Automaton() {
	
}
