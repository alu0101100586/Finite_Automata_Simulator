/**
 * @file main_finite_automata.cc
 * @author Jonay Estévez Díaz (alu0101100586@ull.edu.es)
 * @brief Programa principal que recibe por parametro dos 
 *        ficheros, el primero con la descripción de un 
 *        automata finito ya sea determinista o no determinista, 
 *        y el segundo fichero tendrá algunas cadenas.Este 
 *        programa construirá el automata y comprobará si 
 *        son aceptadas las cadenas por el mismo
 * @version 0.1
 * @date 2022-11-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <string>

#include "../include/finite_automata.h"

//Funciones Auxiliares
/**
 * @brief Funcion que muestra al usuario que ha ten ido un error de ejecución
 * 
 */
void Error(void) {
  std::cout << "EXECUTION ERROR: \n";
  std::cout << "TRY: ~$./p06_jonay.out [-h || --help]\n";
}

/**
 * @brief Funcion que muestra al usuario como usar el programa
 * 
 */
void Help(void) {
  std::cout << "USAGE: \n";
  std::cout << "EXECUTION: ~$./p06_jonay.out [FA FILE] [FA INPUT]\n";
  std::cout << "FOR EXAMPLE: ~$./p07_jonay.out input.nfa input.txt\n";
}

/**
 * @brief Funcion que lee un fichero y almacena las líneas de un fichero
 * 
 * @param file_name 
 * @param input_txt 
 */
void ReadFile(std::string file_name, std::vector<std::string>& input_txt) {
  std::string aux;
  std::ifstream in_file;

  in_file.open(file_name, std::ios::in);
  if (in_file.fail()) {
    std::cout << "Error al abrir el archivo\n";
    exit(1); 
  }
  while (!in_file.eof()) {
    aux = "";
    getline(in_file, aux);
    input_txt.push_back(aux);    
  }
  in_file.close();
}

int main(int argc, char const *argv[]) {
  std::string fa_file, chains_file;
  if (argc == 2) {
    std::string first_arg(argv[1]);
    if(first_arg == "-h" || first_arg == "--help") {
      Help();
      return 0;
    } else {
      Error();
      return 1;
    }
  } else if (argc == 3) {
    fa_file = argv[1];
    chains_file = argv[2];
  } else {
    Error();
    return 1;
  }
  std::vector<std::string> fa_file_txt, chains_file_txt;
  ReadFile(fa_file, fa_file_txt);
  ReadFile(chains_file, chains_file_txt);
  
  //inicializamos el alphabeto
  Alphabet alpha(fa_file_txt[0]);
  fa_file_txt.erase(fa_file_txt.begin());

  //almacenamos todas las cadenas
  std::vector<Chain> all_chain;
  for (const std::string &i: chains_file_txt) {
    all_chain.push_back(Chain(i, alpha));
  }

  //creamos el automata finito
  FiniteAutomata fa_object(fa_file_txt, alpha);
  //analisis de cada una de las cadenas
  for (const Chain &i: all_chain) {
    std::cout << i.ToString() << "\t-------\t";
    if(fa_object.Analyze(i)) std::cout << "Accepted\n";
    else                     std::cout << "Rejected\n";
  }

  return 0;
}
