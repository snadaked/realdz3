#include "parser.h"
#include <sstream>
#include <fstream>
#include <iostream>
#include <string>

Parser::Parser(const std::string& input_file) : input_file_(input_file) {}

void Parser::split_input(const std::string line, std::string & sn, std::string & sm) const {
    std::stringstream str(line);
    str >> sn >> sm;
}

void Parser::read() {
    std::ifstream file(input_file_);
    std::string line;
    while (std::getline(file, line)) {
        std::string sn, sm;
        split_input(line, sn, sm);
        edges_.push_back(std::make_pair(std::stoi(sn), std::stoi(sm)));
    }
}

const std::vector<std::pair<int, int> >& Parser::get_edges() const {
    return edges_;
}
