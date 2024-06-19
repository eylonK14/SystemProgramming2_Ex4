// eylony1403@gmail.com

#pragma once

#include <iostream>
#include <vector>

template <typename T>
class Node{

    public:
        Node(T);
        ~Node();
        void add_child(Node<T>);
        void remove_child(Node<T>);
        T get_value();
        Node<T> get_child(int);
        std::vector<Node<T>> get_children();
    
    private:
        T _data;
        std::vector<Node<T>> _children;
};
