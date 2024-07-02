// //@author eylony1403@gmail.com

#include <iostream>
#include "Node.hpp"
#include "Tree.hpp"
#include "Complex.hpp"
#include <SFML/Graphics.hpp>

int main()
{
    {
        Node<Complex> root_node = Node<Complex>(Complex(1.1, 2.2));

        Node<Complex> n1 = Node<Complex>(Complex(1.2, 1));
        Node<Complex> n2 = Node<Complex>(Complex(1.3, 3.7));
        Node<Complex> n3 = Node<Complex>(Complex(1.4, 0.5));
        Node<Complex> n4 = Node<Complex>(Complex(1.5, 0.9));
        Node<Complex> n5 = Node<Complex>(Complex(1.6, 11.3));
        Tree<Complex> tree;

        tree.add_root(&root_node);
        tree.add_sub_node(&root_node, &n1);
        tree.add_sub_node(&root_node, &n2);
        tree.add_sub_node(&n1, &n3);
        tree.add_sub_node(&n1, &n4);
        tree.add_sub_node(&n2, &n5);

        std::cout << "In Order:" << std::endl;

        for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node)
        {
            std::cout << node->get_value() << " ";
        } // prints: 1.4, 1.2, 1.5, 1.1, 1.6, 1.3

        std::cout << "\n";
        std::cout << "Pre Order:" << std::endl;

        for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node)
        {
            std::cout << node->get_value() << " ";
        } // prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6

        std::cout << "\n";
        std::cout << "Post Order:" << std::endl;

        for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node)
        {
            std::cout << node->get_value() << " ";
        } // prints: 1.4, 1.5, 1.2, 1.6, 1.3, 1.1

        std::cout << "\n";
        std::cout << "BFS:" << std::endl;

        for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node)
        {
            std::cout << node->get_value() << " ";
        } // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6

        std::cout << "\n";
        std::cout << "DFS:" << std::endl;

        for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node)
        {
            std::cout << node->get_value() << " ";
        } // prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6

        std::cout << "\n";
        std::cout << "Standart Iterator:" << std::endl;

        for (auto node : tree)
        {
            std::cout << node << " ";
        } // same as BFS: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6

        std::cout << "\n";
        std::cout << "Heap Iterator:" << std::endl;

        for (auto node = tree.begin_heap(); node != tree.end_heap(); ++node)
        {
            std::cout << node->get_value() << " ";
        } // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6

        std::cout << "\n";

        std::cout << tree;
    }

    {
        // Create a tree
        Node<double> root_node = Node<double>(1.1);

        Node<double> n1 = Node<double>(1.2);
        Node<double> n2 = Node<double>(1.3);
        Node<double> n3 = Node<double>(1.4);
        Node<double> n4 = Node<double>(1.5);
        Node<double> n5 = Node<double>(1.6);

        Tree<double, 3> three_ary_tree; // 3-ary tree.
        three_ary_tree.add_root(&root_node);
        three_ary_tree.add_sub_node(&root_node, &n1);
        three_ary_tree.add_sub_node(&root_node, &n2);
        three_ary_tree.add_sub_node(&root_node, &n3);
        three_ary_tree.add_sub_node(&n1, &n4);
        three_ary_tree.add_sub_node(&n2, &n5);

        std::cout << "BFS 3-ary:" << std::endl;

        for (auto node = three_ary_tree.begin_bfs_scan(); node != three_ary_tree.end_bfs_scan(); ++node)
        {
            std::cout << node->get_value() << " ";
        }

        std::cout << "\n";
        std::cout << "DFS 3-ary:" << std::endl;

        for (auto node = three_ary_tree.begin_dfs_scan(); node != three_ary_tree.end_dfs_scan(); ++node)
        {
            std::cout << node->get_value() << " ";
        }

        std::cout << "\n";

        std::cout << three_ary_tree;

        // // The tree should look like:
        // /**
        //  *       root = 1.1
        //  *     /      |     \
        //  *    1.2    1.3    1.4
        //  *   /        |
        //  *  1.5      1.6
        //  */
    }

    return 0;
}
