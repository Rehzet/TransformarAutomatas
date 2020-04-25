#pragma once
#include <vector>
#include <string>

class Automaton {
private:

	std::vector<std::vector<int>> statesVector;		// Vector of vectors. Each vector contains all the transitions to 
													// the other states.


public:
	Automaton();
	Automaton(int states, int elements);

	std::string toString();

	~Automaton();
};

