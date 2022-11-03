/**
 * @file chain.h
 * @author Jonay Estévez Díaz (alu0101100586@ull.edu.es)
 * @brief Clase que almacena una cadenas y el alfabeto a 
 *        la que pertenece dicha cadena. En este fichero
 *        se almacena la definición de la calse así como
 *        de las cabeceras
 * @version 1.0
 * @date 2022-11-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef CHAIN_CLASS_H
#define CHAIN_CLASS_H

#include "alphabet.h"
#include <vector>

class Chain {
  public:
    Chain();
    Chain(std::string chain);
    ~Chain();

    std::vector<std::string> GetChain() const;
    void SetChain(std::vector<std::string> new_chain);

    std::string ToString() const;

  private:
    std::vector<std::string> chain_;
};

#endif //CHAIN_CLASS_H