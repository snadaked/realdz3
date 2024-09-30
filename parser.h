
#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>

class Parser {
public:
    Parser(const std::string& input_file);
    void split_input(const std::string line, std::string & sn, std::string & sm) const;
    void read();
    const std::vector<std::pair<int, int> >& get_edges() const;
private:
    std::string input_file_;
    std::vector<std::pair<int, int> > edges_;
};

#endif
