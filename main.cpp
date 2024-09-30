
#include "parser.h"
#include "solver.h"
#include <string>
#include <iostream>

int main(void) {
    std::string input_file = "data.txt";
    Parser parser(input_file);
    parser.read();

    Solver solver(&parser);
    solver.colorize();
    solver.show_colors();

    return 0;
}
