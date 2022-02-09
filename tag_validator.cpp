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
