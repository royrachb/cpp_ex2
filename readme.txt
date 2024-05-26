# Graph Project

## Details

- **ID**: 123456789
- **Email**: example@example.com

## Project Structure

This project consists of three main files:

1. `Graph.hpp`: The header file defining the Graph class and its methods.
2. `Graph.cpp`: The implementation file for the Graph class.
3. `main.cpp`: The main file to test the Graph class and its functionalities.

## Graph Class

The `Graph` class represents a graph using an adjacency matrix. It includes the following functionalities:

- **Constructors**: 
  - `Graph(int n)`: Initializes a graph with size `n`.
  - `Graph(const Graph& other)`: Copy constructor.

- **Set Value**: 
  - `void setValue(int i, int j, int value)`: Sets the value at position `(i, j)` in the adjacency matrix.

- **Arithmetic Operators**: 
  - `Graph operator+(const Graph& other) const`: Adds two graphs.
  - `Graph& operator+=(const Graph& other)`: Adds another graph to the current graph.
  - `Graph operator+() const`: Unary plus.
  - `Graph operator-(const Graph& other) const`: Subtracts another graph from the current graph.
  - `Graph& operator-=(const Graph& other)`: Subtracts another graph from the current graph.
  - `Graph operator-() const`: Unary minus.

- **Comparison Operators**: 
  - `bool operator==(const Graph& other) const`: Checks if two graphs are equal.
  - `bool operator!=(const Graph& other) const`: Checks if two graphs are not equal.
  - `bool operator<(const Graph& other) const`: Checks if the current graph is less than another graph.
  - `bool operator<=(const Graph& other) const`: Checks if the current graph is less than or equal to another graph.
  - `bool operator>(const Graph& other) const`: Checks if the current graph is greater than another graph.
  - `bool operator>=(const Graph& other) const`: Checks if the current graph is greater than or equal to another graph.

- **Increment and Decrement Operators**: 
  - `Graph& operator++()`: Prefix increment.
  - `Graph operator++(int)`: Postfix increment.
  - `Graph& operator--()`: Prefix decrement.
  - `Graph operator--(int)`: Postfix decrement.

- **Scalar Multiplication**: 
  - `Graph operator*(int scalar) const`: Multiplies all values in the graph by a scalar.

- **Graph Multiplication**: 
  - `Graph operator*(const Graph& other) const`: Multiplies two graphs.

- **Output Operator**: 
  - `friend std::ostream& operator<<(std::ostream& os, const Graph& graph)`: Outputs the graph.

- **Additional Methods**: 
  - `bool isSubgraph(const Graph& other) const`: Checks if the current graph is a subgraph of another graph.
  - `int getEdgeCount() const`: Returns the number of edges in the graph.
  - `int getSize() const`: Returns the size of the graph.

## Testing

The `main.cpp` file contains tests for all the functionalities of the `Graph` class, including:

- Arithmetic operations (addition, subtraction).
- Unary operations (plus, minus).
- Increment and decrement operations.
- Scalar multiplication.
- Graph multiplication.
- Comparison operations.

## Makefile

A `Makefile` is included to simplify the build process. Use the following commands:

- `make`: Compiles the project.
- `make run`: Runs the compiled program.
- `make clean`: Cleans the build files.

## How to Run

1. Ensure all files (`Graph.hpp`, `Graph.cpp`, `main.cpp`, and `Makefile`) are in the same directory.
2. Open a terminal and navigate to the directory containing the files.
3. Run `make` to compile the project.
4. Run `make run` to execute the program.
5. Run `make clean` to clean the build files.

