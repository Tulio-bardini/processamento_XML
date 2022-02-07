#include <iostream>
#include <fstream>
#include <string>
#include "tag_validator.h"

using namespace std;

int main() {

    char xmlfilename[100];

    std::cin >> xmlfilename;  // entrada

    xml::tag_validator(xmlfilename);

    /*
     
       COLOQUE SEU CODIGO AQUI
    
    */

    return 0;
}
