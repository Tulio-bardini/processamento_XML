#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "tag_validator.h"

using namespace std;

int main() {

    char xmlfilename[100];

    std::cin >> xmlfilename;  // entrada

    std::ifstream file(xmlfilename);
    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string xml_contents = buffer.str();

    if (not xml::tag_validator(xml_contents)) {
        std::cout << "error\n";
    }

    std::size_t i = 11;
    while (i < xml_contents.length()) {

        std::string image =  xml::get_value("<img>", "</img>", xml_contents, i);

        std::string name = xml::get_value("<name>", "</name>", xml_contents, i);
        std::string height = xml::get_value("<height>", "</height>", xml_contents, i);
        std::string width = xml::get_value("<width>", "</width>", xml_contents, i);
        std::string data = xml::get_value("<data>", "</data>", xml_contents, i);

        i += image.length() + 14;
        if (i >= xml_contents.length()) break;

    }

    return 0;
}
