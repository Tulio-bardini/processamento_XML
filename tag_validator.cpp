#include <string>
#include <fstream>
#include "array_stack.h"
#include "tag_validator.h"

namespace xml {

    // Implementação o algortimo de validação das tags. 
    // Esse algoritmo se utiliza de uma pilha para descobrir se todas as Tags estão corretamente 
    // indentadas. Quando há uma Tag de abertura (<) ela é colocada na pilha, já quando é passado 
    // uma tag de fechamento (>) ela procura seu complemento na pilha e caso encontre o desempilha.

    bool tag_validator(const std::string xml_contents) {

        structures::ArrayStack<std::string> tags;

        for (auto i = 0; i < xml_contents.length(); i++) {

            if (xml_contents[i] == '<') {
                std::size_t tag_ending_pos = xml_contents.find_first_of('>', i);
                
                auto tag_length = tag_ending_pos - i - 1;

                std::string str_tag = xml_contents.substr(i+1, tag_length);

                if (str_tag[0] == '/') {
                    
                    str_tag = str_tag.substr(1);
                    if (tags.empty() || tags.top() != str_tag) {
                        return false;
                    } else {
                        tags.pop();
                    }

                } else {
                    tags.push(str_tag);
                }

                i = tag_ending_pos;
            }
        }
        return tags.empty();
    }

    // Implementa a busca dos valores referentes as tags passadas, encontrando
    // a posição do primeiro e último elemento da Tag, e posteriormente retornando
    // esse pedaço específico da String

    std::string get_value(const std::string start_tag,
                        const std::string end_tag,
                        const std::string xml_contents,
                        int reference) {

        std::string tag_value;
            
        auto tag_length = start_tag.length();

        std::size_t start_position_1 = xml_contents.find(start_tag, reference) + tag_length;
        std::size_t start_position_2 = xml_contents.find(end_tag, reference);

        tag_value += xml_contents.substr(start_position_1, start_position_2 - start_position_1);

        return tag_value;
    }
}
