make: include/alphabet.h include/chain.h include/dfa.h include/nfa.h src/main_finite_automata.cc
	g++ src/alphabet.cc src/chain.cc src/dfa.cc src/nfa.cc src/main_finite_automata.cc -o p05_dfa_simulator.out

clean:
	rm -r *.out 