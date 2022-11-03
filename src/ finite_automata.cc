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
 * @brief Constructor de la clase FiniteAutomata
 * 
 */
FiniteAutomata::FiniteAutomata() {

}

/**
 * @brief Constructor de la clase FiniteAutomata pasandole un 
 *        fichero con el automata finito
 * 
 * @param file 
 */
FiniteAutomata::FiniteAutomata(std::string file) {

}

/**
 * @brief Destructor de la clase FiniteAutomaton
 * 
 */
FiniteAutomata::~FiniteAutomata() {

}

/**
 * @brief Retorna el alfabeto del autómata finito
 * 
 * @return Alphabet 
 */
Alphabet FiniteAutomata::GetAlphabet() const {

}

/**
 * @brief Retorna el numero de estados del automata finito
 * 
 * @return int 
 */
int FiniteAutomata::GetNumberStates() const {

}

/**
 * @brief Retorna el estado inicial
 * 
 * @return int 
 */
int FiniteAutomata::GetInitState() const {

}  

/**
 * @brief Retorna los estados
 * 
 * @return std::vector<int> 
 */
std::vector<int> FiniteAutomata::GetStates() const {

}

/**
 * @brief Analiza una cadena para ver si el automata finito la acepta
 * 
 * @param chain 
 * @return true 
 * @return false 
 */
bool FiniteAutomata::Analyze(Chain chain) {

}

/**
 * @brief 
 * 
 */
void FiniteAutomata::ExistInit() {

}

/**
 * @brief 
 * 
 * @param actual_states 
 * @return true 
 * @return false 
 */
bool FiniteAutomata::FinishState(std::vector<int> actual_states) {

}

/**
 * @brief Realiza las transiciones epsilon si las hubiera
 * 
 * @param state 
 * @param result 
 */
void FiniteAutomata::EpsilonTransition(int state, std::vector<int> &result) {

}