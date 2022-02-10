#ifndef COUNTER_COMPONENT_COUNTER_H
#define COUNTER_COMPONENT_COUNTER_H

#include <string>

namespace counter {
    
    /**
     * @brief Percorre a matriz imagem e coleta o número de elementos conexo na região
     * 
     * @param width_s comprimento horizontal da imagem
     * @param height_s comprimento vertical da imagem
     * @param data_s String dos dados da matriz imagem
     * @return int com a quantidade de elementos da matriz 
     */

    int component_counter (const std::string width_s,
                            const std::string height_s,
                            const std::string data_s);
}

#endif