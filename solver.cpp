#include "solver.h"
#include <iostream>
#include <vector>
#include <algorithm>

Solver::Solver(Parser* parser) : parser_(parser), max_color_(0) {}

void Solver::colorize() {
    const std::vector<std::pair<int, int> >& edges = parser_->get_edges();
    std::vector<int> nodes;

    for (const auto& edge : edges) {
        nodes.push_back(edge.first);
        nodes.push_back(edge.second);
    }
    
    std::sort(nodes.begin(), nodes.end());
    nodes.erase(std::unique(nodes.begin(), nodes.end()), nodes.end());

    colors_.resize(nodes.size(), -1);
    std::vector<bool> available(nodes.size(), true);

    for (const auto& edge : edges) {
        int u = edge.first - 1;
        int v = edge.second - 1;

        if (colors_[u] != -1) available[colors_[u]] = false;
        if (colors_[v] != -1) available[colors_[v]] = false;

        int cr;
        for (cr = 0; cr < nodes.size(); ++cr) {
            if (available[cr]) break;
        }

        colors_[u] = cr;
        colors_[v] = cr;
        max_color_ = std::max(max_color_, cr + 1);

        std::fill(available.begin(), available.end(), true);
    }
}

void Solver::show_colors() const {
    std::cout << "Node colors:\n";
    for (size_t i = 0; i < colors_.size(); ++i) {
        std::cout << "Node " << i + 1 << ": Color " << colors_[i] << "\n";
    }
    std::cout << "Total colors used: " << max_color_ << "\n";
}
