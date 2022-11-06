/**
 * @file  finite_automata.cc
 * @author Jonay Estévez Díaz (alu0101100586@ull.edu.es)
 * @brief Clase que simula un autómata finito que acepta 
 *        y rechaza cadenas. En este fichero se realizará
 *        el desarrollo de lso métodos de la clase
 * @version 1.0
 * @date 2022-11-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../include/finite_automata.h"

/**
 * @brief Constructor por defecto
 * 
 */
FiniteAutomata::FiniteAutomata() {

}

/**
 * @brief Constructor parametrizado al que le pasamos un fichero en vector y un alfabeto
 * 
 * @param file_fa 
 * @param alpha 
 */
FiniteAutomata::FiniteAutomata(std::vector<std::string> file_fa, Alphabet alpha) {
  alpha_ = alpha;
  number_states_ = stoi(file_fa[0]);
  init_state_ = stoi(file_fa[1]);
  states_.push_back(init_state_);

  if (OneInitState(file_fa) && OneLine(file_fa)) {
    std::vector<std::string> aux_lines;
    std::vector<std::pair<std::string, std::vector<int>>> aux_node;
    std::pair<std::string, std::vector<int>> aux_description;
    std::vector<int> aux_transition;
    std::string aux_symbol;

    //Inicialización de las posibles tranciciones de cada nodo
    aux_description.first = "&";
    aux_node.push_back(aux_description);
    for (const std::string &i: alpha_.GetAlphabet()) {
      aux_description.first = i;
      aux_node.push_back(aux_description);
    }


    file_fa.erase(file_fa.begin());
    file_fa.erase(file_fa.begin());

    //Inicialización del mapeado
    for (const auto &i: file_fa) {
      aux_lines = RemoveSpaces(i);
      if (aux_lines[1] == "1") accepted_states_.push_back(stoi(aux_lines[0]));
      aux_lines.erase(aux_lines.begin(), aux_lines.begin() + 3);
      for (int j = 0; j < aux_lines.size(); j++) {
        aux_symbol = aux_lines[j];
        if (alpha_.OnAlphabet(aux_symbol) || aux_symbol == "&") {
          for (auto &k: aux_node) {
            if (k.first == aux_symbol) {
              j++;
              k.second.push_back(stoi(aux_lines[j]));
            }
          }
        } else {
          ErrorFA();
        }
      }
      fa_map_.push_back(aux_node);
      aux_lines.clear();
      aux_symbol = "";
      for (auto &j: aux_node) j.second.clear();
    }
  } else {
    ErrorFA();
  }
}

/**
 * @brief Destructor por defecto de la clase 
 * 
 */
FiniteAutomata::~FiniteAutomata() {

}

/**
 * @brief Retorna el alfabeto del automata finito
 * 
 * @return Alphabet 
 */
Alphabet FiniteAutomata::GetAlphabet() const {
 return alpha_;
}

/**
 * @brief Retorna el numero de estados del automata finito
 * 
 * @return int 
 */
int FiniteAutomata::GetNumberStates() const {
  return number_states_;
}

/**
 * @brief Devuelve cual es el estado de arranque
 * 
 * @return int 
 */
int FiniteAutomata::GetInitState() const {
  return init_state_;
} 

/**
 * @brief Devuelve los estados
 * 
 * @return std::vector<int> 
 */
std::vector<int> FiniteAutomata::GetState() const {
  return states_;
}

/**
 * @brief Analiza una cadena para comprobar si es aceptada o no por el automata
 * 
 * @param chain 
 * @return true 
 * @return false 
 */
bool FiniteAutomata::Analyze(Chain chain) {
  if (alpha_.BelongToAlphabet(chain.GetChain())) {
    std::vector<int> next_state;
    for (const auto i: chain.GetChain()) {
      for (const auto j : states_) {
        for (int k = 0; k < fa_map_[j].size(); k++) {
          if (fa_map_[j][k].first == "&") {
            EClausure(j, next_state);
          } else if (fa_map_[j][k].first == i) {
            for (const auto l: fa_map_[j][k].second){
              next_state.push_back(l);
            }
          }
        }
      }
      states_.clear();
      states_ = next_state;
      next_state.clear();
    }
    for (const auto i: states_) {
      for (const auto j: accepted_states_) {
        if (i == j) {
          states_.clear();
          states_.push_back(init_state_);
          return true;
        } 
      }
    }
  }
  states_.clear();
  states_.push_back(init_state_);
  return false;
}

/**
 * @brief Realiza las eclausura en en calso de que las haya
 * 
 * @param state 
 * @param new_nodes 
 */
void FiniteAutomata::EClausure(int state, std::vector<int> &new_nodes) {
  if (!fa_map_[state][0].second.empty()) {
    for (int i = 0; i < fa_map_[state][0].second.size(); i++) {
      new_nodes.push_back(fa_map_[state][0].second[i]);
      EClausure(fa_map_[state][0].second[i], new_nodes);
    }
  }
}

/**
 * @brief Comprueba que soilo existe un estado de inicio
 * 
 * @param file_nfa 
 * @return true 
 * @return false 
 */
bool FiniteAutomata::OneInitState(std::vector<std::string> file_nfa) {
  return file_nfa[1].size() == 1;
}

/**
 * @brief Comprueba que solo existe una definicion de tranciones para cada estado
 * 
 * @param file_nfa 
 * @return true 
 * @return false 
 */
bool FiniteAutomata::OneLine(std::vector<std::string> file_nfa) {
  std::vector<std::string> states;
  std::vector<std::string> aux_states;
  for (int i = 2; i < file_nfa.size(); i++) {
    aux_states = RemoveSpaces(file_nfa[i]);
    states.push_back(aux_states[0]);
  }

  int counter = 0;
  for (int i = 0; i < states.size(); i++) {
    for (int j = i + 1; j < states.size(); j++) {
      if (states[i] == states[j]) {
        counter++;
      }
    }
  }
  return counter == 0;
}

/**
 * @brief Mensaje de Error si se detecta una mala definicion del archivo
 * 
 */
void FiniteAutomata::ErrorFA(void) {
  std::cout << "INVALID FINITE aUTOMATA\n";
  std::cout << "BAD DEFINITION\n";
  std::cout << "TRY FOR EXAMPLE:\n";
  std::cout << "a b                  //FA's Alphabet\n";
  std::cout << "4                    //Number of nodes\n";
  std::cout << "0                    //Initial state\n";
  std::cout << "0 0 3 a 0 b 0 b 1    //Definition of node\n";
  std::cout << "1 0 2 a 2 b 2        //Definition of node\n";
  std::cout << "2 0 2 a 3 b 3        //Definition of node\n";
  std::cout << "3 1 0                //Definition of node\n";
  exit(1);
}

/**
 * @brief crea un vector de string a partir de un string cuyos elementos estan separador por espacio
 * 
 * @param line 
 * @return std::vector<std::string> 
 */
std::vector<std::string> FiniteAutomata::RemoveSpaces(std::string line) {
  std::stringstream sstream(line);
  std::istream_iterator<std::string> begin(sstream);
  std::istream_iterator<std::string> end;
  std::vector<std::string> no_spaces(begin, end);
  return no_spaces;
}
