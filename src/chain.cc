/**
 * @file chain.cc
 * @author Jonay Estévez Díaz (alu0101100586@ull.edu.es)
 * @brief Clase que almacena una cadenas y el alfabeto a 
 *        la que pertenece dicha cadena. En este fichero
 *        se almacena la definición de las funcionalidades
 *        de la clase
 * @version 1.0
 * @date 2022-11-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../include/chain.h"

/**
 * @brief Constructor de la clase Chain:: Chain object
 * 
 */
Chain::Chain() {

}

/**
 * @brief Constructor de la clase Chain:: Chain object
 * 
 * @param chain 
 */
Chain::Chain(std::string chain) {
  for (const char &i: chain) {
    chain_.push_back(std::string(1, i));
  }
}

/**
 * @brief Destructor de Chain:: Chain object
 * 
 */
Chain::~Chain() {

}

/**
 * @brief Retorna el atributo de la clase
 * 
 * @return std::vector<std::string> 
 */
std::vector<std::string> Chain::GetChain() const {
  return chain_;
}

/**
 * @brief Modifica el atributo de la clase
 * 
 * @param new_chain 
 */
void Chain::SetChain(std::vector<std::string> new_chain) {
  chain_.clear();
  chain_ = new_chain;
}

/**
 * @brief Pasa el atributo de la clase a string
 * 
 */
std::string Chain::ToString() const {
  std::string chain_str;
  for (const std::string &i: chain_) {
    chain_str += i;
  }
  return chain_str;
}