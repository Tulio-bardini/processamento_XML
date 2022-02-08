#include <string>
#include <fstream>
#include "array_stack.h"
#include "tag_validator.h"

namespace xml {
    bool tag_validator(const char* file_name) {

        structures::ArrayStack<std::string> tags;

        std::string line;

        std::ifstream myfile(file_name);

        if (myfile.is_open()) {

            while (getline(myfile,line)) {

                char tag[20];
                for (auto i = 0; i < line.length(); i++) {

                    if (line[i] == '<') {
                        std::size_t final_tag = line.find_first_of(">", i);
                        
                        auto tag_length = int(final_tag) - i - 1;
                        
                        std::size_t length = line.copy(tag,tag_length,i+1);

                        tag[length] = '\0';
                        
                        std::string str_tag = tag;

                        if (str_tag[0] == '/') {
                            
                            str_tag = str_tag.substr(1);
                            if (tags.empty() || tags.top() != str_tag) {
                                myfile.close();
                                return false;
                            } else {
                                tags.pop();
                            }

                        } else {
                            tags.push(str_tag);
                        }
                    }
                }
            }
        }
        myfile.close();
        return tags.empty();
    }
}