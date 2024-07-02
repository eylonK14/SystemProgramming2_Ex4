//@author eylony1403@gmail.com

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <iostream>

#include "Node.hpp"
#include "Tree.hpp"
#include "Complex.hpp"
#include "Iterators.hpp"

#include "doctest.h"

// ----------------- Node -----------------

TEST_CASE("Test add_child")
{
    Node<int> node(1);
    Node<int> child1(2);
    Node<int> child2(3);

    CHECK(node.get_value() == 1);

    node.add_child(&child1);
    node.add_child(&child2);

    CHECK(node.get_children().size() == 2);
}

TEST_CASE("Test get_child")
{
    Node<int> node(1);
    Node<int> child1(2);
    Node<int> child2(3);

    node.add_child(&child1);
    node.add_child(&child2);

    CHECK(node.get_child(0)->get_value() == 2);
    CHECK(node.get_child(1)->get_value() == 3);
}

TEST_CASE("Test remove_child")
{
    Node<int> node(1);
    Node<int> child1(2);
    Node<int> child2(3);

    node.add_child(&child1);
    node.add_child(&child2);

    node.remove_child(&child1);

    CHECK(node.get_children().size() == 1);
    CHECK(node.get_child(0)->get_value() == 3);
}

TEST_CASE("TEST Invalid Index")
{
    Node<int> node(1);
    Node<int> child1(2);
    Node<int> child2(3);

    node.add_child(&child1);
    node.add_child(&child2);

    CHECK_THROWS(node.get_child(2));
    CHECK_THROWS(node.get_child(-1));
}

TEST_CASE("TEST Invalid Removing Child")
{
    Node<int> node(1);
    Node<int> child1(2);

    CHECK_THROWS(node.remove_child(&child1));
}

TEST_CASE("Test Node Equal")
{
    Node<int> node1(1);
    Node<int> node2(1);

    CHECK(node1 == node2);
}

TEST_CASE("Test Node Not Equal")
{
    Node<int> node1(1);
    Node<int> node2(2);

    CHECK_FALSE(node1 == node2);
}

TEST_CASE("Test Node String Rep")
{
    Node<int> node1(1);
    Node<int> node2(2);

    CHECK(node1.to_str() == "1");
    CHECK(node2.to_str() == "2");
}

// ----------------- Tree -----------------

TEST_CASE("Test add_root")
{
    Tree<int> tree;
    Node<int> root(1);

    tree.add_root(&root);

    CHECK(tree.get_root()->get_value() == 1);
}

TEST_CASE("Test add_sub_root BIN")
{
    Tree<int> tree;
    Node<int> root(1);
    Node<int> child1(2);
    Node<int> child2(3);

    tree.add_root(&root);
    tree.add_sub_node(&root, &child1);
    tree.add_sub_node(&root, &child2);

    CHECK(tree.get_root()->get_children().size() == 2);
}

TEST_CASE("Test add_sub_root 3")
{
    Tree<int, 3> tree;
    Node<int> root(1);
    Node<int> child1(2);
    Node<int> child2(3);
    Node<int> child3(4);

    tree.add_root(&root);
    tree.add_sub_node(&root, &child1);
    tree.add_sub_node(&root, &child2);
    tree.add_sub_node(&root, &child3);

    CHECK(tree.get_root()->get_children().size() == 3);
}

TEST_CASE("Test Invalid Adding Sub Root")
{
    Tree<int> tree;
    Node<int> root(1);
    Node<int> child1(2);
    Node<int> child2(3);
    Node<int> child3(4);

    tree.add_root(&root);
    tree.add_sub_node(&root, &child1);
    tree.add_sub_node(&root, &child2);

    CHECK_THROWS(tree.add_sub_node(&root, &child3));
}

// ----------------- Complex -----------------

TEST_CASE("Test Complex")
{
    Complex c1{1.0, 2.0};
    Complex c2{1.0, 2.0};

    CHECK(c1 == c2);
}

TEST_CASE("Test Complex Not Equal")
{
    Complex c1{1.0, 2.0};
    Complex c2{1.0, 3.0};

    CHECK_FALSE(c1 == c2);
}

TEST_CASE("Test Complex Normal")
{
    Complex c1(2.0, 3.0);
    Complex c2(4.0, -1.0);
    Complex c3(0.0, 0.0);

    // Test the normal() function
    CHECK(c1.normal() == 3.605551275463989);
    CHECK(c2.normal() == 4.123105625617661);
    CHECK(c3.normal() == 0.0);
}

TEST_CASE("Test Complex Equal")
{
    Complex c1(2.0, 3.0);
    Complex c2(4.0, -1.0);

    CHECK(c1 == Complex(2.0, 3.0));
    CHECK_FALSE(c1 == c2);
}

TEST_CASE("Test Complex Greater")
{
    Complex c1(2.0, 3.0);
    Complex c2(4.0, -1.0);

    CHECK(c2 > c1);
}

TEST_CASE("Test Complex String Rep")
{
    Complex c1(2.0, 3.0);
    Complex c2(4.0, -1.0);
    Complex c3(0.0, 0.0);

    CHECK(c1.string_rep() == "(2 + 3i)");
    CHECK(c2.string_rep() == "(4 - 1i)");
    CHECK(c3.string_rep() == "(0 + 0i)");
}

// ----------------- Iterator -----------------

TEST_CASE("Test InOrder Iterator")
{
    Node<int> *root = new Node<int>(1);
    Node<int> *left = new Node<int>(2);
    Node<int> *right = new Node<int>(3);
    root->add_child(left);
    root->add_child(right);
    Node<int> *left_left = new Node<int>(4);
    Node<int> *left_right = new Node<int>(5);
    left->add_child(left_left);
    left->add_child(left_right);
    Node<int> *right_left = new Node<int>(6);
    Node<int> *right_right = new Node<int>(7);
    right->add_child(right_left);
    right->add_child(right_right);

    InOrderIterator<int> inOrderIter(root);
    CHECK(*inOrderIter == 4);
    ++inOrderIter;
    CHECK(*inOrderIter == 2);
    inOrderIter++;
    CHECK(*inOrderIter == 5);
    ++inOrderIter;
    CHECK(*inOrderIter == 1);
    ++inOrderIter;
    CHECK(*inOrderIter == 6);
    ++inOrderIter;
    CHECK(*inOrderIter == 3);
    ++inOrderIter;
    CHECK(*inOrderIter == 7);
    ++inOrderIter;
}

TEST_CASE("Test PreOrder Iterator")
{
    Node<int> *root = new Node<int>(1);
    Node<int> *left = new Node<int>(2);
    Node<int> *right = new Node<int>(3);
    root->add_child(left);
    root->add_child(right);
    Node<int> *left_left = new Node<int>(4);
    Node<int> *left_right = new Node<int>(5);
    left->add_child(left_left);
    left->add_child(left_right);
    Node<int> *right_left = new Node<int>(6);
    Node<int> *right_right = new Node<int>(7);
    right->add_child(right_left);
    right->add_child(right_right);

    PreOrderIterator<int> preOrderIter(root);
    CHECK(*preOrderIter == 1);
    ++preOrderIter;
    CHECK(*preOrderIter == 2);
    preOrderIter++;
    CHECK(*preOrderIter == 4);
    ++preOrderIter;
    CHECK(*preOrderIter == 5);
    ++preOrderIter;
    CHECK(*preOrderIter == 3);
    ++preOrderIter;
    CHECK(*preOrderIter == 6);
    ++preOrderIter;
    CHECK(*preOrderIter == 7);
    ++preOrderIter;
}

TEST_CASE("Test PostOrder Iterator")
{
    Node<int> *root = new Node<int>(1);
    Node<int> *left = new Node<int>(2);
    Node<int> *right = new Node<int>(3);
    root->add_child(left);
    root->add_child(right);
    Node<int> *left_left = new Node<int>(4);
    Node<int> *left_right = new Node<int>(5);
    left->add_child(left_left);
    left->add_child(left_right);
    Node<int> *right_left = new Node<int>(6);
    Node<int> *right_right = new Node<int>(7);
    right->add_child(right_left);
    right->add_child(right_right);

    PostOrderIterator<int> postOrderIter(root);
    CHECK(*postOrderIter == 4);
    ++postOrderIter;
    CHECK(*postOrderIter == 5);
    postOrderIter++;
    CHECK(*postOrderIter == 2);
    ++postOrderIter;
    CHECK(*postOrderIter == 6);
    ++postOrderIter;
    CHECK(*postOrderIter == 7);
    ++postOrderIter;
    CHECK(*postOrderIter == 3);
    ++postOrderIter;
    CHECK(*postOrderIter == 1);
}

TEST_CASE("Test BFS Iterator")
{
    Node<int> *root = new Node<int>(1);
    Node<int> *left = new Node<int>(2);
    Node<int> *right = new Node<int>(3);
    root->add_child(left);
    root->add_child(right);
    Node<int> *left_left = new Node<int>(4);
    Node<int> *left_right = new Node<int>(5);
    left->add_child(left_left);
    left->add_child(left_right);
    Node<int> *right_left = new Node<int>(6);
    Node<int> *right_right = new Node<int>(7);
    right->add_child(right_left);
    right->add_child(right_right);
    BFSIterator<int> bfsIter(root);
    CHECK(*bfsIter == 1);
    ++bfsIter;
    CHECK(*bfsIter == 2);
    bfsIter++;
    CHECK(*bfsIter == 3);
    ++bfsIter;
    CHECK(*bfsIter == 4);
    ++bfsIter;
    CHECK(*bfsIter == 5);
    ++bfsIter;
    CHECK(*bfsIter == 6);
    ++bfsIter;
    CHECK(*bfsIter == 7);
    ++bfsIter;
}

TEST_CASE("Test DFS Iterator")
{
    Node<int> *root = new Node<int>(1);
    Node<int> *left = new Node<int>(2);
    Node<int> *right = new Node<int>(3);
    root->add_child(left);
    root->add_child(right);
    Node<int> *left_left = new Node<int>(4);
    Node<int> *left_right = new Node<int>(5);
    left->add_child(left_left);
    left->add_child(left_right);
    Node<int> *right_left = new Node<int>(6);
    Node<int> *right_right = new Node<int>(7);
    right->add_child(right_left);
    right->add_child(right_right);
    DFSIterator<int> dfsIter(root);
    CHECK(*dfsIter == 1);
    ++dfsIter;
    CHECK(*dfsIter == 2);
    dfsIter++;
    CHECK(*dfsIter == 4);
    ++dfsIter;
    CHECK(*dfsIter == 5);
    ++dfsIter;
    CHECK(*dfsIter == 3);
    ++dfsIter;
    CHECK(*dfsIter == 6);
    ++dfsIter;
    CHECK(*dfsIter == 7);
}

TEST_CASE("Test Heap Iterator")
{
    Node<int> *root = new Node<int>(1);
    Node<int> *left = new Node<int>(2);
    Node<int> *right = new Node<int>(3);
    root->add_child(left);
    root->add_child(right);
    Node<int> *left_left = new Node<int>(4);
    Node<int> *left_right = new Node<int>(5);
    left->add_child(left_left);
    left->add_child(left_right);
    Node<int> *right_left = new Node<int>(6);
    Node<int> *right_right = new Node<int>(7);
    right->add_child(right_left);
    right->add_child(right_right);

    HeapIterator<int> heapIter(root);
    CHECK(*heapIter == 1);
    ++heapIter;
    CHECK(*heapIter == 2);
    heapIter++;
    CHECK(*heapIter == 3);
    ++heapIter;
    CHECK(*heapIter == 4);
    ++heapIter;
    CHECK(*heapIter == 5);
    ++heapIter;
    CHECK(*heapIter == 6);
    ++heapIter;
    CHECK(*heapIter == 7);
    ++heapIter;
}