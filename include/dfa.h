/**
 * @file dfa.h
 * @author Jonay Estévez Díaz (alu0101100586@ull.edu.es)
 * @brief Clase que simula un dfa dado por el usuario. En este fichero 
 *        se define la clase y además tiene la definicion de la cabeceras
 * @version 0.1
 * @date 2022-11-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef DFA_CLASS_H
#define DFA_CLASS_H

#include <fstream>
#include <utility>
#include <algorithm>

#include "alphabet.h"
#include "chain.h"

class DFA {
  public:
    DFA();
    DFA(std::string file);
    ~DFA();
        
    Alphabet GetAlphabet() const;
    int GetNumberStates() const;
    int GetInitState() const;
    std::vector<std::vector<std::string>> GetInfoStates() const;
    std::vector<int> GetStates() const;
        
    bool Analyze(Chain chain);

  private:
    Alphabet alphabet_;
    std::vector<int> states_;
    std::vector<std::vector<std::pair<std::string, int>>> transition_;  
    std::vector<std::vector<std::string>> info_states_;
    int number_states_;
    int init_state_;

    void CheckDefinition();
};

#endif //DFA_CLASS_H