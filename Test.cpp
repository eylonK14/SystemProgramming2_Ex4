#include "doctest.h"
#include "Node.hpp"
#include "Tree.hpp"

TEST_CASE("Test Add Node")
{
    Node<int> node(1);
    Node<int> child1(2);
    Node<int> child2(3);

    CHECK(node.getData() == 1);

    node.addChild(&child1);
    node.addChild(&child2);

    CHECK(node.getChildren().size() == 2);
}

TEST_CASE("Test Get Child")
{
    Node<int> node(1);
    Node<int> child1(2);
    Node<int> child2(3);

    node.addChild(&child1);
    node.addChild(&child2);

    CHECK(node.getChild(0)->getData() == 2);
    CHECK(node.getChild(1)->getData() == 3);
}

TEST_CASE("Test Remove Child")
{
    Node<int> node(1);
    Node<int> child1(2);
    Node<int> child2(3);

    node.addChild(&child1);
    node.addChild(&child2);

    node.removeChild(&child1);

    CHECK(node.getChildren().size() == 1);
    CHECK(node.getChild(0)->getData() == 3);
}

TEST_CASE("TEST Invalid Index")
{
    Node<int> node(1);
    Node<int> child1(2);
    Node<int> child2(3);

    node.addChild(&child1);
    node.addChild(&child2);

    CHECK_THROWS(node.getChild(2));
    CHECK_THROWS(node.getChild(-1));
}