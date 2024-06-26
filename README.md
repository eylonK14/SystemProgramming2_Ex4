# Tree Iterators - With GUI

This project implements a new `Tree` container.
The default of the `Tree` is a binary tree, but can be implemented to any amount of nodes that a father canp possess.

There are also implemetations of various iterators:
BFS, DFS (for all trees), InOrder, PreOrder, PostOrder, Heap (only for binary tree).

## Class Hierarchy (Bottom To Top)

- [Tree Iterators - With GUI](#tree-iterators---with-gui)
  - [Class Hierarchy (Bottom To Top)](#class-hierarchy-bottom-to-top)
  - [Node Class](#node-class)
    - [Node.hpp](#nodehpp)
  - [Complex Class](#complex-class)
    - [Complex.hpp](#complexhpp)
  - [Iterators Class](#iterators-class)
    - [Iterators.hpp](#iteratorshpp)
  - [Tree Class](#tree-class)
    - [Tree.hpp](#treehpp)
  - [Libraries Used](#libraries-used)
    - [Containers Library](#containers-library)
    - [Testing Library](#testing-library)
    - [GUI Library](#gui-library)
    - [I\\O Library](#io-library)
  - [Execution](#execution)
  - [Author](#author)

## Node Class

This class implements the basic `Node` object, that we'll use in order to create the nodes of the `Tree`.

### Node.hpp

```cpp
Node(T data)
~Node()
void add_child(Node<T> *child)
void remove_child(Node<T> *child)
const T &get_value() const
Node<T> *&get_child(int index)
std::vector<Node<T> *> &get_children()
bool operator==(const Node<T> &other) const
bool operator!=(const Node<T> &other) const
void drawNode(sf::RenderWindow &window, int depth, int x, int y)
```

## Complex Class

This class implements the complex numbers , that we'll use the demo.

### Complex.hpp

```c++
Complex(double, double)
bool operator==(const Complex &) const
```

## Iterators Class

This class implements all the iterators that will be used in this program: `BFS`, `DFS`, `In Order`, `Pre Order`, `Post Order`, `Heap`.

### Iterators.hpp

```c++
//Since all iterators apply to the same interface, I will describe a general iterator:

Iterator(Node<T> *root)
const T &operator*() const
const Node<T> *operator->() const
Iterator &operator++()
const Iterator operator++(int)
bool operator==(const InOrderIterator &rhs) const
bool operator!=(const InOrderIterator &rhs) const
```

## Tree Class

This is the main `Tree` container. There's a basic `AnyTree` class for the functionality that every tree (binary and k-ary) can implement, and then there's specialization for the `Binary Tree` class.

### Tree.hpp

```cpp
//AnyTree class functions: 

void add_root(Node<T> *root)
void add_sub_node(Node<T> *parent, Node<T> *child)
Node<T> *get_root()
BFSIterator<T> begin()
BFSIterator<T> end()
BFSIterator<T> begin_bfs_scan()
BFSIterator<T> end_bfs_scan()
DFSIterator<T> begin_dfs_scan()
DFSIterator<T> end_dfs_scan()
void drawTree(sf::RenderWindow &window)

/* K-ary/Binary tree specialization - only difference is in the implementation: 
The InOrder, PreOrder, PostOrder traversals are not available to K-ary trees, so they're implemented using the DFSIterator
*/

//For K-ary
DFSIterator<T> begin_in_order()
DFSIterator<T> end_in_order()
DFSIterator<T> begin_pre_order()
DFSIterator<T> end_pre_order()
DFSIterator<T> begin_post_order()
DFSIterator<T> end_post_order()

//For Binary
InOrderIterator<T> begin_in_order()
InOrderIterator<T> end_in_order()
PreOrderIterator<T> begin_pre_order()
PreOrderIterator<T> end_pre_order()
PostOrderIterator<T> begin_post_order()
PostOrderIterator<T> end_post_order()
```

## Libraries Used

Here's a list of all libraries used in this project:

### Containers Library

```c++
#include <vector>
#include <stack>
#include <queue>
```

### Testing Library

```c++
#include "doctest.h"
```

### GUI Library

```c++
#include <SFML/Graphics.hpp>
```

### I\O Library

```c++
#include <iostream>
```

## Execution

The are two files being executed in the project : `demo` and `test`.
`demo` is used to showcase a main program that demonstrates how the program works.
`test` is used to showcase the testing done on the various functions of the project.
In order to execute the project, preform the following commands in the terminal:

```make
make tree # will execute the demo file
./test # will execute the test after make is done
```

## Author

- [Eylon Yaakov Katan](https://github.com/eylonk14)
