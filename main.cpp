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

    return 0;
}
