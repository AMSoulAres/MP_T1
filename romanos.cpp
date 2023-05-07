// "Copyright 2023 Gabriel Amorim Soares e Silva"

#include "./romanos.hpp"
// #include "MP/TDD_romanos/romanos.hpp"
#include <iostream>
#include <map>
#include <regex>
#include <string>

int romanos_para_decimal(char const *num_romano) {
    std::map<char, int> associaNumero = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}};

    std::string romano = num_romano;

    std::regex validInput("^M{0,4}(CM|CD|D?C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3})$");

    if (std::regex_match(romano, validInput)) {
        int resultado = 0, charAnterior = 0, charAtual = 0;

        for (int i = romano.length() - 1; i >= 0; i--) {
            charAtual = associaNumero[romano[i]];

            if (charAtual < charAnterior) {
                resultado -= charAtual;
            } else {
                resultado += charAtual;
            }
            charAnterior = charAtual;
        }
        return resultado;

    } else {
        return -1;
    }
}
