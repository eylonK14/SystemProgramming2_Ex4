#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>

#include "Node.hpp"
#include "Tree.hpp"

#include "doctest.h"

TEST_CASE("Test Add Node")
{
    Node<int> node(1);
    Node<int> child1(2);
    Node<int> child2(3);

    CHECK(node.get_value() == 1);

    node.add_child(child1);
    node.add_child(child2);

    CHECK(node.get_children().size() == 2);
}

TEST_CASE("Test Get Child")
{
    Node<int> node(1);
    Node<int> child1(2);
    Node<int> child2(3);

    node.add_child(child1);
    node.add_child(child2);

    CHECK(node.get_child(0).get_value() == 2);
    CHECK(node.get_child(1).get_value() == 3);
}

TEST_CASE("Test remove_child")
{
    Node<int> node(1);
    Node<int> child1(2);
    Node<int> child2(3);

    node.add_child(child1);
    node.add_child(child2);

    node.remove_child(child1);

    CHECK(node.get_children().size() == 1);
    CHECK(node.get_child(0).get_value() == 3);
}

TEST_CASE("TEST Invalid Index")
{
    Node<int> node(1);
    Node<int> child1(2);
    Node<int> child2(3);

    node.add_child(child1);
    node.add_child(child2);

    CHECK_THROWS(node.get_child(2));
    CHECK_THROWS(node.get_child(-1));
}