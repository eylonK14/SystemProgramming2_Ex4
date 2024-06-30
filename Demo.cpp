//@author eylony1403@gmail.com

#include <iostream>
#include "Node.hpp"
#include "Tree.hpp"
#include "Complex.hpp"

int main()
{

    Node<double> root_node = Node<double>(1.1);

    Node<double> n1 = Node<double>(1.2);
    Node<double> n2 = Node<double>(1.3);
    Node<double> n3 = Node<double>(1.4);
    Node<double> n4 = Node<double>(1.5);
    Node<double> n5 = Node<double>(1.6);

    {
        Tree<double> tree; // Binary tree that contains doubles.
        tree.add_root(&root_node);
        tree.add_sub_node(&root_node, &n1);
        tree.add_sub_node(&root_node, &n2);
        tree.add_sub_node(&n1, &n3);
        tree.add_sub_node(&n1, &n4);
        tree.add_sub_node(&n2, &n5);

        // The tree should look like:
        /**
         *       root = 1.1
         *     /       \
         *    1.2      1.3
         *   /  \      /
         *  1.4  1.5  1.6
         */

        std::cout << "In Order:" << std::endl;

        for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node)
        {
            std::cout << node->get_value() << std::endl;
        } // prints: 1.4, 1.2, 1.5, 1.1, 1.6, 1.3

        std::cout << "Pre Order:" << std::endl;

        for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node)
        {
            std::cout << node->get_value() << std::endl;
        } // prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6

        std::cout << "Post Order:" << std::endl;

        for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node)
        {
            std::cout << node->get_value() << std::endl;
        } // prints: 1.4, 1.5, 1.2, 1.6, 1.3, 1.1

        std::cout << "BFS:" << std::endl;

        for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node)
        {
            std::cout << node->get_value() << std::endl;
        } // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6

        std::cout << "DFS:" << std::endl;

        for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node)
        {
            std::cout << node->get_value() << std::endl;
        } // prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6

        std::cout << "Standart Iterator:" << std::endl;

        for (auto node : tree)
        {
            std::cout << node << std::endl;
        } // same as BFS: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6

        std::cout << "Heap Iterator:" << std::endl;

        for(auto node = tree.begin_heap(); node != tree.end_heap(); ++node)
        {
            std::cout << node->get_value() << std::endl;
        } // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6
    }

    // cout << tree; // Should print the graph using GUI.

    {
        Tree<double, 3> three_ary_tree; // 3-ary tree.
        three_ary_tree.add_root(&root_node);
        three_ary_tree.add_sub_node(&root_node, &n1);
        three_ary_tree.add_sub_node(&root_node, &n2);
        three_ary_tree.add_sub_node(&root_node, &n3);
        three_ary_tree.add_sub_node(&n1, &n4);
        three_ary_tree.add_sub_node(&n2, &n5);

        // // The tree should look like:
        // /**
        //  *       root = 1.1
        //  *     /      |     \
    //  *    1.2    1.3    1.4
        //  *   /        |
        //  *  1.5      1.6
        //  */

        std::cout << "BFS 3-ary:" << std::endl;

        for (auto node = three_ary_tree.begin_bfs_scan(); node != three_ary_tree.end_bfs_scan(); ++node)
        {
            std::cout << node->get_value() << std::endl;
        }

        std::cout << "DFS 3-ary:" << std::endl;

        for (auto node = three_ary_tree.begin_dfs_scan(); node != three_ary_tree.end_dfs_scan(); ++node)
        {
            std::cout << node->get_value() << std::endl;
        }
    }
}
