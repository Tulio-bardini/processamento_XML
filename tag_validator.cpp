#include <string>
#include <fstream>
#include "array_stack.h"
#include "tag_validator.h"

namespace xml {
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
}
