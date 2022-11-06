make: include/alphabet.h include/chain.h include/finite_automata.h src/main_finite_automata.cc
	g++ src/alphabet.cc src/chain.cc src/finite_automata.cc src/main_finite_automata.cc -o p06_fa_simulator.out

clean:
	rm -r *.out 