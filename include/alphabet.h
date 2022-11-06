/**
 * @file alphabet.h
 * @author Jonay Estévez Díaz (alu0101100586@ull.edu.es)
 * @brief Clase que almacena las funciones y caracteristicas de un alfabeto
 *        En este fichero se almacena la definicion de la clase así como de sus
 *        cabeceras
 * @version 1.0
 * @date 2022-11-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef ALPHABET_CLASS_H
#define ALPHABET_CLASS_H

#include <iostream>
#include <sstream>
#include <set>
#include <vector>

class Alphabet {
  public:
    Alphabet();
    Alphabet(std::string alpha_str);
    Alphabet(std::set<std::string> alpha);
    ~Alphabet();

    std::set<std::string> GetAlphabet() const;
    void SetAlphabet(std::set<std::string> new_alpha);

    bool BelongToAlphabet(std::vector<std::string> chain);
    bool OnAlphabet(std::string symbol);

    std::string ToString();

  private:
    std::set<std::string> alpha_;
};

#endif //ALPHABET_CLASS_H