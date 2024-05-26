//213030158
//royrachbuch@gmail.com


#include "Graph.hpp"
#include <stdexcept>
#include <algorithm>

// Constructor and Copy Constructor
Graph::Graph(int n) : size(n), adjacencyMatrix(n, std::vector<int>(n, 0)) {}

Graph::Graph(const Graph& other) : size(other.size), adjacencyMatrix(other.adjacencyMatrix) {}

// Set value
void Graph::setValue(int i, int j, int value) {
    adjacencyMatrix[i][j] = value;
}

// Arithmetic operators
Graph Graph::operator+(const Graph& other) const {
    if (size != other.size) throw std::invalid_argument("Graphs must be of the same size.");
    Graph result(size);
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            result.adjacencyMatrix[i][j] = adjacencyMatrix[i][j] + other.adjacencyMatrix[i][j];
    return result;
}

Graph& Graph::operator+=(const Graph& other) {
    if (size != other.size) throw std::invalid_argument("Graphs must be of the same size.");
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            adjacencyMatrix[i][j] += other.adjacencyMatrix[i][j];
    return *this;
}

Graph Graph::operator+() const {
    return *this;
}

Graph Graph::operator-(const Graph& other) const {
    if (size != other.size) throw std::invalid_argument("Graphs must be of the same size.");
    Graph result(size);
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            result.adjacencyMatrix[i][j] = adjacencyMatrix[i][j] - other.adjacencyMatrix[i][j];
    return result;
}

Graph& Graph::operator-=(const Graph& other) {
    if (size != other.size) throw std::invalid_argument("Graphs must be of the same size.");
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            adjacencyMatrix[i][j] -= other.adjacencyMatrix[i][j];
    return *this;
}

Graph Graph::operator-() const {
    Graph result(size);
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            result.adjacencyMatrix[i][j] = -adjacencyMatrix[i][j];
    return result;
}

// Comparison operators
bool Graph::operator==(const Graph& other) const {
    return size == other.size && adjacencyMatrix == other.adjacencyMatrix;
}

bool Graph::operator!=(const Graph& other) const {
    return !(*this == other);
}

bool Graph::operator<(const Graph& other) const {
    if (size != other.size) return size < other.size;

    int thisEdgeCount = getEdgeCount();
    int otherEdgeCount = other.getEdgeCount();

    if (thisEdgeCount != otherEdgeCount) return thisEdgeCount < otherEdgeCount;

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (adjacencyMatrix[i][j] != other.adjacencyMatrix[i][j]) {
                return adjacencyMatrix[i][j] < other.adjacencyMatrix[i][j];
            }
        }
    }

    return false;
}

bool Graph::operator<=(const Graph& other) const {
    return *this < other || *this == other;
}

bool Graph::operator>(const Graph& other) const {
    return !(*this <= other);
}

bool Graph::operator>=(const Graph& other) const {
    return !(*this < other);
}

// Increment and decrement operators
Graph& Graph::operator++() {
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            ++adjacencyMatrix[i][j];
    return *this;
}

Graph Graph::operator++(int) {
    Graph temp = *this;
    ++(*this);
    return temp;
}

Graph& Graph::operator--() {
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            --adjacencyMatrix[i][j];
    return *this;
}

Graph Graph::operator--(int) {
    Graph temp = *this;
    --(*this);
    return temp;
}

// Scalar multiplication
Graph Graph::operator*(int scalar) const {
    Graph result(size);
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            result.adjacencyMatrix[i][j] = adjacencyMatrix[i][j] * scalar;
    return result;
}

// Graph multiplication
Graph Graph::operator*(const Graph& other) const {
    if (size != other.size) throw std::invalid_argument("Graphs must be of the same size.");
    Graph result(size);
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            for (int k = 0; k < size; ++k)
                result.adjacencyMatrix[i][j] += adjacencyMatrix[i][k] * other.adjacencyMatrix[k][j];
    return result;
}

// Output operator
std::ostream& operator<<(std::ostream& os, const Graph& graph) {
    for (const auto& row : graph.adjacencyMatrix) {
        for (int val : row)
            os << val << " ";
        os << std::endl;
    }
    return os;
}

// Additional methods for Graph class
bool Graph::isSubgraph(const Graph& other) const {
    if (size != other.size) return false;
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            if (adjacencyMatrix[i][j] > other.adjacencyMatrix[i][j])
                return false;
    return true;
}

int Graph::getEdgeCount() const {
    int count = 0;
    for (const auto& row : adjacencyMatrix)
        count += std::count_if(row.begin(), row.end(), [](int x) { return x != 0; });
    return count;
}

int Graph::getSize() const {
    return size;
}

