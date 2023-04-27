#include "romanos.hpp"
#include <iostream>
#include <map>

using namespace std;

int romanos_para_decimal(char const *num_romano)
{
    map<char, int> associaNumero = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}};

        std::string romano = num_romano;

    int resultado = 0, caractereAnterior = 0, caractereAtual = 0;

    for (int i = romano.length() - 1; i >= 0; i--){
        caractereAtual = associaNumero[romano[i]];

        if (caractereAtual >= caractereAnterior){
            resultado += caractereAtual;
        } else {
            resultado -= caractereAtual;
        }
        caractereAnterior = caractereAtual;
        
        return resultado;
    }
}
