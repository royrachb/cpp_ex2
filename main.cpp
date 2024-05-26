//213030158
//royrachbuch@gmail.com


#include <iostream>
#include "Graph.hpp"

void initializeGraph(Graph& g, const std::vector<std::vector<int>>& values) {
    int size = g.getSize();
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            g.setValue(i, j, values[i][j]);
        }
    }
}

void testOperators() {
    Graph g1(3);
    Graph g2(3);

    std::vector<std::vector<int>> values1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    std::vector<std::vector<int>> values2 = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    initializeGraph(g1, values1);
    initializeGraph(g2, values2);

    // Test addition
    Graph g3 = g1 + g2;
    std::cout << "g3 = g1 + g2:\n" << g3 << std::endl;

    // Test subtraction
    Graph g4 = g3 - g1;
    std::cout << "g4 = g3 - g1:\n" << g4 << std::endl;

    // Test unary plus and minus
    Graph g5 = +g1;
    std::cout << "g5 = +g1:\n" << g5 << std::endl;

    Graph g6 = -g1;
    std::cout << "g6 = -g1:\n" << g6 << std::endl;

    // Test increment and decrement
    ++g1;
    std::cout << "++g1:\n" << g1 << std::endl;

    g1++;
    std::cout << "g1++:\n" << g1 << std::endl;

    --g1;
    std::cout << "--g1:\n" << g1 << std::endl;

    g1--;
    std::cout << "g1--:\n" << g1 << std::endl;

    // Test scalar multiplication
    Graph g7 = g1 * 3;
    std::cout << "g7 = g1 * 3:\n" << g7 << std::endl;

    // Test graph multiplication
    Graph g8 = g1 * g2;
    std::cout << "g8 = g1 * g2:\n" << g8 << std::endl;

    // Test comparison operators
    bool isEqual = (g1 == g2);
    std::cout << "g1 == g2: " << isEqual << std::endl;

    bool isNotEqual = (g1 != g2);
    std::cout << "g1 != g2: " << isNotEqual << std::endl;

    bool isLess = (g1 < g2);
    std::cout << "g1 < g2: " << isLess << std::endl;

    bool isLessEqual = (g1 <= g2);
    std::cout << "g1 <= g2: " << isLessEqual << std::endl;

    bool isGreater = (g1 > g2);
    std::cout << "g1 > g2: " << isGreater << std::endl;

    bool isGreaterEqual = (g1 >= g2);
    std::cout << "g1 >= g2: " << isGreaterEqual << std::endl;

    // Additional test cases for different sizes
    Graph g9(2);
    std::vector<std::vector<int>> values3 = {
        {1, 2},
        {3, 4}
    };
    initializeGraph(g9, values3);

    bool isLessDifferentSize = (g9 < g1);
    std::cout << "g9 < g1: " << isLessDifferentSize << std::endl;

    bool isGreaterDifferentSize = (g1 > g9);
    std::cout << "g1 > g9: " << isGreaterDifferentSize << std::endl;
}

int main() {
    testOperators();
    return 0;
}

