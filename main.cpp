//! Projeto 01.
/*!
* \author Patrícia Bardini Arigoni, Tulio Scarabelot Bardini.
* \since 10/02/22
*/


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include "tag_validator.h"
#include "component_counter.h"

using namespace std;

int main() {

    char xmlfilename[100];

    // Nome do arquivo de entrada
    std::cin >> xmlfilename;  

    //Converte o conteudo do arquivo de entrada em String
    std::ifstream file(xmlfilename);
    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string xml_contents = buffer.str();

    xml_contents.erase(std::remove(xml_contents.begin(), xml_contents.end(), '\n'), xml_contents.end());

    // Valida as Tags do arquivo
    if (not xml::tag_validator(xml_contents)) {
        std::cout << "error\n";
    } else {
        std::size_t i = 9;
        while (i < xml_contents.length()) {
            
            // Busca os valores referentes a cada uma das Tags
            std::string image =  xml::get_value("<img>", "</img>", xml_contents, i);
            std::string name = xml::get_value("<name>", "</name>", xml_contents, i);
            std::string height = xml::get_value("<height>", "</height>", xml_contents, i);
            std::string width = xml::get_value("<width>", "</width>", xml_contents, i);
            std::string data = xml::get_value("<data>", "</data>", xml_contents, i);

            //incrementa o i com o tamanho do caminho já percorrido no arquivo
            i += image.length() + 11;
            if (i >= xml_contents.length()) break;

            // Recebe o número de elementos presentes na imagem da matriz
            int label = counter::component_counter(width, height, data);
            cout << name << ' ' << label << '\n';

        }
    }

    return 0;
}
