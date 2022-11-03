/**
 * @file finite_automata.h
 * @author Jonay Estévez Díaz (alu0101100586@ull.edu.es)
 * @brief Clase que simula un autómata finito que acepta 
 *        y rechaza cadenas. En este fichero se realizará 
 *       la definición de la clase así como la definición 
 *       de los métodos públicos y privados
 * @version 1.0
 * @date 2022-11-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef FINITE_AUTOMATA_CLASS_H
#define FINITE_AUTOMATA_CLASS_H

#include <fstream>
#include <vector>
#include <utility>
#include <sstream>
#include <iterator>
#include <algorithm> 
#include "alphabet.h"
#include "chain.h"

class FiniteAutomata {
  public:
    FiniteAutomata();
    FiniteAutomata(std::string file);
    ~FiniteAutomata();

    Alphabet GetAlphabet() const;
    int GetNumberStates() const;
    int GetInitState() const;    
    std::vector<int> GetStates() const;

    bool Analyze(Chain chain);

  private:
    void ExistInit();
    bool FinishState(std::vector<int> actual_states);
    void EpsilonTransition(int state, std::vector<int> &result);

    Alphabet alphabet_;
    int number_states_;
    int init_state_;
    std::vector<int> states_;   
    std::vector<int> acceptance_status_; 
    std::vector<std::vector<std::pair<std::string, std::vector<int>>>> transition_;
};

#endif //FINITE_AUTOMATA_CLASS_H