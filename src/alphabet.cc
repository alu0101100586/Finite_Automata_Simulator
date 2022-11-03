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