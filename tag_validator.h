#ifndef XML_TAG_VALIDATOR_H
#define XML_TAG_VALIDATOR_H

namespace xml {
    
    /**
     * @brief Valida todas as Tags do arquivo
     * 
     * @param xml_contents String do conteudo do arquivo lido
     * @return true caso as estejam corretas
     * @return false caso tenha erro nas Tags
    */
    
    bool tag_validator(const std::string xml_contents);

    /**
     * @brief Retorna os valores referente as Tags requeridas
     * 
     * @param start_tag Tag de abertura
     * @param end_tag Tag de fechamento
     * @param xml_contents String do conteudo do arquivo lido
     * @param referrence Posição para inicio de leitura
     * @return String com valor das Tags
     */

    std::string get_value(const std::string start_tag,
                        const std::string end_tag,
                        const std::string xml_contents,
                        int referrence);
}  // namespace xml

#endif
