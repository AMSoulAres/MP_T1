// "Copyright 2023 Gabriel Amorim Soares e Silva"

#include "./romanos.hpp"
#include <iostream>
#include <map>

bool verificaInputRomano(std::string romano) {
    int countI = 0;
    int countX = 0;
    int countC = 0;
    int countM = 0;
    
    char charAtual = ' ';
    char charAnterior = ' ';


    for (char algarismo : romano) {
        charAtual = algarismo;

        if (algarismo == 'I') {
            countI++;
            if (countI > 3) {
                return false;
            }
        }
        else if (algarismo == 'X') {
            countX++;
            if (countX > 3) {
                return false;
            }
        }
        else if (algarismo == 'C') {
            countC++;
            if (countC > 3) {
                return false;
            }
        }
        else if (algarismo == 'M') {
            countM++;
            if (countM > 3) {
                return false;
            }
        }
        else if (algarismo == 'D' || algarismo == 'L' || algarismo == 'V') {
            if (algarismo == 'D' && countC > 1) {
                return false;
            }
            if (algarismo == 'L' && countX > 1) {
                return false;
            }
            if (algarismo == 'V' && countI > 1) {
                return false;
            }
        }
        else{
            return false;
        }
    }

    return true;
}

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

    if (verificaInputRomano(romano)) {
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
