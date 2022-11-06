/**
 * @file alphabet.cc
 * @author Jonay Estévez Díaz (alu0101100586@ull.edu.es)
 * @brief Clase que almacena las funciones y caracteristicas de un alfabeto
 *        En ente fichero, se realizan las definiciones del comportamiento
 *        de las funciones
 * @version 1.0
 * @date 2022-11-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../include/alphabet.h"

/**
 * @brief Construye un nuevo Alphabet:: Alphabet object
 * 
 */
Alphabet::Alphabet() {

}

/**
 * @brief Construye un nuevo Alphabet:: Alphabet object
 * 
 * @param alpha_str 
 */
Alphabet::Alphabet(std::string alpha_str) {
  std::istringstream total_string(alpha_str);
  std::string piece; 
  while (!total_string.eof()) {
    total_string >> piece;
    alpha_.insert(piece);
  }
}

/**
 * @brief Construye un nuevo Alphabet:: Alphabet object
 * 
 * @param alpha 
 */
Alphabet::Alphabet(std::set<std::string> alpha) {
  alpha_ = alpha;
}

/**
 * @brief Destructor de Alphabet:: Alphabet object
 * 
 */
Alphabet::~Alphabet() {

}

/**
 * @brief Funcion que permite obtener el atributo de la clase alphabet
 * 
 * @return std::set<std::string> 
 */
std::set<std::string> Alphabet::GetAlphabet() const {
  return alpha_;
}

/**
 * @brief Funcion que permite modificar el atributo de la clase alphabet
 * 
 * @param new_alpha 
 */
void Alphabet::SetAlphabet(std::set<std::string> new_alpha) {
  alpha_ = new_alpha;
}

/**
 * @brief Comprueba si una cadena
 * 
 * @param chain 
 * @return true 
 * @return false 
 */
bool Alphabet::BelongToAlphabet(std::vector<std::string> chain) {
  bool belong;
  int counter = 0;
  for (int i = 0; i < chain.size(); i++) {
    counter = 0;
    belong = false;
    for (const std::string &j: alpha_) {
      counter++;
      if (j == chain[i]) {
        belong = true;
        break;
      }
      if (counter == alpha_.size()) return belong;
    }
  }
  return belong;
}

/**
 * @brief Comprueba si un symbolo pertenece al alfabeto
 * 
 * @param symbol 
 * @return true 
 * @return false 
 */
bool Alphabet::OnAlphabet(std::string symbol) {
  auto search = alpha_.find(symbol);
  return search != alpha_.end();
}

/**
 * @brief Funcion que crea un string a partir del atributo de la clase
 * 
 * @return std::string 
 */
std::string Alphabet::ToString() {
  std::string alpha_str = "Σ = { ";
  for (auto it : alpha_) {
    alpha_str += it + " ";
  }
  alpha_str += "}";
  return alpha_str;
}