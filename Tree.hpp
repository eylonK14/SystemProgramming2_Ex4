// eylony1403@gmail.com

#include <iostream>

#include "Node.hpp"

#define BIN 2

template <typename T, int N = BIN>

class Tree {

    public:
        Tree() : _root(nullptr) {}
        ~Tree() {
            delete _root;
        }

        void add_root(Node<T>* root) {
            _root = root;
        }

        void add_sub_root(Node<T>* parent, Node<T>* child) {
            if (parent->getChildren().size() >= N) {
                throw std::out_of_range("Parent has too many children");
            }

            parent->addChild(child);
        }

        Node<T>* getRoot() {
            return _root;
        }

        void print() {
            print(_root, 0);
        }

    private:
        Node<T>* _root;

        void print(Node<T>* node, int level) {
            if (node == nullptr) {
                return;
            }

            for (int i = 0; i < level; i++) {
                std::cout << "  ";
            }

            std::cout << node->getData() << std::endl;

            for (auto child : node->getChildren()) {
                print(child, level + 1);
            }
        }
};