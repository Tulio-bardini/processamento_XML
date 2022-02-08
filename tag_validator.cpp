#include <string>
#include <fstream>
#include "array_stack.h"
#include "tag_validator.h"

namespace xml {
    bool tag_validator(const std::string xml_contents) {

        structures::ArrayStack<std::string> tags;

        char tag[20];
        for (auto i = 0; i < xml_contents.length(); i++) {

            if (xml_contents[i] == '<') {
                std::size_t final_tag = xml_contents.find_first_of('>', i);
                
                auto tag_length = int(final_tag) - i - 1;
                
                std::size_t length = xml_contents.copy(tag,tag_length,i+1);

                tag[length] = '\0';
                
                std::string str_tag = tag;

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

                i + final_tag;
            }
        }
        return tags.empty();
    }
}
