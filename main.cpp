#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {

    char xmlfilename[100];
    string line;

    std::cin >> xmlfilename;  // entrada

    ifstream myfile(xmlfilename);

    if (myfile.is_open())
    {
        while (getline(myfile,line))
        {
            cout << line << '\n';
        }
        myfile.close();
    }

    else cout << "Unable to open file";

    /*
     
       COLOQUE SEU CODIGO AQUI
    
    */

    return 0;
}
