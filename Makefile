make: include/alphabet.h include/chain.h include/dfa.h src/main_dfa.cc
	g++ src/alphabet.cc src/chain.cc src/dfa.cc src/main_dfa.cc -o p05_dfa_simulator.out

clean:
	rm -r *.out