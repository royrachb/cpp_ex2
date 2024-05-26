//213030158
//royrachbuch@gmail.com

 #pragma once

#include <vector>
#include <iostream>

class Graph {
private:
    std::vector<std::vector<int>> adjacencyMatrix;
    int size;

public:
    Graph(int n);
    Graph(const Graph& other);

    // Set value
    void setValue(int i, int j, int value);

    // Arithmetic operators
    Graph operator+(const Graph& other) const;
    Graph& operator+=(const Graph& other);
    Graph operator+() const;
    Graph operator-(const Graph& other) const;
    Graph& operator-=(const Graph& other);
    Graph operator-() const;

    // Comparison operators
    bool operator==(const Graph& other) const;
    bool operator!=(const Graph& other) const;
    bool operator<(const Graph& other) const;
    bool operator<=(const Graph& other) const;
    bool operator>(const Graph& other) const;
    bool operator>=(const Graph& other) const;

    // Increment and decrement operators
    Graph& operator++(); // Prefix increment
    Graph operator++(int); // Postfix increment
    Graph& operator--(); // Prefix decrement
    Graph operator--(int); // Postfix decrement

    // Scalar multiplication
    Graph operator*(int scalar) const;

    // Graph multiplication
    Graph operator*(const Graph& other) const;

    // Output operator
    friend std::ostream& operator<<(std::ostream& os, const Graph& graph);

    // Additional methods for Graph class
    bool isSubgraph(const Graph& other) const;
    int getEdgeCount() const;
    int getSize() const;
};
