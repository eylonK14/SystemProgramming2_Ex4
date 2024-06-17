// eylony1403@gmail.com

#pragma once

#include <iostream>
#include <vector>

template <typename T> 
class Node{

    public:
        Node(T){};
        ~Node() {};
        void addChild(Node<T>) {};
        void removeChild(Node<T>) {};
        T getData() {};
        Node<T> getChild(int) {}
        std::vector<Node<T>> getChildren() {}
    
    private:
        T _data;
        std::vector<Node<T>> _children;
};
