#ifndef XML_TAG_VALIDATOR_H
#define XML_TAG_VALIDATOR_H

namespace xml {
    bool tag_validator(const std::string xml_contents);

    std::string get_value(const std::string start_tag,
                        const std::string end_tag,
                        const std::string xml_contents,
                        int referrence);
}  // namespace structures

#endif
