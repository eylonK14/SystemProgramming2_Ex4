// eylony1403@gmail.com

#pragma once

#include <iostream>
#include "Node.hpp"

#define BIN 2

template <typename T, int N = BIN>
class Tree {

    public:
        Tree();
        ~Tree();
        void add_root(Node<T>);
        void add_sub_root(Node<T>, Node<T>);
        Node<T> get_root();

    private:
        Node<T> _root;
};