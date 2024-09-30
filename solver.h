
#ifndef SOLVER_H
#define SOLVER_H

#include "parser.h"
#include <vector>

class Solver {
public:
    Solver(Parser* parser);
    void colorize();
    void show_colors() const;
private:
    Parser* parser_;
    std::vector<int> colors_;
    int max_color_;
};

#endif
