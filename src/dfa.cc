/**
 * @file dfa.cc
 * @author Jonay Estévez Díaz (alu0101100586@ull.edu.es)
 * @brief Clase que simula un dfa dado por el usuario. En este fichero 
 *        se definela funcionalidad de las cabeceras del fichero de 
 *        definicion de la clase
 * @version 0.1
 * @date 2022-11-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../include/dfa.h"

/**
 * @brief Construct a new DFA::DFA object
 * 
 */
DFA::DFA() {

}

/**
 * @brief Construct a new DFA::DFA object
 * 
 * @param file 
 */
DFA::DFA(std::string file) {
  std::vector<std::string> file_txt;
  std::ifstream file_in;
  std::string aux, info;
  file_in.open(file, std::ios::in);

  if (file_in.fail()) {
    std::cout << "Cannot open the file " + file << std::endl;
    exit(1); 
  }

  while (!file_in.eof()) {
    getline(file_in, aux);
    file_txt.push_back(aux);
  }

  alphabet_ = Alphabet(file_txt[0]);
  number_states_ = std::stoi(file_txt[1]);
  init_state_ = std::stoi(file_txt[2]);

  states_.resize(number_states_);
  info_states_.resize(number_states_);
  for (int i = 0; i < info_states_.size(); i++) {
    aux = file_txt[i + 3].c_str();
    aux.erase(std::remove(aux.begin(), aux.end(), ' '), aux.end());
    for (int j = 0; j < aux.size(); j++) {
      info = aux[j];
      info_states_[i].push_back(info);
    }
  }

  for (int i = 0; i < states_.size(); i++) {
    states_[i] = atoi(info_states_[i][0].c_str());
  }

  int aux_transition, pos_symbol, pos_state;
  transition_.resize(info_states_.size());
  for (int i = 0; i < transition_.size(); i++) {  
    aux_transition = atoi(info_states_[i][2].c_str());
    transition_[i].resize(aux_transition);
    pos_symbol = 3;
    pos_state = 4;
    for (int j = 0; j < aux_transition; j++) {
      transition_[i][j].first = info_states_[i][pos_symbol];
      transition_[i][j].second = atoi(info_states_[i][pos_state].c_str());
      pos_symbol = pos_symbol + 2;
      pos_state = pos_state + 2;
    }
  }

  file_in.close();
  CheckDefinition();
}

/**
 * @brief Destroy the DFA::DFA object
 * 
 */
DFA::~DFA() {

}

/**
 * @brief Retorna el alfabeto 
 * 
 * @return Alphabet 
 */
Alphabet DFA::GetAlphabet() const {
  return alphabet_;
}

/**
 * @brief Retorna el numero de estados del dfa
 * 
 * @return int 
 */
int DFA::GetNumberStates() const {
  return number_states_;
}

/**
 * @brief Retorna el estado de inicio
 * 
 * @return int 
 */
int DFA::GetInitState() const {
  return init_state_;
}

/**
 * @brief Retorna la información de los estados
 * 
 * @return std::vector<std::vector<std::string>> 
 */
std::vector<std::vector<std::string>> DFA::GetInfoStates() const {
  return info_states_;
}

/**
 * @brief Retorna los estados
 * 
 * @return std::vector<int> 
 */
std::vector<int> DFA::GetStates() const {
  return states_;
}

/**
 * @brief Analiza una cadena para ver si es aceptada por el dfa
 * 
 * @param chain 
 * @return true 
 * @return false 
 */
bool DFA::Analyze(Chain chain) {
  int acceptance_state = 0;
  std::string symbol;
  int actual_state = init_state_;

  for (int i = 0; i < chain.GetChain().size(); i++) {
    auto search = alphabet_.GetAlphabet().find(chain.GetChain()[i]);
    if (search == alphabet_.GetAlphabet().end()) return false;
    symbol = chain.GetChain()[i];
    for (int j = 0; j < transition_[actual_state].size(); j++) {
      if (symbol == transition_[actual_state][j].first) {
        actual_state = transition_[actual_state][j].second;
        break;
      }
    }
    acceptance_state = atoi(info_states_[actual_state][1].c_str());
  }

  return (acceptance_state == 1);
}

/**
 * @brief Revisa que la definición del DFA es correcta
 * 
 */
void DFA::CheckDefinition() {
  int count = 0;

  for (int i = 0; i < info_states_.size(); i++) {
    if (atoi(info_states_[i][0].c_str()) == init_state_) {
      count++;
    }
  }
  if (count != 1) {
    std::cout << "Error, no boot state available" << std::endl;
    exit(1);
  }

  for (int i = 0; i < info_states_.size(); i++) {
    if (atoi(info_states_[i][2].c_str()) != alphabet_.GetAlphabet().size()) {
      std::cout << "Error, Poor definition of transitions" << std::endl;
      exit(1);
    }
  }

  for (int i = 0; i < info_states_.size(); i++) {
    for (const std::string &x: alphabet_.GetAlphabet()) {
      count = 0;
      for (int j = 0; j < info_states_[i].size(); j++) {
        if (x == info_states_[i][j]) {
          count++;
        }
      }
      if (count != 1) {
        std::cout << "Error, Poor definition of transitions" << std::endl;
        exit(1);
      }
    }
  }
}