//@author eylony1403@gmail.com

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <iostream>

#include "Node.hpp"
#include "Tree.hpp"
#include "Complex.hpp"

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

TEST_CASE("TEST Invalid Adding Child")
{
    Node<int> node(1);
    Node<int> child1(2);

    node.add_child(&child1);

    CHECK_THROWS(child1.add_child(&node));
}

TEST_CASE("TEST Invalid Removing Child")
{
    Node<int> node(1);
    Node<int> child1(2);

    CHECK_THROWS(node.remove_child(&child1));
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
    tree.add_sub_root(&root, &child1);
    tree.add_sub_root(&root, &child2);

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
    tree.add_sub_root(&root, &child1);
    tree.add_sub_root(&root, &child2);
    tree.add_sub_root(&root, &child3);

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
    tree.add_sub_root(&root, &child1);
    tree.add_sub_root(&root, &child2);

    CHECK_THROWS(tree.add_sub_root(&root, &child3));
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